#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> parent;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int m = log2(n) + 1;
    parent.resize(n, vector<int>(m, -1));
    for (int i = 1; i < n; i++) {
        cin >> parent[i][0];
        parent[i][0]--;
    }
    for (int j = 1; j < m; j++)
        for (int i = 0; i < n; i++)
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
    while (q--) {
        int u, k;
        cin >> u >> k;
        u--;
        for (int i = 0; i < m; i++) {
            if (k & (1 << i)) {
                u = parent[u][i];
                if (u == -1) break;
            }
        }
        cout << u + (u != -1) << endl;
    }
    return 0;
}