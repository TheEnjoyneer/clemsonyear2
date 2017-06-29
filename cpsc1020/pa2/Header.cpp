/* Header.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#include "Header.h"

// Default Constructor
Header::Header()
{
	// Set default magicNum
	magicNum = "P6";

	// Set default width height, and maxVal
	width = 0;
	height = 0;
	maxVal = 255;
}

// Not necessary, but included regardless
Header::Header(string magic, int w, int h, int max)
{
	magicNum = magic;
	width = w;
	height = h;
	maxVal = max;
}

// The following 4 functions set specific values
void Header::setMagicNum(string magic)
{
	magicNum = magic;
}

void Header::setWidth(int w)
{
	width = w;
}

void Header::setHeight(int h)
{
	height = h;
}

void Header::setMaxVal(int max)
{
	maxVal = max;
}

// Prints header to output file
void Header::printHead(ofstream &outFile)
{
	outFile << magicNum << endl
			<< width << " "
			<< height << " "
			<< maxVal << endl;
}

Header::~Header()
{
	// Not really necessary either
}