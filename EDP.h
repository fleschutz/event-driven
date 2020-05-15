#pragma once

extern void at_pre_sunrise(void (*func)(void));
extern void at_sunrise(void (*func)(void));
extern void at_post_sunrise(void (*func)(void));

extern void at_pre_midday(void (*func)(void));
extern void at_midday(void (*func)(void));
extern void at_post_midday(void (*func)(void));

extern void at_pre_sunset(void (*func)(void));
extern void at_sunset(void (*func)(void));
extern void at_post_sunset(void (*func)(void));

extern void at_pre_noon(void (*func)(void));
extern void at_noon(void (*func)(void));
extern void at_post_noon(void (*func)(void));

extern void at_pre_exit(void (*func)(void));
extern void at_exit(void (*func)(void));
extern void at_post_exit(void (*func)(void));

extern void at_pre_run(void (*func)(void));
extern void at_run(void (*func)(void));
extern void at_post_run(void (*func)(void));

extern void run();
