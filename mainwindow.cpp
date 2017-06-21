#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void asd()
{
    //SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

   // qDebug()<<"123";


}

StandardWindowTimer StdWinTmer(10);
void MainWindow::on_btnWin32Timer_clicked()
{
    StdWinTmer.DoSomething =  asd;
    StdWinTmer.SetIntervalms(10);
    StdWinTmer.Start();
}

void MainWindow::on_btnWin32TimerStop_clicked()
{
    StdWinTmer.Kill();
}


MultMediaTimer MMtimer(10);
void MainWindow::on_btnMultMediaTimer_clicked()
{
    MMtimer.DoSomething =  asd;
    MMtimer.SetIntervalms(10);
    MMtimer.Start();
}

void MainWindow::on_btnMultMediaTimerStop_clicked()
{
    MMtimer.Kill();
}
