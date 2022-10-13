#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;
int cmp(long double x, long double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

struct Point {
    long double x, y;
    Point(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
    string toString() {
        return "(" + to_string(int(x)) + ", " + to_string(int(y)) + ")";
    }
};

long double dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

struct Line {
    long double a, b, c;
    Point A, B;
    Line(Point A, Point B) : A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }
    bool isBetween(const Point& p) {
        return cmp(dist(A, p) + dist(B, p), dist(A, B)) == 0;
    }
    string toString() {
        return "Segment(" + A.toString() + ", " + B.toString() + ")";
    }
};
bool areParallel(Line l1, Line l2) {
    return cmp(l1.a * l2.b, l1.b * l2.a) == 0;
}
bool areSame(Line l1, Line l2) {
    return areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 && cmp(l1.c * l2.b, l1.b * l2.c) == 0 && (l1.isBetween(l2.A) || l1.isBetween(l2.B)) && (l2.isBetween(l1.A) || l2.isBetween(l1.B));
}
bool areIntersect(Line l1, Line l2, Point& p) {
    if (areParallel(l1, l2)) return false;
    long double dx = l1.b * l2.c - l2.b * l1.c;
    long double dy = l1.c * l2.a - l2.c * l1.a;
    long double d = l1.a * l2.b - l2.a * l1.b;
    p = Point(dx / d, dy / d);
    return l1.isBetween(p) && l2.isBetween(p);
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
        Point a, b, c, d;
        cin >> a >> b >> c >> d;
        Line l1(a, b), l2(c, d);
        Point p;
        if (areSame(l1, l2) || areIntersect(l1, l2, p))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}