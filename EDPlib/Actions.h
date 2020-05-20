#pragma once

#include <stdarg.h> // required by variable arguments

class Actions
{
public:
	void say(const char *text, ...);
	void shut_up();

	void exit_failure();

private:
	bool m_shut_up = false;
};

