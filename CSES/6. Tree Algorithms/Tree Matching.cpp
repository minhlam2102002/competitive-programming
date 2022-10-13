#include <bits/stdc++.h>
using namespace std;

int n;
int nleft, nright;
vector<vector<int>> adj;
vector<int> matchL, matchR, dist;
const int INF = 1e9;
int NIL;

bool dfs(int u) {
    if (u != NIL) {
        for (int v : adj[u]) {
            if (dist[matchR[v]] == dist[u] + 1) {
                if (dfs(matchR[v])) {
                    matchR[v] = u;
                    matchL[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
bool bfs() {
    queue<int> q;
    for (int i = 0; i < nleft; i++) {
        if (matchL[i] == NIL) {
            dist[i] = 0;
            q.push(i);
        }
    }
    dist[NIL] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[NIL]) {
            for (int v : adj[u]) {
                v = matchR[v];
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return dist[NIL] != INF;
}
int HopcroftKarp() {
    NIL = nleft;
    matchL.assign(nleft, NIL);
    matchR.assign(nright, NIL);
    dist.assign(nleft + 1, NIL);

    int matching = 0;
    while (bfs()) {
        for (int u = 0; u < nleft; u++)
            if (matchL[u] == NIL && dfs(u))
                matching++;
    }
    return matching;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    adj.assign(nleft, vector<int>());
    return 0;
}