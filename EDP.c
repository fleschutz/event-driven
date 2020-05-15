// EDP.c - event-driven programming (EDP)
#include "EDP.h"

#include <stdlib.h>
#include <unistd.h>

#define NUM_CALLS 20
typedef struct {
	void (*func[NUM_CALLS])(void);
} Calls;
static Calls pre_run_calls, run_calls, post_run_calls;
static Calls buffer_overflow_calls, memory_exhausted_calls;
static Calls pre_exit_calls, exit_calls, post_exit_calls;

static void call(Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (calls->func[i])
			(*calls->func[i])();
		else
			return;
}

static void remember(void (*func)(void), Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
	{
		if (calls->func[i])
			continue;
		calls->func[i] = func;
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

void at_run(void (*fn)(void))
{
	remember(fn, &run_calls);
}

void at_post_run(void (*fn)(void))
{
	remember(fn, &post_run_calls);
}

void run()
{
	call(&pre_run_calls);
	call(&run_calls);
	usleep(5 * 1000 * 1000);
	call(&post_run_calls);
}

void at_buffer_overflow(void (*fn)(void))
{
	remember(fn, &buffer_overflow_calls);
}

void at_memory_exhausted(void (*fn)(void))
{
	remember(fn, &memory_exhausted_calls);
}

static void _on_exit(void)
{
	call(&pre_exit_calls);
	call(&exit_calls);
	call(&post_exit_calls);
}

void at_pre_exit(void (*fn)(void))
{
	atexit(_on_exit);
	remember(fn, &pre_exit_calls);
}

void at_exit(void (*fn)(void))
{
	atexit(_on_exit);
	remember(fn, &exit_calls);
}

void at_post_exit(void (*fn)(void))
{
	atexit(_on_exit);
	remember(fn, &post_exit_calls);
}
