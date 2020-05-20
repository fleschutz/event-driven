#include "EDP/Triggers.h"
#include "EDP/Actions.h"

class MyClass : public Triggers, Actions
{
	void on_enter() { say("Hello world! I'm Ivy"); }
	void on_sunrise() { say("By the way, the sun rises now"); }
	void on_midday() { say("By the way, it's midday"); }
	void on_sunset() { say("By the way, the sun sets down"); }
	void on_noon() { say("By the way, it's noon"); }
	void on_buffer_overflow() { say("I have a buffer overflow!"); exit_program(); }
	void on_memory_exhausted() { say("My memory is exhausted"); exit_program(); }
	void on_exit() { say("Bye, I'm exiting now"); }
};

int main()
{
	MyClass myClass;
	myClass.exec();
	return 0;
}
