/* Quadrilateral.h
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

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

class Quadrilateral: public Shape
{
	private:
		Point vertex[4];

	public:
		// Constructors
		Quadrilateral();
		Quadrilateral(Point a, Point b, Point c, Point d);

		// Setter
		void setVertices(Point a, Point b, Point c, Point d);

		// Tester
		bool isInside(Point *check);
};

#endif