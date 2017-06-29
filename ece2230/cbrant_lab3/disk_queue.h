/* disk_queue.h
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 3/1/17 at 11:59 PM
 */

#include "list.h"

#ifndef DISK_QUEUE_H

typedef struct disk_queue_s {
	int dq_size;
	list_t dq_list;
} *disk_queue_t;

typedef struct request_s {
	int track;
	double arrival_time;
	double start_time;
	double finish_time;
} *request_t;

disk_queue_t disk_queue_init(void);

int disk_queue_insert(disk_queue_t dq, request_t req);

request_t disk_queue_peek(disk_queue_t dq);

request_t disk_queue_remove(disk_queue_t dq);

int disk_queue_empty(disk_queue_t dq);

void disk_queue_finalize(disk_queue_t dq);

#endif