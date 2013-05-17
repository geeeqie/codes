/*
 * getpwnam
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/17
 * @description
 */
#include <pwd.h>
#include <stdio.h>

int main(void)
{
    struct passwd *pwd;
    setpwent();
    while ((pwd = getpwent()) != NULL) {
        printf("name=%s\n", pwd->pw_name);
    }
    endpwent();
    return 0;
}

