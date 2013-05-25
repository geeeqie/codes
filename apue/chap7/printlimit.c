#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

#define doit(name) pr_limits(#name, name)

void pr_limits(char *name, int resource)
{
    struct rlimit limit;

    getrlimit(resource, &limit);
    printf("%-14s ", name);
    if (limit.rlim_cur == RLIM_INFINITY)
        printf("(infinity) ");
    else
        printf("%10ld ", limit.rlim_cur);

    if (limit.rlim_max == RLIM_INFINITY)
        printf("(infinity) ");
    else
        printf("%10ld ", limit.rlim_max);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    doit(RLIMIT_AS);
    doit(RLIMIT_CPU);
    doit(RLIMIT_FSIZE);
    doit(RLIMIT_DATA);
    doit(RLIMIT_STACK);
    doit(RLIMIT_CORE);
    doit(RLIMIT_RSS);
    doit(RLIMIT_NOFILE);
    doit(RLIMIT_OFILE);
    doit(RLIMIT_NPROC);
    doit(RLIMIT_MEMLOCK);
    doit(RLIMIT_LOCKS);
    doit(RLIMIT_SIGPENDING);
    doit(RLIMIT_MSGQUEUE);
    doit(RLIMIT_NICE);
    doit(RLIMIT_RTPRIO);
    doit(RLIMIT_RTTIME);
    doit(RLIMIT_NLIMITS);

    return 0;
}
