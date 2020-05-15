#include <stdio.h>
#include "at.h"

void on_sunrise()
{
	puts("good morning");
}

void on_sunset()
{
	puts("good night");
}

void on_exit1()
{
	puts("good-bye");
}

void on_exit2()
{
	puts("farewell");
}

void main()
{
	at_sunrise(on_sunrise);
	at_sunset(on_sunset);
	at_exit(on_exit1);
	at_exit(on_exit2);
	await();
}
