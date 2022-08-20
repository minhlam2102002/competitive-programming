/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mem[20][2][11];

ll dp(int id, bool tight, int preDitgit, vector<int> &digit) {
    if (id < 0) return 1;
    if (mem[id][tight][preDitgit] != -1) 
        return mem[id][tight][preDitgit];

    ll& res = mem[id][tight][preDitgit];
    res = 0;
    int limit = tight ? digit[id] : 9;

    for (int i = 0; i <= limit; i++) {
        if (i == preDitgit) continue;
        if (preDitgit == 10 && i == 0) {
            res += dp(id - 1, false, 10, digit);
            continue;
        }

        bool newTight = (tight && i == limit);
        res += dp(id - 1, newTight, i, digit);
    }
    return res;
}
vector<int> toVector(ll x) {
    vector<int> digit;
    while (x > 0) {
        digit.push_back(x % 10);
        x /= 10;
    }
    return digit;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    vector<int> digitB = toVector(b);
    memset(mem, -1, sizeof(mem));
    ll res = dp(digitB.size() - 1, true, 10, digitB);
    if (a > 0) {
        vector<int> digitA = toVector(a - 1);
        memset(mem, -1, sizeof(mem));
        res -= dp(digitA.size() - 1, true, 10, digitA);
    }
    cout << res << endl;
    return 0;
}