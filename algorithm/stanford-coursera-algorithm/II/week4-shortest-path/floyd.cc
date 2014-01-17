#include <stdio.h>

#define INFINITY 999999999
int n, m;

#define MAX 1001
int graph[MAX][MAX];
int dist[MAX][MAX];

void dump()
{
    printf("---\n");
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("---\n");
}
int floyd()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != INFINITY)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = INFINITY;
        }
    }

    // dump();

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int d = dist[i][k] + dist[k][j];
                if (d < dist[i][j]) {
                    dist[i][j] = d;
                } else {
                    dist[i][j] = dist[i][j];
                }
                // dump();
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            printf("negtive cycle detected\n");
            return INFINITY;
        }
    }
            
    int dmin = INFINITY;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dist[i][j] < dmin) dmin = dist[i][j];
    return dmin;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INFINITY;

    for (int i = 0; i < m; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        graph[u][v] = d;
    }

    printf("min=%d\n", floyd());

    return 0;
}
