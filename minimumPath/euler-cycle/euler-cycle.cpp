#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int nV, nE;
int a[101][101];

void euler_cycle(int x) {
    stack<int> st;
    vector<int> ce;
    st.push(x);
    while (!st.empty()) {
        bool ok = false;
        int u = st.top();
        for (int v = 0; v < nV; v++) {
            if (a[u][v] == 1) {
                st.push(v);
                a[u][v] = 0;
                ok = true;
                break;
            }
        }
        if (!ok) {
            ce.push_back(u);
            st.pop();
        }
    }
    for (int v = ce.size() - 1; v >= 0; v--) {
        cout << ce[v] + 1 << " ";
    }
}

void testCase() {
    cin >> nV >> nE;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            cin >> a[i][j];
        }
    }
    euler_cycle(1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }  
    return 0;
}