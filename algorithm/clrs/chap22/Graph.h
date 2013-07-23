class Graph {
public:
    Graph();
    virtual ~Graph();
    int nr_vertex;
    int nr_edge;
    virtual void add_edge(int v1, int v2);
    virtual bool has_edge(int v1, int v2);
    void print();
};

class AdjacencyMatrixGraph:public Graph {
public:
    AdjacencyMatrixGraph(int nr_vertex_);
    ~AdjacencyMatrixGraph() {};
private:
    int *_adjacency_matrix;
};

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int nr_vertex_)
{
    nr_vertex = nr_vertex_;
    _adjacency_matrix = new int[nr_vertex*nr_vertex];
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    delete[] _adjacency_matrix;
}

void AdjacencyMatrixGraph::add_edge(int v1, int v2)
{
}

