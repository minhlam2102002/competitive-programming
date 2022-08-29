// Verified: https://cses.fi/problemset/task/1671/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
vector<vector<pair<int, int>>> adj;
vector<int> pre;

ll Dijkstra(int s, int t) {
    int n = adj.size();
    vector<ll> dist;
    dist.assign(n, INF);
    pre.assign(n, -1);

    dist[s] = 0;
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [distU, u] = pq.top();
        pq.pop();

        if (distU != dist[u])
            continue;

        for (auto edge : adj[u]) {
            auto [v, w] = edge;
            if (dist[v] > distU + w) {
                pre[v] = u;
                dist[v] = distU + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}
