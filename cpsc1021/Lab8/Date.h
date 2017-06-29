/* Date.h
 * Christopher Brant
 * cbrant
 * Lab 8
 * Lab Section 002
 * Lauren Fuller
 */

#include <iostream>

using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;

	public:
		/*Default constructors*/
		Date();

		/*Overloaded constructor*/
		Date(int m, int d, int y);

		/*Setters*/
		void setMonth(int m);
		void setDay(int d);
		void setYear(int y);

		/*Getters*/
		int getMonth();
		int getDay();
		int getYear();

};
