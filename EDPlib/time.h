#pragma once

#include <time.h> // to provide time_t

class Time
{
public:
	Time() { time(&m_time); }
	Time(unsigned long unixTime) { m_time = unixTime; }

	const char *toString(void) { return ctime(&m_time); }
	const char *toHM(void) { static char buf[20]; auto myTime = localtime(&m_time); strftime(buf, sizeof(buf), "%H:%M", myTime); return buf; }
	const char *toHMS(void) { static char buf[20]; auto myTime = localtime(&m_time); strftime(buf, sizeof(buf), "%H:%M:%S", myTime); return buf; }
	unsigned long unixTime() { return m_time; }
private:
	time_t m_time;
};
