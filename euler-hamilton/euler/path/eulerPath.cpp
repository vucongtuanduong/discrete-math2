#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    int edges[101][101];
};
void findEulerPath(Graph *g);
bool hasAdjacent(Graph *g, int v);
int findStartVertice(Graph *g);
int main () {
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
    findEulerPath(g);
    return 0;
}

bool hasAdjacent(Graph *g, int v) {
    for (int i = 0 ; i < g->nV; i++ ){
        if (g->edges[v][i]) {
            return true;
        }
    }
    return false;
}
int findStartVertice(Graph *g) {
    int start = 0;
    for (int i = 0; i < g->nV; i++) {
        int degree = 0;
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                degree++;
            }
        }
        if (degree % 2 == 1) {
            start = i;
            break;
        }
    }
    return start;
}

void findEulerPath(Graph *g) {
    stack<int> st;
    vector<int> eulerpath;
    int start = findStartVertice(g);
    st.push(start);
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
            eulerpath.push_back(x);
        }
    }
    for (int i = eulerpath.size() - 1; i >= 0; i--) {
        cout << eulerpath[i] + 1 << " ";
    }
}