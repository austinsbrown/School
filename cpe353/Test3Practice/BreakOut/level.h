#ifndef LEVEL_H
#define LEVEL_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QGraphicsView>
#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>

class Level : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();

    void loadLevel(int lvlx[], int lvly[], int sizeX, int sizeY);

protected:
    void keyPressEvent(QKeyEvent* ke);
    void mouseMoveEvent(QMouseEvent* me);

private:
    int brickCount;
    int liveCount;
    QGraphicsScene* scene;
    Ball* ball = nullptr;
    Brick* brick[255];
    Paddle* paddle = nullptr;

private slots:
    void collisionCheck();
};

#endif // LEVEL_H
