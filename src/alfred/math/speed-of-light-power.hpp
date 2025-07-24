#ifndef AFMT_SPEED_OF_LIGHT_POWER
#define AFMT_SPEED_OF_LIGHT_POWER

#include "utils.hpp"
#include <cmath>
#include <vector>

template <int base, class mint>
class SOLPower { // Speed Of Light Power. O(sqrt(n)) ~ O(1)
    // p1 stores base^0  ~ base^sq
    // ps stores base^sq ~ base^(sq^2)
private:
    std::vector<mint> p1, ps;
    static const int mod = mint::mod();
    static const bool P = is_prime(mod);
    static const int sq = std::sqrt(mod);

public:
    SOLPower(void) : p1(sq + 1, 1) {
        ps.push_back(1);
        for (int i = 1; i <= sq; i++) {
            p1[i] = p1[i - 1] * base;
        }
        ps.push_back(p1.back());
        for (int i = 2 * sq; i <= mod; i += sq) {
            ps.push_back(ps.back() * ps[1]);
        }
    }
    inline mint power(long long index) {
        if (P && index >= mod) index %= mod - 1;
        return ps[index / sq] * p1[index % sq];
    }
};

#endif // AFMT_SPEED_OF_LIGHT_POWER
