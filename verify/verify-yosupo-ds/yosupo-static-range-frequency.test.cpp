// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_frequency

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/appear-statistics.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, q, l, r, x;
    optimizeIO(), std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    AppearStats<int> A(a);
    while (q--) {
        std::cin >> l >> r >> x;
        std::cout << A.count(l, r - 1, x) << '\n';
    }
    return 0;
}
