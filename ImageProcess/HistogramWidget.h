#pragma once

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QImage>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QSlider>
 #include <QVBoxLayout>
using namespace std;
class HistogramWidget :
	public QWidget
{
	Q_OBJECT
public:
	HistogramWidget(QWidget *parent);
	~HistogramWidget();
	void setHistogram(vector<int> his);
	void paintEvent(QPaintEvent *e);
	void contextMenuEvent(QContextMenuEvent *e);
	
	public slots:
		void save();
private:
	QImage* hist;

	vector<int> count;

	QMenu* mMenu;
	QAction* actSaveHis;
	bool readToDraw;
// 	QWidget* panel;
// 	QVBoxLayout* layout;
public:
	int widgetid;
	/*QSlider *slider;*/
};
