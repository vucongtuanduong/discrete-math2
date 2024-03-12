#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int startVertice;
    int endVertice;
    int edges[101][101];
};
void findEulerPath(Graph *g);
bool hasAdjacent(Graph *g, int v);
int findStartVertice(Graph *g);
bool isSemiEulerian(Graph *g);
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Graph *g = new Graph;
    int nV, nE;
    cin >> nV >> nE;
    g->nV = nV;
    g->nE = nE;
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            cin >> g->edges[i][j];
        }
    }
    if (isSemiEulerian(g)) {
        cout << "Do thi la do thi nua Euler\n";
    } else {
        cout << "Do thi khong la do thi nua Euler\n";
    }
    findEulerPath(g);
    return 0;
}
bool isSemiEulerian(Graph *g) {
    bool ok1 = false, ok2 = false;
    for (int i = 0; i < g->nV; i++) {
        int outdegree = 0, indegree = 0;
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                outdegree++;
            } 
            if (g->edges[j][i])  {
                indegree++;
            }
        }
        if (outdegree - indegree == 1 ) {
            if (ok1 == false) {
                g->startVertice = i;
                ok1 = true;
            } else {
                return false;
            }
            
        }
        else if (indegree - outdegree == 1) {
            if (ok2 == false) {
                g->endVertice = i;
                ok2 = true;
            } else {
                return false;
            }
        } else if (indegree == outdegree) {

        } else {
            return false;
        }

    }
    return true;
}
bool hasAdjacent(Graph *g, int v) {
    for (int i = 0 ; i < g->nV; i++ ){
        if (g->edges[v][i]) {
            return true;
        }
    }
    return false;
}


void findEulerPath(Graph *g) {
    stack<int> st;
    vector<int> eulerpath;
    int start = g->startVertice;
    st.push(start);
    while (!st.empty()) {
        int x = st.top();
        if (hasAdjacent(g, x)) {
            for (int i = 0; i < g->nV; i++) {
                if (g->edges[x][i]) {
                    st.push(i);
                    g->edges[x][i] = 0;
                    break;
                }
            }
        } else {
            int x = st.top();
            st.pop();
            eulerpath.push_back(x);
        }
    }
    for (int i = eulerpath.size() - 1; i >= 0; i--) {
        cout << eulerpath[i] + 1 << " ";
    }
}