/*
 * Client.c
 *
 * @author Geeeqie@gmail.com
 * @date 2011/12/04
 * @description
 */
#include <stdio.h>
#include <string.h>

#define MAX 1000
int main(int argc, char**argv)
{
	WSADATA wsaData;
	SOCKET s; 
	struct sockaddr_in addr;
	char str[MAX];

	WSAStartup(MAKEWORD(2,2), &wsaData);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4567);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	while (gets(str) && strcmp(str, "q")) {
		s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		connect(s, (struct sockaddr*) &addr, sizeof(addr));
		send(s, str, strlen(str), 0);
		recv(s, str, MAX, 0);
		str[strlen(str)] = 0;
		printf("%s\n", str);
		closesocket(s);
	}

	return 0;
}
