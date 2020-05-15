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

void main()
{
	at_sunrise(on_sunrise);
	at_midday(on_midday);
	at_sunset(on_sunset);
	at_noon(on_noon);
	at_exit(on_exit);
	run();
}
