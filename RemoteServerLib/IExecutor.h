#ifndef IEXECUTOR_H
#define IEXECUTOR_H

#include "ICommand.h"
#include "IResult.h"

class IExecutor
{
public:
	IExecutor(void) {}
	virtual ~IExecutor(void) {}
	virtual void ExecComm(ICommand* command, IResult* result) = 0;
};

#endif // IEXECUTOR_H
