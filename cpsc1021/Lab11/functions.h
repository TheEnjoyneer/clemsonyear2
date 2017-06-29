/* functions.h
 * Christopher Brant
 * cbrant
 * Lab 11
 * Lab Section 002
 * Lauren Fuller
 * 4/11/17
 */

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &vec, int vec_size);
void selection_sort(vector<int> &vec, int vec_size);
int  linear_search(vector<int> &vec, int vec_size, int search_item);

#endif
