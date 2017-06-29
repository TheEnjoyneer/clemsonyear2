/* ThreeDay.h
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */
/* Class definitions for a three day package */

#ifndef THREEDAY_H
#define THREEDAY_H

#include "Package.h"
#include <string>
using namespace std;

class ThreeDay:public Package
{
   public:
	ThreeDay(Person, Person, double, double, double);
	double calculateCost();

   private: 
	double additionalFee;
};
#endif
