vector<bool> visited;
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (visited[v] == false)
            dfs(v);
}
visited.resize(n, false);