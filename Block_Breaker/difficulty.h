#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include <QWidget>

extern int diff;

namespace Ui {
class Difficulty;
}

class Difficulty : public QWidget
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = nullptr);
    ~Difficulty();
signals:
    void diffclosed();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Difficulty *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // DIFFICULTY_H
