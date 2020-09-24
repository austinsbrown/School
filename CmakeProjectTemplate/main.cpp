#include <iostream>
#include "clock.h"

int main() 
{
    Clock c;
    c.SetTime(1, 34, 2, 4);
    c.PrintSMH();
    return 0;
}
