/* event_queue.h
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 3/1/17 at 11:59 PM
 */

#include "disk_queue.h"

#ifndef EVENT_QUEUE_H

typedef enum events_e {
	REQ_SUB = 1,
	DISK_RDY = 2,
	REQ_DONE = 3
} events_t;

/*typedef struct request_s {
	int track;
	double arrival_time;
	double start_time;
	double finish_time;
} *request_t;*/

typedef struct event_s {
	events_t event_type;
	double event_time;
	request_t request;	// Declared as void pointer 
					// because request_t created #include problems
} *event_t;

typedef struct event_queue_s {
	int limit;
	int tree_size;
	event_t *event_tree;
} *event_queue_t;

event_queue_t event_queue_init(int size);

int event_queue_insert(event_queue_t eq, event_t ev);

event_t event_queue_remove(event_queue_t eq);

int event_queue_empty(event_queue_t eq);

int event_queue_full(event_queue_t eq);

void event_queue_finalize(event_queue_t eq);

#endif