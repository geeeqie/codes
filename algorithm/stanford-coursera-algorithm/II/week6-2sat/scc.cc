#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Element {
    int v;
    Element *next;
};

Element **G;
Element **G_reverse;
bool *visited;
int *id;
vector<int> f;

void graph_add(Element *graph[], int u, int v)
{
    Element *p = graph[u];
    if (p) {
        Element *new_p = new Element;
        new_p->v = v;
        new_p->next = p->next;
        p->next = new_p;
    } else {
        graph[u] = p = new Element;
        p->v=v;
        p->next = NULL;
    }
}

vector<int> dfs_v;
int curid = 0;

void DFS(Element *graph[], int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    dfs_v.push_back(u);
    id[u] = curid;

    Element *p = graph[u];
    while(p) {
        DFS(graph, p->v);
        p = p->next;
    }
    if (graph == G)
        f.push_back(u);
}

int main(void)
{
    int u, v;

    int n;
    scanf("%d", &n);

    int N = n*2+1;

    G = new Element*[N];
    G_reverse = new Element*[N];
    visited = new bool[N];
    id = new int[N];

    for(int i = 0; i < N; i++) {
        G[i] = NULL;
        G_reverse[i] = NULL;
        visited[i] = false;
        id[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &u, &v);

        int a = -u, b = v;
        if (a < 0) {
            a = -a + n;
        }
        if (b < 0) {
            b = -b + n;
        }
        graph_add(G, a, b);
        graph_add(G_reverse, b, a);

        a = -v; b = u;
        if (a < 0) {
            a = -a + n;
        }
        if (b < 0) {
            b = -b + n;
        }
        graph_add(G, a, b);
        graph_add(G_reverse, b, a);
    }

    printf("read graph ok\n");
    for (int i = 1; i < N; i++) {
        DFS(G, i);
    }

    for(int i = 0; i < N; i++) {
        visited[i] = false;
    }
    vector<int> scc_size;

    printf("DFS G ok\n");
    printf("f.size = %ld\n", f.size());
    while (!f.empty()) {
        dfs_v.clear();
        curid++;
        DFS(G_reverse, f.back());
        f.pop_back();
        if (dfs_v.size() > 0) {
            scc_size.push_back(dfs_v.size());
        }
    }
    printf("DFS G_reverse ok\n");

    sort(scc_size.begin(), scc_size.end());
    reverse(scc_size.begin(), scc_size.end());
    for (int i = 0; i < 5; i++) {
        printf("%d, ", scc_size[i]);
    }
    printf("END: size = %ld\n", scc_size.size());

    for (int i = 1; i <= n; i++) {
        if (id[i] == id[i+n]) {
            printf("no solution\n");
            break;
        }
    }
    printf("\n");

    delete[] G;
    delete[] G_reverse;
    delete[] visited;
    delete[] id;
    return 0;
}
