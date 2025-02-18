#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/data_structure/priority-set.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, q, opt, x;
    optimizeIO(), std::cin >> n >> q;
    PrioritySet<int, std::less<int>> P1;
    PrioritySet<int, std::greater<int>> P2;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        P1.insert(x);
        P2.insert(x);
    }
    while (q--) {
        std::cin >> opt;
        if (opt == 0) {
            std::cin >> x;
            P1.insert(x);
            P2.insert(x);
        } else if (opt == 1) {
            x = P2.top();
            std::cout << x << '\n';
            P1.erase(x), P2.erase(x);
        } else {
            x = P1.top();
            std::cout << x << '\n';
            P1.erase(x), P2.erase(x);
        }
    }
    return 0;
}
