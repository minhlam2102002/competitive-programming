const double EPS = 1e-9;
int cmp(double x, double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }
    double cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
    double norm() {
        return x * x + y * y;
    }
};
using Polygon = vector<Point>;
int ccw(Point a, Point b, Point c) {
    return cmp((b - a).cross(c - a), 0);
}
bool isConvex(const Polygon& p) {
    int sz = p.size();
    if (sz < 3) return false;
    int turn = ccw(p[0], p[1], p[2]);
    for (int i = 1; i < sz; i++)
        if (ccw(p[i], p[(i + 1) % sz], p[(i + 2) % sz]) * turn < 0)
            return false;
    return true;
}