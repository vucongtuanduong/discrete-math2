#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};
vector<vector<int>> totalPaths;
void dfs(Graph *g, int u, int v, bool *visited, stack<int> &path);
void print(stack<int> path);
void testCase();
int main () {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
void testCase() {
    int nV, src, dest;
    cin >> nV >> src >> dest;
    src--;
    dest--;
    cin.ignore();
    Graph *g = new Graph;
    g->nV = nV;
    for (int i = 0; i < nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            g->edges[i].push_back(stoi(temp) - 1);
        }
    }
    stack<int> path;
    bool visited[g->nV];
    memset(visited, false, sizeof(visited));
    dfs(g, src, dest, visited, path);
    int numPaths = totalPaths.size();
    map<int, int> mp;
    for (auto x : totalPaths) {
        for (int i = 0; i < x.size(); i++) {
            mp[x[i]]++;
        }
    }
    vector<int> res;
    for (auto x : mp) {
        if (x.second == numPaths && x.first != src && x.first != dest) {
            res.push_back(x.first + 1);
        }
    }
    cout << "Cac dinh that: " ;
    for (auto x : res) {
        cout << x << " ";
    }
    totalPaths.clear();
}
void print(stack<int> path) {
    vector<int> temp;
    while (!path.empty()) {
        int x= path.top();
        path.pop();
        temp.push_back(x);
    }
    totalPaths.push_back(temp);
}
void dfs(Graph *g, int u, int v, bool *visited, stack<int> &path) {
    visited[u] = true;
    path.push(u);
    if (u == v) {
        print(path);
    } else {
        for (int i = 0; i < g->edges[u].size(); i++) {
            int x = g->edges[u][i];
            if (!visited[x]) {
                dfs(g, x, v, visited, path);
            }
        }
    }
    path.pop();
    visited[u] = false;
}