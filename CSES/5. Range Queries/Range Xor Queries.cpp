#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] ^ a[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (pref[r] ^ pref[l - 1]) << '\n';
    }
    return 0;
}