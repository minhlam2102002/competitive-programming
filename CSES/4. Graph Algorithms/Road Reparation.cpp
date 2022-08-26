#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n, m;
vector<Edge> edges;
vector<int> parent, setSize;
long long mst;

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

bool Kruskal() {
    makeSet(n);
    sort(edges.begin(), edges.end());
    int cnt = mst = 0;
    for (const Edge &e : edges)
        if (unionSet(e.u, e.v)) {
            mst += 1ll * e.w;
            cnt++;
        }
    return cnt == n - 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    edges.resize(m);
    for (auto &e : edges) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        e = {u, v, w};
    }
    if (Kruskal())
        cout << mst;
    else
        cout << "IMPOSSIBLE";
    return 0;
}