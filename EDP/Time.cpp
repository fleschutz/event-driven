#include "Time.h"

Time::Time()
{
	time(&m_time);
}

Time::Time(unsigned long unixTime)
{
	m_time = unixTime;
}

const char *Time::toString()
{
	return ctime(&m_time);
}

const char *Time::toHM()
{
	static char buf[20];
	auto myTime = localtime(&m_time);
	strftime(buf, sizeof(buf), "%H:%M", myTime);
	return buf;
}

const char *Time::toHMS()
{
	static char buf[20];
	auto myTime = localtime(&m_time);
	strftime(buf, sizeof(buf), "%H:%M:%S", myTime);
	return buf;
}

unsigned long Time::unixTime()
{
	return m_time;
}
