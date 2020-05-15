#pragma once

#include <stdlib.h>
#include <unistd.h>

void at_sunrise(void (*func)(void))
{
	// TODO
}

void at_sunset(void (*func)(void))
{
	// TODO
}

void at_exit(void (*func)(void))
{
	atexit(func);
}

void await()
{
	usleep(5 * 1000 * 1000);
}
