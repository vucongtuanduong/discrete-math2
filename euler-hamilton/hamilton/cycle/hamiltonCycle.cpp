#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct Graph {
    int nV;
    int nE;
    vector<int> edges[1001]; // Assuming a maximum of 1000 vertices
};
vector<int> path;
vector<bool> visited;
void findHamiltonianCycle(Graph* g, int startVertex);
void explorePath(Graph* g, int vertex, int length);
int main() {
    int nV, nE;
    cin >> nV >> nE;
    Graph* g = new Graph;
    g->nV = nV;
    g->nE = nE;
    cin.ignore(); // Clear the newline from the input buffer
    for (int i = 0; i < nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            g->edges[i].push_back(stoi(temp) - 1); // Adjust index to 0-based
        }
    }
    findHamiltonianCycle(g, 0);
    delete g; // Deallocate memory for graph
    return 0;
}
void findHamiltonianCycle(Graph* g, int startVertex) {
    path.resize(g->nV);
    visited.resize(g->nV, false);
    path[0] = startVertex;
    visited[startVertex] = true;
    explorePath(g, startVertex, 1);
}
void explorePath(Graph* g, int vertex, int length) {
    if (length == g->nV && g->edges[vertex][0] == path[0]) {
        for (int i = 0; i < length; i++) {
            cout << path[i] + 1 << " "; // Printing 1-based index
        }
        cout << path[0] + 1 << endl; // Print the first vertex again for the cycle
    } 
    else {
        for (int i = 0; i < g->edges[vertex].size(); i++) {
            int nextVertex = g->edges[vertex][i];
            if (!visited[nextVertex]) {
                path[length] = nextVertex;
                visited[nextVertex] = true;
                explorePath(g, nextVertex, length + 1);
                visited[nextVertex] = false;
            }
        }
    }
}
