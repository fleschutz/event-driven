#include "at.h"

#include <stdlib.h>
#include <unistd.h>
#include "calls.h"

void at_midday(void (*fn)(void))
{
	Time now;
	sortIn(fn, now, &time_calls);
}

void at_noon(void (*fn)(void))
{
	Time now;
	sortIn(fn, now, &time_calls);
}

void at_sunrise(void (*fn)(void))
{
	Time now;
	sortIn(fn, now, &time_calls);
}

void at_sunset(void (*fn)(void))
{
	Time now;
	sortIn(fn, now, &time_calls);
}

void at_pre_run(void (*fn)(void))
{
	append(fn, &pre_run_calls);
}

void at_pre_run(void (*fn)(Time))
{
	append(fn, &pre_run_calls);
}

void at_post_run(void (*fn)(void))
{
	append(fn, &post_run_calls);
}

void at_post_run(void (*fn)(Time))
{
	append(fn, &post_run_calls);
}

void run()
{
	call(&pre_run_calls);
	usleep(5 * 1000 * 1000);
	call(&post_run_calls);
}

void at_buffer_overflow(void (*fn)(void))
{
	append(fn, &buffer_overflow_calls);
}

void at_buffer_overflow(void (*fn)(Time))
{
	append(fn, &buffer_overflow_calls);
}

void at_memory_exhausted(void (*fn)(void))
{
	append(fn, &memory_exhausted_calls);
}

void at_memory_exhausted(void (*fn)(Time))
{
	append(fn, &memory_exhausted_calls);
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
	append(fn, &exit_calls);
}

void at_exit(void (*fn)(Time))
{
	atexit(_on_exit);
	append(fn, &exit_calls);
}
