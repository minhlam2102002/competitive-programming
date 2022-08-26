// Verified: https://cses.fi/problemset/task/1671/
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;
vector<int> pre;

void Dijkstra(int s) {
    int n = adj.size();
    dist.assign(n, INF);
    pre.assign(n, -1);

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
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}
vector<int> restorePath(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = pre[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
