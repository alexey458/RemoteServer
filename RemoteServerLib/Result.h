#ifndef RESULT_H
#define RESULT_H

#include "IResult.h"

class ExecResult :public IResult
{
public:
	ExecResult(UCHAR exit_code)
	{
		newData(sizeof(UCHAR));
		data[0] = exit_code;
	}
	ExecResult()
	{
		newData(sizeof(UCHAR));
	}
	virtual ~ExecResult(void){}

	virtual void SetExitCode(UCHAR exit_code)
	{
		if(data!=NULL)
			data[0] = exit_code;
	}

	virtual UCHAR GetExitCode()
	{
		return data[0];
	}
};

class DirResult :public IResult
{
public:
	DirResult(){}
	virtual ~DirResult(void){}
	virtual void GetFiles(char* dirs[]);
};

class DelResult :public IResult
{
public:
	DelResult(){}
	virtual ~DelResult(void){}
	virtual int GetResult();
};

#endif // RESULT_H