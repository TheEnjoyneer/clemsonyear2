/* Christopher Brant
 * cbrant
 * Lab 4
 * Lab Section: 002
 * Lauren Fuller
 * functions.cpp
 */

#include "functions.h"

int checkPoint(struct point_t *p, struct point_t *test)
{
	double a, b, c, a1, a2, b1, b2;
	int check = 0;

	// a  and b are split into the dividend and divisor for formatting choices
	a1 = (p[1].y-p[2].y)*(test->x-p[2].x)+(p[2].x-p[1].x)*(test->y-p[2].y);
	a2 = (p[1].y-p[2].y)*(p[0].x-p[2].x)+(p[2].x-p[1].x)*(p[0].y-p[2].y);

	b1 = (p[2].y-p[0].y)*(test->x-p[2].x)+(p[0].x-p[2].x)*(test->y-p[2].y);
	b2 = a2;

	// Calculate a, b, and c values
	a = a1 / a2;
	b = b1 / b2;
	c = 1 - a - b;

	// Test for validity of the point
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
		check = 1;

	return check;
}