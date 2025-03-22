#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../src/alfred/config/io-sync-off.hpp"
#include <iostream>

int n, k, c, q, u, v;
std::vector<int> G[100010];

#include "../../src/alfred/graph/lca.hpp"

int main(int argc, char const *argv[]) {
    optimizeIO(), std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        while (k--) {
            std::cin >> c;
            G[i].push_back(c);
        }
    }
    LCA.init(n, 0), std::cin >> q;
    while (q--) {
        std::cin >> u >> v;
        std::cout << LCA.LCA(u, v) << '\n';
    }
    return 0;
}
