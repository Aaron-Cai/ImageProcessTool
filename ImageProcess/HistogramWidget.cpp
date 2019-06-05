#include "HistogramWidget.h"

HistogramWidget::HistogramWidget(QWidget* parent):QWidget(parent),readToDraw(false)
{
	mMenu = new QMenu();
	actSaveHis = mMenu->addAction(tr("Save Histogram"));
	connect(actSaveHis,SIGNAL(triggered()),this,SLOT(save()));


// 	layout = new QVBoxLayout(this);
// 
// 	panel = new QWidget(this);
// 	layout->addWidget(panel);
// 	slider = new QSlider(this);
// 	slider->setMaximum(255);
// 	slider->setOrientation(Qt::Horizontal);
// 
// 	layout->addWidget(slider);
// 
// 	this->setLayout(layout);
}

HistogramWidget::~HistogramWidget()
{
}
void HistogramWidget::save()
{
	if(readToDraw)
	{
		QString filename = QFileDialog::getSaveFileName(this, tr("Save"),
			"C:/Users/Aaron/Pictures/",
			tr("Images (*.png *.xpm *.jpg *.tiff *.bmp)"));
		hist->save(filename);
	}
}
void HistogramWidget::paintEvent(QPaintEvent *e)
{
	QPainter p(this);
	p.setBrush(QBrush(QColor(121,121,121)));
	p.drawRect(0,0,this->width(),this->height());
	if(!readToDraw)
		return;	

	p.setBrush(QBrush(QColor(255,255,255)));
	p.drawRect(0,0,this->width(),this->height());
	std::vector<int> sortcount = count;
	std::sort(sortcount.begin(),sortcount.end());
	int maxcount = sortcount[sortcount.size()-1];


	hist = new QImage(this->width(),this->height(),QImage::Format_RGB888);
	hist->fill(qRgb(255,255,255));
	p.translate(0,hist->height());


	p.drawLine(0,0,100,100);

	int wid=hist->width();
	int hei=hist->height();

	p.drawLine(10,-10,wid-10,-10);// ºáÖá
	p.drawLine(10,-10,10,-hei+10);//×ÝÖá

	float xstep = float(wid-20) / 256;
	float ystep = float(hei-20) / maxcount;

	for (int i=0;i!=256;i++)
	{
		if(i!=255)
		{
			QColor color(i,255-i,0);
			//p.setPen(Qt::blue);
			//p.setBrush(Qt::blue);
			p.setBrush(color);
			p.setPen(color);
			//p.drawLine(QPointF(10+(i+0.5)*xstep,-10-ystep*count[i]),QPointF(10+(i+1.5)*xstep,-10-ystep*count[i+1]));
			p.drawRect(10+i*xstep,-10,xstep,-10-ystep*count[i]);
		}

		if(i % 32 == 0||i==255)
		{
			p.drawText(QPointF(10+(i-0.5)*xstep,0),QString::number(i));
		}

	}
}

void HistogramWidget::setHistogram(vector<int> his)
{
	count = his;
	readToDraw=true;
	update();
}

void HistogramWidget::contextMenuEvent(QContextMenuEvent *e)
{
	mMenu->exec(QCursor::pos());
}
