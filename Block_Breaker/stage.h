#ifndef STAGE_H
#define STAGE_H
#include <QWidget>

extern int stage_num;

namespace Ui {
class Stage;
}

class Stage : public QWidget
{
    Q_OBJECT

public:
    explicit Stage(QWidget *parent = nullptr);
    ~Stage();
signals:
    void stageclosed();
private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
private:
    Ui::Stage *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // STAGE_H
