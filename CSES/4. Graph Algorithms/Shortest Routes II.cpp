// Verified: https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void FloydWarshall(int n, vector<vector<long long>> &dist) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist;
    dist.resize(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], (long long)w);
        dist[v][u] = min(dist[v][u], (long long)w);
    }
    FloydWarshall(n, dist);
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << endl;
    }
    return 0;
}