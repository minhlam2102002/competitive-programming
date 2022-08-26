/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<pair<int, int>> monsters;
vector<vector<int>> dist;
vector<vector<bool>> visited;
pair<int, int> human;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    dist[x][y] = 0;
    while (!q.empty()) {
        int u, v;
        tie(u, v) = q.front();
        q.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) + abs(j) == 1) {
                    int x = u + i, y = v + j;
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y]) {
                        visited[x][y] = true;
                        dist[x][y] = dist[u][v] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                human = {i, j};
            } else if (grid[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }
    dist.resize(n, vector<int>(m, -1));
    visited.resize(n, vector<bool>(m, false));
    for (auto &monster : monsters) {
        BFS(monster);
    }
    return 0;
}