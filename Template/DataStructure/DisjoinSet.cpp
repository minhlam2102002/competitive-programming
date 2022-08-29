// Verified: https://cses.fi/problemset/task/1676/
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent, setSize;

void makeSet(int n) {
    parent.resize(n);
    setSize.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);
}

int findSet(int u) {
    return parent[u] == u ? u : parent[u] = findSet(parent[u]);
}

bool unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v) return false;
    if (setSize[u] < setSize[v]) swap(u, v);
    parent[v] = u;
    setSize[u] += setSize[v];
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    makeSet(n);
    int components = n, maxSize = 1;
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (unionSet(u, v)) {
            --components;
            maxSize = max(maxSize, setSize[findSet(u)]);
        }
        cout << components << ' ' << maxSize << '\n';
    }
    return 0;
}