struct Point {
    long double x, y;
    Poinvectort(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
    long double cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
};
using Polygon = vector<Point>;
long double signedArea(const Polygon& p) {
    long double area = 0;
    for (int j, i = 0; i < p.size(); i++) {
        j = (i + 1) % p.size();
        area += p[i].cross(p[j]);
    }
    return area / 2.0;
}
long double area(const Polygon& p) {
    return fabs(signedArea(p));
}