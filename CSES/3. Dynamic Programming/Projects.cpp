/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

struct Project {
    int start, end, money;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<Project> a(n);
    vector<int> compress;
    for (Project &x : a) {
        cin >> x.start >> x.end >> x.money;
        x.end++;
        compress.push_back(x.start);
        compress.push_back(x.end);
    }

    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

    for (Project &x : a) {
        x.start = lower_bound(compress.begin(), compress.end(), x.start) - compress.begin();
        x.end = lower_bound(compress.begin(), compress.end(), x.end) - compress.begin();
    }

    int maxx = compress.size();
    vector<vector<pair<int, int>>> p(maxx);
    for (Project &x : a)
        p[x.end].emplace_back(x.start, x.money);

    vector<long long> dp(maxx);
    for (int i = 0; i < maxx; i++) {
        if (i > 0) dp[i] = dp[i - 1];
        for (auto project : p[i])
            dp[i] = max(dp[i], dp[project.first] + 1ll * project.second);
    }
    cout << dp.back() << endl;
    return 0;
}