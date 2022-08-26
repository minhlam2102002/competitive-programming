// Verified: https://cses.fi/problemset/task/1682/
// Verified: https://cses.fi/problemset/task/1683/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> low, num, sccId;
vector<bool> found;
stack<int> st;
vector<vector<int>> scc;
int n, m;
int counter;

void dfs(int u) {
    num[u] = low[u] = ++counter;
    st.push(u);
    for (int v : adj[u]) {
        if (!found[v]) {
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u] == low[u]) {
        // Found a SCC
        int v;
        scc.push_back(vector<int>());
        do {
            v = st.top();
            st.pop();
            scc.back().push_back(v);
            sccId[v] = scc.size() - 1;
            found[v] = true;
        } while (v != u);
    }
}

void Tarjan() {
    counter = 0;
    low.assign(n, 0);
    num.assign(n, 0);
    sccId.assign(n, -1);
    found.assign(n, false);
    st = stack<int>();
    for (int i = 0; i < n; i++)
        if (!num[i]) 
            dfs(i);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }
    Tarjan();
    return 0;
}