#include "mainwindow.h"
#include <math.h>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags),fileload(false),isProcessed(false),isSetSE(false)
{
	ui.setupUi(this);
	setWindowState(Qt::WindowMaximized);

	iniSEDialog();

	ui.widget_1->widgetid = 0;
	ui.widget_2->widgetid = 1;
	//ui.widget_hist->widgetid = 2;
	ui.widget_3->widgetid = 3;
	ui.widget_3->iniActions();
	connect(ui.widget_3,SIGNAL(sig_condional_dia(int,int)),this,SLOT(conditional_dialation(int,int)));
}


void MainWindow::conditional_dialation(int x, int y)
{
	if(!pre_process())
		return;
	IPFbyCJY::ConditionalDilation* cond;
	vector<vector<int>> seed(1);
	seed[0].push_back(x);
	seed[0].push_back(y);
	cond = new IPFbyCJY::ConditionalDilation(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,seed);
	post_process(cond,"Conditonal dilation");
	showStructureElement(cond);


	ui.tabWidget->setCurrentIndex(2);
}

void MainWindow::iniSEDialog()
{
	m_seDialog = new QDialog(this);
	m_seDialogUi.setupUi(m_seDialog);
	m_seSet= new StructureElementSet(m_seDialog,&m_seDialogUi);
	connect(ui.btnSetSE,SIGNAL(clicked()),m_seSet,SLOT(showDialog()));
	connect(m_seSet,SIGNAL(sendSE(SE ,int ,int )),this,SLOT(setStructureElement(SE,int,int)));
}


void MainWindow::setStructureElement(SE se,int cx, int cy)
{
	m_se = se;
	m_centerx = cx;
	m_centery = cy;
	isSetSE = true;
	showStructureElement(m_se);
}

MainWindow::~MainWindow()
{

}
void MainWindow::clearOperations()
{
	if(!fileload)
		return;
	ui.widget_3->clear();
	switch(ui.tabWidget->currentIndex())
	{
	case 1:
		ui.plainTextEdit->setPlainText("");
		ui.comboBox->setCurrentIndex(-1);
	default:
		break;
	}
	isProcessed = false;

	for (int i=0;i!=m_processimgstack.size();i++)
	{
		unsigned char* p = m_processimgstack[i]->bits();
		delete []p;
	}
// 	for (vector<QImage*>::iterator itr = m_processimgstack.begin();itr != m_processimgstack.end();++itr)
// 	{
// 		delete *itr;
// 		*itr = NULL;
// 	}
	m_processimgstack.clear();
	ui.statusBar->clearMessage();
	ui.statusBar->showMessage("clear all operation.");
}
void MainWindow::SetProjectView(int i)
{
	if(i!=0)
		ui.slider->setVisible(false);
	else
		ui.slider->setVisible(true);

	ui.comboBox->setCurrentIndex(-1);
}


void MainWindow::loadImage()
{
	clearOperations();
	filedir = QFileDialog::getOpenFileName(this, tr("Open File"),
		"C:/Users/Aaron/Pictures/standord test/",
		tr("Images (*.png *.xpm *.jpg *.tiff *.bmp)"));
	if (filedir.isNull()||filedir == "")
	{
		return;
	}
	fileName = filedir;
	ori_img = new QImage;
	ori_img->load(fileName);
	//ui.label_1->setPixmap(QPixmap::fromImage((ori_img->scaled(ui.label_1->width(),ui.label_1->height(),Qt::KeepAspectRatio))));
	ui.widget_1->setImage(ori_img);
	gray_img = IPFbyCJY::Processer::rgb2gray(ori_img);
	//ui.label_2->setPixmap(QPixmap::fromImage((gray_img->scaled(ui.label_2->width(),ui.label_2->height(),Qt::KeepAspectRatio))));
	ui.widget_2->setImage(gray_img);
	showHistogram();
	fileload = true;

	ui.statusBar->showMessage("Image load");
}

