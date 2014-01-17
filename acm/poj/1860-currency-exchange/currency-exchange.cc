/*
 * Bellman-Ford, 判断是否有一直能增大的路径
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

#define MAX 101
double R[MAX][MAX], C[MAX][MAX];

int N, M, S;
double V;

bool bellman_ford(Graph& g)
{
    double *d = new double[N];
    for (int j = 0; j < N; j++) {
        d[j] = 0;
    }
    d[S] = V;

    vector<Edge>& edges = g.edges();
    for (int j = 0; j < N; j++) {
        for (size_t k = 0; k < edges.size(); k++) {
            int u = edges[k].u;
            int v = edges[k].v;
//            printf("u=%d, v=%d, d[u]=%d, w[u][v]=%d, d[v]=%d\n", u, v, d[u], weight[u+v*N], d[v]);
            if ( (d[u] - C[u][v])*R[u][v] > d[v]) {
                d[v] = (d[u] - C[u][v])*R[u][v];
            }
        }
//        for(int i = 0; i < N; i++) {
//            printf("%8lf ", d[i]);
//        }
//        printf("\n");
    }
    for (size_t j = 0; j < edges.size(); j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        if ( (d[u] - C[u][v])*R[u][v] > d[v]) {
            d[v] = (d[u] - C[u][v])*R[u][v];
            delete[] d;
            return false;
        }
    }
    delete[] d;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%lf", &N, &M, &S, &V);
    S--;
    Graph g(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        scanf("%lf%lf%lf%lf", &R[a][b], &C[a][b], &R[b][a], &C[b][a]);
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    if (bellman_ford(g)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
