#include "EDP/Triggers.h"
#include "EDP/Actions.h"

class MyRules : public Triggers, Actions
{
	void on_enter() { say("Hello world! I'm Ivy"); }
	void on_sunrise() { say("By the way, the sun rises now"); }
	void on_midday() { say("By the way, it's midday"); }
	void on_sunset() { say("By the way, the sun sets down"); }
	void on_noon() { say("By the way, it's noon"); }
	void on_buffer_overflow() { say("I have a buffer overflow!"); exit_program(); }
	void on_memory_exhausted() { say("My memory is exhausted"); exit_program(); }
	void on_SIGTERM() { say("Got signal TERM"); exit_program(); }
	void on_SIGUSER() { say("Got USER signal"); }
	void on_exit() { say("Bye, I'm exiting now"); }
	void on_leave() { say("Bye, I'm leaving now"); }
};

int main()
{
	MyRules rules;
	rules.exec();
	return 0;
}
