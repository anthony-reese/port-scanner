/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QLineEdit *ipLineEdit;
    QSpinBox *startPortSpinBox;
    QSpinBox *endPortSpinBox;
    QTextEdit *resultTextEdit;
    QProgressBar *progressBar;
    QPushButton *scanButton;
    QLabel *ipAddress;
    QLabel *startPort;
    QLabel *endPort;
    QLabel *results;
    QPushButton *clearButton;
    QPushButton *exportButton;
    QCheckBox *darkModeCheckBox;
    QLabel *scanStatusLabel;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuPort_Scanner;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(381, 594);
        QIcon icon;
        icon.addFile(QString::fromUtf8("shield.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(24, 24));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ipLineEdit = new QLineEdit(centralwidget);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setGeometry(QRect(110, 27, 141, 21));
        QFont font;
        font.setPointSize(10);
        ipLineEdit->setFont(font);
        startPortSpinBox = new QSpinBox(centralwidget);
        startPortSpinBox->setObjectName("startPortSpinBox");
        startPortSpinBox->setGeometry(QRect(110, 65, 101, 23));
        startPortSpinBox->setFont(font);
        startPortSpinBox->setMinimum(1);
        startPortSpinBox->setMaximum(65535);
        endPortSpinBox = new QSpinBox(centralwidget);
        endPortSpinBox->setObjectName("endPortSpinBox");
        endPortSpinBox->setGeometry(QRect(110, 109, 101, 23));
        endPortSpinBox->setFont(font);
        endPortSpinBox->setMinimum(1);
        endPortSpinBox->setMaximum(65535);
        resultTextEdit = new QTextEdit(centralwidget);
        resultTextEdit->setObjectName("resultTextEdit");
        resultTextEdit->setGeometry(QRect(20, 299, 321, 201));
        resultTextEdit->setFont(font);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 209, 241, 23));
        progressBar->setFont(font);
        progressBar->setValue(0);
        scanButton = new QPushButton(centralwidget);
        scanButton->setObjectName("scanButton");
        scanButton->setEnabled(true);
        scanButton->setGeometry(QRect(140, 159, 75, 24));
        scanButton->setFont(font);
        ipAddress = new QLabel(centralwidget);
        ipAddress->setObjectName("ipAddress");
        ipAddress->setGeometry(QRect(22, 29, 71, 16));
        ipAddress->setFont(font);
        startPort = new QLabel(centralwidget);
        startPort->setObjectName("startPort");
        startPort->setGeometry(QRect(22, 69, 71, 16));
        startPort->setFont(font);
        endPort = new QLabel(centralwidget);
        endPort->setObjectName("endPort");
        endPort->setGeometry(QRect(22, 112, 61, 16));
        endPort->setFont(font);
        results = new QLabel(centralwidget);
        results->setObjectName("results");
        results->setGeometry(QRect(22, 276, 49, 16));
        results->setFont(font);
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(20, 159, 75, 24));
        clearButton->setFont(font);
        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName("exportButton");
        exportButton->setEnabled(true);
        exportButton->setGeometry(QRect(265, 272, 75, 24));
        exportButton->setFont(font);
        darkModeCheckBox = new QCheckBox(centralwidget);
        darkModeCheckBox->setObjectName("darkModeCheckBox");
        darkModeCheckBox->setGeometry(QRect(274, 0, 91, 20));
        darkModeCheckBox->setFont(font);
        scanStatusLabel = new QLabel(centralwidget);
        scanStatusLabel->setObjectName("scanStatusLabel");
        scanStatusLabel->setGeometry(QRect(20, 510, 171, 20));
        scanStatusLabel->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 381, 33));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuPort_Scanner = new QMenu(menuBar);
        menuPort_Scanner->setObjectName("menuPort_Scanner");
        MainWindow->setMenuBar(menuBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(ipLineEdit, startPortSpinBox);
        QWidget::setTabOrder(startPortSpinBox, endPortSpinBox);
        QWidget::setTabOrder(endPortSpinBox, clearButton);
        QWidget::setTabOrder(clearButton, scanButton);
        QWidget::setTabOrder(scanButton, resultTextEdit);

        menuBar->addAction(menuPort_Scanner->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuPort_Scanner->addAction(actionExit);

        retranslateUi(MainWindow);

        scanButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Port Scanner", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        scanButton->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        ipAddress->setText(QCoreApplication::translate("MainWindow", "IP Address:", nullptr));
        startPort->setText(QCoreApplication::translate("MainWindow", "Start Port:", nullptr));
        endPort->setText(QCoreApplication::translate("MainWindow", "End Port:", nullptr));
        results->setText(QCoreApplication::translate("MainWindow", "Results:", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        darkModeCheckBox->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        scanStatusLabel->setText(QCoreApplication::translate("MainWindow", "Ready.", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuPort_Scanner->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
