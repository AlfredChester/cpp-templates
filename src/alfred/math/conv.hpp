#ifndef AFMT_CONV
#define AFMT_CONV

#include "mod-int.hpp"
#include <vector>

namespace detail {
    template <class mint>
    void NTT(std::vector<mint> &f, std::vector<int> &r, int lim, int flag) {
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

    std::vector<int> rev(lim, 0);
    std::vector<ModInt<mod>> h(lim, 0);
    for (int i = 0; i < lim; i++) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= lim >> 1;
    }
    detail::NTT(f, rev, lim, 1);
    detail::NTT(g, rev, lim, 1);
    for (int i = 0; i < lim; i++) {
        h[i] = f[i] * g[i];
    }
    detail::NTT(h, rev, lim, -1);
    return h.resize(len), h;
}

// (*, +) convolution for long long
inline std::vector<long long> add_conv_ll(
    const std::vector<long long> &f,
    const std::vector<long long> &g
) {
    if (f.empty() || g.empty()) return {};
    static constexpr uint64_t m1 = 754974721;
    static constexpr uint64_t m2 = 167772161;
    static constexpr uint64_t m3 = 469762049;
    static constexpr uint64_t m12 = m1 * m2;
    static constexpr uint64_t m13 = m1 * m3;
    static constexpr uint64_t m23 = m2 * m3;
    static constexpr uint64_t m123 = m1 * m2 * m3;
    auto c1 = add_conv(
        std::vector<ModInt<m1>>(f.begin(), f.end()),
        std::vector<ModInt<m1>>(g.begin(), g.end())
    );
    auto c2 = add_conv(
        std::vector<ModInt<m2>>(f.begin(), f.end()),
        std::vector<ModInt<m2>>(g.begin(), g.end())
    );
    auto c3 = add_conv(
        std::vector<ModInt<m3>>(f.begin(), f.end()),
        std::vector<ModInt<m3>>(g.begin(), g.end())
    );
    const int len = c1.size();
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

template <uint32_t mod>
inline std::vector<ModInt<mod>> and_conv(
    std::vector<ModInt<mod>> f,
    std::vector<ModInt<mod>> g
);

template <class T>
inline std::vector<T> and_conv(
    std::vector<T> f, std::vector<T> g
);

template <uint32_t mod>
inline std::vector<ModInt<mod>> or_conv(
    std::vector<ModInt<mod>> f,
    std::vector<ModInt<mod>> g
);

template <class T>
inline std::vector<T> or_conv(
    std::vector<T> f, std::vector<T> g
);

template <uint32_t mod>
inline std::vector<ModInt<mod>> xor_conv(
    std::vector<ModInt<mod>> f,
    std::vector<ModInt<mod>> g
);

template <class T>
inline std::vector<T> xor_conv(
    std::vector<T> f, std::vector<T> g
);

#endif
