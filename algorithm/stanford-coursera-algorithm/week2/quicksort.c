#include <stdio.h>
#include <stdlib.h>
#define N 10000

int count = 0;

int select_pivot_index(int *a, int low, int high)
{
    int median = (high + low - 1) / 2;
    if ((a[low] <= a[high-1] && a[low] >= a[median]) || (a[low] <= a[median] && a[low] >= a[high-1]))
        return low;
    else if ( (a[median] <= a[high-1] && a[median] >= a[low]) || (a[median] >= a[high-1] && a[median] <= a[low]) )
        return median;
    else
        return high - 1;
}

void swap(int *a, int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int *a, int low, int high)
{
    int i, j;
    int pivot = a[low];

    i = j = low + 1;
    while (j < high) {
        count++;
        if (a[j] < pivot) {
            swap(a, i, j);
            i++;
            j++;
        } else {
            j++;
        }
    }
    a[low] = a[i - 1];
    a[i - 1] = pivot;
    return i - 1;
}

void quicksort(int *a, int low, int high)
{
    int pivot;

    if (low >= high)
        return;
    int median = select_pivot_index(a, low, high);
    swap(a, low, median);
    pivot = partition(a, low, high);
    quicksort(a, low, pivot);
    quicksort(a, pivot + 1, high);
}

int main(int argc, char const *argv[])
{
    int i;
    int *a;

    a = malloc(N * sizeof(*a));
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, N);

    for (i = 0; i < N; i++) {
        printf("%d\n", a[i]);
    }
    printf("%d\n", count);

    free(a);
    return 0;
}
