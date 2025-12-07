// TODO Next generation of flat geometry.
#ifndef AFMT_FLAT_GEOMETRY
#define AFMT_FLAT_GEOMETRY

#include <cmath>
#include <iostream>

template <class T>
struct Vec {
    T x, y;
    Vec(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    inline T norm(void) const { return x * x + y * y; }
    inline Vec operator*(T &&d) const { return Vec(x * d, y * d); }
    inline Vec operator/(T &&d) const { return Vec(x / d, y / d); }
    inline Vec operator+(Vec &&v) const { return Vec(x + v.x, y + v.y); }
    inline Vec operator-(Vec &&v) const { return Vec(x - v.x, y - v.y); }
    friend std::ostream &operator<<(std::ostream &out, Vec &&P) {
        return out << "(" << P.x << ", " << P.y << ")";
    }
    friend std::istream &operator>>(std::istream &in, Vec &P) {
        return in >> P.x >> P.y;
    }
};

template <class T>
using Point = Vec<T>;

template <class T>
inline T dot(Vec<T> &&a, Vec<T> &&b) {
    return a.x * b.x + a.y * b.y;
}

template <class T>
inline T cross(Vec<T> &&a, Vec<T> &&b) {
    return a.x * b.y - a.y * b.x;
}

template <class T>
struct Segment {
};

#endif
