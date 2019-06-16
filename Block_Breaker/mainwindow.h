#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stage.h"
#include "difficulty.h"
#include "gamewindow.h"
#include "help.h"
#include <QMainWindow>

extern int stage_num;
extern int diff;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_stageButton_clicked();
    void on_difButton_clicked();
    void on_helpButton_clicked();
    void on_exitButton_clicked();
    void reshow();
    void xytimerUpDate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
