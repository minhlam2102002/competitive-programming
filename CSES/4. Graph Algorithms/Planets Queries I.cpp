#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXM = 30;

int n, m, q;
// vector<vector<int>> parent;
int parent[MAXN][MAXM];

int succ(int x, int k) {
    for (int j = 0; j < MAXM; j++)
        if (k & (1 << j))
            x = parent[x][j];
    return x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    // m = ceil(log2(MAX)) + 1;
    // parent.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        cin >> parent[i][0];
        parent[i][0]--;
    }
    for (int j = 1; j < MAXM; j++) 
        for (int i = 0; i < n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << succ(x, k) + 1 << '\n';
    }
    return 0;
}