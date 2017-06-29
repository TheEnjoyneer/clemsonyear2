/* disk_queue.c
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 3/1/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "disk_queue.h"

// Initialize and construct disk queue
disk_queue_t disk_queue_init(void)
{
	disk_queue_t dq = (disk_queue_t)malloc(sizeof(struct disk_queue_s));

	dq->dq_size = 0;
	dq->dq_list = list_init();

	return dq;
}

// Insert new disk into the FIFO disk queue
int disk_queue_insert(disk_queue_t dq, request_t req)
{
	int success = list_append(dq->dq_list, req);
	dq->dq_size++;

	return success;
}

// Peek at first item in disk queue
request_t disk_queue_peek(disk_queue_t dq)
{
	request_t peek = list_first(dq->dq_list);
	return peek;
}

// Remove and return first item from the disk queue
request_t disk_queue_remove(disk_queue_t dq)
{
	request_t removed = list_first(dq->dq_list);
	list_remove(dq->dq_list);
	dq->dq_size--;

	return removed;
}

// Returns 1 if dq is empty, and 0 otherwise
int disk_queue_empty(disk_queue_t dq)
{
	int empty;

	if (dq->dq_size == 0)
		empty = 1;
	else
		empty = 0;

	return empty;
}

// Frees and nulls out all memory
void disk_queue_finalize(disk_queue_t dq)
{
	list_finalize(dq->dq_list);
	free(dq);
	dq = NULL;
}