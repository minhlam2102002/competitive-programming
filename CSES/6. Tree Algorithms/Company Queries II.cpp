#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int>> adj, parent;
vector<int> tin, tout;
int counter;

void dfs(int u, int p) {
    tin[u] = ++counter;
    parent[u][0] = p;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    tout[u] = ++counter;
}
void preprocess() {
    l = log2(n) + 1;
    tin.resize(n);
    tout.resize(n);
    parent.resize(n, vector<int>(l));
    counter = 0;
    dfs(0, 0);
    for (int k = 1; k < l; k++)
        for (int i = 0; i < n; i++)
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
}
int isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tin[v] <= tout[u];
}
int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int k = l - 1; k >= 0; k--)
        if (!isAncestor(parent[u][k], v))
            u = parent[u][k];
    return parent[u][0];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> n >> q;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int u; cin >> u;
        u--;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    preprocess();
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << lca(u, v) + 1 << endl;
    }
    return 0;
}