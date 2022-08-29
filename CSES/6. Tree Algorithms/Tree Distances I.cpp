#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
pair<int, int> dfs(int u, int p, int d) {
    pair<int, int> maxChild = {d, u};
    dist[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        maxChild = max(maxChild, dfs(v, u, d + 1));
    }
    return maxChild;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    adj.resize(n);
    dist.resize(n);
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int, int> a = dfs(0, -1, 0);
    pair<int, int> b = dfs(a.second, -1, 0);
    vector<int> distFromB = dist;
    dfs(b.second, -1, 0);
    vector<int> distFromA = dist;
    for (int i = 0; i < n; i++) {
        cout << max(distFromA[i], distFromB[i]) << ' ';
    }
    return 0;
}