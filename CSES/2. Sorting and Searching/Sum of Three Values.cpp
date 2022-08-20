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

vi SumOfTwo(vector<pii> &a, int l, int r, int target) {
    while (l < r) {
        if (a[l].first + a[r].first > target)
            r--;
        else if (a[l].first + a[r].first < target)
            l++;
        else 
            return {a[l].second, a[r].second};
    }
    return {};
}

vi SumOfThree(vector<pii> &a, int l, int r, int target) {
    for (int i = l; i <= r - 2; i++) {
        auto res = SumOfTwo(a, i + 1, r, target - a[i].first);
        if (res.size() > 0)
            return {a[i].second, res[0], res[1]};
    }
    return {};
}


void solve() {
    int n, x; cin >> n >> x;
    vector<pii> a(n);
    forIndex(i, a) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    auto res = SumOfThree(a, 0, n - 1, x);
    if (res.size() > 0) {
        forEach(e, res)
            cout << e + 1 << " ";
        cout << endl;
    } else
        cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // #ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // chrono::steady_clock::time_point start = chrono::steady_clock::now();
    // #endif  

    int t = 1; 
    // int t; cin >> t;
    while (t--) {
        solve();
    }

    // #ifdef LOCAL
    // chrono::steady_clock::time_point end = chrono::steady_clock::now();
    // cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    // #endif
    return 0;
}