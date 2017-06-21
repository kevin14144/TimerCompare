#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdebug.h>

#include "standardwindowtimer.h"
 #include "multmediatimer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnWin32Timer_clicked();
    void on_btnWin32TimerStop_clicked();
    void on_btnMultMediaTimer_clicked();
    void on_btnMultMediaTimerStop_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
