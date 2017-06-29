/* OvernightPackage.cpp
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */
/* Class implementation for an overnight package */

#include "OvernightPackage.h"

/*Complete this code*/

/*This is a constructor.  
 *Use member initialization to initialize the information for the base 
 *class (Package)  Then follow the instruction included to complete
 *the remaining information for the constructor.*/
OvernightPackage::OvernightPackage(Person s, Person r, double w, double c, 
       double f, double ff) : Package(s, r, w, c) 	// Member intialization
{
    /*if the additional fee is negative, intialize it to 10 cents*/
	if (f < 0)
		additionalFee = 0.10;
	else
		additionalFee = f;
    
    /* if the flat fee is negative, initialize it to $3.00 */
	if (ff < 0)
		flatFee = 3.00;
	else
		flatFee = ff;
}

/*This function calls packages calculateCost function, adds weight * additionalFee then adds the
 flatfee and returns the value  */
double OvernightPackage::calculateCost()
{
	double newCost = Package::calculateCost();		// Declare cost variable

	newCost += (weight * additionalFee) + flatFee;	// Perform arithmetic
    
    return newCost;
}
