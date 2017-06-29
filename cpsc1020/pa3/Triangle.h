/* Triangle.h
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

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle: public Shape
{
	private:
		Point vertex[3];

	public:
		// Constructors
		Triangle();
		Triangle(Point a, Point b, Point c);

		// Setters
		void setVertices(Point a, Point b, Point c);

		// Tester
		bool isInside(Point *check);
};

#endif