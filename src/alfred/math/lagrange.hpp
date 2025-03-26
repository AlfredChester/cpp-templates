#ifndef AFMT_LAGRANGE
#define AFMT_LAGRANGE

#include "comb.hpp"
#include <cassert>
#include <iostream>
#include <vector>

template <class mint>
inline mint lagrange(std::vector<mint> x, std::vector<mint> y, mint k) {
    mint ans = 0, cur;
    const int n = x.size();
    for (int i = 0; i < n; i++) {
        cur = y[i];
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            cur *= (k - x[j]) / (x[i] - x[j]);
        }
        ans += cur;
    }
    return ans;
}

// y[0] is placeholder.
// If for all integer x_i in [1, n], we have f(x_i) = y_i (mod p), find f(k) mod p.
template <class mint>
inline mint cont_lagrange(std::vector<mint> y, mint k) {
    mint ans = 0;
    const int n = y.size() - 1;
    Comb<mint> comb(n);
    std::vector<mint> pre(n + 1, 1), suf(n + 2, 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] * (k - i);
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] * (k - i);
    for (int i = 1; i <= n; i++) {
        mint A = pre[i - 1] * suf[i + 1];
        mint B = comb.fac(i - 1) * comb.fac(n - i);
        ans += ((n - i) & 1 ? -1 : 1) * y[i] * A / B;
    }
    return ans;
}

// find 1^k + 2^k + ... + n^k. in O(k log k) of time complexity.
template <class mint>
inline mint sum_of_kth_powers(mint n, int k) {
    mint sum = 0;
    std::vector<mint> Y{0};
    for (int i = 1; i <= k + 2; i++) {
        Y.push_back(sum += (mint)i ^ k);
    }
    return cont_lagrange(Y, n);
}

template <class mint>
std::vector<mint> find_coefficient(
    std::vector<mint> x, std::vector<mint> y
) {
    // F(k) = \prod (k - x_i): n degree, n + 1 coefficients.
    int n = x.size(), i;
    std::vector<mint> F(n + 1);
    assert(n == (int)y.size());
    for (i = 0, F[0] = 1; i < n; i++) {
        for (int j = i + 1; j >= 0; j--) {
            F[j] *= -x[i];
            if (j) F[j] += F[j - 1];
        }
    }
    mint delta, c;
    std::vector<mint> ans(n), res(n);
    auto div = [&](mint xi) {
        delta = 0;
        for (int i = n; i > 0; i--) {
            res[i - 1] = (F[i] + delta);
            delta = (F[i] + delta) * xi;
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        c = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) c /= x[i] - x[j];
        }
        div(x[i]);
        for (int j = 0; j < n; j++) {
            ans[j] += c * res[j];
        }
    }
    return ans;
}

#endif // AFMT_LAGRANGE
