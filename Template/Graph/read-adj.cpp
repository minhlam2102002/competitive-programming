vector<vector<int>> adj;
int n, m;
cin >> n >> m;
adj.resize(n);
for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
}