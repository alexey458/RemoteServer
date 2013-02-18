#ifndef ITRANSPORT_H
#define ITRANSPORT_H

#include "../RemoteServerLib.h"

struct TransportPacket
{
	int commandType;
	UCHAR paramSize;
	char CRC[20];
	UCHAR *data;
};

void CheckProtocol(TransportPacket* transport);

void ConnectTo();

void Close(TransportPacket* transport);

void SendData(TransportPacket* transport);

void ReadData(TransportPacket* transport);

void WaitForConnection(TransportPacket* transport);


#endif // ITRANSPORT_H
