/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500;

int dp[MAXN + 1][MAXN + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b; cin >> a >> b;
    for (int i = 0; i <= a; i++) 
        for (int j = 0; j <= b; j++) 
            if (i == j) dp[i][j] = 0;
            else {
                dp[i][j] = INT_MAX;
                for (int k = 1; k < i; k++) 
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                for (int k = 1; k < j; k++) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
    cout << dp[a][b] << endl;
    return 0;
}