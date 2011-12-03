/*
 * Server.c
 *
 * @author Geeeqie@gmail.com
 * @date 2011/12/04
 * @description
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
int main(int argc, char** argv)
{
	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in addr;

	WSAStartup(MAKEWORD(2,2), &wsaData);
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4567);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(s, (struct sockaddr*) &addr, sizeof(addr));
		
	listen(s, 1);
	while(1) {
		struct sockaddr addrClient;
		int addrLen;
		char buf[MAX];
		int i;
		int nRecv;
		SOCKET sockClient;

		sockClient = accept(s, &addrClient, &addrLen);
		printf("accept\n");
		nRecv = recv(sockClient, buf, MAX, 0);
		buf[nRecv] = 0;
		printf("Recv: %s\n", buf);
		for(i = 0; i < nRecv; i++) {
			buf[i] = toupper(buf[i]);
		}
		printf("Send: %s\n", buf);
		send(sockClient, buf, nRecv, 0);
		closesocket(sockClient);
	}
	closesocket(s);
	return 0;
}
