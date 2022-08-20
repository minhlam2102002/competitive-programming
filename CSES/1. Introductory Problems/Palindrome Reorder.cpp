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
const int ALPHA = 26;

void solve() {
    str s; cin >> s;
    vi cnt(ALPHA);
    for (char c : s) 
        cnt[c - 'A']++;
    vi odd;
    for (int c = 0; c < cnt.size(); c++) 
        if (cnt[c] % 2 == 1) 
            odd.push_back(c);
    if (odd.size() > 1) {
        cout << "NO SOLUTION";
        return;
    } 
    string left;
    for (int c = 0; c < cnt.size(); c++) {
        int times = cnt[c] / 2;
        while(times--) 
            left += c + 'A';
    }
    string right = left;
    reverse(right.begin(), right.end());
    if (odd.size() > 0) 
        left += odd[0] + 'A';
    str res = left + right;
    cout << res;
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