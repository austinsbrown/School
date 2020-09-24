//
// shape.cpp
//
// Shape class models a generic geometric shape with color
// defined by a private Color object attribute c
//
// Use the contents of this file to reverse engineer the contents of shape.h
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
//

#include "shape.h"

Shape::Shape()
// Initializes private attribute c to <0,0,0>
{
    c = new Color;                
}

Shape::Shape(int r, int g, int b)
// Initializes Color object pointed to by c to <r,g,b>
{
    c = new Color;
    c->setRed(r);
    c->setGreen(g);
    c->setBlue(b);
}

Shape::~Shape()
// Deallocates Color object
{
    delete c;
}

Color Shape::getColor() const
// Returns color of object
{
    return *c;
}

double Shape::area() const
// Returns default area of 0.0 -- must be a polymorphic function
{
    return 0.0;
}

double Shape::perimeter() const
// Returns default perimeter of -1.0 -- must be a polymorphic function
{
    return -1.0;
}