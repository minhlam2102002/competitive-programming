#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll l, r, mid, sum;
};

struct SegmentTree {
    const Node NONE = {0, 0, 0, 0};
    int n;
    vector<Node> st;
    SegmentTree(int n) {
        this->n = n;
        st.assign(4 * n + 1, NONE);
    }
    SegmentTree(const vector<int> &a) : SegmentTree(a.size()) {
        build(0, 0, n - 1, a);
    }
    Node merge(const Node &a, const Node &b) const {
        Node p;
        p.l = max(a.l, a.sum + b.l);
        p.r = max(b.r, b.sum + a.r);
        p.mid = max(a.mid, b.mid);
        p.mid = max(p.mid, a.r + b.l);
        p.sum = a.sum + b.sum;
        return p;
    }
    void build(int id, int l, int r, const vector<int> &a) {
        if (l == r) {
            if (a[l] > 0)
                st[id] = {a[l], a[l], a[l], a[l]};
            else 
                st[id] = {0, 0, 0, a[l]};
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
            if (val > 0)
                st[id] = {val, val, val, val};
            else
                st[id] = {0, 0, 0, val};
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
    Node query(int id, int l, int r, int fr, int to) {
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
    Node query(int fr, int to) {
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
        int k, x;
        cin >> k >> x;
        k--;
        st.update(k, x);
        Node res = st.query(0, n - 1);
        ll ans = res.mid;
        ans = max(ans, res.l);
        ans = max(ans, res.r);
        cout << ans << '\n';
    }
    return 0;
}