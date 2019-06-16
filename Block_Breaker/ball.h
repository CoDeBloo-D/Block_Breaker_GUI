#ifndef BALL_H
#define BALL_H
#include <QGraphicsPixmapItem>
#include <QBasicTimer>

class Ball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int v;
    int h;
    int speed;
    QBasicTimer *t;
    QSize b_size;
    void check_Bound();
    void check_Collision();
    void timerEvent(QTimerEvent *event);

signals:
    void collision(QList<QGraphicsItem *>Items);
    void gameover();

public:
    Ball(const QPixmap &pixmap,const QSize &size, int s);
    ~Ball();
    void pause();
    void start();
    bool is_Moving();
};

#endif // BALL_H
