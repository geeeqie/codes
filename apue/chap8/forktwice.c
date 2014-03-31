#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) == 0) {
        if ((pid = fork()) > 0) {
            exit(0);
        }
        sleep(2);
        printf("second child, parent pid = %d\n", getppid());
        exit(0);
    }

    waitpid(pid, NULL, 0);
    exit(0);
}
