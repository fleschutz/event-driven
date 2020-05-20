#include "Actions.h"

#include <stdio.h> // required by puts()
#include <stdlib.h> // required by exit()

void Actions::say(const char *text, ...)
{
	va_list arguments;
	char buf[1024];

	if (m_shut_up)
		return;
	va_start(arguments, text);
	vsnprintf(buf, sizeof(buf), text, arguments);
	puts(buf);
	va_end(arguments);
}

void Actions::shut_up()
{
	m_shut_up = true;
}

void Actions::wakeup(const char* MACaddress)
{
	// TODO
}

void Actions::exit_program(int exitCode)
{
	exit(exitCode);
}
