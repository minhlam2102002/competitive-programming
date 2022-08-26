// Verified: https://cses.fi/problemset/task/1693/
#include<bits/stdc++.h>
using namespace std;

vector<int> Hierholzer(vector<vector<int>> adj, int u) { 
    // Directed graph
    stack<int> path;
    vector<int> circuit;
    path.push(u);
    while (!path.empty()) {
        if (!adj[u].empty()) {
            path.push(u);
            int v = adj[u].back();
            adj[u].pop_back();
            u = v;
        }
        else {
            circuit.push_back(u);
            u = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}


// Verified: https://cses.fi/problemset/task/1691/
vector<int> Hierholzer(vector<set<int>> adj, int u) {
    // Undirected graph
    stack<int> path;
    vector<int> circuit;
    path.push(u);
    while (!path.empty()) {
        if (!adj[u].empty()) {
            path.push(u);
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            u = v;
        }
        else {
            circuit.push_back(u);
            u = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}