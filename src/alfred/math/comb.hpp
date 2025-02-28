#pragma once

#include "mod-int.hpp"
#include <bits/stdc++.h>

template <class mint>
struct Comb {
    int n;
    std::vector<mint> _fac, _invfac, _inv;
    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    inline void init(int m) {
        _fac.resize(m + 1), _inv.resize(m + 1), _invfac.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = ~_fac[m];
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    inline mint fac(int m) {
        if (m > n) init(m);
        return _fac[m];
    }
    inline mint invfac(int m) {
        if (m > n) init(m);
        return _invfac[m];
    }
    inline mint inv(int m) {
        if (m > n) init(m);
        return _inv[m];
    }
    inline mint binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
};

using mint = ModInt<998244353>;
Comb<mint> comb;