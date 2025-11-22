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

/*
// (*, +) convolution for long long
inline std::vector<long long> add_convll(
    std::vector<long long> f, std::vector<long long> g
) {
    std::vector<ModInt<998244353>> f1(f.begin(), f.end());
    std::vector<ModInt<998244353>> g1(g.begin(), g.end());
    std::vector<ModInt<998244353>> h1 = add_conv(f1, g1);

    std::vector<ModInt<469762049>> f2(f.begin(), f.end());
    std::vector<ModInt<469762049>> g2(g.begin(), g.end());
    std::vector<ModInt<469762049>> h2 = add_conv(f2, g2);

    std::vector<ModInt<1004535809>> f3(f.begin(), f.end());
    std::vector<ModInt<1004535809>> g3(g.begin(), g.end());
    std::vector<ModInt<1004535809>> h3 = add_conv(f3, g3);

    std::vector<T> res(h1.size());
}
*/

#endif
