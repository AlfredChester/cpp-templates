#ifndef AFMT_COMB
#define AFMT_COMB

#include <vector>

template <class mint>
class Comb {
private:
    int n;
    std::vector<mint> _fac, _invfac, _inv;

public:
    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    inline void init(int m) {
        _fac.resize(m + 1), _inv.resize(m + 1), _invfac.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
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
        if (m < 0) return -inv(-m);
        if (m > n) init(m);
        return _inv[m];
    }
    inline mint binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
    inline mint perm(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(n - m);
    }
    inline mint catalan(int n) {
        return binom(2 * n, n) - binom(2 * n, n - 1);
    }
};

#endif // AFMT_COMB