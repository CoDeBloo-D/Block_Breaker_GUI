#include "gamewindow.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QApplication>
#include <QCloseEvent>
#include <QDateTime>

Gamewindow::Gamewindow(QGraphicsScene *s) : QGraphicsView(s)
{
    setMinimumSize(600,450);
    setMaximumSize(600,450);
    s->setSceneRect(0,0,598,448);
    scene = s;
    connect(this, SIGNAL(gamewin()), this, SLOT(game_Win()));
    start_Game();
}

Gamewindow::~Gamewindow()
{
    delete ball;
    delete board;
    delete scene;
}

void Gamewindow::gen_Blocks()
{
    QPixmap *Pixmap = new QPixmap(":/src/block1.png");  //same size
    const int &w = Pixmap->width();
    const int &h = Pixmap->height();
    const int XMAX = width() / w;
    const int YMAX = height() / (h * 2);
    block_left = 0;

    switch (stage_num)
    {
        case 1:
        {
            for(int x = 0; x < XMAX; x = x + 2)
            {
                for(int y = 0; y < YMAX; y = y + 3)
                {
                    Block *b;
                    if(y == 0 || y == 3)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else if(y == 6 || y == 9)
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    else
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        case 2:
        {
            for(int x = 0; x < XMAX; x++)
            {
                for(int y = 0; y < 17; y = y + 2)
                {
                    Block *b;
                    if(y == 0)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else if(y == 2)
                    {
                        if(x % 2 != 0)
                            continue;
                        else
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                    }
                    else if(y == 4)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else if(y == 6)
                    {
                        if(x % 2 != 0)
                            continue;
                        else
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                    }
                    else if(y == 8)
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    else if(y == 10)
                    {
                        if(x % 2 != 0)
                            continue;
                        else
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                    }
                    else if(y == 12)
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    else if(y == 14)
                    {
                        if(x % 2 != 0)
                            continue;
                        else
                            b = new Block(QPixmap(":/src/block3.png"), 3);
                    }
                    else
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        case 3:
        {
            for(int y = 0; y < 8; y++)
            {
                for(int x = 0; x < XMAX; x++)
                {
                    if(abs(x - 7) > y)
                        continue;
                    Block *b;
                    if(y <= 4)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            for(int y = 15; y >= 8; y--)
            {
                for(int x = 0; x < XMAX; x++)
                {
                    if(abs(x - 7) > y - 8)
                        continue;
                    Block *b;
                    if(y <= 12)
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    else
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    scene->addItem(b);
                    b->setPos(x * w, (23 - y) * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        case 4:
        {
            for(int y = 0; y < YMAX - 1; y++)
            {
                for(int x = 0; x < XMAX; x++)
                {
                    Block *b;
                    if(y <= 6)
                    {
                        if(x <= 4)
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                        else if(x <= 9)
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                        else
                            b = new Block(QPixmap(":/src/block3.png"), 3);
                    }
                    else if(y <= 13)
                    {
                        if(x <= 4)
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                        else if(x <= 9)
                            b = new Block(QPixmap(":/src/block3.png"), 3);
                        else
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                    }
                    else
                    {
                        if(x <= 4)
                            b = new Block(QPixmap(":/src/block3.png"), 3);
                        else if(x <= 9)
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                        else
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                    }
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        case 5:
        {
            for(int y = 0; y < 15; y++)
            {
                for(int x = 0; x < XMAX; x++)
                {
                    if(XMAX - x - 1 > y)
                        continue;
                    Block *b;
                    if(y <= 4)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else if(y <= 9)
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    else
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            for(int y = 15; y < 30; y++)
            {
                for(int x = 0; x < XMAX; x++)
                {
                    if(XMAX - x - 1 < y - 15)
                        continue;
                    Block *b;
                    if(y <= 19)
                        b = new Block(QPixmap(":/src/block1.png"), 1);
                    else if(y <= 24)
                        b = new Block(QPixmap(":/src/block2.png"), 2);
                    else
                        b = new Block(QPixmap(":/src/block3.png"), 3);
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        case 6:
        {
            srand((unsigned int)time(nullptr));
            for(int x = 0; x < XMAX; x++)
            {
                for(int y = 0; y < YMAX; y++)
                {
                    int sw1 = rand() % 2;
                    if(sw1 == 0)
                        continue;
                    int sw2 = rand() % 3;
                    Block *b;
                    switch(sw2)
                    {
                        case 0:
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                            break;
                        case 1:
                            b = new Block(QPixmap(":/src/block2.png"), 2);
                            break;
                        case 2:
                            b = new Block(QPixmap(":/src/block3.png"), 3);
                            break;
                        default:
                            b = new Block(QPixmap(":/src/block1.png"), 1);
                            break;
                    }
                    scene->addItem(b);
                    b->setPos(x * w, y * h);
                    b->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
                    block_left++;
                }
            }
            break;
        }
        default:
        break;
    }

}

void Gamewindow::start_Game()
{ 
    gen_Blocks();
    ball = new Ball(QPixmap(":/src/ball.png"), size(), diff);
    connect(ball, &Ball::collision, this, &Gamewindow::collision_Process);
    connect(ball, &Ball::gameover, this, &Gamewindow::game_Lose);
    board = new Board(QPixmap(":/src/board_b.png"));

    scene->addItem(ball);
    scene->addItem(board);

    board->setPos((width() - board->pixmap().width()) / 2, height() - board->pixmap().height());
    ball->setPos((width() - ball->pixmap().width()) / 2, board->y() - ball->pixmap().height());
}


void Gamewindow::clean_Scene()
{
    ball->pause();
    QList<QGraphicsItem *>Items = scene->items();
    foreach(QGraphicsItem *Item, Items)
        delete Item;
}

void Gamewindow::collision_Process(QList<QGraphicsItem *>Items)
{
    foreach(QGraphicsItem *Item, Items)
    {
        if(Item == board)
            continue;
        else
        {
            Block *b = (Block *)Item;
            int res = b->reduce_Hp();
            if(res == 2)
            {
                Block *q = new Block(QPixmap(":/src/block2.png"), 2);
                q->setPos(b->x(),b->y());
                scene->removeItem(b);
                //ball->move_Away();
                scene->addItem(q);
                q->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
            }
            else if(res == 1)
            {
                Block *q = new Block(QPixmap(":/src/block1.png"), 1);
                q->setPos(b->x(),b->y());
                scene->removeItem(b);
                //ball->move_Away();
                scene->addItem(q);
                q->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
            }
            else if(res == 0)
            {
                scene->removeItem(b);
                block_left--;
                if(block_left == 0)
                    emit gamewin();
            }
        }
    }
}

void Gamewindow::game_Lose()
{
    QMessageBox::information(this,QString("GAMEOVER"),QString("Better Luck Next Game!"));
    clean_Scene();
    close();
    return;
}

void Gamewindow::game_Win()
{
    QMessageBox::information(this,QString("WIN"),QString("Congratulations!"));
    clean_Scene();
    close();
    return;
}

void Gamewindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
            if(board->pos().x()<0 || !ball->is_Moving())
                return;
            board->move_L();
            break;
        case Qt::Key_Right:
            if(board->pos().x()+board->pixmap().width() > width() || !ball->is_Moving())
                return;
            board->move_R();
            break;
        case Qt::Key_Space:
            if(!ball->is_Moving())
                ball->start();
            else
                ball->pause();
            break;
        case Qt::Key_Escape:
            clean_Scene();
            start_Game();
            break;
        default:
            break;
    }
}

void Gamewindow::closeEvent(QCloseEvent *event)
{
    emit gwclosed();
    event->accept();
}
