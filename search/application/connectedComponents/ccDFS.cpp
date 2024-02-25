#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;
struct Graph{
    int nE;
    int nV;
    bool edges[105][105];
};
void dfs(Graph *g, int v, bool *visited);
void connectedComponenents(Graph *g);
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
    connectedComponenets(g);
    return 0;
}
void connectedComponenents(Graph *g) {
    bool visited[g->nV];
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
    cout << "Connected Components: ";
    for (int i = 0; i < g->nV; i++) {
        if (!visited[i]) {
            dfs(g, i, visited);
        }
    }
}
void dfs(Graph *g, int v, bool *visited) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    set<int> se;
    vector<int>path;
    se.insert(v);
    path.push_back(v);
    while (!st.empty()){ 
        int u = st.top();
        st.pop();
        if (se.count(u) < 1) {
            path.push_back(u);
            se.insert(u);
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
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}