#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<int>> adj;
vector<int> numChild, dfsPath, weight;
vector<ll> totalWeight;
void dfs(int u, int p, ll w) {
    dfsPath.push_back(u);
    numChild[u] = 1;
    totalWeight[u] = w;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u, w + weight[v]);
            numChild[u] += numChild[v];
        }
}

struct SegmentTree {
    const int NONE = INT_MIN;
    int n;
    vector<ll> st, lz;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
        lz.assign(4 * n + 1, 0);
    }
    SegmentTree(const vector<ll> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    void build(int id, int l, int r, const vector<ll> &a) {
        if (l == r) {
            st[id] = a[l];
        } else {
            int m = (l + r) / 2;
            build(id * 2 + 1, l, m, a);
            build(id * 2 + 2, m + 1, r, a);
        }
    }
    void down(int id, int l, int r) {
        if (l != r) {
            lz[2 * id + 1] += lz[id];
            lz[2 * id + 2] += lz[id];
            st[2 * id + 1] += lz[id];
            st[2 * id + 2] += lz[id];
        }
        lz[id] = 0;
    }
    void update(int id, int l, int r, int fr, int to, ll delta) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            st[id] += delta;
            lz[id] += delta;
            return;
        }
        if (lz[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        update(2 * id + 1, l, m, fr, to, delta);
        update(2 * id + 2, m + 1, r, fr, to, delta);
    }
    void update(int fr, int to, int val) {
        update(0, 0, n - 1, fr, to, val);
    }
    long long query(int id, int l, int r, int at) {
        if (r < at || at < l)
            return NONE;
        if (at <= l && r <= at)
            return st[id];
        if (lz[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        return max(
            query(2 * id + 1, l, m, at),
            query(2 * id + 2, m + 1, r, at)
        );
    }
    long long query(int at) {
        return query(0, 0, n - 1, at);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    weight.resize(n);
    for (int &x : weight) cin >> x;
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    numChild.assign(n, 0);
    totalWeight.assign(n, 0);
    dfs(0, 0, weight[0]);
    vector<int> dfsID(n), tmp2(n);
    vector<ll> tmp1(n);
    for (int i = 0; i < n; i++) {
        dfsID[dfsPath[i]] = i;
        tmp1[i] = totalWeight[dfsPath[i]];
        tmp2[i] = numChild[dfsPath[i]];
    }
    totalWeight = tmp1;
    numChild = tmp2;
    SegmentTree st(totalWeight);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st.update(dfsID[s], dfsID[s] + numChild[s] - 1, x - weight[s]);
            weight[s] = x;
        } else {
            int s;
            cin >> s;
            s--;
            cout << st.query(dfsID[s]) << endl;
        }
    }
    return 0;
}

