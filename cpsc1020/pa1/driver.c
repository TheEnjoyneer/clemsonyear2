/* driver.c
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #1
 * Due 2/26/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[])
{
	int i;

	FILE *inputfile = fopen(argv[1], "r");
 	FILE *outputfile = fopen(argv[2], "w");

 	// Test for valid file pointers
 	if (outputfile == NULL || inputfile == NULL)
 	{
 		printf("\nOne or both file pointers failed to open correctly\n");
 		exit (1);
 	}

 	// Declare header and image and initialize header
 	header_t *imageHead = (header_t *)malloc(sizeof(header_t));
 	pixel_t **originalImage;

 	// Read image header for mallocing
 	readHeader(imageHead, inputfile);

 	// Malloc memory for the image
 	originalImage = (pixel_t **)malloc(imageHead->height * sizeof(pixel_t *));

 	for (i = 0; i < imageHead->height; i++)
 		originalImage[i] = (pixel_t *)malloc(imageHead->width * sizeof(pixel_t));

 	// Read total image
 	readImage(imageHead, originalImage, inputfile);

 	// Choose and run transformation function
 	chooseTransform(imageHead, originalImage, outputfile);

 	// Free all malloced memory
 	for (i = 0; i < imageHead->height; i++)
 		free(originalImage[i]);

 	free(originalImage);
 	free(imageHead);

 	fclose(inputfile);
 	fclose(outputfile);

 	printf("Image successfully printed\n\n");


	return 0;
}