#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;
const int INF = 1e9;

struct Edge {
    int u, v, cap, flow;
    Edge(int u = 0, int v = 0, int cap = 0)
        : u(u), v(v), cap(cap), flow(0) {}
};

int n, m;
vector<int> iter, level;
vector<Edge> edges;
vector<vector<int>> adj;

void addEdge(int u, int v, int cap) {
    adj[u].push_back(edges.size());
    edges.push_back({u, v, cap});
    adj[v].push_back(edges.size());
    edges.push_back({v, u, 0});
}
// build Layered Network
bool bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    level.assign(n, -1);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
            if (level[edges[i].v] != -1)
                continue;
            if (edges[i].cap <= edges[i].flow)
                continue;
            level[edges[i].v] = level[u] + 1;
            q.push(edges[i].v);
        }
    }
    return level[t] != -1;
}
// find Augmenting Path
int dfs(int s, int t, int pushed) {
    if (pushed == 0)
        return 0;
    if (s == t)
        return pushed;
    for (int &i = iter[s]; i < adj[s].size(); i++) {
        int id = adj[s][i];
        int v = edges[id].v;
        if (level[v] != level[s] + 1)
            continue;
        if (edges[id].cap <= edges[id].flow)
            continue;
        int f = min(pushed, edges[id].cap - edges[id].flow);
        f = dfs(v, t, f);
        if (f == 0)
            continue;
        edges[id].flow += f;
        edges[id ^ 1].flow -= f;
        return f;
    }
    return 0;
}
int Dinic(int s, int t) {
    int newFlow, sumFlow = 0;
    while (bfs(s, t)) {
        iter.assign(n, 0);
        while (newFlow = dfs(s, t, INF)) 
            sumFlow += newFlow;
    }
    return sumFlow;
}
void trace(int u, int t, vector<int> &path) {
    path.push_back(u);
    if (u == t) return;
    for (int &i = iter[u]; i < adj[u].size(); i++) {
        int id = adj[u][i];
        if (edges[id].flow > 0) {
            edges[id].flow -= 1;
            edges[id ^ 1].flow += 1;
            trace(edges[id].v, t, path);
            return;
        }
    }
}

void pathRecover(int s, int t, int maxflow) {
    iter.assign(n, 0);
    while (maxflow--) {
        vector<int> path;
        trace(s, t, path);
        cout << path.size() << '\n';
        for (int u : path) cout << u << ' ';
        cout << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        addEdge(u, v, 1);
    }
    int res = Dinic(1, n);
    cout << res << endl;
    pathRecover(1, n, res);
    return 0;
}
