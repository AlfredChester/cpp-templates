// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include "../../src/alfred/config/fast-io.hpp"
#include "../../src/alfred/config/io-sync-off.hpp"
#include "../../src/alfred/graph/graph.hpp"
#include "../../src/alfred/graph/lca.hpp"
#include <iostream>

int n, k, c, q, u, v;

int main(int argc, char const *argv[]) {
    Graph G;
    optimizeIO(), fast_read(n);
    for (int i = 0; i < n; i++) {
        fast_read(k);
        while (k--) {
            fast_read(c);
            G.add_directed(i, c);
        }
    }
    LCAImpl LCA(G);
    fast_read(q);
    while (q--) {
        fast_read(u, v);
        writeln(LCA.LCA(u, v));
    }
    return 0;
}
