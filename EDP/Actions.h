#pragma once

#include <string>	// required by std::string
#include <stdarg.h>	// required by variable arguments

class Actions
{
public:
	void say(std::string_view formatString, ...);
	void shut_up();

	void error(std::string_view formatString, ...);
	void warning(std::string_view formatString, ...);
	void hint(std::string_view formatString, ...);
	void log(std::string_view formatString, ...);

	void wakeup(std::string_view MACaddress);

	void exit_program(int exitCode = 1);

private:
	bool m_shut_up = false;
};

