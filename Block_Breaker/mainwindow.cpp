#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QtCore>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(xytimerUpDate()));
    timer->start(1000);
    ui->lcdNumber->setDigitCount(28);
    ui->label_2->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->startButton->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->stageButton->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->difButton->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->helpButton->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->exitButton->setFont(QFont("Book Antiqua", 12, QFont::Light));
    ui->startButton->setStyleSheet("color: blue");
    ui->stageButton->setStyleSheet("color: blue");
    ui->difButton->setStyleSheet("color: blue");
    ui->helpButton->setStyleSheet("color: blue");
    ui->exitButton->setStyleSheet("color: blue");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::reshow()
{
    this->show();
    //std::cout << stage_num << std::endl;
    //std::cout << diff << std::endl;
}

void MainWindow::on_stageButton_clicked()
{
    this->hide();
    Stage *sw = new Stage;
    connect(sw,SIGNAL(stageclosed()),this,SLOT(reshow()));
    sw->setStyleSheet("background-color:white;");
    sw->setWindowTitle("Stage Select");
    sw->setWindowIcon(QIcon(":/src/ball.png"));
    sw->show();
}

void MainWindow::xytimerUpDate()
 {
    QDateTime time = QDateTime::currentDateTime();
    QString strTime = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->lcdNumber->display(strTime);
 }

void MainWindow::on_difButton_clicked()
{
    this->hide();
    Difficulty *dw = new Difficulty;
    connect(dw,SIGNAL(diffclosed()),this,SLOT(reshow()));
    dw->setStyleSheet("background-color:white;");
    dw->setWindowTitle("Difficulty");
    dw->setWindowIcon(QIcon(":/src/ball.png"));
    dw->show();
}

void MainWindow::on_startButton_clicked()
{
    this->hide();
    QGraphicsScene *s = new QGraphicsScene;
    s->setBackgroundBrush(QPixmap(":/src/background.png"));
    Gamewindow *gw = new Gamewindow(s);
    connect(gw,SIGNAL(gwclosed()),this,SLOT(reshow()));
    gw->setWindowTitle("BLOCK BREAKER");
    gw->setWindowIcon(QIcon(":/src/ball.png"));
    gw->show();
}

void MainWindow::on_helpButton_clicked()
{
    this->hide();
    Help *hw = new Help;
    connect(hw,SIGNAL(helpclosed()),this,SLOT(reshow()));
    hw->setStyleSheet("background-color:white;");
    hw->setWindowTitle("Help");
    hw->setWindowIcon(QIcon(":/src/ball.png"));
    hw->show();
}
