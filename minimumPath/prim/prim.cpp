#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];

void prim(int x) {
    vector<bool> visited(nV, false);
    vector<int> d(nV, INF);
    vector<int> truoc(nV, -1);
    for (int i = 0; i < nV; i++) {
        d[i] = a[x][i];
    }
    visited[x] = true;
    truoc[x] = -1;
    d[x] = 0;
    int dem = 1;
    int wt = 0;
    while (dem < nV) {
        int u = -1, min = INF;
        for (int i = 0; i < nV; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        if (u == -1) {
            cout << "Khong co cay khung";
            return;
        }
        visited[u] = true;
        wt += a[u][truoc[u]];
        dem++;
        for (int v = 0; v < nV; v++) {
            if (!visited[v] && d[v] > a[u][v]) {
                d[v] = a[u][v];
                truoc[v] = u;
            }
        }
    }
    cout << wt << endl;
    for (int v = 0; v < nV; v++) {
        if (truoc[v] != -1) {
            cout << v << " " << truoc[v] << endl;
        }
    }
}

void testCase() {
    cin >> nV ;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> a[i][j];
        }
    }
    prim(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }  
    return 0;
}