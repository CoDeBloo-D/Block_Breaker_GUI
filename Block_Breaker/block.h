#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsPixmapItem>

class Block : public QGraphicsPixmapItem
{
private:
    int hp;
public:
    Block(const QPixmap &pixmap, int HP);
    int reduce_Hp();
};

#endif // BLOCK_H
