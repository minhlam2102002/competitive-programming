#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited, topo;

void DFS(int u) {
    visited[u] = 1;
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
    topo.push_back(u);
}
vector<int> restore_path(int s, int t, vector<int> const &prev) {
    vector<int> path;
    for (int v = t; v != -1; v = prev[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
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
    vector<int> dist(n, 0), prev(n, -1);
    for (int u : topo)
        for (int v : adj[u])
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
            }
    if (dist[n - 1] == 0)
        cout << "IMPOSSIBLE";
    else {
        cout << dist[n - 1] + 1 << endl;
        vector<int> path = restore_path(0, n - 1, prev);
        for (int u : path)
            cout << u + 1 << ' ';
    }
    return 0;
}