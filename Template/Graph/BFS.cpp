int BFS(int s, int t) {
    vector<int> dist, pre;
    vector<bool> visited;

    visited.resize(n, false);
    dist.resize(n, -1);
    pre.resize(n, -1);

    queue<int> q;
    dist[s] = 0;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!visited[v]) {
                visted[v] = true;
                dist[v] = dist[u] + 1;
                pre[v] = u;
                q.push(v);
            }
    }
    return dist[t];
}