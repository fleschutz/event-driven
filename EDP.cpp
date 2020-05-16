// EDP.c - event-driven programming (EDP)
#include "EDP.h"

#include <stdlib.h>
#include <unistd.h>

#define NUM_CALLS 10
typedef struct {
	void (*voids[NUM_CALLS])(void);
	void (*nows[NUM_CALLS])(Time now);
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

	Time now;
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

static void remember(void (*fn)(Time now), Calls *calls)
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

void at_pre_run(void (*fn)(Time))
{
	remember(fn, &pre_run_calls);
}

void at_post_run(void (*fn)(void))
{
	remember(fn, &post_run_calls);
}

void at_post_run(void (*fn)(Time))
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

void at_buffer_overflow(void (*fn)(Time))
{
	remember(fn, &buffer_overflow_calls);
}

void at_memory_exhausted(void (*fn)(void))
{
	remember(fn, &memory_exhausted_calls);
}

void at_memory_exhausted(void (*fn)(Time))
{
	remember(fn, &memory_exhausted_calls);
}

void at_program_start(void (*fn)(void))
{
	(*fn)();
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

void at_exit(void (*fn)(Time))
{
	atexit(_on_exit);
	remember(fn, &exit_calls);
}

#include <stdio.h>
static bool shut_up = false;

void say(const char *text, ...)
{
	va_list arguments;
	char buf[1024];

	if (shut_up)
		return;
	va_start(arguments, text);
	vsnprintf(buf, sizeof(buf), text, arguments);
	puts(buf);
	va_end(arguments);
}
