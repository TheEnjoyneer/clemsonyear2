/* driver.cpp
 * Christopher Brant
 * cbrant
 * CPSC 1020 Sec 002 Sp17
 * Yvon Feaster
 * Programming Assignment #2
 * Due 3/19/17 at 11:59 PM
 */

#include <iostream>
#include <cstdlib>
#include "Image.h"
using namespace std;

// Static function for testing if point is inside the triangle
static bool testPoint(Point *triangle, Point *test);

/*The prototype for the client function that determines if the given
 *point is within the parameter of the trianle*/
int main(int argc, char *argv[])
{
    ofstream outPut(argv[2]);
    ifstream inPut(argv[1]);
    
    /*Create an instance of the Image class and Point to represent 
     *the three points that defines the triangle.  Also put other 
     *variables needed here.*/
    
    // Default vals for maxVal and magicNum
    string mNum = "P6";             // Set default magicnum to pass in
    int i, j, maxVal = 255;         // Set default maxVal to pass in
    bool isInside;                  // Boolean for return val when testing

    Image picture;                  // Image instance
    Point test, triangle[3];        // Point instances for test point
                                    // and an array of 3 for the triangle
    int width, height;              // Ints to hold width and height
    double x1, y1, x2, y2, x3, y3;  // Doubles to read in triangle vertices
      
    if(argc != 3)
    {
        cout << "USAGE ERROR:  ./executable outPutFileName";
        exit(EXIT_FAILURE);
    }
    if(inPut.fail())
    {
        cout << argv[1] << " did not open successfully\n";
    }

    if(outPut.fail())
    {
        cout << argv[2] << " did not open successfully\n";
    }
      
    /*read the data from the input file here*/
    inPut >> width >> height;
    
    inPut >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    // Once read in, set the vertices of the triangle
    // into the triangle Point array
    triangle[0].setPoint(x1, y1);
    triangle[1].setPoint(x2, y2);
    triangle[2].setPoint(x3, y3);
      
    /*Using the instance of image created above call the function
     *to set the width and height for the header.  Using the 
     *instance of image call the funtion used to print the header*/

    picture.setHeader(mNum, width, height, maxVal);
    picture.printHeader(outPut);
      
    /*using nested for loops call the client function to test if
     *the given point is within the parameters of the triangle.  
     *Using the instance of image set the color of the pixels RGB
     *channels and then call the function to print the Pixel to 
     *the output file.*/

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // Set the test point
            test.setPoint(static_cast<double>(j), static_cast<double>(i));

            // Test actual point
            isInside = testPoint(triangle, &test);

            // Set pixel values based on if the pixel is inside the triangle
            picture.setPixel(isInside);
            picture.printOut(outPut);
        }
    }

    // Finalize files by closing them
    inPut.close();
    outPut.close();

    return 0;
}

/*Implement the function that determines if a given point is 
 *within the parameter of the triangle*/

// Function from Lab 4 to test if a point is inside a triangle 
static bool testPoint(Point *triangle, Point *test)
{
    double a, b, c, a1, a2, b1, b2;
    bool check = 0;

    // a  and b are split into the dividend and divisor for formatting choices
    a1 = (triangle[1].getY()-triangle[2].getY()) *
         (test->getX()-triangle[2].getX()) +
         (triangle[2].getX()-triangle[1].getX()) *
         (test->getY()-triangle[2].getY());

    a2 = (triangle[1].getY()-triangle[2].getY()) *
         (triangle[0].getX()-triangle[2].getX()) +
         (triangle[2].getX()-triangle[1].getX()) *
         (triangle[0].getY()-triangle[2].getY());

    b1 = (triangle[2].getY()-triangle[0].getY()) *
         (test->getX()-triangle[2].getX()) +
         (triangle[0].getX()-triangle[2].getX()) *
         (test->getY()-triangle[2].getY());
    b2 = a2;

    // Calculate a, b, and c values
    a = a1 / a2;
    b = b1 / b2;
    c = 1 - a - b;

    // Test for validity of the point
    if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
        check = 1;

    return check;
}