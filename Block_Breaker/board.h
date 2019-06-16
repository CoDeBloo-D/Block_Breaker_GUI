#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsPixmapItem>

class Board : public QGraphicsPixmapItem
{
private:
    int step;
public:
    Board(const QPixmap &pixmap);
    void move_L();
    void move_R();
};

#endif // BOARD_H
