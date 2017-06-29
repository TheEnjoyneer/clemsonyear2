/* functions.cpp
 * Christopher Brant
 * cbrant
 * Lab 11
 * Lab Section 002
 * Lauren Fuller
 * 4/11/17
 */

#include "functions.h"

void print_array(vector<int> &vec, int vec_size)
{
	int i; 
	cout << endl;

	// Iterate and print items
	for (i = 0; i < vec_size; i++)
		cout << "Item " << i << ": " << vec.at(i) << endl;	
}

void selection_sort(vector<int> &vec, int vec_size)
{
	int i, j, temp;

	// Typical selection sort algorithm
	for (i = 0; i < vec_size - 1; i++)
	{
		for (j = i + 1; j < vec_size; j++)
		{
			if (vec.at(j) < vec.at(i))
			{
				temp = vec.at(j);
				vec.at(j) = vec.at(i);
				vec.at(i) = temp;
			}
		}
	}
}

int linear_search(vector<int> &vec, int vec_size, int search_item)
{
	int i = 0;

	// If vector is of size 0 immediately return -1
	if (vec_size == 0)
		return -1;

	// Search until end of vector or item is found
	while (i < vec_size && vec.at(i) != search_item)
		i++;

	// If it reaches the end of the vector without matching
	// return -1
	if (i == vec_size)
		return -1;

	return i;
}
