#ifndef AFMT_CONV
#define AFMT_CONV

#include "mod-int.hpp"
#include <vector>

namespace detail {
    inline constexpr int ceil_pw2(int len) {
        int res = 1;
        while (res < len) res *= 2;
        return res;
    }

    template <class mint>
    inline void NTT(std::vector<mint> &f, const std::vector<int> &r, int lim, int flag) {
        const int mod = mint::mod();
        mint gmod = findPrimitiveRoot<mint>();
        for (int i = 0; i < lim; i++) {
            if (i < r[i]) std::swap(f[i], f[r[i]]);
        }
        mint invg = gmod.inv(), tmp;
        mint v = flag > 0 ? gmod : invg;
        for (int k = 1; k < lim; k <<= 1) {
            const int len = k << 1;
            mint gn = v.pow((mod - 1) / len), g = 1;
            for (int i = 0; i < lim; i += len, g = 1) {
                for (int j = 0; j < k; j++, g *= gn) {
                    tmp = f[i + j + k] * g;
                    f[i + j + k] = f[i + j] - tmp;
                    f[i + j] += tmp;
                }
            }
        }
        if (flag == -1) {
            mint inv = mint(lim).inv();
            for (auto &x : f) x *= inv;
        }
    }

    inline const std::vector<int> &get_rev(int lim) {
        static std::vector<int> rev;
        if ((int)rev.size() != lim) {
            rev.resize(lim);
            for (int i = 0; i < lim; i++) {
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
            }
        }
        return rev;
    }

    template <class T>
    inline void fmt_and(std::vector<T> &a, T c) {
        const int n = a.size();
        for (int d = 2; d <= n; d *= 2) {
            const int len = d >> 1;
            for (int i = 0; i < n; i += d) {
                for (int j = 0; j < len; j++) {
                    a[i + j] += c * a[i + j + len];
                }
            }
        }
    }

    template <class T>
    inline void fmt_or(std::vector<T> &a, T c) {
        const int n = a.size();
        for (int d = 2; d <= n; d *= 2) {
            const int len = d >> 1;
            for (int i = 0; i < n; i += d) {
                for (int j = 0; j < len; j++) {
                    a[i + j + len] += c * a[i + j];
                }
            }
        }
    }

    template <uint32_t mod>
    inline void fwt(std::vector<ModInt<mod>> &a, ModInt<mod> c) {
        ModInt<mod> tmp;
        const int n = a.size();
        for (int d = 2; d <= n; d *= 2) {
            const int len = d >> 1;
            for (int i = 0; i < n; i += d) {
                for (int j = 0; j < len; j++) {
                    tmp = a[i + j];
                    a[i + j] = (tmp + a[i + j + len]) * c;
                    a[i + j + len] = (tmp - a[i + j + len]) * c;
                }
            }
        }
    }

    template <class T>
    inline void fwt(std::vector<T> &a) {
        T tmp;
        const int n = a.size();
        for (int d = 2; d <= n; d *= 2) {
            const int len = d >> 1;
            for (int i = 0; i < n; i += d) {
                for (int j = 0; j < len; j++) {
                    tmp = a[i + j];
                    a[i + j] = tmp + a[i + j + len];
                    a[i + j + len] = tmp - a[i + j + len];
                }
            }
        }
    }

    template <class T>
    inline void ifwt(std::vector<T> &a) {
        T tmp;
        const int n = a.size();
        for (int d = 2; d <= n; d *= 2) {
            const int len = d >> 1;
            for (int i = 0; i < n; i += d) {
                for (int j = 0; j < len; j++) {
                    tmp = a[i + j];
                    a[i + j] = (tmp + a[i + j + len]) >> 1;
                    a[i + j + len] = (tmp - a[i + j + len]) >> 1;
                }
            }
        }
    }
}

// (*, +) convolution for modint
template <uint32_t mod>
inline std::vector<ModInt<mod>> add_conv(
    std::vector<ModInt<mod>> f,
    std::vector<ModInt<mod>> g
) {
    if (f.empty() || g.empty()) return {};
    int len = f.size() + g.size() - 1, lim;
    for (lim = 1; lim < len; lim <<= 1);
    f.resize(lim, 0), g.resize(lim, 0);

    const auto &rev = detail::get_rev(lim);
    detail::NTT(f, rev, lim, 1);
    detail::NTT(g, rev, lim, 1);
    for (int i = 0; i < lim; i++) {
        f[i] *= g[i];
    }
    detail::NTT(f, rev, lim, -1);
    f.resize(len);
    return f;
}

