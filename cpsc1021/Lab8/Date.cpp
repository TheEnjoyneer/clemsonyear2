/* Date.cpp
 * Christopher Brant
 * cbrant
 * Lab 8
 * Lab Section 002
 * Lauren Fuller
 */

#include "Date.h"

/*Default constructor*/
Date::Date()
{
	// Defaults set to 1 because there 
	// is no such thing as day, month, or year 0
	// Technically there is a year 0, but unimportant
	month = 1;
	day = 1;
	year = 1;

}

/*Overloaded constructor*/
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

/*Setters*/
void Date::setMonth(int m)
{
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

void Date::setYear(int y)
{
	year = y;
}

/*Getters*/
int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}