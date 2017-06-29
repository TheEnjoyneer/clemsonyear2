/* guitar.h
 * Christopher Brant
 * cbrant
 * ECE 2230
 * Section 001
 * Spring 2017
 * Programming Assignment #2
 * Due on 2/15/17 at 11:59 PM
 * Professor Walt Ligon
 */

#ifndef GUITAR_H

typedef int key_t;

typedef enum guitartype_e {
	S = 'S' /* solid body */,
	A = 'A' /* arch-top hollow body*/,
	T = 'T' /* semi-hollow (thinline) */
} guitartype_t;

typedef enum pickup_e {
	H = 'H' /* humbucker */,
	C = 'C' /* single coil */,
	P = 'P' /* P90 */,
	F = 'F' /* Filtertron */,
	N = 'N' /* none */
} pickup_t;

typedef struct guitar_s {
	key_t id_number;
	char make[20];
	char model[20];
	char submodel[15];
	guitartype_t gtype;
	int year;		/* year of manufacture */
	char finish[25];/* description of finish including color, binding, etc. */
	int strings;	/* number of strings - usually 6 or 7 */
	int pickups;	/* number of pickups */
	pickup_t neck; 	/* pickup type */
	pickup_t middle;/* pickup type */
	pickup_t bridge;/* pickup type */
} *guitar_t;

/* Allocate a new struct guitar_s and return a pointer to it */
guitar_t guitar_init(void);

/* Read from user all fields for a guitardb_guitar */
int guitarfill(guitar_t gpoint);

/* Set the ID of a guitardb_guitar */
key_t guitar_setid(guitar_t gpoint, key_t keynum);

/* Get the ID of a guitardb_guitar */
key_t guitar_getid(guitar_t gpoint);

/* Prints a guitar */
void guitar_print(guitar_t gpoint);

/* Returns 0 if equal, <0 if less than, >0 if greater than*/
int guitar_compare(guitar_t dbcursor, guitar_t findme);

/* Frees a guitar from memory */
void guitar_free(guitar_t gpoint);

#endif