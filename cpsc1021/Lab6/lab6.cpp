/* Christopher Brant
 * cbrant
 * Lab 6
 * Lab Section: 002
 * Lauren Fuller
 * lab6.cpp
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getLotteryInfo(int *range, int *choices);
long int computeWays(int range, int choices);
long int factorial(int factNum);

int main(void)
{
	int pickFrom, numPicks;
	long int ways;

	cout << "This program will tell you your probability of winning "
		 << "\"Little Lotto\"." << endl;

	getLotteryInfo(&pickFrom, &numPicks);
	ways = computeWays(pickFrom, numPicks);

	cout << fixed << showpoint << setprecision(4);
	cout << endl << "Your chance of winning the lottery is "
		 << "1 chance in " << ways << "." << endl;
	cout << "This is a probability of " << (1.0 / ways) << endl;

	return 0;
}