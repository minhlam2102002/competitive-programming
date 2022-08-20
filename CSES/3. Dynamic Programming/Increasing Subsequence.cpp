/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n; 
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> lis;
    for (const int &x : a) {
        if (lis.empty() || x > lis.back()) {
            lis.push_back(x);
        } else {
            int i = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[i] = x;
        }
    }
    cout << lis.size() << endl;
    return 0;
}