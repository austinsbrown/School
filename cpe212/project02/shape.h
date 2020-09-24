#include "color.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape 
{
    public:
         8Shape();
        ~Shape();
         Shape(int red, int green, int blue);
        Color getColor() const; 
        Color* c;
        virtual double area() const;
        virtual double perimeter() const;      
};

#endif