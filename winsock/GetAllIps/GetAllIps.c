#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(int argc, char** argv)
{
	WORD wVersionRequested;
	WSADATA wsaData;

	char szHostName[MAX];
	HOSTENT* pHost;
	char** p;

	wVersionRequested = MAKEWORD(2,2);
	WSAStartup(wVersionRequested, &wsaData);
///////////////////////////////////////////////
	gethostname(szHostName, MAX);
	pHost = gethostbyname(szHostName);
	
	p = pHost->h_addr_list;
	while(*p) {
		IN_ADDR addr;
		memcpy(&addr.S_un.S_addr, *p, pHost->h_length);
		printf("%s: %s\n", szHostName, inet_ntoa(addr));
		p++;
	}

///////////////////////////////////////////////
	WSACleanup();
}
