/* Image.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#include "Image.h"

Image::Image()
{
	// Not really necessary here
}

// Likely cut this here out
Image::Image(Pixel pix, Header head)
{
	// Not really necessary here
}

// Set header values
void Image::setHeader(string mNum, int w, int h, int max)
{
	imageHeader.setMagicNum(mNum);
	imageHeader.setWidth(w);
	imageHeader.setHeight(h);
	imageHeader.setMaxVal(max);
}

// Prints header to outfile
void Image::printHeader(ofstream &outFile)
{
	imageHeader.printHead(outFile);
}

// Prints pixel to outfile
void Image::printOut(ofstream &outFile)
{
	imagePixel.printPixel(outFile);
}

// Set specific pixel's rgb values
void Image::setPixelRGB(unsigned char r, unsigned char g, unsigned char b)
{
	imagePixel.setRGB(r, g, b);
}

// Set pixel's rgb values based on location of pixel
void Image::setPixel(bool isInside)
{
	imagePixel.chooseColor(isInside);
}