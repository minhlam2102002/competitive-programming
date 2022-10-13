#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    long long cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
};

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

using Polygon = vector<Point>;
long long areaMultiply2(const Polygon& p) {
    long long area = 0;
    for (int j, i = 0; i < p.size(); i++) {
        j = (i + 1) % p.size();
        area += p[i].cross(p[j]);
    }
    return labs(area);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    Polygon poly(n);
    for (auto &p : poly) cin >> p;
    cout << areaMultiply2(poly);
    return 0;
}