#ifndef AFMT_VEC_INV
#define AFMT_VEC_INV

#include <vector>

template <class T>
struct VecInv {
    const int n;
    std::vector<T> fac, invf;
    VecInv(std::vector<T> &v) : n(v.size()), fac(n), invf(n) {
        T lst = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) lst *= v[i];
            fac[i] = lst;
        }
        if (n > 0) invf[n - 1] = fac[n - 1].inv();
        for (int i = n - 1; i > 0; i--) {
            if (v[i] == 0) continue;
            invf[i - 1] = invf[i] * v[i];
        }
    }
    inline T query(int i) {
        return i == 0 ? invf[0] : invf[i] * fac[i - 1];
    }
    inline T operator[](int x) {
        return query(x);
    }
};

#endif // AFMT_VEC_INV
