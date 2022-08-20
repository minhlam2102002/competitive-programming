#include<bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &graph, vector<int> &color) {
    for (int v : graph[u]) {
        if (color[v] == 0) {
            color[v] = color[u] == 1 ? 2 : 1;
            DFS(v, graph, color);
        } else if (color[v] == color[u]) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            DFS(i, graph, color);
        }
    }
    for (int c : color) cout << c << " ";
    return 0;
}