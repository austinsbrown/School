#include "triangle.h"
#include <cmath>

Triangle::Triangle() : Shape()
{
    a = 0.0;
    b = 0.0;
    c = 0.0;
}

Triangle::Triangle(double aaa, double bbb, double ccc, int rr, int gg, int bb) : Shape(rr, gg, bb)
{
    a = aaa;
    b = bbb;
    c = ccc;
}

double Triangle::area() const
{
    double s = (a+b+c) / 2;
    double ar = sqrt(s * (s-a) * (s-b) * (s-c));
    return ar;
}

double Triangle::perimeter() const
{
    double perim = a + b + c;
    return perim;
}