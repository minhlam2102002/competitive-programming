/*
    author: Minh Lam
    version: 1.0.2
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define readv(v) for(auto &e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define forEach(e, v) for (auto &e : v) 
#define forIndex(i, v) for (int i = 0; i < (int)v.size(); i++)
#define endl "\n"
#define sz(v) (int)v.size()


using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

multiset<ll> up, low;
ll sumUp = 0, sumLow = 0;

void Balance() {
    if (low.size() < up.size()) {
        sumLow += *up.begin();
        low.insert(*up.begin());
        sumUp -= *up.begin();
        up.erase(up.begin());
    } else if (low.size() > up.size() + 1) {
        auto lastLow = --low.end();
        sumUp += *lastLow;
        up.insert(*lastLow);
        sumLow -= *lastLow;
        low.erase(lastLow);
    }

}

void Add(ll x) {
    // low.size == up.size || low.size == up.size + 1
    if (low.empty()) {
        low.insert(x);
        sumLow += x;
        return;
    }
    auto last = --low.end();
    if (x <= *last) {
        sumLow += x;
        low.insert(x);
    } else {
        sumUp += x;
        up.insert(x);
    }
    Balance();
}

void Remove(ll x) {
    if (low.find(x) != low.end()) {
        low.erase(low.find(x));
        sumLow -= x;
    } else {
        up.erase(up.find(x));
        sumUp -= x;
    }
    Balance();
}

void solve() {
    int n, k; cin >> n >> k;
    int mid = (k - 1) / 2;
    vector<ll> a(n); readv(a);

    for (int i = 0; i <= n; i++) {
        if (i < k) {
            Add(a[i]);
        } else {
            ll median = *(--low.end());
            ll res = 0;
            res +=  median * sz(low) - sumLow;
            res +=  sumUp - median * sz(up);
            cout << res << ' ';
            if (i == n) break;
            Remove(a[i - k]);
            Add(a[i]);
        }
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