/* driver.cpp
 * Christopher Brant
 * cbrant
 * Lab 8
 * Lab Section 2
 * Lauren Fuller
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Date.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Declare basic variables 
	int numDates, i;
	int m, d, y;
	Date oldest;
	ifstream inFile;
	ofstream outFile;

	// Open input and output files
	inFile.open(argv[1]);
	outFile.open(argv[2]);

	// Check for file opening errors
	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "Error opening one or more files" << endl;
		exit (1);
	}

	// Read number of dates
	inFile >> numDates;

	// Declare vector with size numDates
	vector<Date> list(numDates);

	// Read dates into the vector 
	for (i = 0; i < numDates; i++)
	{
		// Read in each month, day, and year value
		inFile >> m >> d >> y;

		// Set the month, day, and year for each element
		list.at(i).setMonth(m);
		list.at(i).setDay(d);
		list.at(i).setYear(y);
	}

	// Set oldest date to the first in the vector
	oldest.setMonth(list.at(0).getMonth());
	oldest.setDay(list.at(0).getDay());
	oldest.setYear(list.at(0).getYear());

	// Loop through and find the oldest date here
	for (i = 1; i < numDates; i++)
	{
		if (list.at(i).getYear() < oldest.getYear())
		{
			oldest.setMonth(list.at(i).getMonth());
			oldest.setDay(list.at(i).getDay());
			oldest.setYear(list.at(i).getYear());
		}

		// Checks if year is the same
		else if (list.at(i).getYear() == oldest.getYear())
		{
			if (list.at(i).getMonth() < oldest.getMonth())
			{
				oldest.setMonth(list.at(i).getMonth());
				oldest.setDay(list.at(i).getDay());
				oldest.setYear(list.at(i).getYear());
			}

			// Checks if month is the same
			else if (list.at(i).getMonth() == oldest.getMonth())
			{
				if (list.at(i).getDay() < oldest.getDay())
				{
					oldest.setMonth(list.at(i).getMonth());
					oldest.setDay(list.at(i).getDay());
					oldest.setYear(list.at(i).getYear());
				}
			}
		}
	}

	// Print the oldest date to the output file
	outFile << "The oldest date in the input file is ";
	outFile << oldest.getMonth() << "/" << oldest.getDay();
	outFile << "/" << oldest.getYear() << endl;

	// Close file streams
	inFile.close();
	outFile.close();

	return 0;
}