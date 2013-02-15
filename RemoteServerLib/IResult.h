#ifndef IRESULT_H
#define IRESULT_H

class IResult
{
protected:
	size_t resultType;
	size_t resultSize;
	UCHAR *data;
public:
	IResult() : data(NULL)
	{
	}
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

	virtual void setData(size_t mSize, UCHAR* dest_data)
	{
		if(data!=NULL)
		{
			for(size_t i = 0; i< mSize; i++ )
			{
				data[i] = dest_data[i];
			}
			resultSize = mSize;
		}
	}
};


#endif // IRESULT_H