void MainWindow::saveImage()
{	
	if(isProcessed)
	{
		QString filename = QFileDialog::getSaveFileName(this, tr("Open File"),
			"C:/Users/Aaron/Pictures/",
			tr("Images (*.png *.xpm *.jpg *.tiff *.bmp)"));
		prcess_img->save(filename);
	}
}
void MainWindow::showHistogram()
{
	if(gray_img->isNull())
	{
		return;
	}
	vector<int> count = IPFbyCJY::Processer::Histogram(gray_img);
	ui.widget_hist->setHistogram(count);
	//ui.smallhist->setHistogram(count);


	histogram.resize(256);
	for (int i=0;i!=256;i++)
	{
		histogram[i] = count[i];
	}


	std::vector<int> sortcount = count;
	std::sort(sortcount.begin(),sortcount.end());
	int maxcount = sortcount[sortcount.size()-1];


	QImage* hist = new QImage(this->width(),this->height(),QImage::Format_RGB888);
	QPainter p(hist);
	hist->fill(qRgb(255,255,255));
	p.translate(0,hist->height());


	p.drawLine(0,0,100,100);

	int wid=hist->width();
	int hei=hist->height();

	//p.drawLine(10,-10,wid-10,-10);// 横轴
	//p.drawLine(10,-10,10,-hei+10);//纵轴

	float xstep = float(wid) / 256;
	float ystep = float(hei-20) / maxcount;

	for (int i=0;i!=256;i++)
	{

		QColor color(i,255-i,0);
		//p.setPen(Qt::blue);
		//p.setBrush(Qt::blue);
		p.setBrush(color);
		p.setPen(color);
		//p.drawLine(QPointF((i+0.5)*xstep,-ystep*count[i]),QPointF(10+(i+1.5)*xstep,-10-ystep*count[i+1]));
		p.drawRect(i*xstep,0,xstep,-ystep*count[i]);
	}
	
	ui.smallhist->setPixmap(QPixmap::fromImage(hist->scaled(ui.smallhist->width(),ui.smallhist->height(),Qt::KeepAspectRatio)));
}

void MainWindow::otsuBinary()
{
	if(fileload)
	{
		IPFbyCJY::Binarization *bin = new IPFbyCJY::OtsuBinarization(gray_img);
		binarization(bin->threshold);
	}
}

void MainWindow::binarization(int threshold)
{
	if(!pre_process())
		return;
	IPFbyCJY::Binarization *bin = new IPFbyCJY::Binarization(gray_img);
	bin->threshold = threshold;
	post_process(bin,"Binarization. Threshold = " + QString::number(threshold,10));

	ui.slider->setValue(threshold);
}

void MainWindow::entropyBinary()
{
	if(fileload)
	{
		IPFbyCJY::EntropyBinarization *bin = new IPFbyCJY::EntropyBinarization(gray_img);
		binarization(bin->threshold);
	}
}


