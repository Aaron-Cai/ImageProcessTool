#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QString>
#include <QPixmap>
#include <QImage>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include <QStack>
#include <QDialog>
//#include <algorithm>
#include <vector>
#include "ui_mainwindow.h"
#include "Convolutioner.h"
#include "Binarization.h"
#include "Morphology.h"
#include "StructureElementSet.h"
#include "ui_DialogStructureElement.h"
using namespace IPFbyCJY;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

	bool pre_process();
	void post_process(Processer* pro,QString s);
	void showStructureElement(Morphology* morph);
	void showStructureElement(SE se);
	void iniSEDialog();

	

	public slots:
		void loadImage();
		void saveImage();
		void showHistogram();
		void SetProjectView(int i);
		void setStructureElement(SE se,int cx, int cy);
		
#pragma region binarization
		void otsuBinary();
		void entropyBinary();
		void binarization(int threshold);
#pragma endregion binarization
		
#pragma region edge dectors and filters
		//void Sobel();
		void conv(int t);
		void cusconv();
#pragma endregion edge dectors and filters

#pragma region morphology
		void dilation();
		void erosion();
		void open();
		void morph_close();
		void distanceTransform();
		void getSkeleton();
		void edgeDect();
		void gradient();
		void grayScaleReconstruction();
		void conditional_dialation(int x, int y);
#pragma endregion morphology


		void undo();
		void redo();
		void clearOperations();

private:
	Ui::MainWindowClass ui;

	QImage* ori_img;
	QImage* gray_img;
	QImage* prcess_img;
	//QStack<QImage*> m_processimgstack;
	vector<QImage*> m_processimgstack;
	QString fileName;
	Processer *mp_processer;

	vector<int> histogram;

	bool fileload;
	bool isProcessed;

	QString filedir;

	StructureElementSet *m_seSet;
	QDialog* m_seDialog;
	Ui_Dialog m_seDialogUi;


	SE m_se;
	int m_centerx;
	int m_centery;
	bool isSetSE;
};

#endif // MAINWINDOW_H
