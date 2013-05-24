/*
 * atexit.c
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/18
 * @description
 */
#include <stdio.h>
#include <stdlib.h>

void qyexit(void)
{
    printf("I'm exiting\n");
}

void qyexit1(void)
{
    printf("30 years later, I'll be back\n");
}

int main(void)
{
    atexit(qyexit1);
    atexit(qyexit);
    atexit(qyexit1);
}
