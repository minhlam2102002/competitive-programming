#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<tuple<int, int, int>> edges;
vector<vector<int>> adj;
void dfs(int u, vector<bool> &visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v, visited);
}
void BellmanFord(vector<long long> &dist) {
    int n = dist.size();
    vector<int> lastChange;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (i == n - 1)
                    lastChange.push_back(v);
            }
        }
    }
    vector<bool> visited(n, false);
    for (int i : lastChange)
        dfs(i, visited);
    for (int i = 0; i < n; i++) 
        if (visited[i])
            dist[i] = -INF;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    edges.resize(m);
    adj.resize(n);
    for (auto &e : edges) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e = {u, v, -w};
        adj[u].push_back(v);
    }
    vector<long long> dist;
    dist.assign(n, INF);
    dist[0] = 0;
    BellmanFord(dist);
    if(dist[n - 1] != INF && dist[n - 1] != -INF) 
        cout << -dist[n - 1] << endl;
    else 
        cout << -1 << endl;
}