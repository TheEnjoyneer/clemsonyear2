/* list.h
 * Christopher Brant
 * cbrant
 * ECE 2230
 * Section 001
 * Spring 2017
 * Professor Walt Ligon
 */

#ifndef LIST_H
#define LIST_H

typedef void *data_t;

struct list_node {
	struct list_node *head;
	struct list_node *tail;
	data_t node_info;
};

struct list {
	int list_size;
	struct list_node *current;
	struct list_node *top;
	struct list_node *bottom;
};

typedef struct list *list_t;

typedef int (*cmpfunc)(data_t dp1, data_t dp2);

/* Create a new empty list */
list_t list_init(void);

/* Insert at head of list */
int list_insert(list_t lpoint, data_t dpoint);

/* Append to tail of list */
int list_append(list_t lpoint, data_t dpoint);

/* Find and sets current item using callback compare function */
data_t list_find(list_t lpoint, data_t dpoint, cmpfunc cmp);

/* Return item at head of list, set current item */
data_t list_first(list_t lpoint);

/* Return next item after current item */
data_t list_next(list_t lpoint);

/* Return prev item before current item */
data_t list_prev(list_t lpoint);

/* Return item at tail of list, set current item */
data_t list_last(list_t lpoint);

/* Insert item before current item */
int list_insert_before(list_t lpoint, data_t dpoint);

/* Insert item after current item */
int list_insert_after(list_t lpoint, data_t dpoint);

/* Remove current item */
int list_remove(list_t lpoint);

/* Free all resources allocated by the list */
int list_finalize(list_t lpoint);

#endif