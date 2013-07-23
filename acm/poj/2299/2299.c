#include <stdio.h>
#include <stdlib.h>

long long *a, *aa;

long long merge(long start, long mid, long end)
{
    long i, j, k;
    long long inv = 0;
    
    i = k = start;
    j = mid;
    while (i < mid && j < end) {
        if (a[i] < a[j]) {
            aa[k++] = a[i++];
            inv += j - mid;
        } else {
            aa[k++] = a[j++];
        }
    }
    if (i < mid) {
        inv += (mid - i) * (end - mid);
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
    return inv;
}

long long inversions(long start, long end)
{
    long mid;
    
    if (end - start < 2)
        return 0;
    mid = (start + end) / 2;
    return inversions(start, mid) + inversions(mid, end) + merge(start, mid, end);
}

int main(void)
{
    long i, n;

    while(scanf("%ld", &n) != EOF && n > 0) {
        a = malloc(sizeof(*a) * n);
        aa = malloc(sizeof(*a) * n);
        for (i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        printf("%lld\n", inversions(0, n));
        free(a);
        free(aa);
    }

    return 0;
}
