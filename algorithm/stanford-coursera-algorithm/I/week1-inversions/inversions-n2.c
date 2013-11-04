#include <stdio.h>

#define N 100000
long a[N];

int main(void)
{
    long i, j;
    long count = 0;
    long *p = a;

    i = 0;
    while(scanf("%ld", &a[i]) != EOF)
        i++;

    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            if (a[i] > a[j])
                count++;
        }
    }
    printf("inversions = %ld\n", count);
    return 0;
}
