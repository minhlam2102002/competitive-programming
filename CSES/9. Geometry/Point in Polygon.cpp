#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;
int cmp(long double x, long double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

struct Point {
    long long x, y;
    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    long long cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
};

long double dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool isBetween(const Point& a, const Point& b, const Point& c) {
    return cmp(dist(a, b) + dist(b, c), dist(a, c)) == 0;
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
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

bool isOnBoundary(const Polygon& poly, const Point& p) {
    for (int j, i = 0; i < poly.size(); i++) {
        j = (i + 1) % poly.size();
        if (isBetween(poly[i], p, poly[j])) return true;
    }
    return false;
}

bool isInside(const Polygon& poly, const Point& p) {
    long long polyArea = areaMultiply2(poly);
    long long totalArea = 0;
    for (int j, i = 0; i < poly.size() - 1; i++) {
        j = (i + 1) % poly.size();
        totalArea += areaMultiply2({poly[i], poly[j], p});
    }
    cout << polyArea << " " << totalArea << endl;
    return totalArea == polyArea;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; 
    cin >> n >> m;
    Polygon poly(n);
    for (auto &p : poly) cin >> p;
    while (m--) {
        Point p;
        cin >> p;
        if (isOnBoundary(poly, p)) {
            cout << "BOUNDARY" << endl;
        } else if (isInside(poly, p)) {
            cout << "INSIDE" << endl;
        } else {
            cout << "OUTSIDE" << endl;
        }
    }
    return 0;
}
