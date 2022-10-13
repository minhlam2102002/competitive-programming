// Verified: https://cses.fi/problemset/task/1682/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, revAdj, compList;
vector<bool> visited;
vector<int> order, comp;

void dfs1(int u) {
    visited[u] = true;

    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;

    compList.back().push_back(u);
    comp[u] = compList.size() - 1;

    for (int v : revAdj[u])
        if (!visited[v])
            dfs2(v);
}

void Kosaraju(int n) {
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    visited.assign(n, false);
    comp.assign(n, -1);
    reverse(order.begin(), order.end());

    for (int v : order)
        if (!visited[v]) {
            compList.push_back(vector<int>());
            dfs2(v);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    revAdj.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    Kosaraju(n);
    return 0;
}