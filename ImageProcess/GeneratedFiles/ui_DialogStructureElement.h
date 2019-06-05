/********************************************************************************
** Form generated from reading UI file 'DialogStructureElement.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTRUCTUREELEMENT_H
#define UI_DIALOGSTRUCTUREELEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSlider *verticalSlider;
    QSlider *horizontalSlider;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxRow;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBoxColumn;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnReset;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(416, 399);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSlider = new QSlider(Dialog);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(50);
        verticalSlider->setValue(3);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(true);
        verticalSlider->setInvertedControls(true);

        gridLayout->addWidget(verticalSlider, 0, 1, 1, 1);

        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(50);
        horizontalSlider->setValue(3);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        tableWidget = new QTableWidget(Dialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(30);
        tableWidget->horizontalHeader()->setMinimumSectionSize(21);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBoxRow = new QSpinBox(Dialog);
        spinBoxRow->setObjectName(QString::fromUtf8("spinBoxRow"));
        spinBoxRow->setMaximum(50);
        spinBoxRow->setValue(3);

        verticalLayout_2->addWidget(spinBoxRow);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        spinBoxColumn = new QSpinBox(Dialog);
        spinBoxColumn->setObjectName(QString::fromUtf8("spinBoxColumn"));
        spinBoxColumn->setMaximum(50);
        spinBoxColumn->setValue(3);

        verticalLayout_4->addWidget(spinBoxColumn);

        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btnReset = new QPushButton(Dialog);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        verticalLayout_5->addWidget(btnReset);

        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        verticalLayout_5->addWidget(okButton);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout_5->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout_5);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBoxColumn, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), spinBoxRow, SLOT(setValue(int)));
        QObject::connect(spinBoxColumn, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(spinBoxRow, SIGNAL(valueChanged(int)), verticalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Row", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Center X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Column", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Center Y", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QString());
        btnReset->setText(QApplication::translate("Dialog", "Reset", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTRUCTUREELEMENT_H
