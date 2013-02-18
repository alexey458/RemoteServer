#ifndef COMMANDS_H
#define COMMANDS_H

#include <string.h>
#include "icommand.h"


struct ExecCommand
{
	UCHAR* cmd;
};

struct DirCommand
{
	UCHAR* cmd;
};

struct DeleteCommand
{
	UCHAR* cmd;
};


void ExtractExecCommand(PackCommand* packCommand, ExecCommand* execCommand)
{
	execCommand->cmd = packCommand->data;
}

void SetExecCommand(PackCommand* packCommand, const char* str)
{
	int len = strlen(str);
	PackageMemResize(packCommand, len + 1);
	strcpy((char*)packCommand->data, str);
	packCommand->commandType = COM_EXEC;
}

void ExtractDirCommand(PackCommand* packCommand, DirCommand* dirCommand)
{
	dirCommand->cmd = packCommand->data;
}

void ExtractDeleteCommand(PackCommand* packCommand, DeleteCommand* deleteCommand)
{
	deleteCommand->cmd = packCommand->data;
}



#endif // COMMANDS_H