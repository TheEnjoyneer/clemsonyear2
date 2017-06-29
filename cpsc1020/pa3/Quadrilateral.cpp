/* Quadrilateral.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Quadrilateral.h"

// Default constructor
Quadrilateral::Quadrilateral()
{
	Point a(0, 0);

	vertex[0] = vertex[1] = vertex[2] = vertex[3] = a;
}

// Overloaded constructor
Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
	vertex[3] = d;
}

// Sets the quadrilateral's vertices values
void Quadrilateral::setVertices(Point a, Point b, Point c, Point d)
{
	vertex[0] = a;
	vertex[1] = b;
	vertex[2] = c;
	vertex[3] = d;
}

// Test if given point is inside the quadrilateral and return boolean
bool Quadrilateral::isInside(Point *check)
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

    // a  and b are split into the dividend and divisor for formatting choices
    a1 = (vertex[2].getY()-vertex[3].getY()) *
         (check->getX()-vertex[3].getX()) +
         (vertex[3].getX()-vertex[2].getX()) *
         (check->getY()-vertex[3].getY());

    a2 = (vertex[2].getY()-vertex[3].getY()) *
         (vertex[1].getX()-vertex[3].getX()) +
         (vertex[3].getX()-vertex[2].getX()) *
         (vertex[1].getY()-vertex[3].getY());

    b1 = (vertex[3].getY()-vertex[1].getY()) *
         (check->getX()-vertex[3].getX()) +
         (vertex[1].getX()-vertex[3].getX()) *
         (check->getY()-vertex[3].getY());
    b2 = a2;

    // Calculate a, b, and c values
    a = a1 / a2;
    b = b1 / b2;
    c = 1 - a - b;

	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
       	inside = 1;

    a1 = (vertex[3].getY()-vertex[0].getY()) *
         (check->getX()-vertex[0].getX()) +
         (vertex[0].getX()-vertex[3].getX()) *
         (check->getY()-vertex[0].getY());

    a2 = (vertex[3].getY()-vertex[0].getY()) *
         (vertex[2].getX()-vertex[0].getX()) +
         (vertex[0].getX()-vertex[3].getX()) *
         (vertex[2].getY()-vertex[0].getY());

    b1 = (vertex[0].getY()-vertex[2].getY()) *
         (check->getX()-vertex[0].getX()) +
         (vertex[2].getX()-vertex[0].getX()) *
         (check->getY()-vertex[0].getY());
    b2 = a2;

    // Calculate a, b, and c values
    a = a1 / a2;
    b = b1 / b2;
    c = 1 - a - b;

	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
       	inside = 1;

    return inside;
}