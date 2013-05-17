/*
 * getpwuid
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/17
 * @description
 */
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(void)
{
    struct passwd *pwd;

    pwd = getpwuid(0);
    printf("name=%s\n", pwd->pw_name);

    pwd = getpwnam("qy");
    printf("name=%s\n", pwd->pw_name);

    return 0;
}
