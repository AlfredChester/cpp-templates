// TODO Next generation of flat geometry.
#ifndef AFMT_FLAT_GEOMETRY
#define AFMT_FLAT_GEOMETRY

#include <cmath>
#include <iostream>

// Recommended eps is 0.25 * given precision
template <long double eps>
struct Double {
    long double val;

    constexpr Double(long double v = 0) : val(v) {}
    static constexpr int sgn(long double x) {
        return (x > eps) - (x < -eps);
    }
    // constexpr long double val(void) const { return val; }
    constexpr operator long double(void) const { return val; }
    constexpr bool operator==(const Double &rhs) const { return sgn(val - rhs.val) == 0; }
    constexpr bool operator!=(const Double &rhs) const { return sgn(val - rhs.val) != 0; }
    constexpr bool operator<(const Double &rhs) const { return sgn(val - rhs.val) < 0; }
    constexpr bool operator>(const Double &rhs) const { return sgn(val - rhs.val) > 0; }
    constexpr bool operator<=(const Double &rhs) const { return sgn(val - rhs.val) <= 0; }
    constexpr bool operator>=(const Double &rhs) const { return sgn(val - rhs.val) >= 0; }
    constexpr Double operator+(void) const { return *this; }
    constexpr Double operator-(void) const { return Double(-val); }
    constexpr Double &operator+=(const Double &rhs) {
        val += rhs.val;
        return *this;
    }
    constexpr Double &operator-=(const Double &rhs) {
        val -= rhs.val;
        return *this;
    }
    constexpr Double &operator*=(const Double &rhs) {
        val *= rhs.val;
        return *this;
    }
    constexpr Double &operator/=(const Double &rhs) {
        val /= rhs.val;
        return *this;
    }
    friend constexpr Double operator+(Double l, const Double &r) { return l += r; }
    friend constexpr Double operator-(Double l, const Double &r) { return l -= r; }
    friend constexpr Double operator*(Double l, const Double &r) { return l *= r; }
    friend constexpr Double operator/(Double l, const Double &r) { return l /= r; }
    friend std::ostream &operator<<(std::ostream &os, const Double &x) { return os << x.val; }
    friend std::istream &operator>>(std::istream &is, Double &x) { return is >> x.val; }
    friend Double sqrt(const Double &x) { return Double(std::sqrt(x.val)); }
    friend Double abs(const Double &x) { return Double(std::abs(x.val)); }
};

template <class T>
struct Vec {
    T x, y;
    Vec(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    constexpr T norm(void) const { return x * x + y * y; }
    constexpr Vec operator+(void) const noexcept { return *this; }
    constexpr Vec operator-(void) const noexcept { return Vec(-x, -y); }
    constexpr Vec &operator+=(const Vec &rhs) noexcept {
        return x += rhs.x, y += rhs.y, *this;
    }
    constexpr Vec &operator-=(const Vec &rhs) noexcept {
        return x -= rhs.x, y -= rhs.y, *this;
    }
    constexpr Vec &operator*=(T d) noexcept {
        return x *= d, y *= d, *this;
    }
    constexpr Vec &operator/=(T d) noexcept {
        return x /= d, y /= d, *this;
    }
    friend constexpr Vec operator+(Vec l, const Vec &r) noexcept { return l += r; }
    friend constexpr Vec operator-(Vec l, const Vec &r) noexcept { return l -= r; }
    friend constexpr Vec operator*(Vec l, const Vec &r) noexcept { return l *= r; }
    friend constexpr Vec operator/(Vec l, const Vec &r) noexcept { return l /= r; }
    friend constexpr bool operator==(const Vec &l, const Vec &r) noexcept {
        return l.x == r.x && l.y == r.y;
    }
    friend constexpr bool operator!=(const Vec &l, const Vec &r) noexcept {
        return l.x != r.x || l.y != r.y;
    }
    friend std::ostream &operator<<(std::ostream &out, const Vec &P) {
        return out << "(" << P.x << ", " << P.y << ")";
    }
    friend std::istream &operator>>(std::istream &in, Vec &P) {
        return in >> P.x >> P.y;
    }
};

template <class T>
using Point = Vec<T>;

template <class T>
inline T dot(const Vec<T> &a, const Vec<T> &b) {
    return a.x * b.x + a.y * b.y;
}

template <class T>
inline T cross(const Vec<T> &a, const Vec<T> &b) {
    return a.x * b.y - a.y * b.x;
}

template <class T>
struct Segment {
};

#endif
