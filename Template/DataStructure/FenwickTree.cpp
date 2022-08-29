// Verified: https://cses.fi/problemset/task/1648/
#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> ft;
    int n;

    FenwickTree(int n) {
        this->n = n;
        ft.assign(n + 1, 0);
    }
    void update(int id, int val) {
        while (id <= n) {
            ft[id] += 1ll * val;
            id += id & -id;
        }
    }
    long long query(int id) {
        long long sum = 0;
        while (id > 0) {
            sum += 1ll * ft[id];
            id -= id & -id;
        }
        return sum;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};