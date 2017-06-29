/* color.h
 * Christopher Brant
 * cbrant
 * Lab 7
 * Section 002
 * Lauren Fuller
 */

#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <cstdlib>


using namespace std;


class Color
{
  private:

    unsigned char red;
    unsigned char green;
    unsigned char blue;

  public:

    Color(unsigned char, unsigned char, unsigned char);
    Color();

    void setRed(unsigned char );
    void setGreen(unsigned char);
    void setBlue(unsigned char);

    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();

};

#endif