// Verified: https://cses.fi/problemset/task/1144/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    indexed_set s;
    s.insert(2);
    auto x = s.find_by_order(2);
    cout << *x << endl;
    cout << s.order_of_key(6) << "\n"; // 2    
    return 0;
}