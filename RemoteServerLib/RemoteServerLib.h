#ifndef REMOTESERVERLIB_H
#define REMOTESERVERLIB_H


#define UCHAR unsigned char
#define UINT unsigned int
#define NULL 0

#ifdef _DEBUG
#include <stdio.h>
	#define PRINT(str) printf("%s", str)
#else
	#define PRINT(str)
#endif

void InitRemoteServer()
{
}

void CloseRemoteServer()
{
}


#endif // REMOTESERVERLIB_H