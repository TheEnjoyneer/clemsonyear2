/* Christopher Brant
 * cbrant
 * Lab 4
 * Lab Section: 002
 * Lauren Fuller
 * functions.h
 */

#include <iostream>
#include <iomanip>
using namespace std;

struct point_t {
	double x;
	double y;
};

int checkPoint(struct point_t *p, struct point_t *test);