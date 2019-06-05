#include "ImageWidget.h"
#include <iostream>

ImageWidget::ImageWidget(QWidget *parent):QWidget(parent),isImageLoad(false),scalex(1),scaley(1),xtranslate(0),ytranslate(0),mouse(No),maxmum(false)
{
	iniActions();
}

ImageWidget::~ImageWidget(void)
{
	if(isImageLoad)
		delete mp_img;
}


void ImageWidget::wheelEvent(QWheelEvent *e)
{
	int numDegrees = e->delta();
	if(numDegrees > 0)
	{
		zoomout();
	}
	if(numDegrees < 0)
	{
		zoomin();
	}
	update();
}
void ImageWidget::mousePressEvent(QMouseEvent *e)
{
	switch(e->button())
	{
	case Qt::LeftButton:
		mouse = Left;
		break;
	case Qt::RightButton:
		mouse = Right;
		break;
	case Qt::MiddleButton:
		mouse = Mid;
		break;
	default:
		mouse = No;
	}
	mousePosX = e->x();
	mousePosY = e->y();
}
void ImageWidget::mouseMoveEvent(QMouseEvent *e)
{
	if(mouse == Mid)
	{
		//xtranslate = e->x() - mousePosX;
		//ytranslate = e->y() - mousePosY;
		translate(e->x() - mousePosX,e->y() - mousePosY);
	}
	update();
}

void ImageWidget::translate(int x,int y)
{
	xtranslate = x;
	ytranslate = y;
	update();
}

void ImageWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.setBrush(QBrush(QColor(121,121,121)));
	painter.drawRect(0,0,this->width(),this->height());
	if(!isImageLoad)
		return;
	
	painter.drawImage(QPoint(xtranslate,ytranslate),mp_img->scaled(this->width()*scalex,this->height()*scaley,Qt::KeepAspectRatio));
}

void ImageWidget::contextMenuEvent(QContextMenuEvent *e)
{
	mMenu->exec(QCursor::pos());
	//mousePosX = QCursor::pos().x();
	//mousePosY = QCursor::pos().y();
}

void ImageWidget::resetPos()
{
	xtranslate = 0;
	ytranslate = 0;
	scalex = 1;
	scaley = 1;
	update();
}

void ImageWidget::zoomout()
{
	if(scalex<=100&&scaley<=100)
	{
		scalex *= 1.2;
		scaley *= 1.2;
	}
	update();
}

void ImageWidget::zoomin()
{
	if(scalex>=0.01&&scaley>=0.01)
	{
		scalex *= 1/1.2;
		scaley *= 1/1.2;
	}
	update();
}

void ImageWidget::iniActions()
{
	mMenu = new QMenu();
	mActionResetPos = mMenu->addAction(tr("reset pos"));
	mActionSave		= mMenu->addAction(tr("save picture"));
	
	connect(mActionResetPos,SIGNAL(triggered()),this,SLOT(resetPos()));
	connect(mActionSave,SIGNAL(triggered()),this,SLOT(save()));

	if(widgetid == 3)
	{
		conditionDialation = mMenu->addAction(tr("Conditionnal dilation"));
		connect(conditionDialation,SIGNAL(triggered()),this,SLOT(con_dia()));
	}
}

void ImageWidget::con_dia()
{
	if(isImageLoad)
	{
		QImage tmp = mp_img->scaled(this->width()*scalex,this->height()*scaley,Qt::KeepAspectRatio);

		emit sig_condional_dia(int(mousePosX*1.0 / tmp.width() * mp_img->width()),int(mousePosY*1.0 / tmp.height() * mp_img->height()));
	}
}

void ImageWidget::save()
{
	if(isImageLoad)
	{
		QString filename = QFileDialog::getSaveFileName(this, tr("Open File"),
			"C:/Users/Aaron/Pictures/",
			tr("Images (*.png *.xpm *.jpg *.tiff *.bmp)"));
		mp_img->save(filename);
	}
}

void ImageWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
	if(!maxmum)
	{
		QSplitter *splitter = (QSplitter*)parentWidget();
		QSplitter *splitter1 = (QSplitter*)splitter->parentWidget();

		if(widgetid==0 || widgetid==1)
		{
			splitter1->widget(1)->hide();
			splitter->widget(widgetid%2==0?1:0)->hide();
		}

		if(widgetid==2||widgetid==3)
		{
			splitter1->widget(0)->hide();
			splitter->widget(widgetid%2==0?1:0)->hide();
		}
		maxmum = true;
	}
	else
	{
		QSplitter *splitter = (QSplitter*)parentWidget();
		QSplitter *splitter1 = (QSplitter*)splitter->parentWidget();

		for(int i=0;i!=splitter->count();i++)
		{
			splitter->widget(i)->show();
		}

		maxmum = false;
		for (int i=0;i!=splitter1->count();i++)
		{
			splitter1->widget(i)->show();
		}
	}
}
