const double EPS = 1e-9;
int cmp(double x, double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}
// 2d point and vector
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }
#define op(x) bool operator x(const Point& q) const { return cmp(q) x 0; }
    op(>) op(<) op(==) op(>=) op(<=) op(!=)
#undef op
    Point operator+(const Point& q) const {
        return Point(x + q.x, y + q.y);
    }
    Point operator-(const Point& q) const {
        return Point(x - q.x, y - q.y);
    }
    Point operator*(double k) const {
        return Point(x * k, y * k);
    }
    Point operator/(double k) const {
        return Point(x / k, y / k);
    }
    // dot product
    double dot(const Point& q) const {
        return x * q.x + y * q.y;
    }
    // cross product
    double cross(const Point& q) const {
        return x * q.y - y * q.x;
    }
    double norm() {
        return x * x + y * y;
    }
    double len() {
        return sqrt(norm());
    }
    Point rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
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

struct Line {
    double a, b, c;
    Point A, B;
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    Line(Point A, Point B) : A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }
    Line(Point P, double k) {
        a = -k;
        b = 1;
        c = k * P.x - P.y;
    }
    double f(Point A) {
        return a * A.x + b * A.y + c;
    }
};

bool areParallel(Line l1, Line l2) {
    return cmp(l1.a * l2.b, l1.b * l2.a) == 0;
}
bool areSame(Line l1, Line l2) {
    return areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 && cmp(l1.c * l2.b, l1.b * l2.c) == 0;
}
bool areIntersect(Line l1, Line l2, Point& p) {
    if (areParallel(l1, l2)) return false;
    double dx = l1.b * l2.c - l2.b * l1.c;
    double dy = l1.c * l2.a - l2.c * l1.a;
    double d = l1.a * l2.b - l2.a * l1.b;
    p = Point(dx / d, dy / d);
    return true;
}
double distToLine(Point p, Point a, Point b, Point& c) {
    // distance from p to the line defined by a and b and c is the closest point
    Point ap = p - a, ab = b - a;
    double k = ap.dot(ab) / ab.norm();
    c = a + (ab * k);
    return (p - c).len();
}
using Polygon = vector<Point>;
struct Circle : Point {
    double r;
    Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
    Circle(Point p, double r) : Point(p), r(r) {}
    bool contains(Point p) {
        return (*this - p).len() <= r + EPS;
    }
};
vector<Point> intersection(Line l, Circle cir) {
    double r = cir.r;
    double a = l.a, b = l.b, c = l.c + l.a * cir.x + l.b * cir.y;
    vector<Point> res;
    double x0 = -a * c / (a * a + b * b);
    double y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + EPS)
        return res;
    else if (fabs(c * c - r * r * (a * a + b * b)) < EPS) {
        res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
        return res;
    }
    double d = r * r - c * c / (a * a + b * b);
    double mult = sqrt(d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
    res.push_back(Point(bx, by) + Point(cir.x, cir.y));
    return res;
}