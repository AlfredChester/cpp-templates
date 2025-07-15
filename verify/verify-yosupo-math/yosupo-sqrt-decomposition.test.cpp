// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/math/sqrt-decomposition.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    long long n;
    optimizeIO(), std::cin >> n;

    auto res = sqrt_decomposit(n);
    std::reverse(res.begin(), res.end());

    std::cout << res.size() << '\n';
    for (auto &[l, r, v] : res) {
        std::cout << v << " ";
    }
    return 0;
}
