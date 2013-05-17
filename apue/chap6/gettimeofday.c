/*
 * gettimeofday
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/17
 * @description
 */

#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    printf("tv_sec = %ld\n", tv.tv_sec);
    printf("tv.usec = %ld\n", tv.tv_usec);
    return 0;
}
