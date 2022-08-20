/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> dp[2];
    dp[0].resize(m + 2, 0);
    dp[1].resize(m + 2, 0);
    int res = 0, c = 0;
    auto calc = [&] (int c, int j) -> int {
        return (dp[1 - c][j] + dp[1 - c][j - 1] + dp[1 - c][j + 1]) % MOD;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0) 
                dp[c][j] = i == 1 ? 1 : calc(c, j);
            else {
                if (j == a[i]) {
                    dp[c][j] = i == 1 ? 1 : calc(c, j);
                } else {
                    dp[c][j] = 0;
                }
            }
            if (i == n) res = (res + dp[c][j]) % MOD;
        }
        c = 1 - c;
    }
    cout << res << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;int M=1e9+7,n,m,x,d[100005][105],r,i,j;int l(){return(1ll*d[i-1][j]+d[i-1][j-1]+d[i-1][j+1]+(i==1))%M;}int main(){cin>>n>>m;while(i<n){i++;cin>>x;if(x)j=x,r=d[i][x]=l();else for(r=0,j=1;j<=m;j++)r=(r+(d[i][j]=l()))%M;}cout<<r;}