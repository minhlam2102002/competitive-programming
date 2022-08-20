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
 
int cnt(vi &a, int u, int v) {
    if (u > v) swap(u, v);
    int res = (a[u] > a[u + 1]) + (a[u - 1] > a[u]);
    res += (a[v] > a[v + 1]) + (v > u + 1 && a[v - 1] > a[v]);
    return res;
}
 
void solve() {
    int n, m; cin >> n >> m;
    vi a(n + 2), r(n + 2);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        r[i] = x;
        a[x] = i;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) 
        if (a[i] > a[i + 1])
            res += 1;
    while (m--) {
        int u, v; cin >> u >> v;
        res -= cnt(a, r[u], r[v]);
        cout << cnt(a, r[u], r[v]) <<' ';
        swap(a[r[u]], a[r[v]]);
        swap(r[u], r[v]);
        res += cnt(a, r[u], r[v]);
        cout << cnt(a, r[u], r[v]) <<'\n';
        cout << res << endl;
    }   
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
// #include<bits/stdc++.h>
// using namespace std;
// #define c(i) (a[i] > a[i + 1])
// #define R for(i = 1; i <= n; i++)
// int a[200005], r[200005], n, m, u, v, s, x, y, i;int t() {u = r[x]; v = r[y]; if (u > v) swap(u, v);return c(u) + c(u-1) + c(v) + ((v > u + 1) && c(v-1));}
// int main() {cin >> n >> m;R cin >> r[i], a[r[i]] = i;R s += c(i);while (m--) cin >> x >> y, s -= t(), swap(a[u], a[v]), swap(r[x], r[y]), s += t(), cout << s << endl;}