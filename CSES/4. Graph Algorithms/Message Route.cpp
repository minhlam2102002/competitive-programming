#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }    
    queue<int> q;
    vector<int> path(n, -1);
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                path[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    if (path[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> ans;
        int u = n - 1;
        while (u != -1) {
            ans.push_back(u);
            u = path[u];
        }
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}