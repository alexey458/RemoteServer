#ifndef SHELLEXECUTOR_H
#define SHELLEXECUTOR_H

#include "iexecutor.h"
#include "Commands.h"
#include "Result.h"

class ShellExecutor :public IExecutor
{
public:
	ShellExecutor(void);
	~ShellExecutor(void);
	void ExecComm(ICommand* command, IResult* result);
};


#endif // SHELLEXECUTOR_H