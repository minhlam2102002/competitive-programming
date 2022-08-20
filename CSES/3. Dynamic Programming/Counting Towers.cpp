/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int MOD = 1e9 + 7;

int a[MAX_N + 1], b[MAX_N + 1]; // a -> both cells in last row are same block, b -> they are different block
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    a[1] = b[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        a[i] = (2ll * a[i - 1] + b[i - 1]) % MOD; 
        // row[i] and row[i - 1] are same block <-> a[i - 1]
        //if they are different block <-> a[i - 1] + b[i - 1]
        b[i] = (4ll * b[i - 1] + a[i - 1]) % MOD; 
        // a[i - 1] + b[i - 1] if there is no blocks between row i and i - 1
        // 3 * b[i - 1] for 3 case of blocks between row i and i - 1
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (a[n] + b[n]) % MOD << endl;
    }
    return 0;
}