#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> low, num, sccId, coin;
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

vector<int> topo;
vector<bool> visited;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
    topo.push_back(u);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    coin.resize(n);
    for (int &x : coin) cin >> x;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }
    Tarjan();
    n = scc.size();
    vector<vector<int>> adj2(n);
    vector<long long> newCoin(n, 0), maxCoin(n);
    for (int i = 0; i < n; i++) {
        for (int u : scc[i]) {
            newCoin[i] += 1ll * coin[u];
            for (int v : adj[u])  {
                if (sccId[v] != i) 
                    adj2[i].push_back(sccId[v]);
            }
        }
        maxCoin[i] = newCoin[i];
    }
    adj = adj2;
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(i);
    reverse(topo.begin(), topo.end());
    for (int u : topo) {
        for (int v : adj[u]) {
            maxCoin[v] = max(maxCoin[v], maxCoin[u] + newCoin[v]);
        }
    }
    cout << *max_element(maxCoin.begin(), maxCoin.end()) << '\n';
    return 0;
}