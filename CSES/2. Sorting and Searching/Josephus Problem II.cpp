/*
    author: Minh Lam
    version: 1.0.1
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define all(v) v.begin(), v.end()
#define readv(v) for(auto &e : v) cin >> e;
#define readvv(vv) for(auto &v : vv) for(auto &e : v) cin >> e; 

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

using ll = long long;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

void solve() {
    int n, k; cin >> n >> k;
    indexed_set s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int idx = k % n;
    while (n--) {
        auto it = s.find_by_order(idx);
        cout << *it << " ";
        s.erase(it);
        if  (n > 0) 
            idx = (idx + k) % n;
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