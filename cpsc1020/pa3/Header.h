/* Header.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #3
 * Due 4/14/17 at 11:59 PM
 */

#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <fstream>
using namespace std;


class Header
{
  private:
  	string magicNum;
  	int width;
  	int height;
  	int maxVal;
    
  public:
  	// Constructors
  	Header();
  	Header(string magic, int w, int h, int max);

  	// Setters
  	void setMagicNum(string magic);
  	void setWidth(int w);
  	void setHeight(int h);
  	void setMaxVal(int max);
  	void printHead(ofstream &outFile);

    // Getters
    int getWidth(void);
    int getHeight(void);

  	// Destructor
  	~Header();
};

#endif
