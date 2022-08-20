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
    int n, x;
    cin >> n >> x;
    // vi a(n); readv(a);
    // unordered_map<int, int> vals;
    // for (int i = 0; i < n; i++) {
    //     if (vals.count(x - a[i])) {
    //         cout << i + 1 << ' ' << vals[x - a[i]] + 1 << endl;
    //         return;
    //     }
    //     vals[a[i]] = i;
    // }
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i].first + a[j].first > x)
            j--;
        else if (a[i].first + a[j].first < x)
            i++;
        else {
            cout << a[i].second + 1 << ' ' << a[j].second + 1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    solve();

    return 0;
}