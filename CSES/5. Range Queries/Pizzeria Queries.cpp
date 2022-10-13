#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct SegmentTree {
    const int INF = 1e9;
    const pii NONE = {INF, INF};
    int n;
    vector<pii> st;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
    }
    SegmentTree(const vector<int> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    pii merge(const pii &a, const pii &b) const {
        return {min(a.first, b.first), min(a.second, b.second)};
    }
    void build(int id, int l, int r, const vector<int> &a) {
        if (l == r) {
            st[id] = {a[l] + l, a[l] + n - 1 - l};
        } else {
            int m = (l + r) / 2;
            build(id * 2 + 1, l, m, a);
            build(id * 2 + 2, m + 1, r, a);
            st[id] = merge(st[id * 2 + 1], st[id * 2 + 2]);
        }
    }
    void update(int id, int l, int r, int fr, int to, int delta) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            st[id].first += delta;
            st[id].second += delta;
            return;
        }
        int m = (l + r) / 2;
        update(2 * id + 1, l, m, fr, to, delta);
        update(2 * id + 2, m + 1, r, fr, to, delta);
        st[id] = merge(st[2 * id + 1], st[2 * id + 2]);
    }
    void update(int at, int val) {
        update(0, 0, n - 1, at, at, val);
    }
    pii query(int id, int l, int r, int fr, int to) {
        if (r < fr || to < l)
            return NONE;
        if (fr <= l && r <= to)
            return st[id];
        int m = (l + r) / 2;
        return merge(
            query(2 * id + 1, l, m, fr, to),
            query(2 * id + 2, m + 1, r, fr, to)
        );
    }
    pii query(int fr, int to) {
        return query(0, 0, n - 1, fr, to);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> pizzas(n);
    for (int &x : pizzas) cin >> x;
    SegmentTree st(pizzas);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            st.update(k, x - pizzas[k]);
            pizzas[k] = x;
        } else {
            int k; cin >> k;
            k--;
            int left2end = st.query(0, k).second;
            int right2start = st.query(k, n - 1).first;
            left2end -= n - 1 - k;
            right2start -= k;
            cout << min(left2end, right2start) << '\n';
        }
    }
    return 0;
}