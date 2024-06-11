#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int a[100][100];
int n, s;
bool vs[100];
vector<vector<int>> adj;
int par[100];
int d[100];
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            q.push({i, d[i]});
        }
    }
    while (!q.empty()) {
        int u = q.top().first;
        int v = q.top().second;
        q.pop();
        if (!vs[u]) {
            vs[u] = true;
            for (int i = 1; i <= n; i++) {
                if (!vs[i]) {
                    if (d[u] + a[u][i] < d[i]) {
                        d[i] = d[u] + a[u][i];
                        par[i] = u;
                        q.push({i, d[i]});
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1000) {
            cout << "K/c " << s << " -> " << i << " = " << "INF;" << endl;
        } else {
            if (i == s) {
                cout << "K/c " << s << " -> " << i << " = " << "0" << ";       ";
                cout << s << " <- " << s << endl;
                continue;
            }
            cout << "K/c " << s << " -> " << i << " = " << d[i] << ";       ";
            int tmp = i;
            while (tmp != s) {
                cout << tmp << " <- ";
                tmp = par[tmp];
            }
            cout << tmp << endl;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] == 0) {
                    a[i][j] = 1000;
                }
            }
            vs[i] = false;
        }
        vs[s] = true;
        d[s] = 0;
        par[s] = s;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                if (a[s][i] < 1000) {
                    d[i] = a[s][i];
                } else {
                    d[i] = 1000;
                }
                par[i] = s;
            }
        }
        solve();
    }
    
    return 0;
}
