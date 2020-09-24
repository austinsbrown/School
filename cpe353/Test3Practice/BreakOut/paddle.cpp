#include "paddle.h"
#include "defs.h"
#include <QKeyEvent>

Paddle::Paddle()
{
    color = Qt::white;
    x = 0.0;
    y = 0.0;
    w = 100.0;
    h = 10.0;
    dx = 0.00;
    dy = 0.00;
}
