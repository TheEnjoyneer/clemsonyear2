/* Christopher Brant
 * cbrant
 * Lab 2
 * Lab Section 002
 * TA: Lauren Fuller
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i, j, height, width, range, pixels;
	char red, green, blue;
	height = 400;
	width = 600;
	range = 255;
	pixels = (width * height) / 4;
	srand(time(0));

	printf("P6\n");	// Printing out the magic number
	printf("%d %d %d\n", width, height, range);	// Printing picture info

	for (i = 0; i < 4; i++)
	{
		red = (rand() % 205) + 50;			// Assigning randomized colors
		green = (rand() % 205) + 50;
		blue = (rand() % 205) + 50;

		for (j = 0; j < pixels; j++)		// Loop for printing those colors
			printf("%c%c%c", red, green, blue);
	}

	return 0;
}
