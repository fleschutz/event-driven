// EDP.h - event-driven programming (EDP)
#pragma once

#include <time.h> // to provide time_t
class Time
{
public:
	Time() { time(&m_time); }
	const char *toString(void) { return ctime(&m_time); }
	const char *localTime(void) { static char buf[20]; auto myTime = localtime(&m_time); strftime(buf, sizeof(buf), "%H:%M", myTime); return buf; }
private:
	time_t m_time;
};

extern void at_pre_sunrise(void (*fn)(void));
extern void at_sunrise(void (*fn)(void));
extern void at_post_sunrise(void (*fn)(void));

extern void at_pre_midday(void (*fn)(void));
extern void at_midday(void (*fn)(void));
extern void at_post_midday(void (*fn)(void));

extern void at_pre_sunset(void (*fn)(void));
extern void at_sunset(void (*fn)(void));
extern void at_post_sunset(void (*fn)(void));

extern void at_pre_noon(void (*fn)(void));
extern void at_noon(void (*fn)(void));
extern void at_post_noon(void (*fn)(void));

extern void at_pre_run(void (*fn)(void));
extern void at_pre_run(void (*fn)(Time));
extern void at_post_run(void (*fn)(void));
extern void at_post_run(void (*fn)(Time));
extern void run();

extern void at_buffer_overflow(void (*fn)(void));
extern void at_buffer_overflow(void (*fn)(Time));

extern void at_memory_exhausted(void (*fn)(void));
extern void at_memory_exhausted(void (*fn)(Time));

extern void at_program_start(void (*fn)(void));
extern void at_program_start(void (*fn)(Time));
extern void at_exit(void (*fn)(void));
extern void at_exit(void (*fn)(Time));


// output:
extern void say(const char *text, ...);
