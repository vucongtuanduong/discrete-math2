#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];

void bellman_ford(int u) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, -1);
    d[u] = 0;
    for (int k = 1; k <= nV - 1; k++) {
        for (int j = 0; j < nV; j++) {
            if (j != u) {
                for (int i  = 0; i < nV; i++) {
                    if (a[i][j] != INF && d[j] > d[i] + a[i][j]) {
                        d[j] = d[i] + a[i][j];
                        truoc[j] = i;
                    }
                }
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