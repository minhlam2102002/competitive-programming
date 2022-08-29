#include<bits/stdc++.h>
using namespace std;

void ask(vector<int> v) {
    cout << "ASK " << v.size() << ' ';
    for (int x : v) cout << x << ' ';
    cout << endl;
}
void answer(vector<int> v) {
    for (int x : v) cout << x << ' ';
    cout << "ANSWER ";
    cout << endl;
}
vector<int> res;
void solve(int l, int r) {
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    res.resize(n);
    solve(1, n);
    return 0;
}