#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> ft;
    int n;

    FenwickTree(int n) {
        this->n = n;
        ft.assign(n + 1, 0);
    }
    void update(int i, int v) {
        while (i <= n) {
            ft[i] += 1ll * v;
            i += i & -i;
        }
    }
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += 1ll * ft[i];
            i -= i & -i;
        }
        return sum;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    FenwickTree ft(n);
    for (int i = 0; i < n; i++) 
        ft.update(i + 1, a[i]);
    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i, v;
            cin >> i >> v;
            ft.update(i, v - a[i - 1]);
            a[i - 1] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.query(l, r) << '\n';
        }
    }
    return 0;
}