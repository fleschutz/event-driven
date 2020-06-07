#include "Actions.h"

#include <stdio.h> // required by puts()
#include <stdlib.h> // required by exit()

void Actions::say(std::string_view formatString, ...)
{
	va_list arguments;
	char buf[1024];

	if (m_shut_up)
		return;
	va_start(arguments, formatString);
	vsnprintf(buf, sizeof(buf), formatString.data(), arguments);
	puts(buf);
	va_end(arguments);
}

void Actions::shut_up()
{
	m_shut_up = true;
}

void Actions::wakeup(std::string_view MACaddress)
{
	// TODO: send a magic packet per UDP to port 9
}

void Actions::exit_program(int exitCode)
{
	exit(exitCode);
}
