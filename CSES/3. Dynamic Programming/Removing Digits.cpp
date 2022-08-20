/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp) {
            dp[i] = min(dp[i], dp[i - (tmp % 10)] + 1);
            tmp /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}