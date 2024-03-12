#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int edges[101][101];
};
void findEulerCycle(Graph *g);
bool hasAdjacent(Graph *g, int v);
bool isEulerGraph(Graph *g);
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
    if (isEulerGraph(g)) {
        cout << "Do thi la do thi Euler\n";
    } else {
        cout << "Do thi khong la do thi Euler\n";
    }
    findEulerCycle(g);
    return 0;
}
bool isEulerGraph(Graph *g){
    int degree[g->nV] = {0} ;
    for (int i = 0; i < g->nV; i++) {
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                degree[i]++;
            }
        }
        if (degree[i] % 2 == 1) {
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
void findEulerCycle(Graph *g) {
    stack<int> st;
    vector<int> eulercycle;
    st.push(0);
    while (!st.empty()) {
        int x = st.top();
        if (hasAdjacent(g, x)) {
            for (int i = 0; i < g->nV; i++) {
                if (g->edges[x][i]) {
                    st.push(i);
                    g->edges[x][i] = 0;
                    g->edges[i][x] = 0;
                    break;
                }
            }
        } else {
            int x = st.top();
            st.pop();
            eulercycle.push_back(x);
        }
    }
    for (int i = eulercycle.size() - 1; i >= 0; i--) {
        cout << eulercycle[i] + 1 << " ";
    }
}