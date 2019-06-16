#include "help.h"
#include "ui_help.h"
#include <QCloseEvent>

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->label->setFont(QFont("Book Antiqua", 12, QFont::Black));
    ui->label->setText(QString("Help Info\n"
                               "Control Board: Key Left and Right\n"
                               "Start and Stop: Key Space\n"
                               "New Game: Key Escape\n"
                               "Stage num is relative to the number of blocks.\n"
                               "(Stage 6 is a random stage, all blocks generate randomly)\n"
                               "Difficulty num is relative to the speed of ball.\n"));
    ui->retButton->setFont(QFont("Book Antiqua", 10, QFont::Black));
}

Help::~Help()
{
    delete ui;
}

void Help::on_retButton_clicked()
{
    emit helpclosed();
    close();
}

void Help::closeEvent(QCloseEvent *event)
{
    emit helpclosed();
    event->accept();
}


