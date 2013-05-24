/*
 * env.c
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/25
 * @description
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *str;

    str = getenv("HOME");
    printf("HOME=%s\n", str);

    setenv("FUTURE", "unknown", 0);
    str = getenv("FUTURE");
    printf("FUTURE=%s\n", str);

    return 0;
}
