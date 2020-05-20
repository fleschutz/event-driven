#pragma once

#include <stdarg.h> // required by variable arguments

class Actions
{
public:
	void say(const char* text, ...);
	void shut_up();

	void wakeup(const char* MACaddress);

	void exit_program(int exitCode = 1);

private:
	bool m_shut_up = false;
};

