#ifndef BALL_H
#define BALL_H

#include "object.h"
#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRect>

class Ball : public Object
{
public:
    explicit Ball();
    ~Ball();

    void bounce(int dir, qreal posX, qreal posY, int w, int h);

private:
    int speed;
};

#endif // BALL_H
