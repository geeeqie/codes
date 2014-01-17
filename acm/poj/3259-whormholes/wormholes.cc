/*
 * 判断是否有负环, Bellman-Ford
 * - 正边是双向的, 有重边
 *
 */

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct Edge {
    Edge(int _u, int _v) {u = _u; v = _v;};
    int u, v;
};

class Graph {
public:
    Graph(int _nr_vertex) {
        nr_vertex = _nr_vertex;
        graph = new vertex*[nr_vertex];
        memset(graph, 0, sizeof(vertex*)*nr_vertex);
    }

    ~Graph() {
        for (int i = 0; i < nr_vertex; i++) {
            vertex *p = graph[i];
            while(p) {
                vertex *next= p->next;
                delete p;
                p = next;
            }
        }
        delete[] graph;
    }

    void add_edge(int u, int v)
    {
        vertex *vt = new vertex(v);
        if (graph[u]) {
            vt->next = graph[u];
        }
        graph[u] = vt;
        _edges.push_back(Edge(u, v));
    }

    vector<Edge>& edges() { return _edges;};

private:
    struct vertex {
        vertex(int _id) {id = _id; next = NULL;}
        int id; vertex *next; 
    };

    vertex **graph;
    int nr_vertex;
    vector<Edge> _edges;
};

int N, M, W;
#define INFINITY 99999999

bool bellman_ford(Graph *g, int *weight)
{
    int *d = new int[N];
    d[0] = 0;
    for (int j = 1; j < N; j++) {
        d[j] = INFINITY;
    }

    vector<Edge>& edges = g->edges();
    for (int j = 0; j < N; j++) {
        for (size_t k = 0; k < edges.size(); k++) {
            int u = edges[k].u;
            int v = edges[k].v;
//            printf("u=%d, v=%d, d[u]=%d, w[u][v]=%d, d[v]=%d\n", u, v, d[u], weight[u+v*N], d[v]);
            if (d[u] + weight[u+v*N] < d[v]) {
                d[v] = d[u] + weight[u+v*N];
            }
        }
//        for(int i = 0; i < N; i++) {
//            printf("%8d ", d[i]);
//        }
//        printf("\n");
    }
    for (size_t j = 0; j < edges.size(); j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        if (d[u] + weight[u+v*N] < d[v]) {
            delete[] d;
            return false;
        }
    }
    delete[] d;
    return true;
}

int main(int argc, char const *argv[])
{
    int nFarm;
    
    scanf("%d", &nFarm);
    for (int i = 0; i < nFarm; i++) {
        int S, E, T;
        scanf("%d%d%d", &N, &M, &W);

        Graph *g = new Graph(N);
        int *weight = new int[N*N];

        for (int j = 0; j < N*N; j++) {
            weight[j] = INFINITY;
        }

        for (int j = 0; j < M; j++) {
            scanf("%d%d%d", &S, &E, &T);
            S--;E--;
            if (weight[S+E*N] > T) {
                if (weight[S+E*N] == INFINITY) {
                    g->add_edge(S, E);
                    g->add_edge(E, S);
                }
                weight[S+E*N] = weight[E+S*N] = T;
            }
        }
        for (int j = 0; j < W; j++) {
            scanf("%d%d%d", &S, &E, &T);
            S--;E--;
            weight[S+E*N] = -T;
            g->add_edge(S, E);
        }
        if (bellman_ford(g, weight)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        delete g;
        delete[] weight;
    }

    return 0;
}
