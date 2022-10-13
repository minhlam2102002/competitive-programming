#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, revAdj, compList;
vector<bool> visited, assignment;
vector<int> order, comp;

void dfs1(int u) {
    visited[u] = true;

    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;

    compList.back().push_back(u);
    comp[u] = compList.size() - 1;

    for (int v : revAdj[u])
        if (!visited[v])
            dfs2(v);
}

void Kosaraju(int n) {
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    visited.assign(n, false);
    comp.assign(n, -1);
    reverse(order.begin(), order.end());

    for (int v : order)
        if (!visited[v]) {
            compList.push_back(vector<int>());
            dfs2(v);
        }
}

bool solve2SAT(int n) {
    Kosaraju(n);
    assignment.assign(n / 2 - 1, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb are true then a and b are to be negated 
    // k is denoted by 2k if k is positive and 2k+1 if k is negative
    a = (a << 1) ^ na;
    b = (b << 1) ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    revAdj[b].push_back(neg_a);
    revAdj[a].push_back(neg_b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    n = (n << 1) + 2;
    adj.assign(n, vector<int>());
    revAdj.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        char wish1, wish2; 
        int topping1, topping2; 
        cin >> wish1 >> topping1;
        cin >> wish2 >> topping2;
        topping1--, topping2--;
        add_disjunction(topping1, wish1 == '-', topping2, wish2 == '-');
    }

    if (solve2SAT(n)) {
        for (int i = 0; i < n / 2 - 1; i++)
            cout << (assignment[i] ? '+' : '-') << ' ';
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}