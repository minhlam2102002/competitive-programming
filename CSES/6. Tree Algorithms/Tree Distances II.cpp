#include<bits/stdc++.h>
using namespace std;

int n; 
vector<vector<int>> adj;
vector<long long> sub, in, out, sumIn, sumSub;

void dfsIn(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsIn(v, u);
        sub[u] += sub[v];
        in[u] += in[v] + sub[v];
        sumIn[u] += in[v];
        sumSub[u] += sub[v];
    }
}
void dfsOut(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        out[v] = out[u] + (n - sumSub[u]);
        out[v] += sumIn[u] + sumSub[u] * 2;
        out[v] -= in[v] + sub[v] * 2;
        dfsOut(v, u);
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    adj.resize(n);
    sub.resize(n);
    in.resize(n);
    out.resize(n);
    sumIn.resize(n);
    sumSub.resize(n);
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsIn(0, -1);
    dfsOut(0, -1);
    for (int i = 0; i < n; i++) 
        cout << in[i] + out[i] << " ";
    return 0;
}