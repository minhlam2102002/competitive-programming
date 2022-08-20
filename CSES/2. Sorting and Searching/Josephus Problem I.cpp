/*
    author: Minh Lam
    version: 1.0.1
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
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    while (dq.size() > 1) {
        int x = dq.front();
        dq.pop_front();
        dq.push_back(x);
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << dq.front() << endl;
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