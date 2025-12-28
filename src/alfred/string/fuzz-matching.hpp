#ifndef AFSTR_FUZZ_MATCHING
#define AFSTR_FUZZ_MATCHING

#include "../math/conv.hpp"
#include <string>

// template <uint32_t mod>
std::vector<long long> __fuzz_matching(
    int n, int m, char fuzz,
    std::vector<int> &pat, std::vector<int> &txt
) {
    // using mint = ModInt<mod>;
    using i64 = long long;
    std::vector<i64> pp[3], pt(n, 1);
    for (int i = 0; i < 3; i++) pp[i].resize(n);
    for (int i = 0; i < n; i++) pp[0][i] = pat[i];
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            pp[i][j] = pp[i - 1][j] * pat[j];
        }
    }
    const i64 c[3]{1, -2, 1};
    std::vector<i64> res, ans(n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) pt[j] *= txt[j];
        res = add_conv_ll(std::move(pp[2 - i]), pt);
        for (int j = 0; j < n; j++) {
            ans[j] += c[i] * res[j];
        }
    }
    return ans;
}

std::vector<int> fuzz_matching(
    std::string pat, std::string txt, char fuzz
) {
    static uint8_t h[1 << 8];
    std::fill_n(h, 1 << 8, 0);
    int m = pat.size(), n = txt.size();
    for (auto &c : pat) h[(uint8_t)c] = 1;
    for (auto &c : txt) h[(uint8_t)c] = 1;
    for (int i = 0; i < 256; i++) {
        if (i == fuzz) h[i] = 0;
        if (i) h[i] += h[i - 1];
    }
    std::vector<int> p(n), t(n), res;
    for (int i = 1; i <= m; i++) {
        p[i - 1] = h[(uint8_t)pat[m - i]];
    }
    for (int i = 0; i < n; i++) {
        t[i] = h[(uint8_t)txt[i]];
    }
    auto f = __fuzz_matching<998244353>(n, m, fuzz, p, t);
    for (int i = 0; i + m <= n; i++) {
        if (f[i + m - 1] == 0) res.push_back(i);
    }
    return res;
}

#endif // AFSTR_FUZZ_MATCHING
