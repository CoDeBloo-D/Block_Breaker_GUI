#include "board.h"

Board::Board(const QPixmap &pixmap) : QGraphicsPixmapItem(pixmap)
{
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    step = 20;
}

void Board::move_L()
{
    moveBy(-step, 0);
}

void Board::move_R()
{
    moveBy(step, 0);
}
