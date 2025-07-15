#ifndef AFMT_SQRT_DECOMP
#define AFMT_SQRT_DECOMP

#include <array>
#include <vector>

template <class T>
std::vector<std::array<T, 3>> sqrt_decomposit(T n) { // (l, r, v)
    std::vector<std::array<T, 3>> ans;
    for (T l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans.push_back({l, r, n / l});
    }
    return ans;
}

#endif
