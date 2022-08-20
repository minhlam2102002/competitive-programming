/*
    author: Minh Lam
    version: 1.0.1
*/

#include<bits/stdc++.h>
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define all(v) v.begin(), v.end()
#define readv(v) for(auto &e : v) cin >> e;
#define readvv(vv) for(auto &v : vv) for(auto &e : v) cin >> e; 

using ll = long long;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

void solve() {
    ll n; cin >> n;
    ll numK = 9, k = 1;
    ll sum = 0;
    ll num = 1;
    while (sum + numK * k <= n) {
        sum += numK * k;
        numK *= 10ll;
        k += 1;
        num *= 10;
    }
    int digit = (n - sum) % k;
    ll pos = (n - sum) / k + (digit > 0);
    num += pos - 1;
    if (digit == 0) digit = k;
    digit = k - digit;
    while(digit--)  num /= 10;
    cout << num % 10 << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int q; cin >> q;
    while (q--)
        solve();

    return 0;
}