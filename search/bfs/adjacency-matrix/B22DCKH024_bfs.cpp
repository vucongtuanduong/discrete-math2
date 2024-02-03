#include <iostream>
#include <queue>
using namespace std;
struct Graph{
    int nV; //number of vertices
    int nE; //number of edges
    bool **edges; //adjacency matrix
};

Graph *GraphNew(int nV);
void GraphDelete(Graph *g);
void GraphInput(Graph *g);
void dobfs(Graph *g, int start);
void bfs(Graph *g, int v, bool *visited);

int main () {
    int nV, start;
    cin >> nV >> start;
    Graph *g = GraphNew(nV);
    GraphInput(g);
    dobfs(g, start);
    GraphDelete(g);
    return 0;
}
void bfs(Graph *g, int v, bool *visited) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    bool *traversed = new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        traversed[i] = false;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (traversed[u] == false) {
            cout << u + 1 << " ";
            traversed[u] = true;
        }
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void GraphDelete(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        delete [] g->edges[i];
    }
    delete [] g->edges;
    delete g;
}
void dobfs(Graph *g, int start) {
    bool *visited = new bool [g->nV];
    for (int i = 0; i < g->nV; i++)  {
        visited[i] = false;
    }
    cout << "Order of traversed vertices when doing bfs(" << start << "): ";
    bfs(g, start - 1, visited);
}
void GraphInput(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            cin >> g->edges[i][j];
        }
    }
}
Graph *GraphNew(int nV) {
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    g->edges = new bool *[nV];
    for (int i = 0; i < nV; i++) {
        g->edges[i] = new bool[nV];
        for (int j = 0; j < nV; j++) {
            g->edges[i][j] = false;
        }

    }
    return g;
}