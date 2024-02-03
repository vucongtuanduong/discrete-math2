#include <bits/stdc++.h>
using namespace std;
// #define DEFAULT_CAPACITY 16
typedef int Vertex;
struct edge {
    Vertex v;
    Vertex w;
};
struct Graph{
    int nV;
    int nE;
    edge *edges;
    int maxE;
};

/**
 * Returns a new graph with nV vertices
 */
Graph *GraphNew(int nV);

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph *g);

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph *g);

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph *g);

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w);

/**
 * Adds an edge between v and w
 */
void GraphInsertEdge(Graph *g, Vertex v, Vertex w);

/**
 * Removes an edge between v and w
 */
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w);

/**
 * Returns the degree of a vertex
 */
int GraphDegree(Graph *g, Vertex v);

/**
 * Displays a graph
 */
void GraphShow(Graph *g);

void GraphInput(Graph *g);
void testCase();
int main () {
    testCase();
    return 0;
}
void testCase() {
    int nV;
    cin >> nV;
    Graph *g = GraphNew(nV);
    for (int i = 0; i < nE; i++) {
        int v, w;
        cin >> v >> w;
        GraphInsertEdge(g, v - 1, w - 1);
    }
    GraphShow(g);
    
}
Graph *GraphNew(int nV) {
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    g->edges = new edge[nV];
    g->maxE = nV * (nV - 1) / 2;
    return g;

}
void GraphFree(Graph *g) {
    delete [] g->edges;
    delete g;
}
int GraphNumVertices(Graph *g) {
    return g->nV;
}
int GraphNumEdges(Graph *g) {
    return g->nE;
}
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w) {
    for (int i = 0; i < g->nE; i++ ) {
        if ((g->edges[i].v == v && g->edges[i].w = w) || (g->edges[i].v == w && g->edges[i].w = v)) {
            return true;
        }
    }
    return false;
}
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
    if (!GraphIsAdjacent(g, v, w)) {
        if (g->nE == g->maxE) {
            g->maxE *= 2;
            edge *newEdges = new edge[g->maxE];
        }
        g->edges[g->nE].v = v;
        g->edges[g->nE].w = w;
        g->nE++;
    }
    

}
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
    for (int i = 0; i < g->nE; i++) {
        if ((g->edges[i].v == v && g->edges[i].w = w) || (g->edges[i].v == w && g->edges[i].w = v)) {
            g->edges[i].v = g->edges[g->nE - 1].v;
            g->edges[i].w = g->edges[g->nE - 1].w;
            g->nE--;
            return;
        }
    
    }
}
void GraphShow(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < g->nE; j++) {
            if (g->edges[j].v == i) {
                cout << g->edges[j].w + 1 << " ";
            }
        }
        cout << endl;
    }
}
int GraphDegree(Graph *g, Vertex v) {


	int degree = 0;
	for (int i = 0; i < g->nE; i++) {
        if (g->edges[i].v == v || g->edges[i].w == v) {
            degree++;
        }
    }
    return degree;
}
// void GraphInput(Graph *g) {
//     for (Vertex i = 0 ; i < g->nV; i++) {
//         for (Vertex j = 0; j < g->nV; j++) {
//             cin >> g->edges[i][j];
//             g->nE += g->edges[i][j];
//         }
//     }
// }