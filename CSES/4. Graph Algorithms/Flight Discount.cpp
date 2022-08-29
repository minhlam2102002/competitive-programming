#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<vector<pair<int, int>>> adj;

long long Dijkstra(int s, int t) {
    vector<vector<long long>> dist;
    int n = adj.size(); 
    dist.resize(n, vector<long long>(2, INF));
    dist[s][0] = 0;

    using pii = tuple<long long, int, bool>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s, false});

    while (!pq.empty()) {
        auto [dist_u, u, used] = pq.top();
        pq.pop();
        if (dist_u != dist[u][used])
            continue;
        for (auto edge : adj[u]) {
            auto [v, w] = edge;
            if (dist[v][used] > dist_u + w) {
                dist[v][used] = dist_u + w;
                pq.push({dist[v][used], v, used});
            }
            if(used == false){
                if (dist[v][!used] > dist_u + w/2) {
                    dist[v][!used] = dist_u + w/2;
                    pq.push({dist[v][!used], v, !used});
                }
            }
        }
    }
    return min(dist[t][0], dist[t][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    cout << Dijkstra(0, n - 1) << endl;
    return 0;
}