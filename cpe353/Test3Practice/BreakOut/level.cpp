#include "level.h"
#include "defs.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QList>
#include <QGraphicsScene>
#include <QVBoxLayout>

Level::Level(QWidget *parent) : QGraphicsView(parent)
{

    // Create and configure scene
    scene = new QGraphicsScene(-XMAX/2, -YMAX/2, XMAX, YMAX, this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setBackgroundBrush(Qt::black);
    this->setScene(scene);
    this->setMouseTracking(true);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Create and frame timer
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(collisionCheck()));
    timer->setInterval(1000/33);
    timer->start();

    // Create paddle
    paddle = new Paddle;
    paddle->setPos(0, 200);
    scene->addItem(paddle);
}

Level::~Level()
{
    delete this;
}

// Spawns ball
void Level::keyPressEvent(QKeyEvent* ke)
{
    if (ball == nullptr && ke && ke->key() == Qt::Key_Space)
    {
        ball = new Ball;
        ball->setPos(paddle->getPosX(), 195);
        scene->addItem(ball);
    }
}

// Handles Movement of Paddle
void Level::mouseMoveEvent(QMouseEvent* me)
{
    int xMove = me->x() - XMAX/2;
    int yMove = paddle->getPosY();
    if ((xMove - paddle->getWidth()/2 > -XMAX/2) && (xMove + paddle->getWidth()/2 < XMAX/2))
        paddle->setPos(xMove, yMove);
}

void Level::loadLevel(int lvlx[], int lvly[], int sizeX, int sizeY)
{
    // Create bricks
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            brick[i+j] = new Brick;
            brick[i+j]->setPos(lvlx[i], lvly[j]);
            scene->addItem(brick[i+j]);
        }
    }
}

// Handles Collisions Between Objects
void Level::collisionCheck()
{
    if (ball != nullptr)
    {
        qreal ballX = ball->getPosX();
        qreal ballY = ball->getPosY();
        qreal ballW = ball->getWidth();
        qreal ballH = ball->getHeight();

        // Ball-Wall Bounce
        if (ballX + ballW/2 >= XMAX/2 || ballX - ballW/2 <= -XMAX/2)
        {
            ball->bounce(1, 0, 0, 0, 0);
        }
        if (ballY - ballH/2 <= -YMAX/2)
        {
            ball->bounce(2, 0, 0, 0, 0);
        }
        if (ballY + ballH/2 >= YMAX/2)
        {
            scene->removeItem(ball);
            ball = nullptr;
        }
        else if (!ball->collidingItems().isEmpty())
        {
            // Ball-Paddle Bounce
            if (paddle->collidesWithItem(ball))
            {
                ball->bounce(4, paddle->getPosX(), paddle->getPosY(), paddle->getWidth(), paddle->getHeight());
            }
            else
            {
                QList<QGraphicsItem *> list = ball->collidingItems();   // Gets list of items colliding with the ball
                foreach(QGraphicsItem* i, list)                         // For every item colliding with the ball
                {
                    Brick* item = dynamic_cast<Brick*>(i);
                    if (item)
                    {
                        scene->removeItem(item);
                        ball->bounce(3, item->getPosX(), item->getPosY(), item->getWidth(), item->getHeight());
                    }
                }
            }
        }
    }
}
