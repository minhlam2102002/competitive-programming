#include<bits/stdc++.h>
using namespace std;


struct SegmentTree {
    const set<int> NONE = set<int>();
    int n;
    vector<set<int>> st, lz;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
        lz.assign(4 * n + 1, NONE);
    }
    SegmentTree(const vector<int> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    set<int> merge(const set<int> &a, const set<int> &b) const {
        set<int> res;
        for (int x : a)
            res.insert(x);
        for (int x : b)
            res.insert(x);
        return res;
    }
    void build(int id, int l, int r, const vector<int> &a) {
        if (l == r) {
            st[id].insert(a[l]);
        } else {
            int m = (l + r) / 2;
            build(id * 2 + 1, l, m, a);
            build(id * 2 + 2, m + 1, r, a);
            st[id] = merge(st[id * 2 + 1], st[id * 2 + 2]);
        }
    }
    set<int> query(int id, int l, int r, int fr, int to) {
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
    set<int> query(int fr, int to) {
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
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << st.query(l, r).size() << '\n';
    }
    return 0;
}