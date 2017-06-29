/* Pixel.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#ifndef PIXEL_H
#define PIXEL_H
#include "Color.h"
#include "Point.h"
#include <fstream>
using namespace std;


class Pixel
{
  private:
  	Color pixel_color;
  	Point coordinates;
   
  public:
  	// Constructors
  	Pixel();
  	Pixel(Color color_choice, Point xy);

  	// Setters
  	void chooseColor(bool isInside);
  	void setRGB(unsigned char R, unsigned char G, unsigned char B);
  	void printPixel(ofstream &outFile);

  	// Not specified but why isn't it needed
  	void setCoord(double X1, double X2);

  	// Destructor
  	~Pixel();
};

#endif
