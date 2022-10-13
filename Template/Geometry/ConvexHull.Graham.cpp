// Verified: https://open.kattis.com/problems/convexhull

const double EPS = 1e-9;
int cmp(long long x, long long y) {
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
    long long norm() {
        return x * x + y * y;
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
Point pivot;
bool compare(const Point& p, const Point& q) {
    int tmp = ccw(pivot, p, q);
    if (tmp > 0) return true;
    return (tmp == 0 && (p - pivot).norm() < (q - pivot).norm());
}
void ConvexHull(Polygon& pts) {
    pivot = pts[0];
    for (int i = 1; i < pts.size(); i++)
        if (pivot.y > pts[i].y || (pivot.y == pts[i].y && pivot.x > pts[i].x))
            pivot = pts[i];
    sort(pts.begin(), pts.end(), compare); // remove duplicate points
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() < 3) return;
    int n = 0; 
    for (int i = 0; i < pts.size(); i++) {  
        while (n > 1 && ccw(pts[n - 2], pts[n - 1], pts[i]) <= 0) n--; // cannot get collinear points
        pts[n++] = pts[i];
    }
    pts.resize(n);
}