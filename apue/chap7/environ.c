#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    char **p;
    p = environ;
    while (*p) {
        printf("%s\n", *p);
        p++;
    }
    return 0;
}
