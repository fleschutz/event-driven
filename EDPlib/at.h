#pragma once
#include "time.h"

extern void at_sunrise(void (*fn)(void));

extern void at_midday(void (*fn)(void));

extern void at_sunset(void (*fn)(void));

extern void at_noon(void (*fn)(void));

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

