#include "EDP.h" // event-driven programming (EDP)

void on_program_start()
{
	say("Hi, I'm Ivy");
}

void on_sunrise()
{
	say("good morning");
}

void on_midday()
{
	say("midday");
}

void on_sunset()
{
	say("good night");
}

void on_noon()
{
	say("noon");
}

void on_pre_run(time_t now)
{
	say("entering run() at %s", ctime(&now));
}

void on_post_run(time_t now)
{
	say("leaving run() at %s", ctime(&now));
}

void on_buffer_overflow(time_t now)
{
	say("buffer overflow at %s", ctime(&now));
}

void on_memory_exhausted(time_t now)
{
	say("memory exhausted at %s", ctime(&now));
}

void on_exit(time_t now)
{
	say("I'm exiting now at %s", ctime(&now));
}

int main()
{
	at_program_start(on_program_start);
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
	return 0;
}
