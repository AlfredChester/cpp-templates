#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/sum.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, q, l, r;
    optimizeIO(), std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    Sum<long long> S(a);
    while (q--) {
        std::cin >> l >> r;
        std::cout << S.query(l, r - 1) << '\n';
    }

    return 0;
}
