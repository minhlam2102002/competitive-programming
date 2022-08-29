vector<int> restorePath(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = pre[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
