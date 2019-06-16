#include "mainwindow.h"
#include <QApplication>

int stage_num;
int diff;
int main(int argc, char *argv[])
{
    stage_num = 1;
    diff = 3;
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color:white;");
    w.setWindowTitle("Block Breaker");
    w.setWindowIcon(QIcon(":/src/ball.png"));
    w.show();

    return a.exec();
}
