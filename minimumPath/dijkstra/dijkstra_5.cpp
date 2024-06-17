#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];
void dijkstra(int x) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, x);
    vector<bool> visited(nV, false);
    for (int i = 0; i < nV; i++) {
        d[i] = a[x][i];
    }
    while (true) {
        int u = -1, min = INT_MAX;
        for (int v = 0; v < nV; v++) {
            if (!visited[v] && d[v] < min) {
                min = d[v];
                u = v;
            }
        }
        if (u == -1) {
            break;
        }
        visited[u] = true;
        for (int v = 0; v < nV; v++) {
            if (a[u][v] != INF && !visited[v] && d[v] > d[u] + a[u][v]) {
                d[v]  = d[u] + a[u][v];
                truoc[v] = u;
            }
        }
    }
    for (int i = 0; i < nV; i++) {
        if (d[i] == INF)
            cout << "INF ";
        else
            cout << d[i] << " ";
    }
    cout << endl;
}


void testCase() {
    cin >> nV >> nE;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> a[i][j];
        }
    }
    dijkstra(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }  
    return 0;
}