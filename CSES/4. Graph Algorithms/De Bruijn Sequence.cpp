// https://www.geeksforgeeks.org/de-bruijn-sequence-set-1/
#include<bits/stdc++.h>
using namespace std;

vector<int> Hierholzer(vector<vector<int>> adj, int u = 0) {
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
string printBit(int x, int n){
    string s = "";
    for(int i = n - 1; i >= 0; i--){
        s += (x & (1 << i)) ? '1' : '0';
    }
    return s;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    if (n == 1) return cout << "01\n", 0;
    n--;
    vector<vector<int>> adj(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int j = (i & ~(1 << (n - 1))) << 1;
        adj[i].push_back(j);
        adj[i].push_back(j + 1);
    }
    vector<int> circuit = Hierholzer(adj);
    string res = printBit(circuit[0], n);
    for (int i = 1; i < circuit.size(); i++) {
        res += (circuit[i] & 1) ? '1' : '0';
    }
    cout << res;
    return 0;
}