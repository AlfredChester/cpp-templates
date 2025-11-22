// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/cartesian.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    int n;
    optimizeIO(), std::cin >> n;

    std::vector<int> a(n), res(n);
    for (auto &x : a) std::cin >> x;

    auto [p, ans] = cartesian(a);

    for (int i = 0; i < n; i++) {
        if (ans[i].first != -1) {
            res[ans[i].first] = i;
        }
        if (ans[i].second != -1) {
            res[ans[i].second] = i;
        }
    }

    res[p] = p;
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << ' ';
    }

    return 0;
}
