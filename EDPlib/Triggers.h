#pragma once

class Triggers
{
	public:
		void exec() { /*TODO*/; }
	private:
};

typedef enum
{
	PROGRAM_START,
	PROGRAM_EXIT,
	ON_TIMESTAMP,
	FILE_CHANGED,
	FOLDER_CHANGED,
} TriggerType;
