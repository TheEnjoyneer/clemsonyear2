/* event_queue.c
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 3/1/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "event_queue.h"

// Initialize and returns a pointer to new event queue
event_queue_t event_queue_init(int size)
{
	int i;
	event_queue_t eq = (event_queue_t)malloc(sizeof(struct event_queue_s));

	eq->limit = size;
	eq->tree_size = 0;
	eq->event_tree = (event_t *)malloc(size * sizeof(event_t));

	for (i = 0; i < size; i++)
		eq->event_tree[i] = NULL;

	return eq;
}

// Sorts the heap and inserts new event
static void heapify(event_queue_t eq, event_t ev)
{
	eq->tree_size++;
	int child_index = eq->tree_size;
	int parent_index = child_index / 2;
	
	while (parent_index != 0)
	{
		if (ev->event_time >= eq->event_tree[parent_index]->event_time)
		{
			eq->event_tree[child_index] = ev;
			return;
		}
		else
		{
			eq->event_tree[child_index] = eq->event_tree[parent_index];
			child_index = parent_index;
			parent_index = parent_index / 2;
		}
	}

	// Put item in final location
	eq->event_tree[child_index] = ev;
}

// Inserts new event into the heap
int event_queue_insert(event_queue_t eq, event_t ev)
{
	int full, empty, inserted;

	full = event_queue_full(eq);
	empty = event_queue_empty(eq);

	if (full == 1)
		inserted = 0;
	else if (empty == 1)
	{
		eq->tree_size++;
		eq->event_tree[1] = ev;
		inserted = 1;
	}
	else
	{
		heapify(eq, ev);
		inserted = 1;
	}

	return inserted;
}

// Come back here to reheapify shortly

// Sorts the heap after event was removed
static void reheapify(event_queue_t eq)
{
	int current_index = 1;
	int child_index = 2 * current_index;
	event_t ev = eq->event_tree[eq->tree_size];
	eq->event_tree[eq->tree_size] = NULL;
	eq->tree_size--;

	if (event_queue_empty(eq) != 1)
	{
		while (child_index <= eq->tree_size)
		{
			if (child_index < eq->tree_size)
			{
				double r_child = eq->event_tree[child_index+1]->event_time;
				double l_child = eq->event_tree[child_index]->event_time;

				if (r_child < l_child)
					child_index++;
			}

			if (eq->event_tree[child_index]->event_time >= ev->event_time)
				break;
			else
			{
				eq->event_tree[current_index] = eq->event_tree[child_index];
				current_index = child_index;
				child_index = 2 * current_index;
			}
		}

		eq->event_tree[current_index] = ev;
	}
}

// Removes and returns top value from the priority queue
event_t event_queue_remove(event_queue_t eq)
{
	int empty = event_queue_empty(eq);
	event_t removed;

	if (empty == 1)
		removed = NULL;
	else
	{
		removed = eq->event_tree[1];
		reheapify(eq);
	}

	return removed;
}

// Returns 1 if eq is empty, 0 otherwise
int event_queue_empty(event_queue_t eq)
{
	int empty;

	if (eq->tree_size == 0)
		empty = 1;
	else
		empty = 0;

	return empty;
}

// Returns 1 if eq is full, 0 otherwise
int event_queue_full(event_queue_t eq)
{
	int full;

	if (eq->tree_size == eq->limit)
		full = 1;
	else
		full = 0;

	return full;
}

// Frees and nulls all memory malloced for the eq
void event_queue_finalize(event_queue_t eq)
{
	int i;

	for (i = 0; i < eq->tree_size; i++)
	{
		free(eq->event_tree[i]);
		eq->event_tree[i] = NULL;
	}

	free(eq->event_tree);
	eq->event_tree = NULL;

	free(eq);
	eq = NULL;
}