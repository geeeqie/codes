package main

import "fmt"

const INFINITY = 999999999
var n, m int

const MAX = 1001
var graph[MAX][MAX] int;
var dist[MAX][MAX] int;

func floyd() int {
    for i := 1; i <= n; i++ {
        for j := 1; j <= n; j++ {
            if i == j {
                dist[i][j] = 0;
            } else if graph[i][j] != INFINITY {
                dist[i][j] = graph[i][j];
            } else {
                dist[i][j] = INFINITY;
            }
        }
    }

    for k := 1; k <= n; k++ {
        for i := 1; i <= n; i++ {
            for j := 1; j <= n; j++ {
                d := dist[i][k] + dist[k][j];
                if d < dist[i][j] {
                    dist[i][j] = d;
                } else {
                    dist[i][j] = dist[i][j];
                }
            }
        }
//        fmt.Printf("k=%d\n", k);
    }

    for i := 1; i <= n; i++ {
        if dist[i][i] < 0 {
            fmt.Println("negtive cycle detected");
            return INFINITY;
        }
    }

    dmin := INFINITY;
    for i := 1; i <= n; i++ {
        for j := 1; j <= n; j++ {
            if dist[i][j] < dmin {
                dmin = dist[i][j];
            }
        }
    }
    return dmin;
}

func main() {
    fmt.Scanf("%d%d", &n, &m);

    for i := 1; i <= n; i++ {
        for j := 1; j <= n; j++ {
            graph[i][j] = INFINITY;
        }
    }

    for i := 0; i < m; i++ {
        var u, v, d int;
        fmt.Scanf("%d%d%d", &u, &v, &d);
        graph[u][v] = d;
    }

    fmt.Printf("min=%d\n", floyd());
}
