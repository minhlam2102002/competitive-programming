#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}
struct Point {
    long long x, y;
    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }
    #define op(x) bool operator x(const Point &q) const { return cmp(q) x 0; }
	    op(>) op(<) op(==) op(>=) op(<=) op(!=)
	#undef op
    long long cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
    Point operator-(const Point& q) const {
        return Point(x - q.x, y - q.y);
    }
};
istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, const Point& p) {
    os << p.x << " " << p.y;
    return os;
}
int ccw(Point a, Point b, Point c) {
    return cmp((b - a).cross(c - a), 0);
}
using Polygon = vector<Point>;
void ConvexHull(Polygon& pts) {
    // Monotone Chain
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    Polygon up, down;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0) // == 0 for collinear
            up.pop_back();
        up.push_back(pts[i]);
        while (down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], pts[i]) <= 0) // == 0 for collinear
            down.pop_back();
        down.push_back(pts[i]);
    }
    pts = down;
    for (int i = up.size() - 2; i > 0; i--)
        pts.push_back(up[i]);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; 
    while(cin >> n && n) {
        Polygon poly(n);
        for (auto& p : poly) cin >> p;
        ConvexHull(poly);
        cout << poly.size() << endl;
        for (const auto& p : poly) cout << p << endl;
    }
    return 0;
}