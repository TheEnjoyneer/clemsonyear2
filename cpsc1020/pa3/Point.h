/* Point.h
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#ifndef POINT_H
#define POINT_H

class Point
{
    private:
    	double x;
    	double y;
    
    public:
    	// Constructors
    	Point();
    	Point(double x1, double x2);

    	// Setter
    	void setPoint(double x1, double x2);

    	// Getters
    	double getX(void);
    	double getY(void);

    	// Destructor
    	~Point();
};

#endif
