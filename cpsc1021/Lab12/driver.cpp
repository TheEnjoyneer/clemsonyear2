/* driver.cpp
 * Christopher Brant
 * cbrant
 * Lab 12
 * Lab Section 002
 * Lauren Fuller
 * 4/18/17
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
    //create a file pointer
    ifstream inputFile;

    // Using the command line arguments check for a valid input file
    // If there is not one, give the user a message and exit the program
    if (argc != 2)
    {
        cout << "Not enough command line arguments to run this program."
             << endl;
        exit(1);
    }
    else 
    {
        inputFile.open(argv[1]);

        if (!inputFile.is_open())
        {
            cout << "Error, input file could not be opened." << endl;
            exit(1);
        }
    }

    /* Read items into a vector to then dynamically allocate
       space for an array to pass between functions.*/

    vector<int> input;
    int temp, size, i;

    while (!inputFile.eof())
    {
        inputFile >> temp;
        input.push_back(temp);
    }

    /*Dynamically allocate the memory for the array that is going to
      hold the numbers be read in, and get the size array needs to be.*/
    size = input.size();

    int *array = new int[size];

    /*Read in the numbers from the input vector storing them in array*/

    for (i = 0; i < size; i++)
        array[i] = input.at(i);

    /* Close the file you are reading.*/
    inputFile.close();

    /*Print the array to make sure you read in all the values correctly*/
    print_array(array, size);

    /*Using the quicksort function sort the array.*/
    quickSort(array, 0, size - 1);

    /*Now Print the sorted array to make sure it is sorted*/
    print_array(array, size);

    /*To test the binary search algorithm ask the user for a number.
     *Call the binary search function.  If the number was found tell the
     *user you found the number and at what index it was found.*/
    cout << "Please enter an integer value: ";
    cin >> temp;

    int found = binarySearch(array, 0, size - 1, temp);

    if (found == -1)
        cout << endl << "Value, " << temp << ", was not found." << endl;
    else
    {
        cout << endl << "Value, " << temp
             << ", was found at index "
             << found << "." << endl << endl;
    }

    // Delete dynamically allocated array
    delete [] array;

    return 0;
}
