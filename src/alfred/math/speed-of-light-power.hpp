#pragma once

#include <bits/stdc++.h>

template <int base, int mod>
struct SOLPower { // Speed Of Light Power.
    // p1 stores base^0  ~ base^sq
    // ps stores base^sq ~ base^(sq^2)
    std::vector<int> p1, ps;
    static const int sq = std::sqrt(mod);
    SOLPower(void) {
        p1.push_back(1), ps.push_back(1);
        for (int i = 1; i <= sq; i++) {
            p1.push_back(1ll * p1.back() * base % mod);
        }
        ps.push_back(p1.back());
        for (int i = 2 * sq; i <= mod; i += sq) {
            ps.push_back(1ll * ps.back() * ps[1] % mod);
        }
    }
    inline int power(int index) {
#if __cplusplus >= 202002L
        if (index > mod) [[unlikely]] {
            index %= mod;
        }
#else
        if (index > mod) index %= mod;
#endif
        return 1ll * ps[index / sq] * p1[index % sq] % mod;
    }
};
