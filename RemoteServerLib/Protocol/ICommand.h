#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../RemoteServerLib.h"
#include <stdlib.h>


enum {
COM_EXEC = 10001,
COM_DOWNLOAD,
COM_UPLOAD,
COM_DIR,
COM_DEL,
COM_SYS_INFO
};


struct PackCommand
{
	UINT commandType;
	UINT paramSize;
	UCHAR *data;
};

void PackageMemUpdate(PackCommand* packCommand, size_t m_size)
{
	if(packCommand->paramSize < m_size)
	{
		free(packCommand->data);
		packCommand->data = (UCHAR*)malloc(m_size);
	}
	packCommand->paramSize = m_size;
}

void PackageMemResize(PackCommand* packCommand, size_t m_size)
{
	free(packCommand->data);
	packCommand->data = (UCHAR*)malloc(m_size);
	packCommand->paramSize = m_size;
}

void PackageMemInit(PackCommand* packCommand)
{
	packCommand->commandType = 0;
	packCommand->data = NULL;
	packCommand->paramSize = 0;
}

void PackageMemFree(PackCommand* packCommand)
{
	free(packCommand->data);
	packCommand->commandType = 0;
	packCommand->paramSize = 0;
}

#endif // ICOMMAND_H