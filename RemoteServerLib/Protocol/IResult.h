#ifndef IRESULT_H
#define IRESULT_H

#include "../RemoteServerLib.h"
#include <stdlib.h>


enum {
RES_EXEC = 20001,
RES_DOWNLOAD,
RES_UPLOAD,
CRES_DIR,
RES_DEL,
RES_SYS_INFO
};


struct PackResult
{
	UINT commandType;
	UINT paramSize;
	UCHAR *data;
};

void ResultMemUpdate(PackResult* packCommand, size_t m_size)
{
	if(packCommand->paramSize < m_size)
	{
		free(packCommand->data);
		packCommand->data = (UCHAR*)malloc(m_size);
	}
	packCommand->paramSize = m_size;
}

void ResultMemResize(PackResult* packCommand, size_t m_size)
{
	free(packCommand->data);
	packCommand->data = (UCHAR*)malloc(m_size);
	packCommand->paramSize = m_size;
}

void ResultMemInit(PackResult* packCommand)
{
	packCommand->commandType = 0;
	packCommand->data = NULL;
	packCommand->paramSize = 0;
}

void ResultMemFree(PackResult* packCommand)
{
	free(packCommand->data);
	packCommand->commandType = 0;
	packCommand->paramSize = 0;
}



#endif // IRESULT_H