/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;
    
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin >= 0) 
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}