#ifndef RESULT_H
#define RESULT_H

#include "IResult.h"

class ExecResult :public IResult
{
public:
	explicit ExecResult(UCHAR exit_code)
	{
		newData(sizeof(UCHAR));
		data[0] = exit_code;
	}

	ExecResult()
	{
	}

	ExecResult(const IResult & res): IResult(res)
	{
	}

	virtual ~ExecResult(void){}

	virtual void SetExitCode(UCHAR exit_code)
	{
		if(data!=NULL)
			data[0] = exit_code;
	}
	virtual UCHAR GetExitCode()
	{
		if(data!=NULL)
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
	DelResult(UCHAR exit_code)
	{
		newData(sizeof(UCHAR));
		data[0] = exit_code;
	}
	DelResult()
	{
		newData(sizeof(UCHAR));
	}
	virtual ~DelResult(void){}

	virtual void SetResultCode(UCHAR exit_code)
	{
		if(data!=NULL)
			data[0] = exit_code;
	}
	virtual UCHAR SetResultCode()
	{
		if(data!=NULL)
			return data[0];
	}
};

#endif // RESULT_H