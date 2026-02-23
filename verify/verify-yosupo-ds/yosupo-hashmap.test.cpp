// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/associative_array

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/hashmap.hpp"
#include <iostream>

int q, opt;
using u64 = unsigned long long;

int main(int argc, char const *argv[]) {
    u64 x, v;
    optimizeIO();
    HashMap<u64, u64> mp;
    std::cin >> q, mp.init(q);
    while (q--) {
        std::cin >> opt >> x;
        if (opt == 0) {
            std::cin >> v, mp.set(x, v);
        } else {
            std::cout << mp.get(x) << '\n';
        }
    }
    return 0;
}
