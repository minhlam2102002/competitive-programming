#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    indexed_set s;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    while (q--) {
        char t;
        cin >> t;
        if (t == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            s.erase({a[k], k});
            a[k] = x;
            s.insert({x, k});
        } else {
            int a, b;
            cin >> a >> b;
            int l = s.order_of_key({a, -1});
            int r = s.order_of_key({b, n});
            cout << r - l << '\n';
        }
    }
    return 0;
}