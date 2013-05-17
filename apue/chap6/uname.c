/*
 * uname.c
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/17
 * @description
 */

#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    struct utsname name;
    char hostname[64];

    uname(&name);
    printf("sysname = %s\n", name.sysname);
    printf("nodename = %s\n", name.nodename);
    printf("release = %s\n", name.release);
    printf("version = %s\n", name.version);
    printf("machine= %s\n", name.machine);

    gethostname(hostname, sizeof(hostname));
    printf("gethostname=%s\n", hostname);
    return 0;
}
