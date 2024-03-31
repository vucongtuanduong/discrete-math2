#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int source, destination, weight;
};
class Graph {
    public:
        int nV;//number of vertices
        int nE;
        vector<Edge> edges;
        Graph(int nV, int nE) {
            this->nV = nV;
            this->nE = nE;
        }
        void addEdge(int source, int destination, int weight) {
            Edge e = {source, destination, weight};
            edges.push_back(e);
        }
};

void testCase();
vector<Edge> primMST(Graph &g);
bool cmp(Edge &a, Edge &b);
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
bool cmp(Edge &a, Edge &b) {
    return a.weight > b.weight;
}

void testCase() {
    int nV, nE;
    cin >> nV >> nE;
    Graph g(nV, nE);
    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }
    vector<Edge>MST = primMST(g);
    int totalWeight = 0;
    for (auto edge : MST) {

        cout << edge.source + 1 << " - " << edge.destination + 1 << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight: " << totalWeight << endl;;
}
vector<Edge> primMST(Graph &g) {
    vector<Edge>MST;
    vector<bool> inMST(g.nV, false);
    priority_queue<Edge, vector<Edge>, decltype(&cmp)> pq(&cmp);
    int src = 0;
    inMST[src] = true;
    for (auto edge : g.edges) {
        if (edge.source == src) {
            pq.push(edge);
        }
    }
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (inMST[e.destination]) {
            continue;
        }
        MST.push_back(e);
        inMST[e.destination] = true;
        for (auto edge: g.edges) {
            if (edge.source == e.destination && !inMST[edge.destination]) {
                pq.push(edge);
            }
        }
    }
    return MST;
}