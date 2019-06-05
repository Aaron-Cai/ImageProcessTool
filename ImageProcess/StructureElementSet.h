#pragma once
#include "ui_DialogStructureElement.h"
#include <vector>
#include "Morphology.h"
using namespace std;
using namespace IPFbyCJY;

class StructureElementSet :
	public QObject
{
	Q_OBJECT
public:
	StructureElementSet(QDialog *dialog,Ui_Dialog *ui);
	~StructureElementSet();



	public slots:
		void showDialog()
		{
			setTable();
			m_dialog->exec();
			
		}
		void setRows(int r)
		{
			SeRows = r;
			setTable();
		}
		void setColumns(int c)
		{
			SeColumns = c;
			setTable();
		}

		void setTable();

		void clearTable();

		void setCenter(int x,int y)
		{
			SeCenterX = y;
			SeCenterY = x;

			m_DialogUi->lineEdit->setText(QString::number(SeCenterX+1));
			m_DialogUi->lineEdit_2->setText(QString::number(SeCenterY+1));
		}

		void setCenterX(const QString &x)
		{
			SeCenterX = x.toInt();
		}

		void setCenterY(const QString &y)
		{
			SeCenterY = y.toInt();
		}
		
// 		void add_input(int r,int c)
// 		{
// 			vector<int> t;
// 			t.push_back(r);
// 			t.push_back(c);
// 			input_index.push_back(t);
// 		}
		void setSE();

 signals:
		void sendSE(SE se,int cx,int cy);
	
private:
	Ui_Dialog* m_DialogUi;
	QDialog *m_dialog;
	//vector<vector<int>> input_index;
	int SeColumns;
	int SeRows;

	vector<vector<int>> m_se;
	int SeCenterX;
	int SeCenterY;
};
