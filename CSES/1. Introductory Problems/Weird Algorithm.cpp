#include<bits/stdc++.h>
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define all(v) v.begin(), v.end()
#define readv(v) for(auto &x : v) cin >> x;

using ll = long long;
using str = string;
using vi = vector<int>;
using pii = pair<int,int>;

const int MAXN = 1e5 + 5;

void solve() {
    ll n; cin >> n;
    cout << n << ' ';
    while(n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        cout << n << ' ';
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