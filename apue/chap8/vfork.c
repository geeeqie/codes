#include <unistd.h>
#include <stdio.h>

int glob = 6;

int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    printf("before vfork\n");
    if ((pid = vfork()) < 0) {
        printf("vfork error");
    } else if (pid == 0) {
        glob++;
        var++;
        _exit(0);
    }
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

    return 0;
}
