/* Circle.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Circle.h"

// Default constructor
Circle::Circle()
{
	center.setPoint(0, 0);

	radius = 0;
}

// Overloaded constructor
Circle::Circle(double c1, double c2, double r)
{
	center.setPoint(c1, c2);
	radius = r;
}

// Set center point values
void Circle::setCenter(double c1, double c2)
{
	center.setPoint(c1, c2);
}

// Set radius value
void Circle::setRadius(double r)
{
	radius = r;
}

// Test if the given point is inside the circle and return boolean
bool Circle::isInside(Point *check)
{
	bool inside = 0;
	double a, b, c;

	a = (check->getX() - center.getX()) * (check->getX() - center.getX());
	b = (check->getY() - center.getY()) * (check->getY() - center.getY());
	c = radius * radius;

	if ((a + b) <= c)
		inside = 1;

	return inside;
}