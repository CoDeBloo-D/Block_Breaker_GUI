#include "block.h"

Block::Block(const QPixmap &pixmap, int HP):QGraphicsPixmapItem(pixmap),hp(HP)
{
}

int Block::reduce_Hp()
{
    if(hp == 0)
        return -1;
    else {
        hp--;
        return hp;
    }
}
