#include "unp.h"
#define BUF_MAX 255

int main(int argc, char ** argv)
{
	int sockfd;
	struct sockaddr_in serveraddr;
	char buf[BUF_MAX + 1];
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM,0);
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9003);
	inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);
	connect(sockfd, (SA *) &serveraddr, sizeof(serveraddr));

	while( (n = read(sockfd, buf, BUF_MAX)) > 0)
	{
		printf("read %d bytes\n", n);
		//buf[n] = 0;
		//fputs(buf,stdout);
	}
	exit(0);
	
}
