/* driver.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Header.h"
#include "Color.h"
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Quadrilateral.h"
using namespace std;

static void printImage(ofstream&outFile, Color **image, Header& imageHead);
static void printBackground(Color **image, Header& imageHead);

int main(int argc, char *argv[])
{
	int height, width, i, j;
	string temp;
	Header imageHead;
	ifstream inputFile;
	ofstream outputFile;

	// Check for validity of input files and open the files
	if (argc != 3)
	{
		cout << "Error, incorrect amount of file names." << endl;
		exit(1);
	}
	else
	{
		inputFile.open(argv[1]);
		outputFile.open(argv[2]);

		if (!inputFile.is_open() || !outputFile.is_open())
		{
			cout << "Error, one or more files did not open correctly." << endl;
		}
	}

	// Set the header width and height
	inputFile >> width >> height;
	imageHead.setWidth(width);
	imageHead.setHeight(height);

	// Declare and initialize the pointer array for the image
	Color **image = new Color*[height];

	for (i = 0; i < height; i++)
		image[i] = new Color[width];

	// Print the header to the output file
	imageHead.printHead(outputFile);

	// Print the background image to the output file
	printBackground(image, imageHead);

	Point check;

	// Check for more inputs until the end of the file is reached
	while (!inputFile.eof())
	{
		inputFile >> temp;

		// Test if shape is a triangle
		if (temp.compare("Triangle") == 0)
		{
			Triangle newTri;
			newTri.setShapeChars(temp);

			double a1, a2, b1, b2, c1, c2;

			inputFile >> a1 >> a2
					  >> b1 >> b2
					  >> c1 >> c2;

			if (a1 > height || b1 > height || c1 > height)
			{
				cout << "Triangle X parameters are out of accepted bounds"
					 << endl;
				exit(1);
			}
			
			if (a2 > width || b2 > width || c2 > width)
			{
				cout << "Triangle Y parameters are out of accepted bounds"
					 << endl;
				exit(1);
			} 

			Point a(a1, a2);
			Point b(b1, b2);
			Point c(c1, c2);

			newTri.setVertices(a, b, c);

			// Change color if inside shape as needed
			for (i = 0; i < height; i++)
			{
				for (j = 0; j < width; j++)
				{
					check.setPoint(i, j);

					if (newTri.isInside(&check))
						newTri.printColor(&(image[i][j]));
				}
			}
		}
		// Test if shape is a circle
		else if (temp.compare("Circle") == 0)
		{
			Circle newCircle;
			newCircle.setShapeChars(temp);

			double center1, center2;
			double radius;

			inputFile >> center1 >> center2
					  >> radius;

			newCircle.setCenter(center1, center2);
			newCircle.setRadius(radius);

			double check1, check2;
			check1 = center1 + radius;
			check2 = center2 + radius;

			if (check1 > height || check2 > width)
			{
				cout << "Given circle parameters are out of accepted bounds"
					 << endl;
				exit(1);
			} 

			// Change color if inside shape as needed
			for (i = 0; i < height; i++)
			{
				for (j = 0; j < width; j++)
				{
					check.setPoint(i, j);

					if (newCircle.isInside(&check))
						newCircle.printColor(&(image[i][j]));
				}
			}

		}
		else if (temp.compare("Quadrilateral") == 0)
		{
			Quadrilateral newQuad;
			newQuad.setShapeChars(temp);

			double q1, q2, r1, r2, s1, s2, t1, t2;

			inputFile >> q1 >> q2
					  >> r1 >> r2
					  >> s1 >> s2
					  >> t1 >> t2;

			if (q1 > height || r1 > height || s1 > height || t1 > height)
			{
				cout << "Quadrilateral X parameter is out of accepted bounds"
					 << endl;
				exit(1);
			}
			
			if (q2 > width || r2 > width || s2 > width || t2 > height)
			{
				cout << "Quadrilateral Y parameter is out of accepted bounds"
					 << endl;
				exit(1);
			}

			Point q(q1, q2);
			Point r(r1, r2);
			Point s(s1, s2);
			Point t(t1, t2);

			newQuad.setVertices(q, r, s, t);

			// Change color if inside shape as needed
			for (i = 0; i < height; i++)
			{
				for(j = 0; j < width; j++)
				{
					check.setPoint(i, j);

					if (newQuad.isInside(&check))
						newQuad.printColor(&(image[i][j]));
				}
			}
		}
		else
		{
			cout << "Shape type undetermined, program terminated." << endl;
			exit(1);
		}
	}

	printImage(outputFile, image, imageHead);

	// Close all files and destroy memory
	inputFile.close();
	outputFile.close();

	for (i = 0; i < height; i++)
		delete [] image[i];

	delete [] image;

	return 0;
}

static void printImage(ofstream&outFile, Color **image, Header& imageHead)
{
	int i, j;

	// Loop through colors in image array and print to the output file
	for (i = 0; i < imageHead.getHeight(); i++)
	{
		for (j = 0; j < imageHead.getWidth(); j++)
		{
			outFile << image[i][j].getRed()
					<< image[i][j].getGreen()
					<< image[i][j].getBlue();
		}
	}
}

static void printBackground(Color **image, Header& imageHead)
{
	int i, j;
	int height = imageHead.getHeight();
	int width = imageHead.getWidth();
	Color magenta(255, 0, 255);
	Color cyan(0, 255, 255);

	// Colors are given checkerboard background with magenta and cyan
	for (i = 0; i < imageHead.getHeight(); i++)
	{
		for (j = 0; j < imageHead.getWidth(); j++)
		{
			if (i < height / 2 && j < width / 2)
				image[i][j].setColor(magenta);
			else if (i > height / 2 && j >width / 2)
				image[i][j].setColor(magenta);
			else
				image[i][j].setColor(cyan);
		}
	}
}