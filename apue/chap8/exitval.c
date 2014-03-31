#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void pr_exit(int status)
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
                WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n",
                WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status) ? " (core file generated)" : "");
#else
        "");
#endif
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n",
                WSTOPSIG(status));
    }
}

int main(void)
{
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        exit(7);
    }
    wait(&status);
    pr_exit(status);

    if ((pid = fork()) == 0) {
        abort();
    }
    wait(&status);
    pr_exit(status);

    if ((pid = fork()) == 0) {
        status /= 0;
    }
    wait(&status);
    pr_exit(status);
    return 0;
}
