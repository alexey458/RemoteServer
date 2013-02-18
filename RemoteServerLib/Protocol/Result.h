#ifndef RESULT_H
#define RESULT_H

#include "IResult.h"


struct ExecResult
{
	UCHAR execute_result;
};

struct DeleteResult
{
	UCHAR delete_result;
};

struct DirResult
{
	UCHAR* cmd;
};

void SetResultExec()
{

}

void ExtractExecCommand(PackCommand* packCommand, ExecResult* execResult)
{
	execResult->execute_result = packCommand->data[0];
}

void ExtractDeleteCommand(PackCommand* packCommand, DeleteResult* deleteResult)
{
	deleteResult->delete_result = packCommand->data[0];
}

void ExtractDeleteCommand(PackCommand* packCommand, DirResult* dirResult)
{

}


#endif // RESULT_H