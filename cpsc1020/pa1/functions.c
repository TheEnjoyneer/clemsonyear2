/* functions.c
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

#define MAXLINE 20

// Reads and saves header information at the pointer location
void readHeader(header_t *head, FILE *inFile)
{
	int w, h, pS;

	// Scan for header information
	fscanf(inFile, "%s %d %d %d\n", head->magicNum, &w, &h, &pS);

	head->width = w;		// Assign width here bc of dumb formatting rules
							// that cap lines at 80 chars
	head->height = h;		// Assign height for same reason
	head->pixelSpec = pS;	// Assign pixel specification for same reason
}

// Reads and saves all pixels at the given double pointer location
void readImage(header_t *head, pixel_t **image, FILE *inFile)
{
	int i, j;
	char r, g, b;

	for (i = 0; i < head->height; i++)
	{
		for (j = 0; j < head->width; j++)
		{
			fscanf(inFile, "%c%c%c", &r, &g, &b);
			image[i][j].red = r;	// assigns red here and not in line
			image[i][j].green = g;	// assigns green here and not in line
			image[i][j].blue = b;	// assigns blue here and not in line
		}
	}
}

// Scans for user input and calls corresponding function
void chooseTransform(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, choice;
	char line[MAXLINE];

	while (choice > 8 || choice < 1)
	{
		// Print prompt for choosing what transformation to perform
		for (i = 0; i < 65; i++)
			printf("+");
		printf("\nThank you for using the Image Transformer!\n");
		printf("There are several transformations you can perform\n");
		printf("on the input image.");
		printf(" Choose the number that corresponds to the\n");
		printf("transformation you wish to perform on the image.\n");

		for (i = 0; i < 65; i++)
			printf("+");

		printf("\n\n");
		printf("1. Gray Scale\n");
		printf("2. Color to Negative\n");
		printf("3. Flip the Image\n");
		printf("4. Rotate Right\n");
		printf("5. Rotate Left\n");
		printf("6. Reprint\n");
		printf("7. Mirror Horizontally\n");
		printf("8. Mirror Vertically\n\n");

		// Scan for input from the user
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &choice);

		// Print error if necessary and repeat loop
		if (choice > 8 || choice < 1)
			printf("Incorrect input. Try again\n");
	}

	// Switch statement for the completion of the chosen transformation
	switch (choice)
	{
		case 1:
			grayScaleImage(head, image, outFile);
			break;
		case 2:
			color2Negative(head, image, outFile);
			break;
		case 3:
			flipImage(head, image, outFile);
			break;
		case 4:
			rotateRight(head, image, outFile);
			break;
		case 5:
			rotateLeft(head, image, outFile);
			break;
		case 6:
			reprint(head, image, outFile);
			break;
		case 7:
			horizontalMirror(head, image, outFile);
			break;
		case 8:
			verticalMirror(head, image, outFile);
			break;
		default:
			printf("Error in choice decision loop.\n");
			break;
	}
}

// Prints ppm image to output file
void printP6Image(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j;
	i = head->height;
	j = head->width;

	// Print the header information to the file
	fprintf(outFile, "%s %d %d %d\n", head->magicNum, j, i, head->pixelSpec);

	// Print each pixel info to the file
	for (i = 0; i < head->height; i++)
	{
		for (j = 0; j < head->width; j++)
		{
			// Done in sequence because of the length of one line
			// being slightly longer than 80 chars *unnecessary*
			fprintf(outFile, "%c", image[i][j].red);
			fprintf(outFile, "%c", image[i][j].green);
			fprintf(outFile, "%c", image[i][j].blue);
		}
	}
}

// Converts image to a grayscale version of itself
void grayScaleImage(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j;
	char newpixel;
	i = head->height;
	j = head->width;

	fprintf(outFile, "P5 %d %d %d\n", j, i, head->pixelSpec);

	for (i = 0; i < head->height; i++)
	{
		for (j = 0; j < head->width; j++)
		{
			// Adds each pixel value up to the desired value
			newpixel = (char)(.299 * image[i][j].red);
			newpixel += (char)(.587 * image[i][j].green);
			newpixel += (char)(.114 * image[i][j].blue);

			// Prints that pixel value
			fprintf(outFile, "%c", newpixel);
		}
	}
}

// Flips image vertically
void flipImage(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j;

	// Malloc newimage memory
	pixel_t **newimage = (pixel_t **)malloc(head->height * sizeof(pixel_t *));

	for (i = 0; i < head->height; i++)
		newimage[i] = (pixel_t *)malloc(head->width * sizeof(pixel_t));

	// Flip image values into newimage 
	for (i = head->height - 1; i > 0; i--)
	{
		for (j = 0; j < head->width; j++)
			newimage[i][j] = image[head->height-i][j];
	}

	// Print image
	printP6Image(head, newimage, outFile);

	// Free newimage memory
	for (i = 0; i < head->height; i++)
		free(newimage[i]);

	free(newimage);
}

// Rotates image counterclockwise
void rotateLeft(header_t *head, pixel_t **image, FILE *outFile)
{
    int i, j;
    
    // Malloc newhead memory
    header_t *newhead = (header_t *)malloc(sizeof(header_t));

    *newhead = *head;
    newhead->height = head->width;	// Assign newhead height
    newhead->width = head->height;	// Assign newhead width

    // Malloc memory for newimage
    pixel_t **newimage = (pixel_t **)malloc(head->width * sizeof(pixel_t *));

    for (i = 0; i < head->width; i++)
    	newimage[i] = (pixel_t *)malloc(head->height * sizeof(pixel_t));

    // Rotate image here
    for (i = 0; i < newhead->height; i++)
    {
        for (j = 0; j < newhead->width; j++)
        {
            newimage[i][j] = image[j][newhead->height-i];
        }
    }

    // Print image
    printP6Image(newhead, newimage, outFile);

    // Free newimage memory
    for (i = 0; i < head->width; i++)
    	free(newimage[i]);

    free(newimage);
    free(newhead);
}

// Rotates image clockwise
void rotateRight(header_t *head, pixel_t **image, FILE *outFile)
{
    int i, j;
    header_t *newhead = (header_t *)malloc(sizeof(header_t));

    *newhead = *head;
    newhead->height = head->width;	// Assign newhead height
    newhead->width = head->height;	// Assign newhead width

    // Malloc memory for newimage
    pixel_t **newimage = (pixel_t **)malloc(head->width * sizeof(pixel_t *));

    for (i = 0; i < head->width; i++)
    	newimage[i] = (pixel_t *)malloc(head->height * sizeof(pixel_t));

    // Rotate image
    for (i = 0; i < head->width; i++)
    {
        for (j = 0; j < head->height; j++)
        {
            newimage[i][j] = image[head->height-j-1][i];
        }
    }

    // Print image
	printP6Image(newhead, newimage, outFile);

	// Free newimage memory
    for (i = 0; i < head->width; i++)
    	free(newimage[i]);

    free(newimage);
    free(newhead);
}

// Makes a color negative version of image
void color2Negative(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j;
	i = head->height;	// i and j exclusively used to short print line
	j = head->width;	// Because 80 chars is arbitrary and unnecessary

	// Print header info
	fprintf(outFile, "%s %d %d %d\n", head->magicNum, j, i, head->pixelSpec);

	// Print each pixel's negative value directly to output file
	for (i = 0; i < head->height; i++)
	{
		for (j = 0; j < head->width; j++)
		{
			fprintf(outFile, "%c", 255 - image[i][j].red);
			fprintf(outFile, "%c", 255 - image[i][j].green);
			fprintf(outFile, "%c", 255 - image[i][j].blue);
		}
	}
}

// Literally just reprints image
void reprint(header_t *head, pixel_t **image, FILE *outFile)
{
	printP6Image(head, image, outFile);
}

// Mirrors an image over its horizontal middle
void horizontalMirror(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j, mid, reverse = 0;
	mid = head->height / 2;

	// Malloc memory for newimage
	pixel_t **newimage = (pixel_t **)malloc(head->height * sizeof(pixel_t *));

	for (i = 0; i < head->height; i++)
		newimage[i] = (pixel_t *)malloc(head->width * sizeof(pixel_t));

	// Mirror image here
	for (i = 0; i < head->height; i++)
	{
		for (j = 0; j < head->width; j++)
		{
			if (i >= mid)
				newimage[i][j] = image[mid-reverse][j];
			else
				newimage[i][j] = image[i][j];
		}

		if (i >= mid)
			reverse++;
	}

	// Print image
	printP6Image(head, newimage, outFile);

	// Free newimage memory
	for (i = 0; i < head->height; i++)
		free(newimage[i]);

	free(newimage);
}

// Mirros an iamge over its vertical middle
void verticalMirror(header_t *head, pixel_t **image, FILE *outFile)
{
	int i, j, mid, reverse = 0;
	mid = head->width / 2;

	// Malloc memory for newimage
	pixel_t **newimage = (pixel_t **)malloc(head->height * sizeof(pixel_t *));

	for (i = 0; i < head->height; i++)
		newimage[i] = (pixel_t *)malloc(head->width * sizeof(pixel_t));

	// Mirror image here
	for (i = 0; i < head->height; i++)
	{
		reverse = 0;

		for (j = 0; j < head->width; j++)
		{
			if (j >= mid)
			{
				newimage[i][j] = image[i][mid-reverse];
				reverse++;
			}
			else
				newimage[i][j] = image[i][j];
		}
	}

	// Print image
	printP6Image(head, newimage, outFile);

	// Free newimage memory
	for (i = 0; i < head->height; i++)
		free(newimage[i]);

	free(newimage);
}







