/*
 * shadow
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2013/05/17
 * @description
 *    MUST run with root privilege
 */
#include <shadow.h>
#include <stdio.h>

int main(void)
{
    struct spwd *spwd;
    spwd = getspnam("qy");
    printf("shadow password = %s\n", spwd->sp_pwdp);

    setspent();
    while ((spwd = getspent()) != NULL) {
        printf("shadow password = %s\n", spwd->sp_pwdp);
    }
    endspent();
    return 0;
}
