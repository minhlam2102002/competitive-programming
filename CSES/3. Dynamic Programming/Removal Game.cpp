/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> a(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r) 
                dp[l][r] = a[l];
            else 
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << (sum + dp[1][n]) / 2 << endl;
    return 0;
}