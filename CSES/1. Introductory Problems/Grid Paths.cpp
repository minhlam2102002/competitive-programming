/*
    author: Minh Lam
    version: 1.0.1
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define all(v) v.begin(), v.end()
#define readv(v) for(auto &e : v) cin >> e;
#define readvv(vv) for(auto &v : vv) for(auto &e : v) cin >> e; 
 
using ll = long long;
using str = string;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
 
const int MAXN = 10;
const int INF = 1e9;
 
int n = 7;
int maxLen = n * n - 1;
 
bool visited[MAXN][MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dir[4] = {'L', 'R', 'U', 'D'};
int idDir[300]; 
string s;
int res = 0;
 
bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}
 
bool canGo(int x, int y) {
    return isValid(x, y) && !visited[x][y];
}

void dfs(int x, int y, int len) {
    if(x == n - 1 && y == 0) {
        if (len == maxLen) 
            res += 1;
        return;
    }
 
    if (canGo(x, y - 1) && canGo(x, y + 1) 
    && !canGo(x - 1, y) && !canGo(x + 1, y)) return;
    
    if (canGo(x - 1, y) && canGo(x + 1, y) 
    && !canGo(x, y - 1) && !canGo(x, y + 1)) return;
    
    if (s[len] != '?') {
        int d = idDir[s[len]];
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (canGo(xx, yy)) {
            visited[xx][yy] = true;
            dfs(xx, yy, len + 1);
            visited[xx][yy] = false;
        }
    } 
    // else if (!canGo(x, y - 2) 
    // && (!canGo(x - 1, y - 1) || !canGo(x + 1, y - 1))
    // && canGo(x, y - 1)){
    //     visited[x][y - 1] = true;
    //     dfs(x, y - 1, len + 1);
    //     visited[x][y - 1] = false;
    // } 
    else if (!canGo(x, y + 2)
    && (!canGo(x - 1, y + 1) || !canGo(x + 1, y + 1))
    && canGo(x, y + 1)) {
        visited[x][y + 1] = true;
        dfs(x, y + 1, len + 1);
        visited[x][y + 1] = false;
    } 
    else if (!canGo(x - 2, y)
    && (!canGo(x - 1, y - 1) || !canGo(x - 1, y + 1))
    && canGo(x - 1, y)) {
        visited[x - 1][y] = true;
        dfs(x - 1, y, len + 1);
        visited[x - 1][y] = false;
    } 
    // else if (!canGo(x + 2, y)
    // && (!canGo(x + 1, y - 1) || !canGo(x + 1, y + 1))
    // && canGo(x + 1, y)) {
    //     visited[x + 1][y] = true;
    //     dfs(x + 1, y, len + 1);
    //     visited[x + 1][y] = false;
    // }
    else
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (canGo(xx, yy)) {
            visited[xx][yy] = true;
            dfs(xx, yy, len + 1);
            visited[xx][yy] = false;
        }
    }
}
 
void solve() {
    cin >> s;
    visited[0][0] = true;
    idDir['L'] = 0; idDir['R'] = 1; 
    idDir['U'] = 2; idDir['D'] = 3;
    dfs(0, 0, 0);
    cout << res << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
 
    solve();
 
    return 0;
}