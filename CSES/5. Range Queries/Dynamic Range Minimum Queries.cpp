#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    const int NONE = 1e9;
    int n;
    vector<int> st;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
    }
    SegmentTree(const vector<int> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    int merge(const int &a, const int &b) const {
        return min(a, b);
    }
    void build(int id, int l, int r, const vector<int> &a) {
        if (l == r) {
            st[id] = a[l];
        } else {
            int m = (l + r) / 2;
            build(id * 2 + 1, l, m, a);
            build(id * 2 + 2, m + 1, r, a);
            st[id] = merge(st[id * 2 + 1], st[id * 2 + 2]); 
        }
    }
    void update(int id, int l, int r, int fr, int to, int val) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            st[id] = val;
            return;
        }
        int m = (l + r) / 2;
        update(2 * id + 1, l, m, fr, to, val);
        update(2 * id + 2, m + 1, r, fr, to, val);
        st[id] = merge(st[2 * id + 1], st[2 * id + 2]);
    }
    void update(int fr, int to, int val) {
        update(0, 0, n - 1, fr, to, val);
    }
    void update(int at, int val) {
        update(0, 0, n - 1, at, at, val);
    }
    int query(int id, int l, int r, int fr, int to) {
        if (r < fr || to < l)
            return NONE;
        if (fr <= l && r <= to)
            return st[id];
        int m = (l + r) / 2;
        return merge(
            query(2 * id + 1, l, m, fr, to),
            query(2 * id + 2, m + 1, r, fr, to));
    }
    int query(int at) {
        return query(0, 0, n - 1, at, at);
    }
    int query(int fr, int to) {
        return query(0, 0, n - 1, fr, to);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SegmentTree st(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            st.update(k, u);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << st.query(l, r) << '\n';
        }
    }
    return 0;
}