/* Christopher Brant
 * cbrant
 * Lab 2
 * Lab Section 002
 * TA: Lauren Fuller
 */


 #include <stdio.h>
 #include <stdlib.h>


 int main(int argc, char *argv[])
 {
 	int i, pixelnum;
 	char magicnum[3];
 	int height, width, range;
 	char red, green, blue;
 	
 	FILE *inputfile = fopen(argv[1], "r");
 	FILE *outputfile = fopen(argv[2], "w");

 	if (outputfile == NULL || inputfile == NULL)
 	{
 		printf("\nOne or both file pointers failed to open correctly.\n");
 		//exit 1;
 	}

 	fscanf(inputfile, "%s %d %d %d\n", magicnum, &width, &height, &range);
 	pixelnum = height * width;
 	fprintf(outputfile, "%s %d %d %d\n", magicnum, width, height, range);

 	for (i = 0; i < pixelnum; i++)
 	{
 		fscanf(inputfile, "%c%c%c", &red, &green, &blue);
 		fprintf(outputfile, "%c%c%c", red, green, blue);
 	}

 	fclose(inputfile);
 	fclose(outputfile);

 	return 0;
 }