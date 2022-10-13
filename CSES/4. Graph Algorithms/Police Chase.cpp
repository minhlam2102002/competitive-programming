// O(V^2*E)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll cap, flow;
    Edge(int u = 0, int v = 0, int cap = 0) : u(u), v(v), cap(cap), flow(0) {}
};

vector<Edge> edges;
vector<vector<int>> adj;
vector<vector<ll>> cap, flow;
vector<int> level, iter;

void addEdge(int u, int v, int cap) {
    adj[u].push_back(edges.size());
    edges.push_back({u, v, cap});
    adj[v].push_back(edges.size());
    edges.push_back({v, u, cap});
}

// build Layered Network
bool bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
            if (level[edges[i].v] != -1) continue;
            if (edges[i].cap <= edges[i].flow) continue;
            level[edges[i].v] = level[u] + 1;
            q.push(edges[i].v);
        }
    }
    return level[t] != -1;
}
// find augmentation Path
ll dfs(int s, int t, ll pushed) {
    if (pushed == 0) return 0;
    if (s == t) return pushed;
    for (int &i = iter[s]; i < adj[s].size(); i++) {
        int id = adj[s][i];
        int v = edges[id].v;
        if (level[v] != level[s] + 1) continue;
        if (edges[id].cap <= edges[id].flow) continue;
        ll f = min(pushed, edges[id].cap - edges[id].flow);
        f = dfs(v, t, f);
        if (f == 0) continue;
        edges[id].flow += f;
        edges[id ^ 1].flow -= f;
        return f;
    }
    return 0;
}
ll Dinic(int s, int t) {
    ll newFlow, sumFlow = 0;
    while (bfs(s, t)) {
        fill(iter.begin(), iter.end(), 0);
        while (newFlow = dfs(s, t, INF)) 
            sumFlow += newFlow;
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
    level.resize(n + 1);
    iter.resize(n + 1);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        addEdge(u, v, 1);
    }
    cout << Dinic(1, n) << endl;
    for (auto e : edges)
        if (e.flow == e.cap) 
            cout << e.u << ' ' << e.v << '\n';
    return 0;
}

