#ifndef IEXECUTOR_H
#define IEXECUTOR_H

#include "../Protocol/ICommand.h"
#include "../Protocol/IResult.h"

class IExecutor
{
public:
	IExecutor(void) {}
	virtual ~IExecutor(void) {}
	virtual void ExecComm() = 0;
};

#endif // IEXECUTOR_H
