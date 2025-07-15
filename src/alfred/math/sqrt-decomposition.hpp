#ifndef AFMT_SQRT_DECOMP
#define AFMT_SQRT_DECOMP

#include <array>
#include <vector>

template <class T>
std::vector<std::array<T, 3>> sqrt_decomposit(T n) { // (l, r, v)
    std::vector<std::array<T, 3>> ans;
    for (T l = 1, r, v; l <= n; l = r + 1) {
        v = n / l, r = n / v;
        ans.push_back({l, r, v});
    }
    return ans;
}

#endif
