#ifndef AFMT_LAGRANGE
#define AFMT_LAGRANGE

#include "comb.hpp"
#include "vec-inv.hpp"
#include <algorithm>
#include <cassert>
#include <vector>

template <class mint>
class Lagrange {
private:
    std::vector<mint> x, y, b;

public:
    Lagrange(void) = default;
    Lagrange(std::vector<mint> _x, std::vector<mint> _y) : x(_x), y(_y) {
        for (size_t i = 0; i < x.size(); i++) insert(x[i], y[i]);
    }
    inline void insert(mint x0, mint y0) {
        b.push_back(y0);
        std::vector<mint> tmp(x.size());
        for (size_t i = 0; i < x.size(); i++) {
            tmp[i] = x0 - x[i];
        }
        VecInv<mint> inv(tmp);
        for (size_t i = 0; i < x.size(); i++) {
            b.back() *= inv[i], b[i] *= -inv[i];
        }
        x.push_back(x0), y.push_back(y0);
    }
    inline mint query(mint k) {
        mint ans = 0, tot = 1;
        const int n = x.size();
        std::vector<mint> tmp(n);
        for (int i = 0; i < n; i++) {
            if (x[i] == k) return y[i];
            tmp[i] = k - x[i], tot *= tmp[i];
        }
        VecInv<mint> inv(tmp);
        for (int i = 0; i < n; i++) {
            ans += b[i] * tot * inv[i];
        }
        return ans;
    }
    std::vector<mint> coefficient(void) { // now O(n^2), TODO: maintain it dynamically.
        int n = x.size(), i;
        // F(k) = \prod (k - x_i): degree = n, n + 1 coefficients.
        std::vector<mint> F(n + 1);
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
                res[i - 1] = F[i] + delta;
                delta = (F[i] + delta) * xi;
            }
        };
        for (int i = 0; i < n; i++) {
            c = b[i], div(x[i]);
            for (int j = 0; j < n; j++) {
                ans[j] += c * res[j];
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

// y[0] is placeholder.
// If for all integer x_i in [1, n], we have f(x_i) = y_i (mod p), find f(k) mod p.
template <class mint>
inline mint cont_lagrange(std::vector<mint> y, mint k) {
    mint ans = 0;
    Comb<mint> comb(y.size());
    const int n = y.size() - 1;
    std::vector<mint> pre(n + 1, 1), suf(n + 2, 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] * (k - i);
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] * (k - i);
    for (int i = 1; i <= n; i++) {
        mint A = pre[i - 1] * suf[i + 1];
        mint B = comb.invfac(i - 1) * comb.invfac(n - i);
        ans += ((n - i) & 1 ? -1 : 1) * y[i] * A * B;
    }
    return ans;
}

// find 1^k + 2^k + ... + n^k. in O(k log k) of time complexity.
template <class mint>
inline mint sum_of_kth_powers(mint n, int k) {
    mint sum = 0;
    std::vector<mint> Y{0};
    for (int i = 1; i <= k + 2; i++) {
        Y.push_back(sum += mint(i).pow(k));
    }
    return cont_lagrange(Y, n);
}

#endif // AFMT_LAGRANGE
