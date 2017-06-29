/* Christopher Brant
 * ppmheader.c
 * ppm header 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	fprintf(stdout, "P3\n200 200 255\n");

	for (; i < 200+200; i++)
		fprintf(stdout, "%d %d %d ", 255, 0, 0);

	return 0;
}
