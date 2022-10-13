#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int n, m;
vector<vector<char>> grid;
vector<vector<int>> dist, Mdist;
vector<vector<bool>> visited;
vector<vector<pii>> pre;
pii finish;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isInside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(vector<pii> start, bool isHuman) {
    dist.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<bool>(m, false));
    pre.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pii> q;
    for (auto s : start) {
        q.push(s);
        visited[s.first][s.second] = true;
        dist[s.first][s.second] = 0;
    }
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = u + dx[i];
            int y = v + dy[i];
            if (isHuman && !isInside(x, y))
                finish = {u, v};
            if (isInside(x, y) && !visited[x][y] && grid[x][y] != '#') {
                if (isHuman && Mdist[x][y]!= -1 && Mdist[x][y] <= dist[u][v] + 1) {
                    continue;
                }
                q.push({x, y});
                visited[x][y] = true;
                dist[x][y] = dist[u][v] + 1;
                pre[x][y] = {u, v};
            }
        }
    }
}

string restorePath(pii s, pii t) {
    string path;
    while (t != s) {
        pii p = pre[t.first][t.second];
        int dx = t.first - p.first;
        int dy = t.second - p.second;
        if (dx == 1)
            path += 'D';
        else if (dx == -1)
            path += 'U';
        else if (dy == 1)
            path += 'R';
        else if (dy == -1)
            path += 'L';
        t = p;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    vector<pii> monsters;
    pii human;
    
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
    BFS(monsters, false);
    Mdist = dist;
    finish = {-1, -1};
    BFS({human}, true);
    if (finish != make_pair(-1, -1)) {
        auto path = restorePath(human, finish);
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO";
    }
    return 0;
}