#ifndef COMMANDS_H
#define COMMANDS_H

#include <string.h>
#include "icommand.h"


class ExecCommand :public ICommand
{
public:
	ExecCommand(const char* cmd)
	{
		setType(COM_EXEC);
		newData(strlen(cmd)+1);
		strcpy((char*)data, cmd);
	}

	ExecCommand(void)
	{
		setType(COM_EXEC);
	}

	const unsigned char* getCommand(){
		return data;
	}

	~ExecCommand(void) {};
};


class DirCommand :public ICommand
{
public:
	DirCommand(const char* cmd)
	{
		setType(COM_DIR);
		newData(strlen(cmd)+1);
		strcpy((char*)data, cmd);
	}
	DirCommand(void) {};
	~DirCommand(void) {};

	const unsigned char* getDir(){
		return data;
	}
};

class DelCommand :public ICommand
{
public:
	DelCommand(const char* cmd)
	{
		setType(COM_DEL);
		newData(strlen(cmd)+1);
		strcpy((char*)data, cmd);
	}
	DelCommand(void) {};
	~DelCommand(void) {};
	const unsigned char* getPath(){
		return data;
	}
};




#endif // COMMANDS_H