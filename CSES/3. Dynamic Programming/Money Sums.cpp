/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXX = 1000;

int a[MAXN + 1];
bool dp[MAXN + 1][MAXN * MAXX + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m = 0; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m += a[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) 
            dp[i][j] = dp[i - 1][j] || (j >= a[i] && dp[i - 1][j - a[i]]);
    vector<int> res;
    for (int j = 1; j <= m; j++) 
        if (dp[n][j]) res.push_back(j);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}