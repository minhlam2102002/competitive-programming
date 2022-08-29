// Verified: https://cses.fi/problemset/submit/1651/
#include <bits/stdc++.h>
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
        return a + b;
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
    void down(int id, int l, int r) {
        if (l != r) {
            lz[2 * id + 1] = merge(lz[2 * id + 1], lz[id]);
            lz[2 * id + 2] = merge(lz[2 * id + 2], lz[id]);
            st[2 * id + 1] = merge(st[2 * id + 1], lz[id]);
            st[2 * id + 2] = merge(st[2 * id + 2], lz[id]);
        }
        lz[id] = NONE;
    }
    void update(int id, int l, int r, int fr, int to, int val) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            st[id] = merge(st[id], val);
            lz[id] = merge(lz[id], val);
            return;
        }
        if (lz[id] != NONE)
            down(id, l, r);
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
    long long query(int id, int l, int r, int fr, int to) {
        if (r < fr || to < l)
            return NONE;
        if (fr <= l && r <= to)
            return st[id];
        if (lz[id] != NONE)
            down(id, l, r);
        int m = (l + r) / 2;
        return merge(
            query(2 * id + 1, l, m, fr, to),
            query(2 * id + 2, m + 1, r, fr, to)
        );
    }
    long long query(int at) {
        return query(0, 0, n - 1, at, at);
    }
    long long query(int fr, int to) {
        return query(0, 0, n - 1, fr, to);
    }
};