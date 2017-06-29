/* Package.h
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */
/* Class definitions for package */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Person.h"
using namespace std;

class Package
{
   public:
	Package(Person, Person, double, double);
	double calculateCost();
    Person& getSender();
    Person& getRecipient();

   protected:
	Person sender;
	Person recipient;
	double weight;
	double cost;
};
#endif
