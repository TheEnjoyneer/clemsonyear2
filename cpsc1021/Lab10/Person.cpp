/* Person.cpp
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */

#include "Person.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*Use initialization list to initialize the two following constructors */

Person::Person(string name, string address, string city, string state, int zip)
: name(name), address(address), city(city), state(state), zip(zip) 
// Member initialization list
{

}

Person::Person() : name("NoName"), address("NoAddress"), city("NoCity"),
state("NoState"), zip(00000) // Member initialization list
{

}

/*Setters*/
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAddress(string address)
{
    this->address = address;
}
void Person::setState(string state)
{
    this->state = state;
}
void Person::setCity(string city)
{
    this->city = city;
}
void Person::setZip(int zip)
{
    this->zip = zip;
}

/*The next two functions are used to print the Sender and Recipient's
 *mailing information*/

void Person::printSenderInfo()
{
	cout << setprecision(5) << endl
		 << "SENDER ADDRESS:" << endl
		 << name << endl
		 << address << endl
		 << city << ", " << state << " " << zip << endl;
}

void Person::printRecipientInfo()
{
	cout << setprecision(5) << endl
		 << "RECIPIENT ADDRESS:" << endl
		 << name << endl
		 << address << endl
		 << city << ", " << state << " " << zip << endl;
}
