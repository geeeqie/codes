#include <stdio.h>
#include <math.h>
#include <limits.h>

#define N 50000

typedef struct {
    int x;
    int y;
} Point;

Point a[N];

long distance(Point p1, Point p2)
{
    long d1 = p1.x - p2.x;
    long d2 = p1.y - p2.y;
    return (d1*d1 + d2*d2);
}

int main(int argc, char const *argv[])
{
    int i, j;
    long min = INT_MAX;

    for (i = 0; i < N; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }

    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            long d = distance(a[i], a[j]);
            if (d < min) {
                min = d;
            }
        }
    }
    printf("min=%lf\n", sqrt(min));
    return 0;
}
