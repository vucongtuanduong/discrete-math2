#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
int dfs(Graph *g, int v, bool *visited, int x);
void listPendant(Graph *g);
void reinit(Graph *g, bool *visited);
int main () {
    int t;
    cin >> t;
    while (t--) {
        int nV, nE;
        cin >> nV >> nE;
        Graph *g = new Graph;
        g->nV = nV;
        g->nE = nE;
        for (int i = 0; i < nE; i++ ) {
            int v, u;
            cin >> v >> u;
            u--;
            v--;
            g->edges[v].push_back(u);
            g->edges[u].push_back(v);
        }
        listPendant(g);
    }
    
    return 0;
}
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
}
void listPendant(Graph *g) {
    bool visited[g->nV];
    // reinit(g, visited);
    vector<int> pendants;
    for (int i = 0; i < g->nV; i++) {
        reinit(g, visited);
        int x = 0;
        if (i == 0) {
            x = dfs(g, 1, visited, i);
            
        } else {
            x = dfs(g, i - 1, visited, i);
        }
        // cout << "i = " << i << ", x = " << x  << endl;
        if (x != g->nV - 1) {
            pendants.push_back(i + 1);
        }
        
    }
    if (pendants.size() == 0) {
        // cout << "Khong co dinh tru";
    } else {
        for (int i = 0; i < pendants.size(); i++) {
            cout << pendants[i] << " ";
        }
        cout << endl;
    }

}
int dfs(Graph *g, int v, bool *visited, int x) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    set<int> se;
    se.insert(v);
    vector<int> path;
    path.push_back(v);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (se.count(u) == 0) {
            path.push_back(u);
            se.insert(u);
        }
        for (int i = 0; i < g->edges[u].size(); i++) {
            int curr = g->edges[u][i];
            if (curr != x) {
                if (!visited[curr]) {
                    st.push(u);
                    st.push(curr);
                    visited[curr] = true;
                    break;
                }
            }
            
        }   
    }
    // for (auto x : path) {
    //     cout << x << " ";
    // }
    // cout << endl;
    return path.size();
}