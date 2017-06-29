/* Color.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#ifndef COLOR_H
#define COLOR_H

class Color
{
  private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;    

  public:
  	// Constructors
  	Color();
  	Color(unsigned char r, unsigned char g, unsigned char b);

  	// Setter
    void setColor(Color copy);
  	void setColor(unsigned char r, unsigned char g, unsigned char b);

  	// Getters
  	unsigned char getRed(void);
  	unsigned char getGreen(void);
  	unsigned char getBlue(void);

  	// Destructor
  	~Color();
};

#endif
