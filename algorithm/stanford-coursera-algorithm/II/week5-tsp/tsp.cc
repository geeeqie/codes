#include <stdio.h>
#include <math.h>

const double INF = 1000000000;

struct City {
    double x;
    double y;
};

City *cities;
int n;

double distance[30][30];
int *howmuch1;
double *C;

void init_distance()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double x = cities[i].x - cities[j].x;
            double y = cities[i].y - cities[j].y;
            distance[i][j] = sqrt(x*x + y*y);
            printf("dist %d -> %d = %lf\n", i, j, distance[i][j]);
        }
    }
}

void subset(int size)
{
    for (int g = 0; g < 1<<(n-1); g++) {
        int s = (g<<1) | 1;
        if (howmuch1[s] == size) {
            C[s*n + 0] = INF;
            for (int j = 1; j < n; j++) {
                if (s & (1<<j)) {
                    double min_dist = INF;
                    for (int i = 0; i < n; i++) {
                        if ((s & (1<<i)) && i!=j) {
                            double dist = C[(s&(~(1<<j)))*n + i] + distance[i][j];
                            if (dist < min_dist) min_dist = dist;
                        }
                    }
                    C[s*n + j] = min_dist;
                }
            }
        }
    }
}

double tsp(City *c)
{
    init_distance();
    C[(1 * n) + 0] = 0;
    for (int size = 2; size <= n; size++) {
        printf("size = %d\n", size);
        subset(size);
    }
    double min_dist = INF;
    int S = (1<<n)-1;
    for (int j = 1; j < n; j++) {
         double dist = C[S*n + j] + distance[j][0];
         if (dist < min_dist) {
             min_dist = dist;
         }
    }
    return min_dist;
}


void init_howmuch1()
{
    for (int i = 0; i < (1<<n); i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (i & 1<<j) c++;
        }
        howmuch1[i] = c;
    }
}

int main(int argc, char const *argv[])
{

    scanf("%d", &n);
    cities = new City[n];

    howmuch1 = new int[1<<n];
    init_howmuch1();

    C = new double[(1<<n)*n];  

    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &cities[i].x, &cities[i].y);
    }

    printf("%lf\n", tsp(cities));

    delete[] C;
    delete[] cities;
    return 0;
}
