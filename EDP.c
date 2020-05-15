#include "EDP.h"

#include <stdlib.h>
#include <unistd.h>

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

void at_pre_exit(void (*func)(void))
{
	atexit(func);
}

void at_exit(void (*func)(void))
{
	atexit(func);
}

void at_post_exit(void (*func)(void))
{
	atexit(func);
}

void run()
{
	usleep(5 * 1000 * 1000);
}
