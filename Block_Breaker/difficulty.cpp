#include "difficulty.h"
#include "ui_difficulty.h"
#include <QMessageBox>
#include <QCloseEvent>

Difficulty::Difficulty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->lineEdit->setPlaceholderText("Input an int between 1~6(default 3)");
    ui->label->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->label_2->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->okButton->setFont(QFont("Book Antiqua", 10, QFont::Black));
    ui->cancelButton->setFont(QFont("Book Antiqua", 10, QFont::Black));
    QString t = "Current difficulty: " + QString::number(diff, 10);
    ui->label_2->setText(t);
}

Difficulty::~Difficulty()
{
    delete ui;
}

void Difficulty::on_okButton_clicked()
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
    diff = num;
    //->lineEdit->clear();
    emit diffclosed();
    close();
}

void Difficulty::on_cancelButton_clicked()
{
    emit diffclosed();
    close();
}

void Difficulty::closeEvent(QCloseEvent *event)
{
    emit diffclosed();
    event->accept();
}
