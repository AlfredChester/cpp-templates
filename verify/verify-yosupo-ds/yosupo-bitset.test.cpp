// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/predecessor_problem

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/dynamic-bitset.hpp"
#include <iostream>

std::string T;
int n, q, opt, x;

int main(int argc, char const *argv[]) {
    optimizeIO();
    std::cin >> n >> q >> T;

    DynamicBitset bit(n);

    for (int i = 0; i < n; i++) {
        if (T[i] == '1') bit.set(i);
    }

    while (q--) {
        std::cin >> opt >> x;
        if (opt == 0) {
            bit.set(x);
        } else if (opt == 1) {
            bit.set(x, false);
        } else if (opt == 2) {
            std::cout << bit.test(x) << '\n';
        } else if (opt == 3) {
            std::cout << bit.suf(x, true) << '\n';
        } else {
            std::cout << bit.pre(x, true) << '\n';
        }
    }

    return 0;
}
