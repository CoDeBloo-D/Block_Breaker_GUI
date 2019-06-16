#include "stage.h"
#include "ui_stage.h"
#include <QMessageBox>
#include <QCloseEvent>

Stage::Stage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stage)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->lineEdit->setPlaceholderText("Input an int between 1~6(default 1)");
    ui->label->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->label_2->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->okButton->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->cancelButton->setFont(QFont("Book Antiqua", 10, QFont::Black));
    QString t = "Current stage num: " + QString::number(stage_num, 10);
    ui->label_2->setText(t);
}

Stage::~Stage()
{
    delete ui;
}

void Stage::on_okButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
         QMessageBox::information(this,QString("Error"),QString("No input!"));
         return;
    }
    int num = ui->lineEdit->text().toInt();
    if(num < 1 || num > 6)
    {
         QMessageBox::information(this,QString("Error"),QString("Overflow!"));
         return;
    }
    stage_num = num;
    //->lineEdit->clear();
    emit stageclosed();
    close();
}

void Stage::on_cancelButton_clicked()
{
    //ui->lineEdit->clear();
    emit stageclosed();
    close();
}

void Stage::closeEvent(QCloseEvent *event)
{
    emit stageclosed();
    event->accept();
}
