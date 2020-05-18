#pragma once

#include <time.h> // to provide time_t
#include <stdarg.h>
class Time
{
public:
	Time() { time(&m_time); }
	const char *toString(void) { return ctime(&m_time); }
	const char *toLocalHM(void) { static char buf[20]; auto myTime = localtime(&m_time); strftime(buf, sizeof(buf), "%H:%M", myTime); return buf; }
	unsigned long unixTime() { return m_time; }
private:
	time_t m_time;
};
