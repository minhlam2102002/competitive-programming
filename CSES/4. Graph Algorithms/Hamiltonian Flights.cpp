#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(1 << n, 0));
    dp[0][1] = 1;
    for (int state = 1; state < (1 << n); state++) {
        bool isLast = (state == (1 << n) - 1);
        bool hasLast = state & (1 << (n - 1));
        if (!isLast && hasLast) continue;
        for (int v = n - 1; v >= 0; v--) {
            if ((state >> v) & 1) {
                for (const int &u : adj[v]) {
                    if ((state >> v) & 1) {
                        dp[v][state] += dp[u][state ^ (1 << v)];
                        dp[v][state] %= MOD;
                    }
                }
            }
        }
        if (isLast) break;
    }
    cout << dp[n - 1][(1 << n) - 1];
    return 0;
}