/* color.cpp
 * Christopher Brant
 * cbrant
 * Lab 7
 * Section 002
 * Lauren Fuller
 */

#include "color.h"

// Constructor for supplied inputs sets corresponding values
Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

// Default constructor sets all values to 0
Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
}

// Sets red to supplied input
void Color::setRed(unsigned char r)
{
	red = r;
}

// Sets green to supplied input
void Color::setGreen(unsigned char g)
{
	green = g;
}

// Sets blue to supplied input
void Color::setBlue(unsigned char b)
{
	blue = b;
}

// Returns value for red
unsigned char Color::getRed()
{
	return red;
}

// Returns value for green
unsigned char Color::getGreen()
{
	return green;
}

// Returns value for blue
unsigned char Color::getBlue()
{
	return blue;
}
