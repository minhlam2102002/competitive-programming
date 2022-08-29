#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;
int n, m, k;
vector<vector<pair<int, int>>> adj;

vector<ll> Dijkstra(int s, int t) {
    vector<multiset<ll>> dist;
    dist.resize(n);

    dist[s].insert(0);
    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [dist_u, u] = pq.top();
        pq.pop();
        if(dist[u].count(dist_u) == 0) continue;
        for (auto &edge : adj[u]) {
            auto [v, w] = edge;
            ll dist_v = dist_u + w;
            if (dist[v].empty() || dist[v].size() < k) {
                dist[v].insert(dist_v);
                pq.push({dist_v, v});
            } else {
                auto last = dist[v].end();
                last--;
                if (dist_v < *last) {
                    dist[v].erase(last);
                    dist[v].insert(dist_v);
                    pq.push({dist_v, v});
                }
            }
        }
    }
    return vector<ll> (dist[n - 1].begin(), dist[n - 1].end());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    adj.resize(n);
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    vector<ll> lens = Dijkstra(0, n - 1);
    for (ll len : lens)
        cout << len << ' ';
    return 0;
}