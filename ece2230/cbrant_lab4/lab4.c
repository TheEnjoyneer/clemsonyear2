/* lab4.c
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 4/28/17 at 11:59 PM
 */

#include "lab4.h"

// Each of these should always be magnitudes of 10 * an integer
#define MAXITEMS 1000000
#define COLLISIONCONSTANT 1

int main(void)
{
	int i, table_size;

	/* Arbitrarily make table_size smaller than MAXITEMS
 	   so that there are more collisions to test how well
 	   our collision fix method works. */
	table_size = MAXITEMS / COLLISIONCONSTANT;

	clock_t start, end;

	double insert_time, find_time, remove_time;

	table_t hash_table = Table_new(table_size);

	int *keynums = (int *)malloc(sizeof(int) * MAXITEMS * 5);

	for (i = 0; i < (MAXITEMS * 5); i++)
		keynums[i] = 0;

	srand(time(NULL));

	// Start timer for remove time
	start = clock();

	/* Randomizes key and random data values and then inserts or 
	   updates the values in the table if the key value is repeated. */
	for (i = 0; i < MAXITEMS; i++)
	{
		itemptr newitem = (itemptr)malloc(sizeof(struct item_type));

		if (i == 0)
			newitem->key = 13;
		else if (i == 1)
			newitem->key = 33;
		else if (i == 2)
			newitem->key = 13;
		else
			newitem->key = rand() % (5 * MAXITEMS);

		keynums[newitem->key] += 1;

		newitem->data_val = (rand() % MAXITEMS) + (MAXITEMS / 5);

		if (keynums[newitem->key] == 1)
			Table_insert(hash_table, newitem->key, newitem);
		else
		{
			itemptr removed = Table_find(hash_table, newitem->key);

			if (removed != NULL)
			{
				Table_update(hash_table, newitem->key, newitem);
				free(removed);
			}
		}
	}

	end = clock();

	// Calculate insert time
	insert_time = (double)(end - start) / CLOCKS_PER_SEC;

	// Start timer for find time
	start = clock();

	/* Random keys are generated just like in the insert section,
	   except that here they are just found or not.
	   It doesn't matter if they are found, it only matters how long
	   the find function takes.  As the find function obviouisly works
	   as it is called in the Table_remove and Table_update functions
	   and it works in those calls. */
	for (i = 0; i < MAXITEMS; i++)
	{
		int remove_key = rand() % (5 * MAXITEMS);

		Table_find(hash_table, remove_key);
	}

	end = clock();

	find_time = (double)(end - start) / CLOCKS_PER_SEC;

	// Start timer for remove time
	start = clock();

	/* Remove runs through all possible key numbers,
	   which is why it will take the most time overall,
	   regardless of its complexity class. */
	for (i = 0; i <= (MAXITEMS * 5); i++)
	{
		data_t rover = Table_remove(hash_table, i);

		if (rover != NULL)
			free(rover);
	}

	end = clock();

	// Calculate remove time
	remove_time = (double)(end - start) / CLOCKS_PER_SEC;

	free(keynums);
	Table_free(hash_table);

	// Print statistics
	printf("Insert time was %.6f seconds for %d items.\n", insert_time, MAXITEMS);
	printf("Find time was %.6f seconds for %d items.\n", find_time, MAXITEMS);
	printf("Remove time was %.6f seconds for %d items.\n", remove_time, MAXITEMS);
	printf("Collision constant is %d.\n", COLLISIONCONSTANT);

	return 0;
}

// Key compare function to pass into list_find as compare function
int key_compare(itemptr rover, itemptr findme)
{
	int match;

	if (rover == NULL)
		return -1;

	// Key value is held in the first 
	if (rover->key == findme->key)
		match = 0;
	else if (rover->key > findme->key)
		match = -1;
	else if (rover->key < findme->key)
		match = 1;

	return match;
}