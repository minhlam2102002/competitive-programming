// Verified: https://cses.fi/problemset/task/1694/
// O(E^2 * V)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<vector<int>> adj;
vector<vector<ll>> cap, flow;
vector<int> parent;

ll bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, INF});
    while (!q.empty()) {
        auto [u, f] = q.front();
        q.pop();
        for (int v : adj[u])
            if (parent[v] == -1 && 1ll * cap[u][v] > flow[u][v]) {
                parent[v] = u;
                ll newFlow = min(f, 1ll * cap[u][v] - flow[u][v]);
                if (v == t) return newFlow;
                q.push({v, newFlow});
            }
    }
    return 0;
}
ll EdmondsKarp(int s, int t) {
    ll newFlow, sumFlow = 0;
    while ((newFlow = bfs(s, t)) != 0) {
        sumFlow += newFlow;
        int prev, cur = t;
        while (cur != s) {
            prev = parent[cur];
            flow[prev][cur] += newFlow;
            flow[cur][prev] -= newFlow;
            cur = prev;
        }
    }
    return sumFlow;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    cap.assign(n + 1, vector<ll>(n + 1, 0));
    flow.assign(n + 1, vector<ll>(n + 1, 0));
    parent.resize(n + 1);
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
    }
    cout << EdmondsKarp(1, n);
    return 0;
}