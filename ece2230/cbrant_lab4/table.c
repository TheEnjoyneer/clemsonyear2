/* table.c
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 4/28/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "lab4.h"

// Hash table function
static int hash(key_t key, int table_size);

// Struct table definition
struct table {
	int size;
	list_t *table_array;
};

// Initializes the hash table
table_t Table_new(int table_size)
{
	int i;

	table_t new_table = (table_t)malloc(sizeof(struct table));

	new_table->size = table_size + 1;

	new_table->table_array = (list_t *)malloc(sizeof(list_t) * (new_table->size));

	// Goes <= so that there are no array boundary errors
	for (i = 0; i < new_table->size; i++)
		new_table->table_array[i] = list_init();

	return new_table;
}

// Inserts item with given info into the hash table
int Table_insert(table_t tableptr, key_t key, data_t dptr)
{
	int success;

	// Hash function to determine the slot for the given key
	int hash_val = hash(key, tableptr->size);
	list_t hash_slot = tableptr->table_array[hash_val];

	// Insert item into the list at the hash value index in the table_array
	success = list_append(hash_slot, dptr);

	return success;
}

// Finds an item based on key and returns data for that key
data_t Table_find(table_t tableptr, key_t key)
{
	data_t found;
	struct item_type searchfor;
	searchfor.key = key;
	cmpfunc temp = (cmpfunc)key_compare;

	// Find hash_val to reference
	int hash_val = hash(key, tableptr->size);
	list_t hash_slot = tableptr->table_array[hash_val];

	if (hash_slot->current == NULL)
		return NULL;

	// Run list_find to find key value
	found = list_find(hash_slot, &searchfor, temp);

	return found;
}

// Updates item data in given place
/* For the purposes of this assignment, the data pointer points to
   the address of the beginning of an array of 2 integers.
   The first integer being the key value, and the second is a random
   data value.
*/
int Table_update(table_t tableptr, key_t key, data_t dptr)
{
	int hash_val = hash(key, tableptr->size);
	list_t hash_slot = tableptr->table_array[hash_val];

	// Call Table_find to set the current item
	data_t found = Table_find(tableptr, key);

	if (found == NULL)
		return -1;

	// Insert new value into hash table with same key value
	list_append(hash_slot, dptr);

	// Then re-search and remove first instance
	found = Table_remove(tableptr, key);

	if (found == NULL)
		return -1;
	else
		return 0;
}

// Removes and returns a single item from the table
data_t Table_remove(table_t tableptr, key_t key)
{
	data_t found;
	struct item_type searchfor;
	searchfor.key = key;
	cmpfunc temp = (cmpfunc)key_compare;

	// Find hash_val to reference
	int hash_val = hash(key, tableptr->size);
	list_t hash_slot = tableptr->table_array[hash_val];

	// Run list_find to find key value
	found = list_find(hash_slot, &searchfor, temp);

	if (found == NULL)
		return found;
	else
	{
		list_remove(hash_slot);
		return found;
	}
}

// Frees the entire table
void Table_free(table_t tableptr)  /* possibly unnecessary to be a double pointer */
{
	int i;

	for (i = 0; i < tableptr->size; i++)
		list_finalize(tableptr->table_array[i]);

	free(tableptr->table_array);
	free(tableptr);
}

// Hash function definition
static int hash(key_t key, int table_size)
{
	return (key % table_size);	
}


