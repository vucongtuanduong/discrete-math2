#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];

void floyd() {
    for (int k = 0; k < nV; k++) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (a[i][k] != INF && a[k][j] != INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (a[i][j] == INF)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
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
    floyd();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }  
    return 0;
}