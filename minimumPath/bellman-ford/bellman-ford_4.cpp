#include <bits/stdc++.h>
using namespace std;
const int INF = 1e3;
int nV, nE;
int a[101][101];

void bellman_ford(int s) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, s);
    
    for (int i = 0; i < nV; i++) {
        d[i] = a[s][i];
    }
    d[s] = 0;
    for (int k = 1; k <= nV - 1; k++) {
        bool ok = true;
        for (int v = 0; v < nV; v++) {
            if (v != s) {
                for (int u = 0; u < nV; u++) {
                    if (a[u][v] != INF && d[v] > d[u] + a[u][v]) {
                        d[v] = d[u] + a[u][v];
                        truoc[v] = u;
                        ok = false;
                    }
                }
            }
        }
        if (ok) {
            break;
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
    bellman_ford(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }  
    return 0;
}