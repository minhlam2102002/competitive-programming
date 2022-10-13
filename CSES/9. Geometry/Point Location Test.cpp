#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
int cmp(double x, double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point& q) const {
        return Point(x - q.x, y - q.y);
    }
    double cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
};

int ccw(Point a, Point b, Point c) {
    return cmp((b - a).cross(c - a), 0);
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        Point a, b, c;
        cin >> a >> b >> c;
        int isCCW = ccw(a, b, c);
        if (isCCW == 0) {
            cout << "TOUCH\n";
        } else if (isCCW == 1) {
            cout << "LEFT\n";
        } else {
            cout << "RIGHT\n";
        }
    }
    return 0;
}