#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int>> adj, parent;
vector<int> tin, tout, height;
int counter;

void dfs(int u, int p) {
    tin[u] = ++counter;
    parent[u][0] = p;
    height[u] = height[p] + 1;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    tout[u] = ++counter;
}
void preprocess() {
    l = log2(n) + 1;
    tin.resize(n);
    tout.resize(n);
    height.resize(n);
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
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess();
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int x = lca(u, v);
        cout << height[u] + height[v] - 2 * height[x] << endl;
    }
    return 0;
}