// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/wildcard_pattern_matching

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/string/fuzz-matching.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::string s, t;
    optimizeIO(), std::cin >> s >> t;

    std::string ans(s.size() - t.size() + 1, '0');

    for (auto &p : fuzz_matching(t, s, '*')) {
        ans[p] = '1';
    }

    std::cout << ans << '\n';
    return 0;
}
