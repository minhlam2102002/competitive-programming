/*
    author: Minh Lam
    version: 1.0.2
*/

#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define readv(v) for(auto &e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define forEach(e, v) for (auto &e : v) 
#define forIndex(i, v) for (int i = 0; i < (int)v.size(); i++)
#define endl "\n"

using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

bool canDivision(vi &a, int k, ll m) {
    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (1ll * a[i] > m) return false;
        if (sum + 1ll * a[i] > m) {
            sum = 0;
            cnt++;
        } 
        sum += 1ll * a[i];
    }
    return cnt + 1 <= k;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); readv(a);
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    ll res = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (canDivision(a, k, m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    #endif

    int t = 1; 
    // int t; cin >> t;
    while (t--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    #endif
    return 0;
}