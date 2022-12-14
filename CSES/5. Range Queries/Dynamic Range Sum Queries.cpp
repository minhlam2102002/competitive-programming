#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree {
    vector<T> bit;
    int n;
    const int NONE = 0;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, NONE);
    }
    void add(int idx, T delta) {
        while (idx < n) {
            bit[idx] += delta;
            idx = idx | (idx + 1);
        }
    }
    T sum(int idx) {
        T sum = 0;
        while (idx >= 0) {
            sum += bit[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return sum;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    FenwickTree<long long> ft(n);
    for (int i = 0; i < n; i++) 
        ft.add(i, a[i]);
    while (q--) {
        int k; cin >> k;
        if (k == 1) {
            int i, v;
            cin >> i >> v;
            i--;
            ft.add(i, v - a[i]);
            a[i] = v;
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << ft.sum(l, r) << '\n';
        }
    }
    return 0;
}