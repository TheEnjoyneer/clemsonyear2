/* guitardb.h
 * Christopher Brant
 * cbrant
 * ECE 2230
 * Section 001
 * Spring 2017
 * Programming Assignment #2
 * Due on 2/15/17 at 11:59 PM
 * Professor Walt Ligon
 */

#ifndef GUITARDB_H

typedef struct guitardb_s {
	int dbsize;
	list_t dblist;
} *guitardb_t;

/* Initialize a new guitar database */
guitardb_t guitardb_init(void);

/* Add a guitar to the database */
key_t guitardb_add(guitardb_t dbpoint, guitar_t gpoint);

/* Lookup a guitar by ID and return a pointer to it */
guitar_t guitardb_lookup(guitardb_t dbpoint, key_t keynum);

/* Delete a guitar from database, return pointer to it, do not free */
guitar_t guitardb_delete(guitardb_t dbpoint, key_t keynum);

/* Reports all of the guitars in the database with all info for each guitar */
void guitardb_report(guitardb_t dbpoint);

/* Free all resources used by the guitar database.
   Remove everything from the linked list and free all pointers there 
   before finalizing the list */
void guitardb_finalize(guitardb_t dbpoint);

#endif