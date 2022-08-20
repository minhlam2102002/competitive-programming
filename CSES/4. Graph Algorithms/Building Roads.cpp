/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v, graph, visited);
        }
    }
}

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
    vector<int> points;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited);
            points.push_back(i);
        }
    }
    cout << points.size() - 1 << endl;
    for (int i = 1; i < points.size(); i++) {
        cout << points[i - 1] + 1 << " " << points[i] + 1 << endl;
    }
    return 0;
}