void MainWindow::conv(int t)
{
	if(!pre_process())
	{
		ui.comboBox->setCurrentIndex(-1);
		return;
	}
	IPFbyCJY::Convolutioner *con;
	switch(t)
	{
	case 0:
		con = new IPFbyCJY::Sobel(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
		break;
	case 1:
		con = new IPFbyCJY::Prewitt(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
		break;
	case 2:
		con = new IPFbyCJY::MeanFilter(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
		break;
	case 3:
		con = new IPFbyCJY::MedianFilter(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
		break;
	case 4:
		con = new IPFbyCJY::GaussianFilter(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
		break;
	default:
		return;
	}
	post_process(con,"convolution with kernal of "+ui.comboBox->currentText());
#pragma region show_kernel
	vector<vector<float>> kernal = con->getKernal();
	QString s;
	for (int i=0;i!=kernal.size();i++)
	{
		for (int j=0;j!=kernal[i].size();j++)
		{
			s += QString::number(double(kernal[i][j]));
			s += " ";
		}
		s += "\n";
	}

	ui.plainTextEdit->setPlainText(s);
#pragma endregion show_kernel

}
void MainWindow::cusconv()
{
	if(!pre_process())
		return;
	if(ui.plainTextEdit->toPlainText().isEmpty())
	{
		QMessageBox::warning(this,tr("Error"),tr("Nothing input"));  
		ui.plainTextEdit->setPlainText("");
		return;
	}
	QStringList strlst = ui.plainTextEdit->toPlainText().split(QRegExp("\\s+")); 
	int length = strlst.size();
	float kernelsize = sqrt(float(length));
	if(kernelsize - int(kernelsize) > 0.0000001 || int(kernelsize)%2 == 0)
	{
		QMessageBox::warning(this,"Error","Invalid input");
		ui.plainTextEdit->setPlainText("");
		return;
	}
	vector<vector<float>> kernel;
	kernel.resize(kernelsize);
	for (int i=0;i!=kernelsize;i++)
	{
		for (int j=0;j!=kernelsize;j++)
		{
			kernel[i].push_back(strlst[i*kernelsize+j].toDouble());
		}
	}
	IPFbyCJY::Convolutioner *con = new IPFbyCJY::CunstomCon(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	con->setKernel(kernel);
	post_process(con,"convolution with custom kernal");
}

void MainWindow::undo()
{
	if(m_processimgstack.size() == 0)
		return;

	vector<QImage*>::iterator itr = m_processimgstack.end()-1;
	unsigned char* p = m_processimgstack[m_processimgstack.size()-1]->bits();
	delete []p;
	//delete *itr;
	//*itr = NULL;
	m_processimgstack.pop_back();

	if(m_processimgstack.size() == 0)
	{
		//ui.label_4->clear();
		ui.widget_3->clear();
		isProcessed = false;
	}
	else
	{
		ui.widget_3->setImage(m_processimgstack[m_processimgstack.size()-1]);
	}
	//ui.label_4->setPixmap(QPixmap::fromImage(m_processimgstack[m_processimgstack.size()-1]->scaled(ui.label_4->width(),ui.label_4->height(),Qt::KeepAspectRatio)));
}

void MainWindow::redo()
{
	//mp_processer->process();
}


void MainWindow::dilation()
{
	if(!pre_process())
		return;
	IPFbyCJY::Dilation* dila = new IPFbyCJY::Dilation(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);

// 	prcess_img = new QImage(dila->biterosion(),gray_img->width(),gray_img->height(),gray_img->bytesPerLine(),QImage::Format_RGB888);
// 	ui.widget_3->setImage(prcess_img);
// 	m_processimgstack.push(prcess_img);
// 	isProcessed = true;
	post_process(dila,"Dilation");
	showStructureElement(dila);
}


void MainWindow::erosion()
{
	if(!pre_process())
		return;
	IPFbyCJY::Erosion* ero = new IPFbyCJY::Erosion(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	post_process(ero,"Erosion");
	showStructureElement(ero);
}

void MainWindow::open()
{
	if(!pre_process())
		return;
	IPFbyCJY::Open* ope;
	if(!isSetSE)
		ope = new IPFbyCJY::Open(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		ope = new IPFbyCJY::Open(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);

// 	SE se(1);
// 	for (int i=0;i!=30;i++)
// 	{
// 		se[0].push_back(1);
// 	}
// 	ope = new IPFbyCJY::Open(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,se,15,0);
	post_process(ope,"Open");
	showStructureElement(ope);
}

void MainWindow::morph_close()
{
	if(!pre_process())
		return;

	IPFbyCJY::Close* close;
	if(!isSetSE)
		close = new IPFbyCJY::Close(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		close = new IPFbyCJY::Close(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);

	post_process(close,"close");
	showStructureElement(close);
}

void MainWindow::distanceTransform()
{
	if(!pre_process())
		return;
	IPFbyCJY::DistanceTransform* disTrans; 
	if (!isSetSE)
		disTrans= new IPFbyCJY::DistanceTransform(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		disTrans=new IPFbyCJY::DistanceTransform(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);
	post_process(disTrans,"Distance Transform");
	showStructureElement(disTrans);
}

void MainWindow::getSkeleton()
{
	if(!pre_process())
		return;
	IPFbyCJY::Skeleton *ske;
	if(!isSetSE)
		ske = new IPFbyCJY::Skeleton(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		ske = new IPFbyCJY::Skeleton(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);

	post_process(ske,"Skeleton");
	showStructureElement(ske);
}

void MainWindow::edgeDect()
{
	if(!pre_process())
		return;
	IPFbyCJY::MorphEdgeDect *edge ;
	if(!isSetSE)
		edge = new IPFbyCJY::MorphEdgeDect(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		edge = new IPFbyCJY::MorphEdgeDect(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);

	post_process(edge,"Edge");
	showStructureElement(edge);
}

void MainWindow::gradient()
{
	if(!pre_process())
		return;
	IPFbyCJY::MorphGradient *grad ;
	if(!isSetSE)
		grad= new IPFbyCJY::MorphGradient(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img);
	else
		grad = new IPFbyCJY::MorphGradient(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,m_se,m_centerx,m_centery);

	post_process(grad,"Gradient");
	showStructureElement(grad);
}

void MainWindow::grayScaleReconstruction()
{
	if(!pre_process())
		return;
// 	IPFbyCJY::GrayScaleReconstruction *grscale;
// 	if(!isSetSE)
// 		grscale = new IPFbyCJY::GrayScaleReconstruction(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,gray_img);
// 	else
// 		grscale = new IPFbyCJY::GrayScaleReconstruction(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,gray_img);
	post_process(new IPFbyCJY::GrayScaleReconstruction(isProcessed?m_processimgstack[m_processimgstack.size()-1]:gray_img,gray_img,ui.radioButton_3->isChecked()),"Gray scale reconstructino");
}

bool MainWindow::pre_process()
{
	if(!fileload)
		return false;

	ui.statusBar->showMessage("Processing...");
	return true;
}

void MainWindow::post_process(Processer* pro,QString s)
{
	LARGE_INTEGER litmp;
	LONGLONG qt1,qt2;
	double dft,dff,dfm;
	QueryPerformanceFrequency(&litmp);//获得时钟频率
	dff=(double)litmp.QuadPart;
	QueryPerformanceCounter(&litmp);//获得初始值
	qt1=litmp.QuadPart;
	prcess_img = pro->process();
	//ui.label_4->setPixmap(QPixmap::fromImage(prcess_img->scaled(ui.label_4->width(),ui.label_4->height(),Qt::KeepAspectRatio)));
	ui.widget_3->setImage(prcess_img);
	m_processimgstack.push_back(prcess_img);

	QueryPerformanceCounter(&litmp);//获得终止值
	qt2=litmp.QuadPart;
	dfm=(double)(qt2-qt1);
	dft=dfm/dff;//获得对应的时间值

	QString st = ", time cost " + QString::number(dft) +" Seconds";
	ui.statusBar->showMessage(s + st);
	isProcessed = true;
}

void MainWindow::showStructureElement(Morphology* morph)
{
	SE se = morph->getSE();

	QString str_se="";
	for (int i =0;i!=se.size();i++)
	{
		for (int j=0;j!=se[i].size();j++)
		{
			if(se[i][j] == 0 || se[i][j] == 1)
				str_se += QString::number(se[i][j]);
			else
				str_se += "-";
			str_se += " ";
		}
		str_se += "\n";
	}

	ui.plainTextEdit_2->setPlainText(str_se);
}

void MainWindow::showStructureElement(SE se)
{
	QString str_se="";
	for (int i =0;i!=se.size();i++)
	{
		for (int j=0;j!=se[i].size();j++)
		{
			if(se[i][j] == 0 || se[i][j] == 1)
				str_se += QString::number(se[i][j]);
			else
				str_se += "-";
			str_se += " ";
		}
		str_se += "\n";
	}

	ui.plainTextEdit_2->setPlainText(str_se);
}