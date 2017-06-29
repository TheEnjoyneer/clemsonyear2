/* functions.cpp
 * Christopher Brant
 * cbrant
 * Lab 12
 * Lab Section 002
 * Lauren Fuller
 * 4/18/17
 */

#include "functions.h"
using namespace std;

/*********************************************
 *This function should print each element in *
 *the array.                                 *
 *********************************************/
void print_array(int array[], int array_size)
{
    int i;

    for (i = 0; i < array_size; i++)
    {
        cout << "Item " << setw(2) << i << ": " 
             << setw(3) << array[i] << endl;
    }

    // Added for clearer output to stdin
    cout << endl;
}

//************************************************
// quickSort uses the quickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
// This is a recursive algorithm                 *
//************************************************
void quickSort(int array[], int start, int end)
{
    int i = partition(array, start, end);

    if (start < i - 1)
        quickSort(array, start, i - 1);

    if (end > i)
        quickSort(array, i, end);
}


//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end)
{
    /*Create two variables --
     *1 that is equal to the element of arr at [start]     *
     *2 that is the position of the pivot                  */
    int pivotVal = arr[(start + end) / 2];
    int i = start;
    int j = end;
    int temp;


    // Rearrange the rest of the array elements to
    // partition the subrange from start to end

    while (i <= j)
    {
            // arr[scan] is the "current" item.
            // Swap the current item with the item to the
            // right of the pivot element
        while (arr[i] < pivotVal)
            i++;

        while (arr[j] > pivotVal)
            j--;

            // Swap the current item with the pivot element

        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } 
    
    //return the position of the pivot
    return i;
}

//**********************************************************
// The binarySearch function performs a recursive binary   *
// search on a range of elements of an integer array. The  *
// parameter first holds the subscript of the range's      *
// starting element, and last holds the subscript of the   *
// ranges's last element. The parameter value holds the    *
// the search value. If the search value is found, its     *
// array subscript is returned. Otherwise, -1 is returned  *
// indicating the value was not in the array.              *
//**********************************************************
int binarySearch(const int array[], int first, int last, int value)
{
    // Mid point of search
    int mid = (first + last) / 2;

    // Base case 
    if (first > last)
        return -1;
    // Recursive cases
    if (array[mid] == value)
        return mid;
    else if (array[mid] > value)
        return binarySearch(array, first, mid - 1, value);
    else if (array[mid] < value)
        return binarySearch(array, mid + 1, last, value);

    // If nothing is found at all.
    return -1;
}
