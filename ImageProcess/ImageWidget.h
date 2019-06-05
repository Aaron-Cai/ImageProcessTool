#pragma once
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QWheelEvent>
#include <QMenu>
#include <QCursor>
#include <QFileDialog>
#include <QSplitter>

enum MouseDown{Left,Mid,Right,No};
class ImageWidget :
	public QWidget
{
	Q_OBJECT
public:
	ImageWidget(QWidget *parent);
	~ImageWidget();

	void setImage(QImage* img)
	{
		mp_img = img;
		isImageLoad = true;
		update();
	}

	void clear()
	{
		if(isImageLoad)
		{
			isImageLoad = false;
			//delete mp_img;
			mp_img = NULL;
			update();
		}

	}
	
	void iniActions();
	
	void wheelEvent(QWheelEvent *e);
	void mouseMoveEvent(QMouseEvent * e);
	void mousePressEvent(QMouseEvent * e);
	void paintEvent(QPaintEvent *e);
	void contextMenuEvent(QContextMenuEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);


public slots:
	void resetPos();
	void zoomout();
	void zoomin();
	void translate(int x,int y);
	void save();
	void con_dia();
signals:
	void sig_condional_dia(int x,int y);
private:
	QImage *mp_img;

	float scalex;
	float scaley;
	int xtranslate;
	int ytranslate;

	int mousePosX;
	int mousePosY;
	bool isImageLoad;

	MouseDown mouse;
	
	QAction* mActionResetPos;
	QAction* mActionSave;

	QAction* conditionDialation;
	QMenu* mMenu;
	bool maxmum;

	//QPoint mospos;
public:
	int widgetid;
};
