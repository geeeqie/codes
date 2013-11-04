#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define VERTEX_MAX 875714
//#define VERTEX_MAX 9

struct Element {
    int v;
    Element *next;
};

Element *G[VERTEX_MAX + 1];
Element *G_reverse[VERTEX_MAX + 1];
bool visited[VERTEX_MAX + 1];
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

int time;
vector<int> dfs_v;

void DFS(Element *graph[], int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    dfs_v.push_back(u);

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

    while(scanf("%d%d", &u, &v) != EOF) {
        graph_add(G, u, v);
        graph_add(G_reverse, v, u);
    }
    printf("read graph ok\n");
    for (int i = 1; i <= VERTEX_MAX; i++) {
        DFS(G, i);
    }
    memset(visited, 0, sizeof(visited));
    vector<int> scc_size;

    printf("DFS G ok\n");
    while (!f.empty()) {
        dfs_v.clear();
        DFS(G_reverse, f.back());
        f.pop_back();
        if (dfs_v.size() > 0) {
            /*
            for (int j = 0; j < dfs_v.size(); j++)
                printf("%d ", dfs_v[j]);
            printf("\n");
            */
            scc_size.push_back(dfs_v.size());
        }
    }
    printf("DFS G_reverse ok\n");

    sort(scc_size.begin(), scc_size.end());
    reverse(scc_size.begin(), scc_size.end());
    for (int i = 0; i < 5; i++) {
        printf("%d,", scc_size[i]);
    }
    printf("\n");

    return 0;
}
