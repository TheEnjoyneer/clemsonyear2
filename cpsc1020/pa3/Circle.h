/* Circle.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include "Shape.h"
#include "Point.h"
using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape
{
	private:
		Point center;
		double radius;

	public:
		// Constructors
		Circle();
		Circle(double c1, double c2, double r);

		// Setters
		void setCenter(double c1, double c2);
		void setRadius(double r);

		// Tester
		bool isInside(Point *check);
};

#endif