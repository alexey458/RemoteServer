#ifndef ITRANSPORT_H
#define ITRANSPORT_H

#include "../RemoteServerLib.h"
#include "../Socket/Socket.h"

struct TransportPacket
{
	int commandType;
	UCHAR paramSize;
	char CRC[20];
	UCHAR *data;
	RSOCKET* rsocket;
};

void CheckProtocol(TransportPacket* transport)
{
	rrecv(transport->rsocket, (const char*)transport->data, 5, 0);
}

void ConnectTo()
{

}

void Close(TransportPacket* transport)
{

}

void SendData(TransportPacket* transport)
{

}

void ReadData(TransportPacket* transport)
{

}

void WaitForConnection(TransportPacket* transport)
{

}

void Run()
{

}


#endif // ITRANSPORT_H
