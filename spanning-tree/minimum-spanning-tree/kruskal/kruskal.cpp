#include <bits/stdc++.h>
using namespace std;

struct Graph{
    int nV;
    int nE;
    vector<int> edges[1001];
};

int main () {
    int nV, nE;
    cin >> nV >> nE;
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = nE;
    cin.ignore();
    for (int i = 0; i < nV; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string temp;
        while (ss >> temp) {
            g->edges[i].push_back(stoi(temp) - 1);
        }
    }

}
