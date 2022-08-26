#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    vector<vector<int>> st;
    vector<int> log_2;
    void compute_log(int n) {
        log_2.resize(n + 1, 0);
        for (int i = 2; i <= n; i++) 
            log_2[i] = log_2[i / 2] + 1;
    }
    SparseTable(const vector<int> &a) {
        int n = a.size();
        compute_log(n);
        st.assign(n, vector<int>(log_2[n] + 1));

        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
            
        for (int j = 1; (1 << j) <= n; j++) {
            int step = 1 << (j - 1);
            for (int i = 0; i + 2 * step <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + step][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int k = log_2[r - l + 1];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    SparseTable st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << '\n';
    }
    return 0;
}