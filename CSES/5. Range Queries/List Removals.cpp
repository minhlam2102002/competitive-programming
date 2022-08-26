#include<bits/stdc++.h>
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m - ft.query(m) >= x) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        cout << a[ans] << ' ';
        ft.update(ans, 1);
    }
    return 0;
}