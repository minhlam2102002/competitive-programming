#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;
vector<int> pre, cnt, minLen, maxLen;

void dijkstra(int s) {
    dist.assign(n, INF);
    pre.assign(n, -1);
    cnt.assign(n, 0);
    minLen.assign(n, 0);
    maxLen.assign(n, 0);

    dist[s] = 0;
    cnt[s] = 1;
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
                cnt[v] = cnt[u];
                minLen[v] = minLen[u] + 1;
                maxLen[v] = maxLen[u] + 1;
                pre[v] = u;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                minLen[v] = min(minLen[v], minLen[u] + 1);
                maxLen[v] = max(maxLen[v], maxLen[u] + 1);
            }
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    for (int u, v, w, i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    dijkstra(0);
    cout << dist[n - 1] << ' ' << cnt[n - 1] << ' ' << minLen[n - 1] << ' ' << maxLen[n - 1];
    return 0;
}