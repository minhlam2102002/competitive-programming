/*
    author: Minh Lam
*/
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string d = "RLDU";
int n, m; 
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> path;
string res;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (isValid(xx, yy) && grid[xx][yy] != '#' && !visited[xx][yy]) {
                q.push({xx, yy});
                path[xx][yy] = {x, y};
                visited[xx][yy] = true;
            }
        }   
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    path.resize(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    pair<int, int> finish, start;  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                BFS(i, j);
                start = {i, j};
            } 
            if (grid[i][j] == 'B') {
                finish = {i, j};
            }
        }

    if (visited[finish.first][finish.second]) {
        int x = finish.first, y = finish.second;
        while (x != start.first || y != start.second) {
            auto p = path[x][y];
            for (int i = 0; i < 4; i++) {
                if (x - p.first == dx[i] && y - p.second == dy[i]) {
                    res += d[i];
                    break;
                }
            }
            x = p.first;
            y = p.second;
        }
        cout << "YES" << endl;
        cout << res.length() << endl;
        reverse(res.begin(), res.end());
        cout << res << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
