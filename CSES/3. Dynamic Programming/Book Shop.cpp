/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> prices(n), pages(n);
    for (int &page : pages) cin >> page;
    for (int &price : prices) cin >> price;
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= pages[i]; j--) {
            dp[j] = max(dp[j], dp[j - pages[i]] + prices[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}