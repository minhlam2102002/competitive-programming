/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
    } else {
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) 
            for (int j = 0; j <= sum/2; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= i) 
                    (dp[i][j] += dp[i - 1][j - i]) %= MOD;
            }
        cout << dp[n - 1][sum/2] << endl;
    }
    return 0;
}