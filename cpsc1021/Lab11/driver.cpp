/* driver.cpp
 * Christopher Brant
 * cbrant
 * Lab 11
 * Lab Section 002
 * Lauren Fuller
 * 4/11/17
 */

#include <fstream>
#include <cstdlib>
#include "functions.h"

int main(int argc, char* argv[])
{
    int temp, found;
    ifstream inputFile;

    // Using the command line arguments check for a valid input file
    // If there is not one, give the user a message and exit the program
    
    if (argc != 2)
    {
        cout << "Error, incorrect number of input files. #GitGud" << endl;
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

    // Declare vector and start reading in the input values.

    vector<int> inValues;

    // Read the other items from the file and store them

    inputFile >> temp;

    while (!inputFile.eof())
    {
        inValues.push_back(temp);

        inputFile >> temp;
    }

    // Close the file you are reading

    inputFile.close();

    // Then print the array

    print_array(inValues, inValues.size());

    // Using selection sort, sort the array
    // Then print the array

    selection_sort(inValues, inValues.size());

    print_array(inValues, inValues.size());

    // Ask the user for a number

    cout << endl << "Enter an integer: ";
    cin >> temp;

    // Using linear search, search the array for the user's number

    found = linear_search(inValues, inValues.size(), temp);

    // Print if the number was or was not found in the array
    
    if (found == -1)
        cout << endl << temp << " was not found." << endl;
    else 
        cout << endl << temp << " was found at index "
             << found << "." << endl;

    return 0;
}
