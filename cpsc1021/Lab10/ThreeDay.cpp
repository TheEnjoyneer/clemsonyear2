/* ThreeDay.cpp
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */
/* Class implementation for a 3 day package */

#include "ThreeDay.h"

/*Complete this code*/

/*This is a constructor.
 *Use member initialization to initialize the information for the base
 *class (Package)  Then follow the instruction included to complete
 *the remaining information for the constructor.*/

ThreeDay::ThreeDay(Person s, Person r, double w, double c, double f) 
: Package(s, r, w, c)	// Member intialization list
{
 	// if additional fee is negative, intialize it to ten cents
 	if (f < 0)
 		additionalFee = 0.10;
 	else
 		additionalFee = f; 
}


/*This function calls the packages calculateCost function, 
 *then adds (weight * additionalFee) to it */
double ThreeDay::calculateCost()
{
	double newCost = Package::calculateCost();	// Declare cost variable

	newCost += (weight * additionalFee);		// Perform arithmetic

	return newCost;
}
