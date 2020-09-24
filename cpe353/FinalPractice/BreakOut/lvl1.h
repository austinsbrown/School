#ifndef LVL1_H
#define LVL1_H

#include "level.h"

class Lvl1
{
public:
    Lvl1();
    QPoint getCoords(int x, int y);

private:
    int xCoord[30];
    int yCoord[30];
};

#endif // LVL1_H
