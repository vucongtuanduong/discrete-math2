#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];
void bellman(int x) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, x);
    for (int i = 0; i < nV; i++) {
        d[i] = a[x][i];
    }
    d[x] = 0;

    for (int k = 1; k <= nV - 1; k++) {
        bool ok = false;
        for (int v = 0; v < nV; v++) {
            if (v != x) {
                for (int u = 0; u < nV; u++) {
                    if (a[u][v] != INF && d[v] > d[u] + a[u][v]) {
                        d[v] = d[u] + a[u][v];
                        truoc[v]  = u;
                        ok = true;
                    }
                }
            }
        }
        if (!ok) {
            break;
        }
    }
    
    for (int i = 0; i < nV; i++) {
        if (d[i] == INF)
            cout << "Khong co duong di tu " << x + 1 << " den " << i + 1 << endl;
        else {
            cout << "Duong di ngan nhat tu " << x + 1 << " den " << i + 1 << " bang " << d[i] << ": ";
            int v = i;
            while (v != x) {
                cout << v + 1 << " <- ";
                v = truoc[v];
            }
            cout << x + 1 << endl;

    }
        cout << endl;
    }

}
void testCase() {
    cin >> nV >> nE;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> a[i][j];
        }
    }
    bellman(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }  
    return 0;
}