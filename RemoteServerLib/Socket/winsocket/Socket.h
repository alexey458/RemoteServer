#ifndef SOCKET_H
#define SOCKET_H

#include <WinSock2.h>

#ifdef WIN32
#pragma comment(lib, "Ws2_32.lib")
#endif

struct RSOCKET
{
	SOCKET socket;
}

int init_socks_lib()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        return 1;
    }
	return 0;
}

void clean_sock_lib()
{
	WSACleanup();
}

void rsocket(RSOCKET* rsocket)
{
	rsocket->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void rconnect(RSOCKET* rsocket, const char* address, int port)
{
	sockaddr_in ssin;
	ssin.sin_addr.S_un.S_addr = inet_addr(address);
	ssin.sin_port = htons(port);
	connect(rsocket->socket, (SOCKADDR *)&ssin, sizeof(ssin));
}

void rclose(RSOCKET* rsocket)
{
	closesocket(rsocket->socket);
}

void rsend(RSOCKET* rsocket, const char* buff, int len, int flags)
{
	send(rsocket->socket, "", 0, 0);
}

void rrecv(RSOCKET* rsocket, const char* buff, int len, int flags)
{
	recv(rsocket->socket, "", 0, 0);
}

void rbind(RSOCKET* rsocket, const char* address, int port)
{
	sockaddr_in service;
	service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(address);
    service.sin_port = htons(port);
	bind(rsocket->socket, (SOCKADDR *) &service, sizeof (service));
}

RSOCKET raccept(RSOCKET* rsocket)
{
	RSOCKET rsock;
	rsock.socket = accept(rsocket->socket, 0, 0);
	return rsock;
}


#endif // SOCKET_H