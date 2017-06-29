/* guitardb.c
 * Christopher Brant
 * cbrant
 * ECE 2230
 * Section 001
 * Spring 2017
 * Programming Assignment #2
 * Due on 2/15/17 at 11:59 PM
 * Professor Walt Ligon
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "guitar.h"
#include "guitardb.h"

#define MAXLINE 5


/* Initialize a new guitar database */
guitardb_t guitardb_init(void)
{
	guitardb_t db_new = (guitardb_t)malloc(sizeof(struct guitardb_s));

	db_new->dbsize = 0;
	db_new->dblist = list_init();

	return db_new;
}

/* Add a guitar to the database */
key_t guitardb_add(guitardb_t dbpoint, guitar_t gpoint)
{
	char line[MAXLINE];
	int temp, slot_found;
	guitar_t match, rover;

	printf("\nEnter your desired item key number: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &temp);
	printf("\n");

	guitar_setid(gpoint, temp);
	match = (guitar_t)list_find(dbpoint->dblist, gpoint, (cmpfunc)guitar_compare);

	if (match != NULL)
		return -1;

	guitarfill(gpoint);

	if (dbpoint->dbsize == 0)
	{
		list_insert(dbpoint->dblist, gpoint);
		dbpoint->dbsize++;
	}

	else if (dbpoint->dbsize == 1)
	{
		rover = list_first(dbpoint->dblist);
		slot_found = guitar_compare(rover, gpoint);

		if (slot_found == -1)
		{
			list_insert_before(dbpoint->dblist, gpoint);
			dbpoint->dbsize++;
		}
		else 
		{
			list_append(dbpoint->dblist, gpoint);
			dbpoint->dbsize++;
		}
	}

	else
	{
		rover = list_first(dbpoint->dblist);
		
		while (rover != NULL && slot_found != 5)
		{
			slot_found = guitar_compare(rover, gpoint);

			if (slot_found == -1)
			{
				list_insert_before(dbpoint->dblist, gpoint);
				slot_found = 5;
				dbpoint->dbsize++;
			}
			else
				rover = list_next(dbpoint->dblist);
		}

		if (rover == NULL)
		{
			list_append(dbpoint->dblist, gpoint);
			dbpoint->dbsize++;
		}

		/*for (i = 0; i < dbpoint->dbsize; i++)
		{
			slot_found = guitar_compare(rover, gpoint);

			if (slot_found == 0)
			{
				list_insert_after(dbpoint->dblist, gpoint);
				dbpoint->dbsize++;
			}
			else if (slot_found == 1)
			{
				rover = list_next(dbpoint->dblist);
				slot_found = guitar_compare(rover, gpoint);

				if (slot_found == 0 || slot_found == -1)
				{
					list_insert_before(dbpoint->dblist, gpoint);
					dbpoint->dbsize++;
				}
				else
					rover = list_prev(dbpoint->dblist);
			}
			else if (slot_found == -1)
			{
				list_insert(dbpoint->dblist, gpoint);
				dbpoint->dbsize++;
			}

			rover = list_next(dbpoint->dblist);
		}*/
	}

	return 1;
}

/* Lookup a guitar by ID and return a pointer to it */
guitar_t guitardb_lookup(guitardb_t dbpoint, key_t keynum)
{
	guitar_t match_guitar;
	guitar_t test_guitar = (guitar_t)malloc(sizeof(struct guitar_s));

	guitar_setid(test_guitar, keynum);

	cmpfunc temp = (cmpfunc)guitar_compare;

	// Utilizes a callback function here
	match_guitar = (guitar_t)list_find(dbpoint->dblist, test_guitar, temp);

	free(test_guitar);

	return match_guitar;
}

// Delete a guitar from database, return pointer to it, do not free
guitar_t guitardb_delete(guitardb_t dbpoint, key_t keynum)
{
	guitar_t match_guitar = guitardb_lookup(dbpoint, keynum);

	list_remove(dbpoint->dblist);
	dbpoint->dbsize--;

	return match_guitar;
}

// Reports all of the guitars in the database with all info for each guitar
void guitardb_report(guitardb_t dbpoint)
{
	int i;

	guitar_t rover = list_first(dbpoint->dblist);

	for (i = 0; i < dbpoint->dbsize; i++)
	{
		guitar_print(rover);

		rover = list_next(dbpoint->dblist);
	}

}

/* Free all resources used by the guitar database.
   Remove everything from the linked list and free all pointers there 
   before finalizing the list */
void guitardb_finalize(guitardb_t dbpoint)
{
	// go through list and free each guitar
	// then finalize list
	list_finalize(dbpoint->dblist);

	// then free dbpoint here

}
