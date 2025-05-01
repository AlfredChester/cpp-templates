#ifndef AFMT_MOD_INT
#define AFMT_MOD_INT

#include <cassert>
#include <cstdint>
#include <iostream>
#include <type_traits>

template <uint32_t M>
class ModInt {
public:
    using value_type = uint32_t;
    static constexpr value_type mod() noexcept { return M; }
    value_type v;
    constexpr ModInt() noexcept : v(0) {}
    constexpr ModInt(int64_t x) noexcept : v(norm(x)) {}
    static constexpr value_type norm(int64_t x) noexcept {
        x %= M;
        if (x < 0) x += M;
        return static_cast<value_type>(x);
    }
    constexpr value_type val() const noexcept { return v; }
    constexpr ModInt operator+() const noexcept { return *this; }
    constexpr ModInt operator-() const noexcept { return ModInt(v ? M - v : 0); }
    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {
        v += rhs.v;
        if (v >= M) v -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) noexcept {
        v += M - rhs.v;
        if (v >= M) v -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) noexcept {
        v = static_cast<uint64_t>(v) * rhs.v % M;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) noexcept {
        return *this *= rhs.inv();
    }
    constexpr ModInt pow(int64_t n) const noexcept {
        ModInt res = 1, x = *this;
        if (n < 0) {
            x = x.inv();
            n = -n;
        }
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    constexpr ModInt inv() const noexcept {
        return pow(M - 2);
    }
    friend constexpr ModInt operator+(ModInt l, const ModInt &r) noexcept { return l += r; }
    friend constexpr ModInt operator-(ModInt l, const ModInt &r) noexcept { return l -= r; }
    friend constexpr ModInt operator*(ModInt l, const ModInt &r) noexcept { return l *= r; }
    friend constexpr ModInt operator/(ModInt l, const ModInt &r) noexcept { return l /= r; }
    friend constexpr bool operator==(const ModInt &l, const ModInt &r) noexcept { return l.v == r.v; }
    friend constexpr bool operator!=(const ModInt &l, const ModInt &r) noexcept { return l.v != r.v; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
        return os << x.val();
    }
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        int64_t t;
        is >> t;
        x = ModInt(t);
        return is;
    }
};

// 动态模数modint
// 用法: DynamicModInt::set_mod(998244353); DynamicModInt a = 2;
class DynamicModInt {
public:
    using value_type = uint32_t;
    static value_type &mod_ref() {
        static value_type m = 1;
        return m;
    }
    static value_type mod() noexcept { return mod_ref(); }
    static void set_mod(value_type m) {
        assert(m > 0);
        mod_ref() = m;
    }
    value_type v;
    constexpr DynamicModInt() noexcept : v(0) {}
    DynamicModInt(int64_t x) noexcept : v(norm(x)) {}
    static value_type norm(int64_t x) noexcept {
        value_type m = mod();
        x %= m;
        if (x < 0) x += m;
        return static_cast<value_type>(x);
    }
    value_type val() const noexcept { return v; }
    DynamicModInt operator+() const noexcept { return *this; }
    DynamicModInt operator-() const noexcept { return DynamicModInt(v ? mod() - v : 0); }
    DynamicModInt &operator+=(const DynamicModInt &rhs) noexcept {
        v += rhs.v;
        if (v >= mod()) v -= mod();
        return *this;
    }
    DynamicModInt &operator-=(const DynamicModInt &rhs) noexcept {
        v += mod() - rhs.v;
        if (v >= mod()) v -= mod();
        return *this;
    }
    DynamicModInt &operator*=(const DynamicModInt &rhs) noexcept {
        v = static_cast<uint64_t>(v) * rhs.v % mod();
        return *this;
    }
    DynamicModInt &operator/=(const DynamicModInt &rhs) noexcept {
        return *this *= rhs.inv();
    }
    DynamicModInt pow(int64_t n) const noexcept {
        DynamicModInt res = 1, x = *this;
        if (n < 0) {
            x = x.inv();
            n = -n;
        }
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    DynamicModInt inv() const noexcept {
        int64_t a = v, b = mod(), u = 1, s = 0;
        while (b) {
            int64_t t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * s;
            std::swap(u, s);
        }
        assert(a == 1);
        return DynamicModInt(u);
    }
    friend DynamicModInt operator+(DynamicModInt l, const DynamicModInt &r) noexcept { return l += r; }
    friend DynamicModInt operator-(DynamicModInt l, const DynamicModInt &r) noexcept { return l -= r; }
    friend DynamicModInt operator*(DynamicModInt l, const DynamicModInt &r) noexcept { return l *= r; }
    friend DynamicModInt operator/(DynamicModInt l, const DynamicModInt &r) noexcept { return l /= r; }
    friend bool operator==(const DynamicModInt &l, const DynamicModInt &r) noexcept { return l.v == r.v; }
    friend bool operator!=(const DynamicModInt &l, const DynamicModInt &r) noexcept { return l.v != r.v; }
    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &x) {
        return os << x.val();
    }
    friend std::istream &operator>>(std::istream &is, DynamicModInt &x) {
        int64_t t;
        is >> t;
        x = DynamicModInt(t);
        return is;
    }
};

using m998 = ModInt<998244353>;
using m107 = ModInt<1000000007>;

using dint = DynamicModInt;

#endif // AFMT_MOD_INT
