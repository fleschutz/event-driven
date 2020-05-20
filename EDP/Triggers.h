#pragma once

class Triggers
{
public:
	Triggers();
	virtual void on_enter()			{ }
	virtual void on_sunrise()		{ }
	virtual void on_midday()		{ }
	virtual void on_sunset()		{ }
	virtual void on_noon()			{ }
	virtual void on_buffer_overflow()	{ }
	virtual void on_memory_exhausted()	{ }
	virtual void on_exit()			{ }
	virtual void on_leave()			{ }
	void exec();
	~Triggers();
private:
};
