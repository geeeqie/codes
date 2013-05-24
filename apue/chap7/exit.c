#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("I'm birthing!\n");
    //_Exit(0);
    _exit(0);
    printf("I'm dieing!\n");
    return 0;
}
