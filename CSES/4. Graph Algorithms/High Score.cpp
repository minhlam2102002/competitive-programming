#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<tuple<int, int, int>> edges;
bool BellmanFord(int s, int n, vector<long long> &dist, vector<int> &prev) {
    dist.assign(n, INF);
    prev.assign(n, -1);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        bool changed = false;
        for (auto e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                changed = true;
            }
        }
        if (i == n - 1 && changed) return false;
        if (!changed) return true;
    }
    return true;
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
    edges.resize(m);
    for (auto &e : edges) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e = {u, v, -w};
    }
    vector<long long> dist;
    vector<int> prev;
    bool isNegative = BellmanFord(0, n, dist, prev);
    
    if(dist[n - 1] != INF)
        cout << -dist[n - 1] << endl;
    else 
        cout << -1 << endl;
}