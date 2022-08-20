/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited, inStack;
void DFS(int u) {
    visited[u] = inStack[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v);
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
        graph[v].push_back(u);
    }
    visited.resize(n, false);
    inStack.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    return 0;
}