/* Triangle.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Triangle.h"

// Default constructor
Triangle::Triangle()
{
	Point a;
	vertex[0] = vertex[1] = vertex[2] = a;
}

// Overloaded constructor
Triangle::Triangle(Point a, Point b, Point c)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
}

// Sets the vertices values for the triangle
void Triangle::setVertices(Point a, Point b, Point c)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
}

// Test if given point is inside the triangle and return a boolean
bool Triangle::isInside(Point *check)
{
    double a, b, c, a1, a2, b1, b2;
    bool inside = 0;

    // a  and b are split into the dividend and divisor for formatting choices
    a1 = (vertex[1].getY()-vertex[2].getY()) *
         (check->getX()-vertex[2].getX()) +
         (vertex[2].getX()-vertex[1].getX()) *
         (check->getY()-vertex[2].getY());

    a2 = (vertex[1].getY()-vertex[2].getY()) *
         (vertex[0].getX()-vertex[2].getX()) +
         (vertex[2].getX()-vertex[1].getX()) *
         (vertex[0].getY()-vertex[2].getY());

    b1 = (vertex[2].getY()-vertex[0].getY()) *
         (check->getX()-vertex[2].getX()) +
         (vertex[0].getX()-vertex[2].getX()) *
         (check->getY()-vertex[2].getY());
    b2 = a2;

    // Calculate a, b, and c values
    a = a1 / a2;
    b = b1 / b2;
    c = 1 - a - b;

    // Test for validity of the point
    if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
        inside = 1;

    return inside;
}