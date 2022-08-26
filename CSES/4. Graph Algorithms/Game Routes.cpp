#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> visited, topo;

void DFS(int u) {
    visited[u] = 1;
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
    topo.push_back(u);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int u, v, i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    visited.resize(n, false);
    DFS(0);
    reverse(topo.begin(), topo.end());
    vector<int> numOfWays(n, 0);
    numOfWays[0] = 1;
    for (int u : topo)
        for (int v : adj[u])
            numOfWays[v] = (numOfWays[v] + numOfWays[u]) % MOD;
    cout << numOfWays[n - 1];
    return 0;
}