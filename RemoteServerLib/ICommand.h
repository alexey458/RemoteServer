#ifndef ICOMMAND_H
#define ICOMMAND_H

#define UCHAR unsigned char
#define NULL 0

enum {
COM_EXEC = 10001,
COM_DOWNLOAD,
COM_UPLOAD,
COM_DIR,
COM_DEL,
COM_SYS_INFO
};

class ICommand
{
protected:
	size_t commandType;
	size_t paramSize;
	UCHAR *data;
public:

	virtual ~ICommand(void) {
		freeData();
	}

	virtual int getType() { return commandType; }
	virtual void setType(int type) { commandType = type; }

	virtual void newData(size_t mSize) { 
	data = new UCHAR[mSize];
	paramSize = mSize;
	}

	virtual void freeData() { 
	if(data!=NULL)
		delete [] data;
	paramSize = 0;
	}

};


#endif // ICOMMAND_H