#include "EDP.h"

#include <stdlib.h>
#include <unistd.h>

typedef enum {
	PRE_RUN, RUN, POST_RUN,
	PRE_EXIT, EXIT, POST_EXIT,
} Type;
static void (*calls[100])(void);

static void remember(void (*func)(void), Type type)
{
	calls[type] = func;
}

static void call(Type type)
{
	if (calls[type])
		(*calls[type])();
}

void at_pre_sunrise(void (*func)(void))
{
	// TODO
}

void at_sunrise(void (*func)(void))
{
	// TODO
}

void at_post_sunrise(void (*func)(void))
{
	// TODO
}

void at_midday(void (*func)(void))
{
	// TODO
}

void at_sunset(void (*func)(void))
{
	// TODO
}

void at_noon(void (*func)(void))
{
	// TODO
}

void at_pre_run(void (*func)(void))
{
	remember(func, PRE_RUN);
}

void at_run(void (*func)(void))
{
	remember(func, RUN);
}

void at_post_run(void (*func)(void))
{
	remember(func, POST_RUN);
}

static void _on_exit(void)
{
	call(PRE_EXIT);
	call(EXIT);
	call(POST_EXIT);
}

void at_pre_exit(void (*func)(void))
{
	atexit(_on_exit);
	remember(func, PRE_EXIT);
}

void at_exit(void (*func)(void))
{
	atexit(_on_exit);
	remember(func, EXIT);
}

void at_post_exit(void (*func)(void))
{
	atexit(_on_exit);
	remember(func, POST_EXIT);
}

void run()
{
	call(PRE_RUN);
	call(RUN);
	usleep(5 * 1000 * 1000);
	call(POST_RUN);
}
