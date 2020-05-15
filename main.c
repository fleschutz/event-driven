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

void on_exit()
{
	puts("good-bye");
}

void on_pre_run()
{
	puts("entering run()");
}

void on_post_run()
{
	puts("leaving run()");
}

void main()
{
	at_sunrise(on_sunrise);
	at_midday(on_midday);
	at_sunset(on_sunset);
	at_noon(on_noon);
	at_exit(on_exit);
	at_pre_run(on_pre_run);
	at_post_run(on_post_run);
	run();
}
