/* Color.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Color.h"

// Default constructor
Color::Color()
{
	red = 0;
	green = 0;
	blue = 0;
}

// Not necessary but included
Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

// Copy function
void Color::setColor(Color copy)
{
	red = copy.red;
	green = copy.green;
	blue = copy.blue;
}

// Overloaded function to set each value
void Color::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

// The following 3 functions retrieve specific color values
unsigned char Color::getRed(void)
{
	return red;
}

unsigned char Color::getGreen(void)
{
	return green;
}

unsigned char Color::getBlue(void)
{
	return blue;
}

Color::~Color()
{
	// No destruction really necessary
}