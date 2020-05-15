#include <stdio.h>
#include "EDP.h" // event-driven programming (EDP)

void on_sunrise()
{
	puts("good morning");
}

void on_midday()
{
	puts("midday");
}

void on_sunset()
{
	puts("good night");
}

void on_noon()
{
	puts("noon");
}

void on_pre_run()
{
	puts("entering run()");
}

void on_post_run()
{
	puts("leaving run()");
}

void on_buffer_overflow()
{
	puts("buffer overflow");
}

void on_memory_exhausted()
{
	puts("memory exhausted");
}

void on_exit()
{
	puts("exited");
}

void main()
{
	at_sunrise(on_sunrise);
	at_midday(on_midday);
	at_sunset(on_sunset);
	at_noon(on_noon);
	at_pre_run(on_pre_run);
	at_post_run(on_post_run);
	at_buffer_overflow(on_buffer_overflow);
	at_memory_exhausted(on_memory_exhausted);
	at_exit(on_exit);
	run();
}
