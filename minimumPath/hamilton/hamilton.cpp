#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

int n;
int a[100][100];
int vs[100] = { 0 };
int x[100] = { 0 };
int v0;
void Hamilton(int k) {
	for (int v =  1; v <= n; v++) {
        if (k == 1 || a[x[k - 1]][v]) {
            if (k == n + 1) {
                if (v == x[1]) {
                    for (int i = 1; i <= k - 1; i++) {
                        cout << x[i] << " ";
                    }
                    cout << x[1] ;
                    cout << endl;
                }
                
            } else if (!vs[v]) {
                vs[v] = true;
                x[k] = v;
                Hamilton(k + 1);
                vs[v] = false;
            }
        } 
    }
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
    Hamilton(1);
	

	return 0;
}