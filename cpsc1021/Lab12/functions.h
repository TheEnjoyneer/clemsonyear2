/* functions.h
 * Christopher Brant
 * cbrant
 * Lab 12
 * Lab Section 002
 * Lauren Fuller
 * 4/18/17
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstdlib>

void print_array(int array[], int array_size);
void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);
int binarySearch(const int array[], int first, int last, int value);


#endif
