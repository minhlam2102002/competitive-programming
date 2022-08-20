/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(vector<vector<char>> &grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    return x >= 0 && x < n && y >= 0 && y < m;
}

void DFS(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (isValid(grid, xx, yy) && grid[xx][yy] == '.' && !visited[xx][yy]) {
            DFS(xx, yy, grid, visited);
        }
    }
}

int CountingRooms(int n, int m, vector<vector<char>> &grid) {
    int res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.' && !visited[i][j]) {
                DFS(i, j, grid, visited);
                res++;
            }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << CountingRooms(n, m, grid) << endl;
    return 0;
}