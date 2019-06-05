/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <histogramwidget.h>
#include <imagewidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionUndo;
    QAction *actionClearOperation;
    QAction *actionRe_do;
    QAction *actionToolBox;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    ImageWidget *widget_1;
    ImageWidget *widget_2;
    QSplitter *splitter_2;
    HistogramWidget *widget_hist;
    ImageWidget *widget_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *btnEntBi;
    QLabel *label_3;
    QPushButton *btnOtsuBi;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *smallhist;
    QLabel *label_7;
    QSlider *slider;
    QLCDNumber *lcdNumber;
    QLabel *label_8;
    QWidget *tab_2;
    QPushButton *btnSobel;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btnClear;
    QLabel *label_4;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *btnDilation;
    QPushButton *btnClose;
    QPushButton *btnOpen;
    QPushButton *btnErosion;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEdgeDect;
    QPushButton *btnGradient;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSketeton;
    QRadioButton *radioButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnRescon;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnDisTrans;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_2;
    QPushButton *btnSetSE;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(976, 723);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainWindow/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MainWindow/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionUndo = new QAction(MainWindowClass);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MainWindow/editundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon2);
        actionClearOperation = new QAction(MainWindowClass);
        actionClearOperation->setObjectName(QString::fromUtf8("actionClearOperation"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MainWindow/clearhistory.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearOperation->setIcon(icon3);
        actionRe_do = new QAction(MainWindowClass);
        actionRe_do->setObjectName(QString::fromUtf8("actionRe_do"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MainWindow/editredo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRe_do->setIcon(icon4);
        actionToolBox = new QAction(MainWindowClass);
        actionToolBox->setObjectName(QString::fromUtf8("actionToolBox"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_1 = new ImageWidget(splitter);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setContextMenuPolicy(Qt::NoContextMenu);
        widget_1->setAutoFillBackground(false);
        widget_1->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        splitter->addWidget(widget_1);
        widget_2 = new ImageWidget(splitter);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setAutoFillBackground(false);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        splitter->addWidget(widget_2);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widget_hist = new HistogramWidget(splitter_2);
        widget_hist->setObjectName(QString::fromUtf8("widget_hist"));
        widget_hist->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        splitter_2->addWidget(widget_hist);
        widget_3 = new ImageWidget(splitter_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setAutoFillBackground(false);
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        splitter_2->addWidget(widget_3);
        splitter_3->addWidget(splitter_2);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 976, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindowClass);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(171, 604));
        tabWidget->setTabPosition(QTabWidget::South);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        btnEntBi = new QPushButton(tab_1);
        btnEntBi->setObjectName(QString::fromUtf8("btnEntBi"));
        btnEntBi->setGeometry(QRect(10, 100, 122, 41));
        label_3 = new QLabel(tab_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 10, 72, 16));
        label_3->setAlignment(Qt::AlignCenter);
        btnOtsuBi = new QPushButton(tab_1);
        btnOtsuBi->setObjectName(QString::fromUtf8("btnOtsuBi"));
        btnOtsuBi->setGeometry(QRect(10, 50, 121, 41));
        groupBox_7 = new QGroupBox(tab_1);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 238, 171, 171));
        verticalLayout_5 = new QVBoxLayout(groupBox_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        smallhist = new QLabel(groupBox_7);
        smallhist->setObjectName(QString::fromUtf8("smallhist"));

        verticalLayout_5->addWidget(smallhist);

        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/MainWindow/bar.bmp")));

        verticalLayout_5->addWidget(label_7);

        slider = new QSlider(groupBox_7);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMaximum(255);
        slider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(slider);

        verticalLayout_5->setStretch(0, 1);
        lcdNumber = new QLCDNumber(tab_1);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(90, 470, 71, 31));
        label_8 = new QLabel(tab_1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 480, 81, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Aharoni\";"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        btnSobel = new QPushButton(tab_2);
        btnSobel->setObjectName(QString::fromUtf8("btnSobel"));
        btnSobel->setGeometry(QRect(0, 460, 75, 23));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 270, 161, 161));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(10, 80, 131, 22));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 91, 16));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 250, 131, 16));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 130, 131, 91));
        label_6->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_6->setWordWrap(true);
        btnClear = new QPushButton(tab_2);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(80, 460, 75, 23));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 10, 101, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 20, 161, 81));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btnDilation = new QPushButton(groupBox);
        btnDilation->setObjectName(QString::fromUtf8("btnDilation"));

        gridLayout_4->addWidget(btnDilation, 0, 0, 1, 1);

        btnClose = new QPushButton(groupBox);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout_4->addWidget(btnClose, 2, 2, 1, 1);

        btnOpen = new QPushButton(groupBox);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

        gridLayout_4->addWidget(btnOpen, 2, 0, 1, 1);

        btnErosion = new QPushButton(groupBox);
        btnErosion->setObjectName(QString::fromUtf8("btnErosion"));

        gridLayout_4->addWidget(btnErosion, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 100, 171, 51));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnEdgeDect = new QPushButton(groupBox_2);
        btnEdgeDect->setObjectName(QString::fromUtf8("btnEdgeDect"));

        horizontalLayout->addWidget(btnEdgeDect);

        btnGradient = new QPushButton(groupBox_2);
        btnGradient->setObjectName(QString::fromUtf8("btnGradient"));

        horizontalLayout->addWidget(btnGradient);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 150, 161, 81));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSketeton = new QPushButton(groupBox_3);
        btnSketeton->setObjectName(QString::fromUtf8("btnSketeton"));

        verticalLayout->addWidget(btnSketeton);

        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 310, 161, 77));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnRescon = new QPushButton(groupBox_4);
        btnRescon->setObjectName(QString::fromUtf8("btnRescon"));

        verticalLayout_3->addWidget(btnRescon);

        radioButton_3 = new QRadioButton(groupBox_4);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 230, 161, 77));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnDisTrans = new QPushButton(groupBox_5);
        btnDisTrans->setObjectName(QString::fromUtf8("btnDisTrans"));

        verticalLayout_2->addWidget(btnDisTrans);

        radioButton_2 = new QRadioButton(groupBox_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 400, 161, 191));
        verticalLayout_4 = new QVBoxLayout(groupBox_6);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plainTextEdit_2 = new QPlainTextEdit(groupBox_6);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_2->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit_2);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        btnSetSE = new QPushButton(groupBox_6);
        btnSetSE->setObjectName(QString::fromUtf8("btnSetSE"));

        verticalLayout_4->addWidget(btnSetSE);

        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRe_do);
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionToolBox);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRe_do);
        mainToolBar->addAction(actionUndo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClearOperation);

        retranslateUi(MainWindowClass);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindowClass, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindowClass, SLOT(loadImage()));
        QObject::connect(btnOtsuBi, SIGNAL(clicked()), MainWindowClass, SLOT(otsuBinary()));
        QObject::connect(btnEntBi, SIGNAL(clicked()), MainWindowClass, SLOT(entropyBinary()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), MainWindowClass, SLOT(SetProjectView(int)));
        QObject::connect(btnSobel, SIGNAL(clicked()), MainWindowClass, SLOT(cusconv()));
        QObject::connect(comboBox, SIGNAL(activated(int)), MainWindowClass, SLOT(conv(int)));
        QObject::connect(btnClear, SIGNAL(clicked()), MainWindowClass, SLOT(clearOperations()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainWindowClass, SLOT(saveImage()));
        QObject::connect(actionUndo, SIGNAL(triggered()), MainWindowClass, SLOT(undo()));
        QObject::connect(btnErosion, SIGNAL(clicked()), MainWindowClass, SLOT(erosion()));
        QObject::connect(btnDilation, SIGNAL(clicked()), MainWindowClass, SLOT(dilation()));
        QObject::connect(actionClearOperation, SIGNAL(triggered()), MainWindowClass, SLOT(clearOperations()));
        QObject::connect(actionRe_do, SIGNAL(triggered()), MainWindowClass, SLOT(redo()));
        QObject::connect(btnOpen, SIGNAL(clicked()), MainWindowClass, SLOT(open()));
        QObject::connect(btnClose, SIGNAL(clicked()), MainWindowClass, SLOT(morph_close()));
        QObject::connect(btnDisTrans, SIGNAL(clicked()), MainWindowClass, SLOT(distanceTransform()));
        QObject::connect(btnSketeton, SIGNAL(clicked()), MainWindowClass, SLOT(getSkeleton()));
        QObject::connect(btnEdgeDect, SIGNAL(clicked()), MainWindowClass, SLOT(edgeDect()));
        QObject::connect(btnGradient, SIGNAL(clicked()), MainWindowClass, SLOT(gradient()));
        QObject::connect(btnRescon, SIGNAL(clicked()), MainWindowClass, SLOT(grayScaleReconstruction()));
        QObject::connect(actionToolBox, SIGNAL(triggered()), dockWidget, SLOT(show()));
        QObject::connect(slider, SIGNAL(valueChanged(int)), MainWindowClass, SLOT(binarization(int)));
        QObject::connect(slider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        tabWidget->setCurrentIndex(0);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Image Process Hw", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindowClass", "Save the Image in Right Bottom Window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindowClass", "Save As", 0, QApplication::UnicodeUTF8));
        actionSave_As->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+F4", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("MainWindowClass", "F1", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindowClass", "Un-do", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionClearOperation->setText(QApplication::translate("MainWindowClass", "Clear All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionClearOperation->setToolTip(QApplication::translate("MainWindowClass", "clear all operation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRe_do->setText(QApplication::translate("MainWindowClass", "Re-do", 0, QApplication::UnicodeUTF8));
        actionToolBox->setText(QApplication::translate("MainWindowClass", "ToolBox", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        widget_1->setToolTip(QApplication::translate("MainWindowClass", "Original Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        widget_2->setToolTip(QApplication::translate("MainWindowClass", "Gray Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        widget_hist->setToolTip(QApplication::translate("MainWindowClass", "Histogram", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        widget_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0, QApplication::UnicodeUTF8));
        btnEntBi->setText(QApplication::translate("MainWindowClass", "Binarization Entopy", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Binarization", 0, QApplication::UnicodeUTF8));
        btnOtsuBi->setText(QApplication::translate("MainWindowClass", "Binarization Otsu", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        smallhist->setText(QString());
        label_7->setText(QString());
        label_8->setText(QApplication::translate("MainWindowClass", "threshold:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindowClass", "Pro 1 ", 0, QApplication::UnicodeUTF8));
        btnSobel->setText(QApplication::translate("MainWindowClass", "Ok", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Sobel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Prewitt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Mean Filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Median Filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Gaussian Filter", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindowClass", "Select Filter", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "Cunstom Kernel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowClass", "No filter you want? That's OK. Input the filter you want below. Just make sure there's no wrong input.", 0, QApplication::UnicodeUTF8));
        btnClear->setText(QApplication::translate("MainWindowClass", "Clear", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Convolution", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Pro 2", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Basic Morphology", 0, QApplication::UnicodeUTF8));
        btnDilation->setText(QApplication::translate("MainWindowClass", "Dilation", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("MainWindowClass", "Close", 0, QApplication::UnicodeUTF8));
        btnOpen->setText(QApplication::translate("MainWindowClass", "Open", 0, QApplication::UnicodeUTF8));
        btnErosion->setText(QApplication::translate("MainWindowClass", "Erosion", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        btnEdgeDect->setText(QApplication::translate("MainWindowClass", "EdgeDection", 0, QApplication::UnicodeUTF8));
        btnGradient->setText(QApplication::translate("MainWindowClass", "Gradient", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindowClass", "Skeleton", 0, QApplication::UnicodeUTF8));
        btnSketeton->setText(QApplication::translate("MainWindowClass", "Get Skeleton", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindowClass", "Step by Step", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindowClass", "Gray Scale Rescontruction", 0, QApplication::UnicodeUTF8));
        btnRescon->setText(QApplication::translate("MainWindowClass", "Resconstruction", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindowClass", "Step by Step", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindowClass", "Distance Transform", 0, QApplication::UnicodeUTF8));
        btnDisTrans->setText(QApplication::translate("MainWindowClass", "Distance Transform", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindowClass", "Step by Step", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindowClass", "Structure Element", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        btnSetSE->setText(QApplication::translate("MainWindowClass", "Custom", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindowClass", "Pro 3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
