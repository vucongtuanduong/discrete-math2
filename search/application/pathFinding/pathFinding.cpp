#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[105];
};
void dfs(Graph *g, int v, bool *visited, int *predecessor);
void bfs(Graph *g, int v, bool *visited, int *predecessor);
void findPath(Graph *g, int src, int dest, string algo);
void doFindPath(Graph *g, int src, int dest);
void reinit(Graph *g, bool *visited, int *predecessor);
int main () {
    Graph *g = new Graph;
    int nV, src, dest;
    cin >> nV >> src >> dest;
    cin.ignore();
    g->nV = nV;
    for (int i = 0; i < g->nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            g->edges[i].push_back(stoi(temp) - 1);
        }
    }
    doFindPath(g, src - 1, dest - 1);
}
void reinit(Graph *g, bool *visited, int *predecessor) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
        predecessor[i] = -1;
    }
}
void findPath(Graph *g, int src, int dest, string algo) {
    vector<int> path;
    bool visited[g->nV];
    int predecessor[g->nV];
    reinit(g, visited, predecessor);
    if (algo == "dfs") {
        dfs(g, src, visited, predecessor);
    } else if (algo == "bfs") {
        bfs(g, src, visited, predecessor);
    }
    if (predecessor[dest] == -1) {
        cout << "Khong tim thay duong di tu " << src << " den " << dest << endl;
        return;
    } 
    else {
        int u = predecessor[dest];
        path.push_back(dest + 1);
        path.push_back(u + 1);
        while (u != src) {
            u = predecessor[u];
            path.push_back(u + 1);
        }
    }
    cout << "Duong di tu " << src + 1 << " den " << dest + 1 << " su dung thuat toan " << algo << " : ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] ;
        if (i != 0) {
            cout << " -> ";
        }
    }
    cout << endl;
    reinit(g, visited, predecessor);
}
void bfs(Graph *g, int v, bool *visited, int *predecessor) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g->edges[u].size(); i++) {
            if (!visited[g->edges[u][i]]) {
                q.push(g->edges[u][i]);
                visited[g->edges[u][i]] = true;
                predecessor[g->edges[u][i]] = u;
            }
        }
    }
}

void doFindPath(Graph *g, int src, int dest) {
    findPath(g, src, dest, "dfs");
    findPath(g, src, dest, "bfs");
}
void dfs(Graph *g, int v, bool *visited, int *predecessor) {
    stack<int> st;
    st.push(v);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < g->edges[u].size(); i++) {
            if (!visited[g->edges[u][i]]) {
                st.push(u);
                st.push(g->edges[u][i]);
                predecessor[g->edges[u][i]] = u;
                visited[g->edges[u][i]] = true;
                break;
            }
        }
    }
}