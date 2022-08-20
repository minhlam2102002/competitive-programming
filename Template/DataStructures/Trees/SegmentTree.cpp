#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> seg_tree, lazy;
    SegmentTree(int n) {
        this->n = n;
        seg_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    SegmentTree(vector<int> a, int n) : SegmentTree(n) {
        
    }
    int merge(int a, int b) {
        return max(a, b);
    }
    void down(int id, int l, int r) {
        if (l != r) {
            lazy[2 * id + 1] = merge(lazy[2 * id + 1], lazy[id]);
            lazy[2 * id + 2] = merge(lazy[2 * id + 2], lazy[id]);
        }
        seg_tree[2 * id + 1] = merge(seg_tree[2 * id + 1], lazy[id]);
        seg_tree[2 * id + 2] = merge(seg_tree[2 * id + 2], lazy[id]);
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int fr, int to, int val) {
        if (r < fr || to < l)
            return;
        if (fr <= l && r <= to) {
            seg_tree[id] = val;
            lazy[id] = val;
            return;
        }
        if (lazy[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        update(2 * id + 1, l, m, fr, to, val);
        update(2 * id + 2, m + 1, r, fr, to, val);
    }
    int query(int id, int l, int r, int at) {
        if (r < at || at < l)
            return 0;
        if (l == r && l == at)
            return seg_tree[id];
        if (lazy[id] != 0)
            down(id, l, r);
        int m = (l + r) / 2;
        return merge(
            query(2 * id + 1, l, m, at),
            query(2 * id + 2, m + 1, r, at)
        );
    }
};