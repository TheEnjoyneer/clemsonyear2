/* lab3.c
 * Christopher Brant
 * cbrant
 * ECE 2230 Sec 001
 * Professor Walt Ligon
 * Due 3/1/17 at 11:59 PM
 */

#include <stdio.h>
#include <stdlib.h>

// disk_queue.h was included in event_queue.h
// so that the request_t type would be defined
// when it was referenced there
//#include "disk_queue.h"
#include "event_queue.h"
#include "disk.h"
#include "randsim.h"

#define NUM_EVENTS 1000000
#define ARRAY_EVENTS 1000000

// Ask if it's okay to typedef this here
typedef struct stats_s {
	double min_time;
	double max_time;
	double avg_time;
} *stats_t;

static void stats_constructor(stats_t times);
static event_t req_sub_create(double sched_time);
static void request_submit(disk_queue_t dq, event_queue_t eq, event_t curr_ev, double curr_time);
static void disk_ready(disk_queue_t dq, event_queue_t eq, int *track_ptr, double curr_time);
static void request_done(disk_queue_t dq, event_queue_t eq, stats_t q_time,
						 stats_t IO_time, stats_t tot_time, double curr_time);
static void printStats(stats_t queue_time, stats_t IO_time, stats_t total_req);

int main(void)
{
	int empty, full, curr_track = 0;
	double global_time = 0;
	stats_t q_time, io_time, tot_time;

	// Malloc space for statistics
	q_time = (stats_t)malloc(sizeof(struct stats_s));
	io_time = (stats_t)malloc(sizeof(struct stats_s));
	tot_time = (stats_t)malloc(sizeof(struct stats_s));

	// Construct initial statistics
	stats_constructor(q_time);
	stats_constructor(io_time);
	stats_constructor(tot_time);

	// Initialize both the FIFO dq and the priority queue eq
	disk_queue_t dq = disk_queue_init();
	event_queue_t eq = event_queue_init(ARRAY_EVENTS);

	// Declare variable to hold the current event pointer
	event_t first_ev = req_sub_create(global_time);
	event_queue_insert(eq, first_ev);

	// empty function should return 1 if empty 0 otherwise
	empty = event_queue_empty(eq);
	full = event_queue_full(eq);

	if (full == 1)
	{
		printf("\nError: ");
		printf("Simulation must be re-run with a larger event queue.\n");
		exit (1);
	}

	// Declare variable for current event
	event_t curr_ev;

	while (empty == 0)
	{
		// Set current event by removing it from the eq
		// and set global time to the current event's time
		curr_ev = event_queue_remove(eq);
		global_time = curr_ev->event_time;

		// Switch statements for event types
		switch (curr_ev->event_type)
		{
			case REQ_SUB:
				request_submit(dq, eq, curr_ev, global_time);
				break;
			case DISK_RDY:
				disk_ready(dq, eq, &curr_track, global_time);
				break;
			case REQ_DONE:
				request_done(dq, eq, q_time, io_time, tot_time, global_time);
				break;
			default:
				// Just for some fun
				printf("\nSegmentation fault. (Core dumped)\n");
				break;
		}

		// Free current event before looping to next one
		free(curr_ev);
		curr_ev = NULL;

		empty = event_queue_empty(eq);
		full = event_queue_full(eq);

		if (full == 1)
		{
			printf("\nError: ");
			printf("Simulation must be re-run with a larger event queue.\n");
			exit (1);
		}
	}

	q_time->avg_time /= NUM_EVENTS;
	io_time->avg_time /= NUM_EVENTS;
	tot_time->avg_time /= NUM_EVENTS;
	printStats(q_time, io_time, tot_time);

	disk_queue_finalize(dq);
	event_queue_finalize(eq);
	free(q_time);
	free(io_time);
	free(tot_time);

	return 0;
}

// Constructor function to initialize values in stats structs
static void stats_constructor(stats_t times)
{
	// Starting with time as 0 means the first event's times
	// will automatically populate the the times when it is found
	times->min_time = 1000000;
	times->max_time = 0;
	times->avg_time = 0;
}

// Creates first event for the beginning of the code
static event_t req_sub_create(double sched_time)
{
	event_t event1 = (event_t)malloc(sizeof(struct event_s));

	event1->event_type = REQ_SUB;
	event1->event_time = sched_time;

	event1->request = (request_t)malloc(sizeof(struct request_s));

	event1->request->track = request_track();
	event1->request->arrival_time = sched_time;

	return event1;
}

