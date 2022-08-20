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
    int n; cin >> n;
    ll sum = 1ll * n * (n + 1) / 2;
    if (sum % 2 == 1) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    ll target = sum / 2;
    int split = floor(sqrt(sum));
    if (1ll * split * (split +  1) > sum) split--;
    debug(sum);
    debug(split);
    ll sumLeft = 1ll * split * (split + 1) / 2;
    int diff = sum / 2 - sumLeft;
    pair<int, int> swapPair;
    if (diff > 0) {
        if (diff >= split) {
            swapPair = {1, diff + 1};
        } else {
            swapPair = {split + 1 - diff, split + 1};
        }
        cout << split << endl;
        for (int i = 1; i <= split; i++) 
            if (i != swapPair.first)
                cout << i << ' ';
        cout << swapPair.second << endl;
        cout << n - split << endl;
        for (int i = split + 1; i <= n; i++) 
            if (i != swapPair.second)
                cout << i << ' ';
        cout << swapPair.first;

    } else {
        cout << split << endl;
        for (int i = 1; i <= split; i++) 
            cout << i << ' ';
        cout << endl;
        cout << n - split << endl;
        for (int i = split + 1; i <= n; i++) 
            cout << i << ' ';
        
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