#ifndef HELP_H
#define HELP_H
#include <QWidget>

namespace Ui {
class Help;
}

class Help : public QWidget
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

signals:
    void helpclosed();

private slots:
    void on_retButton_clicked();

private:
    Ui::Help *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // HELP_H
