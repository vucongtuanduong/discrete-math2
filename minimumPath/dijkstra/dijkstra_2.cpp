#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
vector<pair<int,int>> ke[1001];
void dijkstra(int x) {
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> d(nV, INF);
    vector<int> truoc(nV, -1);
    d[x] = 0;
    truoc[x] = -1;
    pq.push({0, x});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u]) {
            continue;
        }
        for (auto x : ke[u]) {
            int v = x.second;
            int uv = x.first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
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
}
void testCase() {
    cin >> nV >> nE;
    int x;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> x;
            if (x != 0 && x != INF) {
                ke[i].push_back({x, j});
            }
        }
    }
    dijkstra(0);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
