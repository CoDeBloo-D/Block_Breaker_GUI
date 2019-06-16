#include "ball.h"
#include <QTimerEvent>

Ball::Ball(const QPixmap &pixmap,const QSize &size, int s):QGraphicsPixmapItem(pixmap), b_size(size)
{
   srand((unsigned int)time(nullptr));
   int sw = rand() % 2;
   if(sw == 0)
       v = 1;
   else
       v = -1;
   h = -1;
   speed = 12 - s;   //is relative to diff
   t = new QBasicTimer;
   setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
}

Ball::~Ball()
{

}

void Ball::start()
{
    t->start(speed, this);
}

void Ball::pause()
{
    t->stop();
}

bool Ball::is_Moving()
{
    return t->isActive();
}

void Ball::check_Collision()
{
    if(collidingItems().count() == 0)
        return;

    const QPointF &Pos = collidingItems().at(0)->pos();
    const QRectF &Rect = collidingItems().at(0)->boundingRect();

    if((int)pos().y() + 1 == (int)Pos.y() + (int)Rect.height() || (int)pos().y() + (int)pixmap().height() - 1 == (int)Pos.y())
        h = -h;
    else if((int)pos().x() + (int)pixmap().width() - 1 == (int)Pos.x() || (int)pos().x() + 1 == (int)Pos.x() + (int)Rect.width())
        v = -v;

    emit collision(collidingItems());
}

void Ball::check_Bound()
{
    if(pos().y() <= 0)
        h = -h;
    else if(pos().x() <= 0)
        v = -v;
    else if(pos().x() + pixmap().width() >= b_size.width())
        v = -v;
    else if(pos().y() >= b_size.height() - 15)
    {
        //pause();
        emit gameover();
    }
}

void Ball::timerEvent(QTimerEvent *event)
{
    if(t->timerId() == event->timerId())
    {
        check_Bound();
        moveBy(v, h);   
        check_Collision();
    }
}
