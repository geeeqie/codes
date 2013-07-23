#include <stdio.h>

#define N 100000
long a[N], aa[N];

void dump(long start, long mid, long end)
{
    int i;
    printf("start=%ld, mid=%ld, end=%ld\n", start, mid, end);
    for (i = start; i < mid; i++)
        printf("%ld ", a[i]);
    printf("- ");
    for (i = mid; i < end; i++)
        printf("%ld ", a[i]);
    printf("\n");
}

/*
start=0, mid=3, end=6
14108 54044 79294 - 25260 29649 60660 
i=1, j=4, mid=3, inv1=1
i=1, j=5, mid=3, inv1=3
i=2, j=6, mid=3, inv1=6
inv2=9, inv=9
*/
long merge(long start, long mid, long end)
{
    long i, j, k;
    long inv = 0;
    
    i = k = start;
    j = mid;
    //dump(start, mid, end);
    while (i < mid && j < end) {
        if (a[i] < a[j]) {
            aa[k++] = a[i++];
            inv += j - mid;
            //printf("i=%ld, j=%ld, mid=%d, inv1=%ld\n", i, j, mid, inv);
        } else {
            aa[k++] = a[j++];
        }
    }
    if (i < mid) {
        inv += (mid - i) * (end - mid);
        //printf("inv2=%ld, ", inv);
        while (i < mid) 
            aa[k++] = a[i++];
    }
    if (j < end) {
        while (j < end)
            aa[k++] = a[j++];
    }
    for (i = start; i < end; i++) {
        a[i] = aa[i];
    }
    //printf("inv=%ld\n", inv);
    return inv;
}

long inversions(long start, long end)
{
    long mid;
    
    if (end - start < 2)
        return 0;
    mid = (start + end) / 2;
    return inversions(start, mid) + inversions(mid, end) + merge(start, mid, end);
}

int main(void)
{
    long i, j;
    long *p = a;

    i = 0;
    while(scanf("%ld", &a[i]) != EOF)
        i++;

    printf("inversions = %ld\n", inversions(0, N));
    return 0;
}
