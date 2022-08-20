/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int &p : w) cin >> p;

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {n + 1, 0};
        for (int p = 0; p < n; p++) {
            if (mask & (1 << p)) {
                auto pre = dp[mask ^ (1 << p)];
                if (pre.second + w[p] <= x) {
                    pre.second += w[p];
                } else {
                    pre.first++;
                    pre.second = w[p];
                }
                dp[mask] = min(dp[mask], pre);
            }
        }
    }
    cout << dp.back().first << endl;
    return 0;
}