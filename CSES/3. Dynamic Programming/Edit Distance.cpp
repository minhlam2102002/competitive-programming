/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;

int dp[MAXN + 1][MAXN + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int n = a.size(); a = '#' + a;
    int m = b.size(); b = '#' + b;
    for (int j = 1; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}