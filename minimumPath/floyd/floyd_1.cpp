#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];
int truoc[101][101];
int d[101][101];
void floyd() {
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            d[i][j] = a[i][j];
            truoc[i][j] = i;
        }
    }
    for (int k = 0; k < nV; k++) {
        for (int i = 0; i < nV; i++) {
            for (int j = 0; j < nV; j++) {
                if (a[i][j] != INF && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    truoc[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (d[i][j] == INF)
                cout << "INF ";
            else
                cout << d[i][j] << " ";
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