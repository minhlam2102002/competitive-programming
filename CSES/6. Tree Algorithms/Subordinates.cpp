#include<bits/stdc++.h>
using namespace std;

vector<int> parent, numChildren;
vector<vector<int>> child;
void dfs(int u, int p) {
    for (int v : child[u]) {
        if (v == p) continue;
        dfs(v, u);
        numChildren[u] += numChildren[v] + 1;
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    parent.resize(n + 1);
    numChildren.resize(n + 1);
    child.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        child[parent[i]].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << numChildren[i] << ' ';
    }
    return 0;
}