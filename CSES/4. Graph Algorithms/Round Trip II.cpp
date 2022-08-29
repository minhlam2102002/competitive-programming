#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> graph;
vector<bool> visited, inStack;
vector<int> parent;
int start, finish;
bool found = false;
void DFS(int u) { 
    visited[u] = inStack[u] = true;
    for (int &v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
        else if (inStack[v]) {
            found = true;
            start = v;
            finish = u;
        }
    }
    inStack[u] = false;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    visited.resize(n, false);
    inStack.resize(n, false);
    parent.resize(n, -1);
    for (int i = 0; i < n; i++) {
        if (!found && !visited[i]) {
            DFS(i);
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> ans = {start};
        while (finish != start) {
            ans.push_back(finish);
            finish = parent[finish];
        }
        ans.push_back(start);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}