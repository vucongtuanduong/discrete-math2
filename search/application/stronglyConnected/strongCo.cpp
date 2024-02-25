#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <queue>
using namespace std;
struct Graph{
    int nE;
    int nV;
    bool edges[105][105];
};
int bfs(Graph *g, int v, bool *visited);
void reinit(bool *visited);
bool isStronglyConnected(Graph *g) ;
int main () {
    int nV;
    cin >> nV;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> g->edges[i][j];
            if (g->edges[i][j] == 1) {
                g->nE ++;
            }
            
        }
    }
    g->nE /= 2;
    if (isStronglyConnected(g)) {
        cout << "Do thi lien thong manh";
    } else {
        cout << "Do thi lien thong yeu";
    }
    return 0;
}
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
}
bool isStronglyConnected(Graph *g) {
    bool visited[g->nV];
    reinit(g, visited);
    for (int i = 0; i < g->nV; i++) {
        int x = bfs(g, i, visited);
        if (x != g->nV) {
            return false;
        }
        reinit(g, visited);
    }
    return true;
}
int bfs(Graph *g, int v, bool *visited) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    set<int> se;
    vector<int>path;
    se.insert(v);
    path.push_back(v);
    while (!q.empty()){ 
        int u = q.front();
        q.pop();
        if (se.count(u) < 1) {
            path.push_back(u);
            se.insert(u);
        }
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return path.size();
}