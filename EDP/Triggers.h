#pragma once

class Triggers
{
public:
	Triggers();
	virtual void on_enter()			{ }
	virtual void on_midday()		{ }
	virtual void on_noon()			{ }
	virtual void on_sunrise()		{ }
	virtual void on_sunset()		{ }
	virtual void on_moonrise()		{ }
	virtual void on_moonset()		{ }
	virtual void on_file_change()		{ }
	virtual void on_folder_change()		{ }
	virtual void on_device_online()		{ }
	virtual void on_device_offline()	{ }
	virtual void on_buffer_overflow()	{ }
	virtual void on_memory_exhausted()	{ }
	virtual void on_exit()			{ }
	virtual void on_leave()			{ }
	void exec();
	~Triggers();
private:
};
