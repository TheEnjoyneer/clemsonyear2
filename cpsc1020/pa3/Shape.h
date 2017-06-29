/* Shape.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Color.h"
#include <string>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	protected:
		string shapeType;
		Color shapeColor;

	public:
		// Constructors
		Shape();
		Shape(string input);

		// Setter
		void setShapeChars(string input);

		// Printer
		void printColor(Color *pointColor);
};

#endif