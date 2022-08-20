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

int n;
vector<pii> reserved;
vector<int> queens;
int res = 0;

bool isValid(int row, int col) {
    for (int i = 0; i < queens.size(); i++) {
        if (queens[i] == col) return false;
        if (i - row == queens[i] - col) return false;
        if (i - row == col - queens[i]) return false;
    }
    for (int i = 0; i < reserved.size(); i++) 
        if (reserved[i] == make_pair(row, col)) return false;
    return true;
}
void backtrack(int row) {
    if (row == n) {
        res += 1;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col)) {
            queens.push_back(col);
            backtrack(row + 1);
            queens.pop_back();
        }
    }   
}
void solve() {
    str row;
    int r = 0;
    while (cin >> row) {
        n = row.size();
        for (int c = 0; c < n; c++)
            if (row[c] == '*')
                reserved.push_back({r, c});
        r++;
    }
    backtrack(0);
    cout << res << endl;
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