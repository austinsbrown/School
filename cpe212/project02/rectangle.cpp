#include "rectangle.h"

Rectangle::Rectangle() : Shape()
{
    l = 0.0;
    w = 0.0;
}

Rectangle::Rectangle(double ll, double ww, int rr, int gg, int bb) : Shape(rr, gg, bb)
{
    l = ll;
    w = ww;
}

double Rectangle::area() const
{
    double area = l * w;
    return area;
}

double Rectangle::perimeter() const
{
    double perim = 2*l + 2*w;
    return perim;
}