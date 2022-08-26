// Verified: https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;

void FloydWarshall(vector<vector<long long>> &dist) {
    const long long INF = 1e18;
    int n = dist.size();
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
}
