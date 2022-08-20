/*
    author: Minh Lam
    version: 1.0.0
*/

#include<bits/stdc++.h>
using namespace std;

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
    int n; cin >> n;
    vvi a(n, vi(n)), id(n, vi(n));
    int cnt = 0;
    readvv(a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            id[i][j] = cnt++;
        }
    }
    int q; cin >> q;
    vector<pii> tiger;
    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        tiger.push_back({u, v});
    }
    int nmask = 1 << q;
    for(int mask = 0; mask < nmask; mask++) {
        for (int i = 0; i < q; i++) {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}