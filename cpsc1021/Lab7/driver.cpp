/* driver.cpp
 * Christopher Brant
 * cbrant
 * Lab 7
 * Section 002
 * Lauren Fuller
 */

#include <iostream>
#include <ios>
#include <fstream>
#include "color.h"
using namespace std;

static void printSquare(int width, int height, Color color1,
						 Color color2, ofstream &outFile);
static void printRect(int width, int height, Color color1,
						 Color color2, ofstream &outFile);


int main(int argc, char *argv[])
{
	// Declare and initialize height and width for images
	const int width = 256;
	const int height_1 = 256;
	const int height_2 = 512;

	// Declare variables for orange and purple RGB values
	unsigned char OR, OG, OB;
	int input_r, input_g, input_b;

	// Assign correct color values for orange and purple
	OR = 246;
	OG = 103;
	OB = 51;

	/* Declare your Color class variables here so that
	   the constructors are called one after the other
	*/
	Color orange(OR, OG, OB);	// Overloaded constructor used to set orange
	Color purple;				// Default constructor sets RGB vals to 0

	ofstream output1, output2;	// Creates output file pointers

	output1.open(argv[1]);		// Opens files and sets them to fpointers
	output2.open(argv[2]);

	// Checks for file opening errors
	if (!output1.is_open()|| !output2.is_open())
	{
		cout << "One or more files not opened." << endl;
		exit (1);
	}

	cout << "Clemson purple has RGB 82, 45, 128" << endl;

	// Gather input from the user
	cout << "Enter desired RGB values for Clemson purple:" << endl;
	cin >> input_r;
	cout << endl << "Enter desired green value for Clemson purple:" << endl;
	cin >> input_g;
	cout << endl << "Enter desired blue value for Clemson purple:" << endl;
	cin >> input_b;
	cout << endl;

	// Unnecessary, but I typecast the ints to unsigned char
	input_r = static_cast<unsigned char>(input_r);
	input_g = static_cast<unsigned char>(input_g);
	input_b = static_cast<unsigned char>(input_b);

	// Set purple values to the input values from the user
	purple.setRed(input_r);
	purple.setGreen(input_g);
	purple.setBlue(input_b);

	// Print images to ppm files
	cout << "Printing your images..." << endl;

	printSquare(width, height_1, orange, purple, output1);

	printRect(width, height_2, orange, purple, output2);

	return 0;
}

static void printSquare(int width, int height, Color color1,
						 Color color2, ofstream &outFile)
{
	unsigned char r1, g1, b1, r2, g2, b2;
	
	// Get the RGB values from the colors
	r1 = color1.getRed();
	g1 = color1.getGreen();
	b1 = color1.getBlue();
	r2 = color2.getRed();
	g2 = color2.getGreen();
	b2 = color2.getBlue();

	// Set middle axes to change colors at
	int midwidth = width/2;
	int midheight = height/2;
	int i, j;

	// Print the header correctly
	outFile << "P6 " << width << " " << height << " " << 255 << endl;

	// Loop through and create blocks of opposite colors
	for (i = 0; i < height; i++)
	{
		if (i > midheight)
		{
			for (j = 0; j < width; j++)
			{
				if (j > midwidth)
					outFile << r1 << g1 << b1;
				else
					outFile << r2 << g2 << b2;
			}
		}
		else
		{
			for (j = 0; j < width; j++)
			{
				if (j > midwidth)
					outFile << r2 << g2 << b2;
				else
					outFile << r1 << g1 << b1;
			}

		}
	}
}

static void printRect(int width, int height, Color color1,
						 Color color2, ofstream &outFile)
{
	unsigned char r1, g1, b1, r2, g2, b2;
	
	// Get the RGB values from the colors
	r1 = color1.getRed();
	g1 = color1.getGreen();
	b1 = color1.getBlue();
	r2 = color2.getRed();
	g2 = color2.getGreen();
	b2 = color2.getBlue();

	// Set middle axes to change colors at
	int midwidth = width/2;
	int midheight = height/2;
	int i, j;

	// Print the header correctly
	outFile << "P6 " << width << " " << height << " " << 255 << endl;

	for (i = 0; i < height; i++)
	{
		if (i > midheight)
		{
			for (j = 0; j < width; j++)
			{
				if (j > midwidth)
					outFile << r1 << g1 << b1;
				else
					outFile << r2 << g2 << b2;
			}
		}
		else
		{
			for (j = 0; j < width; j++)
			{
				if (j > midwidth)
					outFile << r2 << g2 << b2;
				else
					outFile << r1 << g1 << b1;
			}

		}
	}
}