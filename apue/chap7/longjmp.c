#include <unistd.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void search(int n)
{
    printf("search %d\n", n);
    if (n == 100) {
//        return;
        longjmp(env, 1);
    }
    search(n+1);
    printf("back to %d\n", n);
}

int main(int argc, char const *argv[])
{
    if (setjmp(env) != 0) {
        printf("I'm back\n");
    } else {
        search(0);
    }
    return 0;
}
