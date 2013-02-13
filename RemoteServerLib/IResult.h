#ifndef IRESULT_H
#define IRESULT_H

class IResult
{
protected:
	size_t resultType;
	size_t resultSize;
	UCHAR *data;
public:
	virtual ~IResult(void){}
};

class ExecResult :public IResult
{

public:

};

#endif // IRESULT_H