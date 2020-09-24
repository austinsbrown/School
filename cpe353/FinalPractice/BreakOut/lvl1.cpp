#include "lvl1.h"

Lvl1::Lvl1()
{
    int s = 55;       // Spacing between bricks
    int xCoord[] = {0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                    0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                    0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s};
    s = 25;
    int yCoord[] = {0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                    0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                    0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s};

    int test[30][30] = {{0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                        0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                        0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s},
                        {0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                        0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s,
                       0*s, 1*s, 2*s, 3*s, 4*s, 5*s, 6*s, 7*s, 8*s, 9*s}};
}

QPoint Lvl1::getCoords(int x, int y)
{
    int xPos = xCoord[x];
    int yPos = yCoord[y];
    QPoint p(xPos, yPos);
    return p;
}
