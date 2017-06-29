/* Image.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#ifndef IMAGE_H
#define IMAGE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdbool.h>
#include "Pixel.h"
#include "Header.h"

class Image
{
  private:
  	Pixel imagePixel;
  	Header imageHeader;   

  public:
  	// Constructors
  	Image();
  	Image(Pixel pix, Header head);

  	// Setters
  	void setHeader(string mNum, int w, int h, int max);
  	void printHeader(ofstream &outFile);
  	void printOut(ofstream &outFile);
  	void setPixelRGB(unsigned char r, unsigned char g, unsigned char b);
  	void setPixel(bool isInside);
};

#endif
