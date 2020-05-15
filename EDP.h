// EDP.h - event-driven programming (EDP)
#pragma once

#include <time.h> // to provide time_t

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
extern void at_pre_run(void (*fn)(time_t));
extern void at_post_run(void (*fn)(void));
extern void at_post_run(void (*fn)(time_t));
extern void run();

extern void at_buffer_overflow(void (*fn)(void));
extern void at_buffer_overflow(void (*fn)(time_t));

extern void at_memory_exhausted(void (*fn)(void));
extern void at_memory_exhausted(void (*fn)(time_t));

extern void at_exit(void (*fn)(void));
extern void at_exit(void (*fn)(time_t));
