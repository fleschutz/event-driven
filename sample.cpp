#include "EDP.h" // event-driven programming (EDP)

void on_program_start()
{
	say("Hi, I'm Ivy");
}

void on_sunrise()
{
	say("By the way, the sun rises now");
}

void on_midday()
{
	say("By the way, it's midday");
}

void on_sunset()
{
	say("By the way, the sun sets down");
}

void on_noon()
{
	say("By the way, it's noon");
}

void on_pre_run(time_t now)
{
	say("I'm entering run() at %s", ctime(&now));
}

void on_post_run(time_t now)
{
	say("I'm leaving run() at %s", ctime(&now));
}

void on_buffer_overflow(time_t now)
{
	say("I have a buffer overflow! It's %s", ctime(&now));
}

void on_memory_exhausted(time_t now)
{
	say("My memory is exhausted! It's %s", ctime(&now));
}

void on_exit(time_t now)
{
	say("Bye, I'm exiting now. It's %s", ctime(&now));
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