// (*, +) convolution for long long
inline std::vector<long long> add_conv_ll(
    const std::vector<long long> &f,
    const std::vector<long long> &g
) {
    if (f.empty() || g.empty()) return {};
    int len = f.size() + g.size() - 1;
    int lim = detail::ceil_pw2(len);

    auto run = [&](auto tag) {
        using mint = decltype(tag);
        std::vector<mint> tf, tg;
        tf.reserve(lim), tg.reserve(lim);
        for (auto &x : f) tf.emplace_back(x);
        for (auto &x : g) tg.emplace_back(x);
        return add_conv(std::move(tf), std::move(tg));
    };

    static constexpr uint64_t m1 = 754974721;
    static constexpr uint64_t m2 = 167772161;
    static constexpr uint64_t m3 = 469762049;
    static constexpr uint64_t m12 = m1 * m2;
    static constexpr uint64_t m13 = m1 * m3;
    static constexpr uint64_t m23 = m2 * m3;
    static constexpr uint64_t m123 = m1 * m2 * m3;
    auto c1 = run(ModInt<m1>());
    auto c2 = run(ModInt<m2>());
    auto c3 = run(ModInt<m3>());
    std::vector<long long> c(len);
    static constexpr uint64_t i1 = ModInt<m1>(m2 * m3).inv().val();
    static constexpr uint64_t i2 = ModInt<m2>(m1 * m3).inv().val();
    static constexpr uint64_t i3 = ModInt<m3>(m1 * m2).inv().val();
    for (int i = 0; i < len; i++) {
        uint64_t x = 0;
        x += (c1[i].val() * i1) % m1 * m23;
        x += (c2[i].val() * i2) % m2 * m13;
        x += (c3[i].val() * i3) % m3 * m12;
        long long diff = c1[i].val() - (long long)(x % m1);
        if (diff < 0) diff += m1;
        if (diff >= (long long)m1) diff -= m1;
        static constexpr uint64_t offset[5] = {
            0, 0, m123, 2 * m123, 3 * m123
        };
        c[i] = x - offset[diff % 5];
    }
    return c;
}

template <class T>
inline std::vector<T> and_conv(
    std::vector<T> f, std::vector<T> g
) {
    int len = detail::ceil_pw2(std::max(f.size(), g.size()));
    f.resize(len), detail::fmt_and(f, T(1));
    g.resize(len), detail::fmt_and(g, T(1));
    for (int i = 0; i < len; i++) f[i] *= g[i];
    return detail::fmt_and(f, T(-1)), f;
}

template <class T>
inline std::vector<T> or_conv(
    std::vector<T> f, std::vector<T> g
) {
    int len = detail::ceil_pw2(std::max(f.size(), g.size()));
    f.resize(len), detail::fmt_or(f, T(1));
    g.resize(len), detail::fmt_or(g, T(1));
    for (int i = 0; i < len; i++) f[i] *= g[i];
    return detail::fmt_or(f, T(-1)), f;
}

template <uint32_t mod>
inline std::vector<ModInt<mod>> xor_conv(
    std::vector<ModInt<mod>> f,
    std::vector<ModInt<mod>> g
) {
    int len = detail::ceil_pw2(std::max(f.size(), g.size()));
    f.resize(len), detail::fwt(f, ModInt<mod>(1));
    g.resize(len), detail::fwt(g, ModInt<mod>(1));
    for (int i = 0; i < len; i++) f[i] *= g[i];
    return detail::fwt(f, ModInt<mod>(2).inv()), f;
}

template <class T>
inline std::vector<T> xor_conv(
    std::vector<T> f, std::vector<T> g
) {
    int len = detail::ceil_pw2(std::max(f.size(), g.size()));
    f.resize(len), detail::fwt(f);
    g.resize(len), detail::fwt(g);
    for (int i = 0; i < len; i++) f[i] *= g[i];
    return detail::ifwt(f), f;
}

#endif
