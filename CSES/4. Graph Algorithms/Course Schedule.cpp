#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited, topo;
bool hasCycle;
void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0)
            dfs(v);
        else if (visited[v] == 1)
            hasCycle = true;
    }
    topo.push_back(u);
    visited[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    visited.resize(n, 0);
    for (int v = 0; v < n; v++) 
        if (visited[v] == 0)
            dfs(v);
    if (hasCycle)
        cout << "IMPOSSIBLE" << endl;
    else {
        reverse(topo.begin(), topo.end());
        for (int v : topo)
            cout << v + 1 << ' ';
        cout << endl;
    }
    return 0;
}