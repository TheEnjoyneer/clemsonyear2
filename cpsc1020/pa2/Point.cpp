/* Point.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#include "Point.h"

// Default Constructor
Point::Point()
{
	x = 0;
	y = 0;
}

// Overloaded constructor
Point::Point(double x1, double x2)
{
	x = x1;
	y = x2;
}

// Sets coordinate values
void Point::setPoint(double x1, double x2)
{
	x = x1;
	y = x2;
}

// The following 2 functions retrieve coordinate values
double Point::getX(void)
{
	return x;
}

double Point::getY(void)
{
	return y;
}

Point::~Point()
{
	// No destruction necessary
}