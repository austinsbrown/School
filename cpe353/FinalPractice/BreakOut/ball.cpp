#include "ball.h"
#include "defs.h"
#include <qdebug.h>
#include <cmath>

Ball::Ball()
{
    color = Qt::white;
    speed = 7;         // WARNING!!  May cause clipping if set too high (i.e. >10)
    x = 0.0;
    y = 0.0;
    w = 10.0;
    h = 10.0;
    dx = 0.00;
    dy = -speed;
}

Ball::~Ball()
{
    delete this;
}

void Ball::bounce(int dir, qreal posX, qreal posY, int w, int h)
{
    qreal distX = (this->x - posX) / w;
    qreal distY = (this->y - posY) / h;

    switch(dir)
    {
    case 1:               // Horizontal bounce
        dx = -dx;
        break;
    case 2:               // Vertical bounce
        dy = -dy;
        break;
    case 3:               // Brick bounce
        if (std::abs(distX) > std::abs(distY))
        {
            dx = -dx;
        }
        else
        {
            dy = -dy;
        }
        break;
    case 4:               // Paddle bounce
        dx += distX*speed;
        if (dx > speed-2)
            dx = speed-2;
        else if (dx < -speed)
            dx = -(speed-2);
        dy = -sqrt(speed*speed - dx*dx);
        break;
    }
}
