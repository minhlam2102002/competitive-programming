#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    const int NONE = 0;
    int n;
    vector<long long> st, lz;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
        lz.assign(4 * n + 1, NONE);
    }
    SegmentTree(const vector<int> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    long long merge(const long long &a, const long long &b) const {
        return max(a, b);
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
    void update(int at, int val) {
        update(0, 0, n - 1, at, at, val);
    }
    long long query(int id, int l, int r, int fr, int to) {
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
    long long query(int fr, int to) {
        return query(0, 0, n - 1, fr, to);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int &x : h) cin >> x;
    SegmentTree st(h);
    while (m--) {
        int x; cin >> x;
        int l = 0, r = n - 1, res = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (st.query(0, m) >= x) {
                res = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        if (res != -1) {
            st.update(res, h[res] - x);
            h[res] -= x;
            cout << res + 1 << ' ';
        } else
            cout << "0 ";
    }
    return 0;
}