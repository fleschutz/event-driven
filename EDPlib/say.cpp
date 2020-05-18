#include "say.h"

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
