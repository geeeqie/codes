/*
 * time.c
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/18
 * @description
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tm;
    char buf[128];

    time(&t);
    printf("[time]\t\t\t%ld\n", t);

    tm = localtime(&t);
    printf("[asctime+localtime]\t%s", asctime(tm));
    tm = gmtime(&t);
    printf("[asctime+gmtime]\t%s", asctime(tm));

    printf("[mktime]\t\t%ld\n", mktime(tm));

    printf("[ctime]\t\t\t%s", ctime(&t));

    strftime(buf, sizeof(buf), "%D %T", tm);
    printf("[strftime]\t\t%s\n", buf);

    return 0;
}
