#pragma once

#include <cstring>

#define NUM_CALLS 10
typedef struct {
	void (*voids[NUM_CALLS])(void);
	void (*nows[NUM_CALLS])(Time time);
	Time times[NUM_CALLS];
} Calls;
static Calls time_calls;
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

static void append(void (*fn)(void), Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (!calls->voids[i])
		{
			calls->voids[i] = fn;
			return;
		}
	call(&buffer_overflow_calls);
}

static void append(void (*fn)(Time now), Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (!calls->nows[i])
		{
			calls->nows[i] = fn;
			return;
		}
	call(&buffer_overflow_calls);
}

static void sortIn(void (*fn)(void), Time time, Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (!calls->voids[i])
		{
			calls->voids[i] = fn;
			calls->times[i] = time;
			return;
		}
		else if (time.unixTime() <= calls->times[i].unixTime())
		{
			memmove(&calls->voids[i + 1], &calls->voids[i], (NUM_CALLS - i - 1) * sizeof(void *));
			memmove(&calls->times[i + 1], &calls->times[i], (NUM_CALLS - i - 1) * sizeof(Time));
			calls->voids[i] = fn;
			calls->times[i] = time;
			return;
		}
	call(&buffer_overflow_calls);
}

static void sortIn(void (*fn)(Time), Time time, Calls *calls)
{
	for (int i = 0; i < NUM_CALLS; ++i)
		if (!calls->nows[i])
		{
			calls->nows[i] = fn;
			calls->times[i] = time;
			return;
		}
		else if (time.unixTime() <= calls->times[i].unixTime())
		{
			memmove(&calls->nows[i + 1], &calls->nows[i], (NUM_CALLS - i - 1) * sizeof(void *));
			memmove(&calls->times[i + 1], &calls->times[i], (NUM_CALLS - i - 1) * sizeof(Time));
			calls->nows[i] = fn;
			calls->times[i] = time;
			return;
		}
	call(&buffer_overflow_calls);
}
