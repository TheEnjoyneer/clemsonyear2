/* Pixel.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#include "Pixel.h"

// Default constructor
Pixel::Pixel()
{
	// Set default pixel_color to all 0s
	Pixel::setRGB(0, 0, 0);

	// Set default point to the origin
	Pixel::setCoord(0, 0);
}

// Not necessarily needed
Pixel::Pixel(Color color_choice, Point xy)
{
	// Set pixel_color to color choice from user
	pixel_color = color_choice;

	// Set coordinates to point xy
	coordinates = xy;
}

// Chooses color based on a boolean
void Pixel::chooseColor(bool isInside)
{
	if (!isInside)
		Pixel::setRGB(82, 45, 128);
	else
		Pixel::setRGB(234, 106, 32);
}

// Set rgb values for pixel
void Pixel::setRGB(unsigned char R, unsigned char G, unsigned char B)
{
	// Set RGB values of pixel_color
	pixel_color.setColor(R, G, B);
}

// Prints pixel values to outfile
void Pixel::printPixel(ofstream &outFile)
{
	outFile << pixel_color.getRed()
			<< pixel_color.getGreen()
			<< pixel_color.getBlue();
}

// Not specified, but how else do you have a point here
void Pixel::setCoord(double X1, double X2)
{
	coordinates.setPoint(X1, X2);
}

// Included, but not necessary
Pixel::~Pixel()
{
	// No real destruction necessary
}