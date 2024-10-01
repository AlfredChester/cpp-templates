#include "comb.h"
#include "mod-int.h"
#include <bits/stdc++.h>

inline mint lagrange(std::vector<mint> &x, std::vector<mint> &y, mint k) {
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
inline mint cont_lagrange(std::vector<mint> &y, mint k) {
    mint ans = 0;
    const int n = y.size() - 1;
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
// find 1^k + 2^k + ... + n^k. in O(k) of time complexity.
inline mint sum_of_kth_powers(mint n, int k) {
    mint sum = 0;
    std::vector<mint> Y{0};
    for (int i = 1; i <= k + 2; i++) {
        Y.push_back(sum += (mint)i ^ k);
    }
    return cont_lagrange(Y, n);
}