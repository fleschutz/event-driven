#pragma once

#include <time.h> // to provide time_t

class Time
{
public:
	Time();				// construct from current time
	Time(unsigned long unixTime);	// construct from given Unix time

	const char *toString();
	const char *toHM();
	const char *toHMS();
	unsigned long unixTime();

private:
	time_t m_time;
};
