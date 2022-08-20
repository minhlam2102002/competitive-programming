/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<bool>> traps(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            traps[i][j] = (c == '*');
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[1][1] = !traps[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!traps[i][j]) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}