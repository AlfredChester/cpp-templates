template <class T>
struct Point {
    T x, y;
    Point(void) = default;
    Point(T X, T Y) : x(X), y(Y) {}
    inline bool operator==(const Point B) {
        return x == B.x && y == B.y;
    }
    friend std::ostream &operator<<(std::ostream &out, Point P) {
        return out << "(" << P.x << ", " << P.y << ")";
    }
    friend std::istream &operator>>(std::istream &in, Point &P) {
        return in >> P.x >> P.y;
    }
};
template <class T>
struct Line {
    T A, B, C; // Ax + By + C = 0
    Line(void) = default;
    Line(T a, T b, T c) : A(a), B(b), C(c) {} // Ax + By + C = 0
    Line(T k, T b) : A(k), B(-1), C(b) {}     // y = kx + b
};
template <class T>
inline int sign(T x) {
    return x == 0 ? 0 : (x < 0 ? -1 : 1);
}
template <class T>
inline bool parallel(Line<T> P, Line<T> Q) {
    return P.A * Q.B == P.B * Q.A;
}
template <class T>
inline Point<T> intersect(Line<T> P, Line<T> Q) {
    assert(!parallel(P, Q));
    return Point<T>{
        (P.C * Q.B - Q.C * P.B) / (Q.A * P.B - P.A * Q.B),
        (P.C * Q.A - Q.C * P.A) / (P.A * Q.B - Q.A * P.B)
    };
}
template <class T>
inline Line<T> getLine(Point<T> P, Point<T> Q) {
    assert(!(P == Q));
    if (P.x == Q.x) {
        return Line<T>(-1, 0, P.x);
    } else if (P.y == Q.y) {
        return Line<T>(0, -1, P.y);
    } else {
        return Line<T>(
            Q.y - P.y, P.x - Q.x, P.y * Q.x - P.x * Q.y
        );
    }
}
template <class T>
inline bool pointOnLine(Point<T> P, Line<T> L) {
    return L.A * P.x + L.B * P.y + L.C == 0;
}
