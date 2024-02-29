#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int edges[101][101] = {0};
};
int bfs(Graph *g, int v, bool *visited);
void listBridges(Graph *g);
void reinit(Graph *g, bool *visited);
int main () {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < nE; i++ ){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g->edges[v][u] = 1;
        g->edges[u][v] = 1;
    }
    listBridges(g);
    return 0;
}
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
}
int bfs(Graph *g, int v, bool *visited) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    set<int> se;
    vector<int> path;
    se.insert(v);
    path.push_back(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (se.count(u) == 0) {
            path.push_back(u);
            se.insert(u);
        }
        for (int i = 0; i < g->nV; i++) {
            if (g->edges[u][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return path.size();
}
void listBridges(Graph *g) {
    bool visited[g->nV];
    vector<pair<int, int>> bridges;
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j] == 1) {
                g->edges[j][i] = 0;
                g->edges[i][j] = 0;
                reinit(g, visited);
                int x = bfs(g, i, visited);
                if (x != g->nV) {
                    bridges.push_back(make_pair(i, j));
                }
                
                g->edges[j][i] = 1;
                g->edges[i][j] = 1;
            }
        }
    }
    if (bridges.size() == 0) {
        cout << "Do thi khong co canh cau";
    }
     else {
        cout << "Cac canh cau: \n";
        for (auto x : bridges) {
            if (g->edges[x.first][x.second] == 1) {
                cout << x.first + 1 << " " << x.second + 1 << endl;
                g->edges[x.first][x.second] = 0;
                g->edges[x.second][x.first] = 0;
            }
        }
    }
}