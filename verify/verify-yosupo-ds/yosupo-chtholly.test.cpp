#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/chtholly.hpp"
#include "../../src/alfred/math/mod-int.hpp"
#include <iostream>

using mint = ModInt<998244353>;

mint x, y;
int n, q, opt, l, r;

int main(int argc, char const *argv[]) {
    optimizeIO();
    std::cin >> n >> q;
    ChthollyTree<mint> CT(n, 0);

    while (q--) {
        std::cin >> opt >> l >> r;
        if (opt == 0) {
            std::cin >> x >> y;
            CT.modify(l, r - 1, [&](auto it) {
                it->v = x * it->v + y;
            });
        } else {
            std::cout << CT.query(l, r - 1, [](mint &ans, auto it) {
                ans += it->v * (it->r - it->l + 1);
            }) << '\n';
        }
    }

    return 0;
}
