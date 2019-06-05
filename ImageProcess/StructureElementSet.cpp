#include "StructureElementSet.h"

StructureElementSet::StructureElementSet(QDialog *dialog,Ui_Dialog *ui):SeRows(3),SeColumns(3)
{
	m_DialogUi = ui;
	m_dialog = dialog;

	connect(m_DialogUi->spinBoxColumn,SIGNAL(valueChanged(int)),this,SLOT(setColumns(int)));
	connect(m_DialogUi->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(setColumns(int)));
	connect(m_DialogUi->spinBoxRow,SIGNAL(valueChanged(int)),this,SLOT(setRows(int)));
	connect(m_DialogUi->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(setRows(int)));

	connect(m_DialogUi->btnReset,SIGNAL(clicked()),this,SLOT(clearTable()));
	connect(m_DialogUi->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(setCenter(int,int)));
	connect(m_dialog,SIGNAL(accepted()),this,SLOT(setSE()));
	//connect(m_DialogUi->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(add_input(int,int)));
	//connect(m_DialogUi->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(add_input(int,int)));

	connect(m_DialogUi->lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(SeCenterX(const QString&)));
	connect(m_DialogUi->lineEdit_2,SIGNAL(textChanged(const QString&)),this,SLOT(SeCenterY(const QString&)));
}

StructureElementSet::~StructureElementSet()
{
}

void StructureElementSet::setTable()
{
	
	m_DialogUi->tableWidget->clearContents();
	int r = m_DialogUi->tableWidget->rowCount();
	for (int i=0;i<r;i++)
	{
		m_DialogUi->tableWidget->removeRow(0);
	}

	int c = m_DialogUi->tableWidget->columnCount();
	for (int i=0;i<c;i++)
	{
		m_DialogUi->tableWidget->removeColumn(0);
	}
	for (int i=0;i<SeRows;i++)
	{
		m_DialogUi->tableWidget->insertRow(0);
	}
	for (int i=0;i<SeColumns;i++)
	{
		m_DialogUi->tableWidget->insertColumn(0);
	}


	int r1 = m_DialogUi->tableWidget->rowCount();
	int c1 = m_DialogUi->tableWidget->columnCount();

	for (int i=0;i!=m_DialogUi->tableWidget->rowCount();i++)
	{
		for (int j=0;j!=m_DialogUi->tableWidget->columnCount();j++)
		{
			QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(1));
			m_DialogUi->tableWidget->setItem(i,j,newItem);
		}
	}


	setCenter(r1/2,c1/2);

	m_dialog->update();
}

void StructureElementSet::clearTable()
{
	int r = m_DialogUi->tableWidget->rowCount();
	for (int i=0;i<=r;i++)
	{
		m_DialogUi->tableWidget->removeRow(0);
	}

	int c = m_DialogUi->tableWidget->columnCount();
	for (int i=0;i<=c;i++)
	{
		m_DialogUi->tableWidget->removeColumn(0);
	}

	SeColumns = 0;
	SeRows = 0;

	m_DialogUi->spinBoxRow->setValue(0);
	m_DialogUi->spinBoxColumn->setValue(0);
}

void StructureElementSet::setSE()
{
	m_se.clear();
	m_se.resize(SeRows);
	for (int i=0;i!=SeRows;i++)
	{
		m_se[i].resize(SeColumns,-1);
	}
//  	for (int i=0;i!=input_index.size();i++)
// 	{
// 		int r=input_index[i][0]; 
// 		int c=input_index[i][1];
// 		if(m_DialogUi->tableWidget->item(r,c)->text()=="")
// 			continue;
// 		m_se[r][c] = m_DialogUi->tableWidget->item(r,c)->text().toInt();
// 	}
	for (int i=0;i!=m_DialogUi->tableWidget->rowCount();i++)
	{
		for (int j=0;j!=m_DialogUi->tableWidget->columnCount();j++)
		{
			if(m_DialogUi->tableWidget->item(i,j)->text()=="")
			 	continue;
			m_se[i][j] = m_DialogUi->tableWidget->item(i,j)->text().toInt();
		}
	}
	
	//input_index.clear();

	SeCenterX = m_DialogUi->lineEdit->text().toInt()-1;
	SeCenterY = m_DialogUi->lineEdit_2->text().toInt()-1;
	emit sendSE(m_se,SeCenterX,SeCenterY);
}