// Function performed every time a REQ_SUB happens
static void request_submit(disk_queue_t dq, event_queue_t eq, event_t curr_ev, double curr_time)
{
	static int req_subs = 1;
	int empty = disk_queue_empty(dq);
	double next_req_time;

	// check if 1 million requests have been processed
	if (req_subs < NUM_EVENTS)
	{
		// Schedule next request using randsim_exp() + curr_time
		next_req_time = randsim_exp();
		event_t new_req_sub = req_sub_create(next_req_time+curr_time);
		event_queue_insert(eq, new_req_sub);
		req_subs++;
	}

	// Create new request
	// Arrival time and track request number are set inside req_sub_create
	disk_queue_insert(dq, curr_ev->request);

	if (empty == 1)
	{
		event_t rdy_event = (event_t)malloc(sizeof(struct event_s));
		rdy_event->event_type = DISK_RDY;

		// Schedule disk ready immediately
		rdy_event->event_time = curr_time;

		// Insert event
		event_queue_insert(eq, rdy_event);
	}
}

// Function performed every time a DISK_RDY happens
static void disk_ready(disk_queue_t dq, event_queue_t eq, int *track_ptr, double curr_time)
{
	// Peek at the head of the dq and calc the time of the request in the queue
	// Then update the start_time of the request
	request_t peek = disk_queue_peek(dq);
	peek->start_time = curr_time;

	// Calc the finish time using the seek_time function and update curr_track
	peek->finish_time = peek->start_time + seek_time(*track_ptr, peek->track);
	*track_ptr = peek->track;

	// Schedule a new request_done event
	event_t done_event = (event_t)malloc(sizeof(struct event_s));
	done_event->event_type = REQ_DONE;
	done_event->event_time = peek->finish_time;
	done_event->request = peek;

	event_queue_insert(eq, done_event);
}

// Function performed every time a REQ_DONE happens
static void request_done(disk_queue_t dq, event_queue_t eq, stats_t q_time,
						 stats_t IO_time, stats_t tot_time, double curr_time)
{
	// Remove the request at the head of the DQ
	request_t removed = disk_queue_remove(dq);

	// Check for more requests in the DQ and schedule if necessary
	if (disk_queue_empty(dq) != 1)
	{
		event_t rdy_event = (event_t)malloc(sizeof(struct event_s));
		rdy_event->event_type = DISK_RDY;
		rdy_event->event_time = curr_time;

		// Insert event in the eq
		event_queue_insert(eq, rdy_event);
	}

	// Calculate removed request's times
	double rm_qTime = removed->start_time - removed->arrival_time;
	double rm_ioTime = removed->finish_time - removed->start_time;
	double rm_totTime = removed->finish_time - removed->arrival_time;

	// Update global statistics
	if (q_time->min_time > rm_qTime)
		q_time->min_time = rm_qTime;
	if (IO_time->min_time > rm_ioTime)
		IO_time->min_time = rm_ioTime;
	if(tot_time->min_time > rm_totTime)
		tot_time->min_time = rm_totTime;

	if (q_time->max_time < rm_qTime)
		q_time->max_time = rm_qTime;
	if (IO_time->max_time < rm_ioTime)
		IO_time->max_time = rm_ioTime;
	if(tot_time->max_time < rm_totTime)
		tot_time->max_time = rm_totTime;

	q_time->avg_time += rm_qTime;
	IO_time->avg_time += rm_ioTime;
	tot_time->avg_time += rm_totTime;

	// Free the request struct
	free(removed);
}

// Prints all statistics for time
static void printStats(stats_t queue_time, stats_t IO_time, stats_t total_req)
{
	// Print stats for the Event Queue
	printf("\nStatistics for the Event Queue:");
	printf("\nMin time in Event Queue: %f seconds", queue_time->min_time);
	printf("\nMax time in Event Queue: %f seconds", queue_time->max_time);
	printf("\nAverage time in Event Queue: %f seconds", queue_time->avg_time);

	// Print stats for the Disk Queue
	// I believe this is what it meant by time being read
	printf("\n\nStatistics for Disk Move times:");
	printf("\nMin time for reading: %f seconds", IO_time->min_time);
	printf("\nMax time for reading: %f seconds", IO_time->max_time);
	printf("\nAverage time for reading: %f seconds", IO_time->avg_time);

	// Print stats for total time per request
	printf("\n\nStatistics for Total Time:");
	printf("\nMin time per request: %f seconds", total_req->min_time);
	printf("\nMax time per request: %f seconds", total_req->max_time);
	printf("\nAverage time per request: %f seconds", total_req->avg_time);
	printf("\n\nEnd Statistics.\n\n");
}