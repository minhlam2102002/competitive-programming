// Verified: https://cses.fi/problemset/task/1648/
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