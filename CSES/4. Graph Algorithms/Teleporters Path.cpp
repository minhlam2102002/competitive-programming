#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indegree, outdegree;

vector<int> Hierholzer(vector<vector<int>> adj, int u) {
    stack<int> path;
    vector<int> circuit;
    path.push(u);
    while (!path.empty()) {
        if (!adj[u].empty()) {
            path.push(u);
            int v = adj[u].back();
            adj[u].pop_back();
            u = v;
        }
        else {
            circuit.push_back(u);
            u = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

vector<int> findEulerPath(int s, int t) {
    for (int i = 0; i < n; i++) {
        if (i != s && i != t && indegree[i] != outdegree[i])
            return {};
    }
    int ds = outdegree[s] - indegree[s], dt = indegree[t] - outdegree[t];
    if (ds == dt && ds == 1) {
        adj[t].push_back(s);
        vector<int> circuit = Hierholzer(adj, s);
        int last;
        for (int i = 0; i < circuit.size() - 1; i++)
            if (circuit[i] == t && circuit[i + 1] == s) {
                last = i;
                break;
            }
        vector<int> ans(circuit.begin() + last + 1, circuit.end());
        for (int j = 1; j <= last; j++)
            ans.push_back(circuit[j]);
        return ans;
    }
    return {};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    indegree.resize(n);
    outdegree.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        indegree[v]++;
        outdegree[u]++;
    }
    vector<int> circuit = findEulerPath(0, n - 1);
    if (circuit.size() != m + 1)
        cout << "IMPOSSIBLE";
    else
        for (int i : circuit)
            cout << i + 1 << " ";
    return 0;
}