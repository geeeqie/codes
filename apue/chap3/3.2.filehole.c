#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(void)
{
	int fd;

	if ((fd = creat("file.hole", FILE_MODE)) < 0) {
		printf("creat error\n");
		abort();
	}

	if (write(fd, buf1, 10) != 10) {
		printf("buf1 write error\n");
		abort();
	}

	if (lseek(fd, 16384, SEEK_SET) == -1) {
		printf("lseek error\n");
		abort();
	}

	if (write(fd, buf2, 10) != 10) {
		printf("buf2 write error\n");
		abort();
	}
	
	return 0;
}
