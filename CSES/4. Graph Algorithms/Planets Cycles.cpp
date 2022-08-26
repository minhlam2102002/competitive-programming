#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXM = 30;

int n;
vector<vector<int>> adj, cycles, revAdj;
vector<int> cycleIdx, visited, pre, height, root, idx;
int parent[MAXN][MAXM];
int cycleCount = 0;
int startCycle, finishCycle;

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u])
        if (visited[v] == 0) {
            pre[v] = u;
            dfs(v);
        }
        else if (visited[v] == 1) {
            startCycle = v;
            finishCycle = u;
        }
    visited[u] = 2;
}
vector<int> restorePath(int s, int t, vector<int> const &pre) {
    vector<int> path;
    for (int v = t; v != s; v = pre[v]) 
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
void dfs(int u, int r) {
    cycleIdx[u] = cycleCount;
    root[u] = r;
    for (int v : revAdj[u])
        if (height[v] == -1) {
            height[v] = height[u] + 1;
            dfs(v, r);
        }
}
int succ(int x, int k) {
    for (int j = 0; j < MAXM; j++)
        if (k & (1 << j))
            x = parent[x][j];
    return x;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    adj.resize(n);
    revAdj.resize(n);
    for (int v, u = 0; u < n; u++) {
        cin >> v;
        v--;
        parent[u][0] = v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    for (int j = 1; j < MAXM; j++) 
        for (int i = 0; i < n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    cycleIdx.resize(n, -1);
    visited.resize(n, 0);
    pre.resize(n, -1);
    height.resize(n, -1);
    root.resize(n, -1);
    idx.resize(n, -1);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            startCycle = finishCycle = -1;
            dfs(i);
            if (startCycle != -1) {
                cycles.push_back(restorePath(startCycle, finishCycle, pre));
                for (int i = 0; i < cycles.back().size(); i++) {
                    int u = cycles.back()[i];
                    height[u] = 0;
                    idx[u] = i;
                }
                for (int u : cycles.back())
                    dfs(u, u);
                cycleCount++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int u = i;
        int res = height[u];
        u = root[u];
        int cycleSize = cycles[cycleIdx[u]].size();
        res += cycleSize;
        cout << res << " ";
    }
    
    return 0;
}