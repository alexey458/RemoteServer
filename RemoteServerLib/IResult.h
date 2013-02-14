#ifndef IRESULT_H
#define IRESULT_H

class IResult
{
protected:
	size_t resultType;
	size_t resultSize;
	UCHAR *data;
public:
	virtual ~IResult(void){
	freeData();
	}

	virtual void newData(size_t mSize) { 
	data = new UCHAR[mSize];
	resultSize = mSize;
	}

	virtual void freeData() { 
	if(data!=NULL)
		delete [] data;
	resultSize = 0;
	}
};


#endif // IRESULT_H