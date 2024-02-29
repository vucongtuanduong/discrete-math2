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
void dfs(Graph *g, int v, bool *visited, int x);
void dfs(Graph *g, int v, bool *visited, int x, int *predecessor);
void listPendant(Graph *g, int src, int dest);
void reinit(Graph *g, bool *visited);
void reinit(Graph *g, int *predecessor);
int countConnectedComponents(Graph *g, int x, bool *visited);
int main () {
    int nV, src, dest;
    cin >> nV >> src >> dest;
    src--;
    dest--;
    cin.ignore();
    Graph *g = new Graph;
    g->nV = nV;
    for (int i = 0; i < nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            g->edges[i].push_back(stoi(temp) - 1);
        }
    }
    listPendant(g, src, dest);
    return 0;
}
void reinit(Graph *g, int *predecessor) {
    for (int i = 0; i < g->nV; i++) {
        predecessor[i] = -1;
    }
}
void dfs(Graph *g, int v, bool *visited, int x, int *predecessor) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < g->edges[u].size(); i++) {
            int curr = g->edges[u][i];
            if (curr != x) {
                if (!visited[curr]) {
                    st.push(u);
                    st.push(curr);
                    visited[curr] = true;
                    predecessor[curr] = u;
                    break;
                }
            }
            
        }   
    }
}
void reinit(Graph *g, bool *visited) {
    for (int i = 0; i < g->nV; i++) {
        visited[i] = false;
    }
}
int countConnectedComponents(Graph *g, int x, bool *visited) {
    int count = 0;
    for (int i = 0; i < g->nV; i++) {
        if (!visited[i] && i != x) {
            count++;
            dfs(g, i, visited, x);
        }
    }
    return count;
}
void listPendant(Graph *g, int src, int dest) {
    bool visited[g->nV];
    reinit(g, visited);
    int predecessor[g->nV];

    int countFull = countConnectedComponents(g, -1, visited);
    vector<int> pendants;
    for (int i = 0; i < g->nV; i++) {
        reinit(g, visited);
        int countCheck = countConnectedComponents(g, i, visited);
        if (countCheck > countFull) {
            pendants.push_back(i + 1);
            if (src == (i + 1) || dest == (i + 1)) {
                cout << "Khong co dinh that";
                return;
            }
            reinit(g, predecessor);
            dfs(g, src, visited, i, predecessor);
            if (predecessor[dest] != -1) {
                cout << "Khong co dinh that";
                return;
            }
        }
        
    }
    if (pendants.size() == 0) {
        cout << "Khong co dinh that";
    } else {
        cout << "Dinh that: " ;
        for (int i = 0; i < pendants.size(); i++) {
            cout << pendants[i] << " ";
        }
        cout << endl;
    }

}
void dfs(Graph *g, int v, bool *visited, int x) {
    stack<int> st;
    st.push(v);
    visited[v] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
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
}