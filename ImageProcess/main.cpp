#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	QFile file("style.qss");//·��ΪӦ�ó�������Ŀ¼��ʼ
	file.open(QFile::ReadOnly);
	QTextStream filetext(&file);
	QString stylesheet= filetext.readAll();
	a.setStyleSheet(stylesheet);



	return a.exec();
}
