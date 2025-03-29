#ifndef AFMT_MOD_INT
#define AFMT_MOD_INT

#include <iostream>

namespace ModIntImpl {
    template <int mod>
    inline int up(int x) { return x < 0 ? x + mod : x; }
    template <int mod>
    inline int down(int x) { return x >= mod ? x - mod : x; }
    template <int mod>
    struct ModInt {
        int x;
        ModInt(void) = default;
        ModInt(int x) : x(up<mod>(x)) {}
        ModInt(long long x) : x(x % mod) {}
        friend std::istream &operator>>(std::istream &in, ModInt &a) { return in >> a.x; }
        friend std::ostream &operator<<(std::ostream &out, ModInt a) { return out << a.x; }
        friend ModInt operator+(ModInt a, ModInt b) { return down<mod>(a.x + b.x); }
        friend ModInt operator-(ModInt a, ModInt b) { return down<mod>(a.x - b.x + mod); }
        friend ModInt operator*(ModInt a, ModInt b) { return (long long)a.x * b.x; }
        friend ModInt operator/(ModInt a, ModInt b) { return a * ~b; }
        friend ModInt operator^(ModInt a, long long b) { return a.pow(b); }
        friend ModInt operator^(ModInt a, int b) { return a.pow(b); }
        friend ModInt operator~(ModInt a) { return a ^ (mod - 2); }
        friend ModInt operator-(ModInt a) { return down<mod>(mod - a.x); }
        friend ModInt &operator+=(ModInt &a, ModInt b) { return a = a + b; }
        friend ModInt &operator-=(ModInt &a, ModInt b) { return a = a - b; }
        friend ModInt &operator*=(ModInt &a, ModInt b) { return a = a * b; }
        friend ModInt &operator/=(ModInt &a, ModInt b) { return a = a / b; }
        friend ModInt &operator^=(ModInt &a, long long b) { return a = a ^ b; }
        friend ModInt &operator++(ModInt &a) { return a += 1; }
        friend ModInt operator++(ModInt &a, int) {
            ModInt x = a;
            a += 1;
            return x;
        }
        friend ModInt &operator--(ModInt &a) { return a -= 1; }
        friend ModInt operator--(ModInt &a, int) {
            ModInt x = a;
            a -= 1;
            return x;
        }
        friend bool operator==(ModInt a, ModInt b) { return a.x == b.x; }
        friend bool operator!=(ModInt a, ModInt b) { return a.x != b.x; }
        inline ModInt pow(long long b) noexcept {
            ModInt ans = 1, a = x;
            for (b %= (mod - 1); b > 0; b >>= 1, a *= a)
                if (b & 1) ans *= a;
            return ans;
        }
        inline ModInt pow(int b) noexcept {
            ModInt ans = 1, a = x;
            for (; b > 0; b >>= 1, a *= a)
                if (b & 1) ans *= a;
            return ans;
        }
    };
}

using ModIntImpl::ModInt;

template <int mod>
inline void __print(ModInt<mod> x) {
    std::cerr << x;
}

using m998 = ModInt<998244353>;
using m107 = ModInt<1000000007>;

#endif // AFMT_MOD_INT
