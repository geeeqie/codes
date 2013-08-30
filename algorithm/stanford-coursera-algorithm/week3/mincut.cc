#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

#define MAX 201
using namespace std;

class edge {
public:
    edge(int _v1, int _v2) {v1 = _v1; v2 = _v2;}
    int v1;
    int v2;
};

int graph[MAX][MAX];
int new_graph[MAX][MAX];

vector<int> getline()
{
    vector<int> data;
    char line[1024];
    char *p = line;

    fgets(line, 1024, stdin);
    while (1) {
        char *s = p;
        while(*p != '\t' && *p != '\n')
            p++;
        if (*p == '\n')
            break;
        *p++ = 0;
        data.push_back(atoi(s));
    }

    return data;
}


void merge(edge e)
{
    for(int i = 0; i < MAX; i++) {
        if (new_graph[e.v2][i]) {
            new_graph[e.v1][i] += new_graph[e.v2][i];
            new_graph[i][e.v1] += new_graph[i][e.v2];

            new_graph[e.v2][i] = 0;
            new_graph[i][e.v2] = 0;
        }
    }
    for(int i = 0; i < MAX; i++) {
        new_graph[i][i] = 0;
    }
}

void print_graph()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", new_graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<edge> get_edges()
{
    vector<edge> e;
    for(int i = 0; i < MAX; i++) {
        for(int j = i; j < MAX; j++) {
            if (new_graph[i][j]) {
                e.push_back(edge(i, j));
            }
        }
    }
    return e;
}

int main(void)
{
    srand(time(NULL));
    for (int i = 1; i < MAX; i++) {
        vector<int> data = getline();
        int v1 = data[0];
        for (int i = 1; i < data.size(); i++) {
            int v2 = data[i];
            graph[v1][v2] = 1;
        }
    }

    int min_cut = MAX*MAX;
    int n_test = 500000;
    while (n_test-- > 0) {
        int n_merge = MAX-2;

//        printf("[test %d] ", n_test);
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                new_graph[i][j] = graph[i][j];


        while (1) {
            vector<edge> edges = get_edges();
            if (edges.size() == 1) {
                int cut = new_graph[edges[0].v1][edges[0].v2];
                if (cut < min_cut) {
                    printf("%d\n", cut);
                    min_cut = cut;
                }
                break;
            }
            int i = rand() % edges.size();
            edge e = edges[i];
//          print_graph();
//          printf("choose [%d, %d]\n", e.v1, e.v2);
            if (new_graph[e.v1][e.v2]) {
                merge(e);
            }
            edges.erase(edges.begin()+i);
        }
//        print_graph();
    }
    printf("min=%d\n", min_cut);

    return 0;
}
