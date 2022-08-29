#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (n >= 3 && a > 0 && b > 0 && c > 0 && a + b + c >= n) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}