// EDP.c - event-driven programming (EDP)
#include "EDP.h"

#include <stdlib.h>
#include <unistd.h>

#define NUM_CALLS 10
typedef struct {
	void (*voids[NUM_CALLS])(void);
	void (*nows[NUM_CALLS])(time_t now);
} Calls;
static Calls pre_run_calls, post_run_calls;
static Calls buffer_overflow_calls, memory_exhausted_calls;
static Calls pre_exit_calls, exit_calls, post_exit_calls;

static void call(Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (calls->voids[i])
			(*calls->voids[i])();
		else
			break;

	time_t now = 0;
	time(&now);
	for (int i = 0; i < NUM_CALLS; ++i)
		if (calls->nows[i])
			(*calls->nows[i])(now);
		else
			break;
}

static void remember(void (*fn)(void), Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
	{
		if (calls->voids[i])
			continue;
		calls->voids[i] = fn;
		return;
	}
	call(&buffer_overflow_calls);
}

static void remember(void (*fn)(time_t now), Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
	{
		if (calls->nows[i])
			continue;
		calls->nows[i] = fn;
		return;
	}
	call(&buffer_overflow_calls);
}

void at_pre_sunrise(void (*fn)(void))
{
	// TODO
}

void at_sunrise(void (*fn)(void))
{
	// TODO
}

void at_post_sunrise(void (*fn)(void))
{
	// TODO
}

void at_midday(void (*fn)(void))
{
	// TODO
}

void at_sunset(void (*fn)(void))
{
	// TODO
}

void at_noon(void (*fn)(void))
{
	// TODO
}

void at_pre_run(void (*fn)(void))
{
	remember(fn, &pre_run_calls);
}

void at_pre_run(void (*fn)(time_t))
{
	remember(fn, &pre_run_calls);
}

void at_post_run(void (*fn)(void))
{
	remember(fn, &post_run_calls);
}

void at_post_run(void (*fn)(time_t))
{
	remember(fn, &post_run_calls);
}


void run()
{
	call(&pre_run_calls);
	usleep(5 * 1000 * 1000);
	call(&post_run_calls);
}

void at_buffer_overflow(void (*fn)(void))
{
	remember(fn, &buffer_overflow_calls);
}

void at_buffer_overflow(void (*fn)(time_t))
{
	remember(fn, &buffer_overflow_calls);
}

void at_memory_exhausted(void (*fn)(void))
{
	remember(fn, &memory_exhausted_calls);
}

void at_memory_exhausted(void (*fn)(time_t))
{
	remember(fn, &memory_exhausted_calls);
}

static void _on_exit(void)
{
	call(&exit_calls);
}

void at_exit(void (*fn)(void))
{
	atexit(_on_exit);
	remember(fn, &exit_calls);
}

void at_exit(void (*fn)(time_t))
{
	atexit(_on_exit);
	remember(fn, &exit_calls);
}
