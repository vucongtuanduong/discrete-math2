#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e7;
struct Graph {
    int nV, nE;
    vector<vector<int>> edges;
};
void bellman_ford(Graph* g, int start) {
    vector<int> dist(g->nV, MAX);
    dist[start] = 0;
    for (int k = 0; k < g->nV - 1; k++) {
        for (int j = 0; j < g->nV; j++) {
            for (int i = 0; i < g->nV; i++) {
                if (g->edges[j][i] != MAX && dist[i] > dist[j] + g->edges[j][i]) {
                    dist[i] = dist[j] + g->edges[j][i];
                }
            }
        }
    }
    cout << "Shortest path from vertex " << start + 1 << " to other vertices: ";
    for (int i = 0; i < g->nV; i++) {
        if (dist[i] == MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
        
    }
}
void testCase() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    Graph* g = new Graph;
    g->nV = nV;
    g->nE = nE;
    g->edges.resize(nV, vector<int>(nV, MAX));
    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g->edges[u - 1][v - 1] = w;
    }
    bellman_ford(g, start - 1);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}