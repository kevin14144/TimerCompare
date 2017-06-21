/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnWin32Timer;
    QPushButton *btnWin32TimerStop;
    QPushButton *btnMultMediaTimer;
    QPushButton *btnMultMediaTimerStop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnWin32Timer = new QPushButton(centralWidget);
        btnWin32Timer->setObjectName(QStringLiteral("btnWin32Timer"));
        btnWin32Timer->setGeometry(QRect(20, 30, 80, 20));
        btnWin32TimerStop = new QPushButton(centralWidget);
        btnWin32TimerStop->setObjectName(QStringLiteral("btnWin32TimerStop"));
        btnWin32TimerStop->setGeometry(QRect(20, 70, 80, 20));
        btnMultMediaTimer = new QPushButton(centralWidget);
        btnMultMediaTimer->setObjectName(QStringLiteral("btnMultMediaTimer"));
        btnMultMediaTimer->setGeometry(QRect(120, 30, 101, 20));
        btnMultMediaTimerStop = new QPushButton(centralWidget);
        btnMultMediaTimerStop->setObjectName(QStringLiteral("btnMultMediaTimerStop"));
        btnMultMediaTimerStop->setGeometry(QRect(120, 70, 101, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnWin32Timer->setText(QApplication::translate("MainWindow", "Win32Timer Start", Q_NULLPTR));
        btnWin32TimerStop->setText(QApplication::translate("MainWindow", "Win32Timer Stop", Q_NULLPTR));
        btnMultMediaTimer->setText(QApplication::translate("MainWindow", "MultMediaTimer Start", Q_NULLPTR));
        btnMultMediaTimerStop->setText(QApplication::translate("MainWindow", "MultMediaTimer Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
