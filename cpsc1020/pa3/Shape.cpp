/* Shape.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Shape.h"
#include <time.h>
#include <cstdlib>

// Default constructor
Shape::Shape()
{
	char white = 255;

	shapeType = "None";

	shapeColor.setColor(white, white, white);
}

// Overloaded constructor
Shape::Shape(string input)
{
	shapeType = input;

	char randRed, randGreen, randBlue;
	randRed = rand() % 256;
	randGreen = rand() % 256;
	randBlue = rand() % 256;

	if (shapeType.compare("Triangle") == 0)
		shapeColor.setColor(randRed + 100, randGreen, randBlue);
	else if (shapeType.compare("Circle") == 0)
		shapeColor.setColor(randRed, randGreen + 100, randBlue);
	else if (shapeType.compare("Quadrilateral") == 0)
		shapeColor.setColor(randRed, randGreen, randBlue + 100);
}

// Setter
void Shape::setShapeChars(string input)
{
	shapeType = input;

	char randRed, randGreen, randBlue;
	randRed = rand() % 256;
	randGreen = rand() % 256;
	randBlue = rand() % 256;

	if (shapeType.compare("Triangle") == 0)
		shapeColor.setColor(randRed + 100, randGreen, randBlue);
	else if (shapeType.compare("Circle") == 0)
		shapeColor.setColor(randRed, randGreen + 100, randBlue);
	else if (shapeType.compare("Quadrilateral") == 0)
		shapeColor.setColor(randRed, randGreen, randBlue + 100);
}

// Print to image, which means change color in Color array
void Shape::printColor(Color *pointColor)
{
	*pointColor = shapeColor;
}