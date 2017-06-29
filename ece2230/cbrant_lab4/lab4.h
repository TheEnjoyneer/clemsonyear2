/* lab4.h
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 4/28/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LAB4_H
#define LAB4_H

#include "table.h"

typedef struct item_type {
	int key;
	int data_val;
} *itemptr;

// Key compare function to pass into list_find as compare function
int key_compare(itemptr rover, itemptr findme);

#endif
