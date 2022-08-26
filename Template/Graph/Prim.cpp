// Verified: https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

using pii = pair<long long, int>;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;
vector<int> path;
vector<bool> visited;
long long mst;
bool Prim() {
    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    int u, v, w;
    int cnt = 0;
    mst = 0;
    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        mst += dist[u];
        cnt++;
        for (auto &e : adj[u]) {
            tie(v, w) = e;
            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return cnt == n;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    if (Prim())
        cout << mst;
    else
        cout << "IMPOSSIBLE";
    return 0;
}