// Verified: https://cses.fi/problemset/task/1671/
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, int>>> adj;
void dijkstra(int s, vector<long long> &dist, vector<int> &prev) {
    int n = adj.size();
    dist.assign(n, INF);
    prev.assign(n, -1);

    dist[s] = 0;
    using pii = pair<long long, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        long long dist_u = pq.top().first;
        pq.pop();
        if (dist_u != dist[u])
            continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> const &prev) {
    vector<int> path;
    for (int v = t; v != s; v = prev[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    vector<long long> dist;
    vector<int> prev;
    dijkstra(0, dist, prev);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}