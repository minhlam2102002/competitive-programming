#include<bits/stdc++.h>
using namespace std;

template<class T>
struct FenwickTree {
    vector<T> bit;  
    int n;
    FenwickTree() {};

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<T> a, int n) : FenwickTree(n) {
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    T sum(int r) {
        T res = 0;
        while (r > 0) {
            res += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, T val) {
        while (idx < n) {
            bit[idx] += val;
            idx |= idx + 1;
        }
    }
};

int main() {
    // FenwickTreeMinMax<int> ft(10, std::min);
}