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
 
using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
 
typedef tree<pii,null_type,less<pii>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const int MAXN = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
 
struct Range{
    int l, r, id;
    bool operator<(const Range &other) const {
        if (l != other.l) return l < other.l;
        if (r != other.r) return r > other.r;
        return id < other.id;
    }
    void getValues(int &l, int &r, int &id) {
        l = this->l;
        r = this->r;
        id = this->id;
    }
};
 
 
void solve() {
    int n; cin >> n;
    vector<Range> ranges(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }
    sort(all(ranges));
    vi res1(n), res2(n);
    indexed_set s;
    for (int i = n - 1; i >= 0; i--) {
        int l, r, id;
        ranges[i].getValues(l, r, id);
        int pos = s.order_of_key({r, n});
        res1[id] = pos;
        s.insert({r, i});
    }
    s.clear();
    for (int i = 0; i < n; i++) {
        int l, r, id;
        ranges[i].getValues(l, r, id);
        int pos = s.order_of_key({r - 1, n});
        res2[id] = i - pos;
        s.insert({r, i});
    }
    for(int i = 0; i < n; i++) 
        cout << res1[i] << ' ';
    cout << endl;
    for(int i = 0; i < n; i++) 
        cout << res2[i] << ' ';
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