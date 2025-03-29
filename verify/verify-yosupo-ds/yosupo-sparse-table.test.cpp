// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/sparse-table.hpp"
#include <iostream>

int n, q, l, r;

int main(int argc, char const *argv[]) {
    optimizeIO(), std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    SparseTable<MinInfo<int>> ST(a);

    while (q--) {
        std::cin >> l >> r;
        std::cout << ST.query(l, r - 1).val << '\n';
    }

    return 0;
}
