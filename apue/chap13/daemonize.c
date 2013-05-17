#include <unistd.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>

void daemonize()
{
    umask(0);
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    int pid;
    pid = fork();
    if (pid != 0) {
        exit(0);
    }
    setsid();

    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGHUP, &sa, NULL);
    pid = fork();
    if (pid != 0)
        exit(0);
    chdir("/");
    if (rl.rlim_max == RLIM_INFINITY)
        rl.rlim_max = 1024;
    for (int i = 0; i < rl.rlim_max; i++)
        close(i);

    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);
}

int main(void)
{
    daemonize();
    while(1) {
        printf("I'm daemon\n");
        sleep(1);
    }
    return 0;
}
