#include <bits/stdc++.h>
using namespace std;

namespace BellmanFordSpace{
    const long long INF = 1e18;
    vector<tuple<int, int, int>> edges;
    vector<long long> dist;
    vector<int> prev;
    int n, m, lastChange = -1;
    bool hasNegativeCycle = false;
    void BellmanFord(vector<int> starts) {
        dist.assign(n, INF);
        prev.assign(n, -1);
        for (int &s : starts)
            dist[s] = 0;
        for (int i = 0; i < n; i++) {
            bool changed = false;
            for (auto e : edges) {
                int u, v, w;
                tie(u, v, w) = e;
                if (dist[u] < INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                    changed = true;
                    if (i == n - 1) lastChange = v;
                }
            }
            if (i == n - 1 && changed) hasNegativeCycle = true;
            if (!changed) return;
        }
    }
    vector<int> negativeCycle() {
        if (lastChange == -1) return {};
        int n = prev.size();
        int v = lastChange;
        for (int i = 0; i < n; ++i)
            v = prev[v];
        int u = v;
        vector<int> cycle;
        while (true) {
            v = prev[v];
            cycle.push_back(v);
            if (v == u && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        if (cycle.front() != cycle.back())
            cycle.push_back(cycle.front());
        return cycle;
    }
}
using namespace BellmanFordSpace;

namespace ComponentFindingSpace{
    vector<vector<int>> graph;
    vector<int> component, starts;
    int componentCount = 0;
    void DFS(int u, int c) {
        component[u] = c;
        for (int v : graph[u])
            if (component[v] == -1) 
                DFS(v, c);
    }
    void findComponents() {
        int n = graph.size();
        component.assign(n, -1);
        for (int i = 0; i < n; i++)
            if (component[i] == -1) {
                DFS(i, ++componentCount);
                starts.push_back(i);
            }
    }
}
using namespace ComponentFindingSpace;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    edges.resize(m);
    graph.resize(n);
    for (auto &e : edges) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back(v);
        e = {u, v, w};
    }
    findComponents();
    BellmanFord(starts);
    if (hasNegativeCycle) {
        cout << "YES" << endl;
        vector<int> cycle = negativeCycle();
        for (int v : cycle)
            cout << v + 1 << " ";
    } else {
        cout << "NO" << endl;
    }
}