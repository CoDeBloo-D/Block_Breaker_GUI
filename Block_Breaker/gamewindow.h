#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QGraphicsView>
#include "ball.h"
#include "board.h"
#include "block.h"

extern int stage_num;
extern int diff;

class Gamewindow : public QGraphicsView
{
    Q_OBJECT
private:
    Ball *ball;
    Board *board;
    QGraphicsScene *scene;
    int block_left;
    void gen_Blocks();
    void start_Game();
    void clean_Scene();
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);
public:
    Gamewindow(QGraphicsScene *s);
    ~Gamewindow();
private slots:
    void collision_Process(QList<QGraphicsItem *>Item);
    void game_Lose();
    void game_Win();
signals:
    void gwclosed();
    void gamewin();

};



#endif // GAMEWINDOW_H
