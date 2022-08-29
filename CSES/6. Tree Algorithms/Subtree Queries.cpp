#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> weight, tin, tout;
int counter = 0;

struct FenwickTree {
    vector<long long> ft;
    int n;

    FenwickTree(int n) {
        this->n = n;
        ft.assign(n + 1, 0);
    }
    void update(int id, int val) {
        while (id <= n) {
            ft[id] += 1ll * val;
            id += id & -id;
        }
    }
    long long query(int id) {
        long long sum = 0;
        while (id > 0) {
            sum += 1ll * ft[id];
            id -= id & -id;
        }
        return sum;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
} ft;

void dfs(int u, int p) {
    tin[u] = ++counter;

    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    tout[u] = ++counter;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    weight.resize(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tin.resize(n);
    tout.resize(n);
    dfs(0, 0);
    return 0;
}