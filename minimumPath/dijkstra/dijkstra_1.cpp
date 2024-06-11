#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];
void dijkstra(int x) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, -1);
    vector<bool> visited(nV, false);

    d[x] = 0;
    truoc[x] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (int v = 0; v < nV; v++) {
            if (a[u][v] != INF && !visited[v] && d[v] > d[u] + a[u][v]) {
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
                pq.push({d[v], v});
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
void dijkstra1(int u) {
    vector<int> d(nV, INF);
    vector<int> truoc(nV, -1);
    vector<bool> visited(nV, false);

    d[u] = 0;

    set<pair<int, int>> se;
    se.insert({0, u});

    while (!se.empty()) {
        int v = se.begin()->second;
        se.erase(se.begin());

        visited[v] = true;

        for (int x = 0; x < nV; x++) {
            if (a[v][x] != INF && !visited[x] && d[x] > d[v] + a[v][x]) {
                d[x] = d[v] + a[v][x];
                truoc[x] = v;
                se.insert({d[x], x});
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