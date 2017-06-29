/* Christopher Brant
 * cbrant
 * Lab 4
 * Lab Section: 002
 * Lauren Fuller
 * main.cpp
 */

#include "functions.h"

int main(void)
{
	int width, height, i, j, hit;
	struct point_t plane[3];
	struct point_t test;

	// Prompt user for information and gather user input
	cout << "Please enter plane dimensions." << endl;
	cin >> width >> height;

	for (i = 0; i < 3; i++)
	{
		// Prompts User and gathers user input for each point
		cout << "Please enter x and y values for Point " << i+1;
		cout << ", separated by a space." << endl;

		cin >> plane[i].x >> plane[i].y;
	}

	cout << endl << "HIT POINTS:" << endl;

	for (i = 0; i < height; i++)
	{
		// Set y value of test variable to the current i value
		test.y = static_cast<double>(i);

		for (j = 0; j < width; j++)
		{
			// Set the x value of test variable to the current j value
			test.x = static_cast<double>(j);

			// hit uses checkPoint to find Hit Points
			hit = checkPoint(plane, &test);

			if (hit == 1)
			{
				// Prints out the hit points
				cout << fixed << setprecision(1) << test.x << ",";
				cout << fixed << setprecision(1) << test.y << endl;
			}
		}
	}

	return 0;
}
