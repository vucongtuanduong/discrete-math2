#include <iostream>
#include <set>
#include <stack>
using namespace std;
struct Graph{
    int nV; //number of vertices
    int nE; //number of edges
    bool **edges; //adjacency matrix
};
Graph *GraphNew(int nV);
void GraphDelete(Graph *g);
void GraphInput(Graph *g);
void dfsRec(Graph *g, int v, bool *visited);
void dodfs(Graph *g, int start);
void dfsNotRec(Graph *g, int v, bool *visited);
void reinit(Graph *g, bool *visited);
int main () {
    int nV, start;
    cin >> nV >>  start;
    Graph *g = GraphNew(nV);
    GraphInput(g);
    dodfs(g, start);
    GraphDelete(g);
    return 0;
}
void dfsNotRec(Graph *g, int v, bool *visited) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    bool *traversed =  new bool[g->nV];
    for (int i = 0; i < g->nV; i++) {
        traversed[i] = false;
    }
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (traversed[u] == false) {
            cout << u + 1 << " ";
            traversed[u] = true;
        }
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] && !visited[i]) {
                st.push(u);
                st.push(i);
                visited[i] = true;
                break;
            }
        }
    }
}
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
}
void GraphDelete(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        delete [] g->edges[i];
    }
    delete [] g->edges;
    delete g;
}
void dodfs(Graph *g, int start) {
    bool *visited = new bool [g->nV];
    for (int i = 0; i < g->nV; i++)  {
        visited[i] = false;
    }
    cout << "Order of traversed vertices when doing dfs(" << start << ") with recursion: ";
    dfsRec(g, start - 1, visited);//using recursion
    reinit(g, visited);
    cout << "\nOrder of traversed vertices when doing dfs(" << start << ") without recursion: ";

    dfsNotRec(g, start - 1, visited);//not using recursion
}
void dfsRec(Graph *g, int v, bool *visited) {
    visited[v] = true;
    cout << v + 1 << " ";
    for (int i = 0; i < g->nV; i++) {
        if (g->edges[v][i] && !visited[i]) {
            dfsRec(g, i, visited);
        }
    }
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