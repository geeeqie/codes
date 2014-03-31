#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("pid=%d\n", getpid());
    printf("parent pid=%d\n", getppid());
    printf("uid=%d\n", getuid());
    printf("gid=%d\n", getgid());
    printf("egid=%d\n", getegid());
    return 0;
}
