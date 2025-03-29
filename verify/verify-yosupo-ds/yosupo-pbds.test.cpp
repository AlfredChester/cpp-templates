// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/predecessor_problem

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/pbds-balance-tree.hpp"
#include <iostream>

std::string T;
int n, q, opt, x;
BalanceTree<int, std::less<int>> tr;

int main(int argc, char const *argv[]) {
    optimizeIO();
    std::cin >> n >> q >> T;
    for (int i = 0; i < n; i++) {
        if (T[i] == '1') tr.insert(i);
    }

    while (q--) {
        std::cin >> opt >> x;
        if (opt == 0) {
            tr.insert(x);
        } else if (opt == 1) {
            if (tr.find(x) != tr.end()) {
                tr.erase(x);
            }
        } else if (opt == 2) {
            std::cout << (tr.find(x) != tr.end()) << '\n';
        } else if (opt == 3) {
            auto it = tr.lower_bound(x);
            std::cout << (it == tr.end() ? -1 : *it) << '\n';
        } else {
            auto it = tr.upper_bound(x);
            std::cout << (it == tr.begin() ? -1 : *(--it)) << '\n';
        }
    }

    return 0;
}
