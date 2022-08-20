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

ll numberOf(int x, int y) {
    int n = max(x, y);
    ll first = 1ll * (n - 1) * (n - 1) + 1;
    ll last = 1ll * n * n;
    int dir = n % 2; // 0 -> down - left , 1 -> right - up
    // cout << first << ' ' << last << ' ' << dir << endl;
    if (x <= y) {
        if (dir == 0) 
            return first + x - 1;
        else
            return last - x + 1;
    } else {
        if (dir == 0)
            return last - y + 1;
        else
            return first + y - 1;
    }
    return 0;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int x, y; 
        cin >> x >> y;
        cout << numberOf(x, y) << endl;
    }
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