#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> adj;
vector<int> degree;

vector<int> Hierholzer(vector<set<int>> adj, int u) {
    stack<int> path;
    vector<int> circuit;
    path.push(u);
    while (!path.empty()) {
        if (!adj[u].empty()) {
            path.push(u);
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
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

vector<int> findEulerPath() {
    vector<int> odds;
    for (int i = 0; i < n; i++) 
        if (degree[i] % 2 == 1)
            odds.push_back(i);
    if (odds.size() == 2) {
        int s = odds[0], t = odds[1];
        adj[s].insert(t);
        adj[t].insert(s);
        vector<int> circuit = Hierholzer(adj, odds[0]);
        int last;
        for (int i = 0; i < circuit.size() - 1; i++)
            if (circuit[i] == t && circuit[i + 1] == s || circuit[i] == s && circuit[i + 1] == t) {
                last = i;
                break;
            }
        vector<int> ans(circuit.begin() + last + 1, circuit.end());
        for (int j = 1; j <= last; j++)
            ans.push_back(circuit[j]);
        return ans;
    } 
    if (odds.size() == 0) 
        return Hierholzer(adj, 0);
    return {};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    adj.resize(n);
    degree.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        --u, --v;
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int> circuit = findEulerPath();
    if (circuit.size() != m + 1)
        cout << "IMPOSSIBLE";
    else
        for (int i : circuit)
            cout << i + 1 << " ";
    return 0;
}