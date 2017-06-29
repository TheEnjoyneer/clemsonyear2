/* inventory.h
 * Christopher Brant
 * cbrant
 * ECE 2230
 * Section 001
 * Spring 2017
 * Programming Assignment #1
 * Due on 1/23/17 at 11:30 PM
 * Professor Walt Ligon
*/

#define ISIZE 100

// Structure definitions
struct inventory_item {
	int item_key;
	int item_type;
	char description[15];
	float power;
	int modifier;
};

struct inventory {
	int cursor;
	struct inventory_item *slot[ISIZE];

};

// Function prototypes
struct inventory *inventory_create();
int inventory_add(struct inventory *inv, struct inventory_item *invitem);
struct inventory_item *inventory_lookup(struct inventory *inv, int key);
int inventory_delete(struct inventory *inv, int key);
struct inventory_item *inventory_first(struct inventory *inv);
struct inventory_item *inventory_next(struct inventory *inv);
int inventory_destroy(struct inventory *inv);

