#ifndef AFGR_2SAT
#define AFGR_2SAT

#include <vector>

struct TwoSAT {
    std::vector<std::vector<int>> G;
    std::vector<int> dfn, low, stk, bel, in;
    // TwoSAT(void) = default;
    TwoSAT(int n) : G(2 * n) {}
    void tarjan(int u, int &cnt, int &cc) {
        dfn[u] = low[u] = ++cnt;
        in[u] = 1, stk.push_back(u);
        for (auto &v : G[u]) {
            if (dfn[v] == 0) {
                tarjan(v, cnt, cc);
                low[u] = std::min(low[u], low[v]);
            } else if (in[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        int v;
        if (dfn[u] == low[u]) {
            cc++;
            do {
                v = stk.back(), in[v] = 0;
                stk.pop_back(), bel[v] = cc;
            } while (v != u);
        }
    }
    // Add constraint: x = a or y = b.
    inline void add(int x, bool a, int y, bool b) {
        // size_t should = 2 * (std::max(x, y) + 1);
        // if (G.size() < should) G.resize(should);
        G[x << 1 | !a].push_back(y << 1 | b);
        G[y << 1 | !b].push_back(x << 1 | a);
    }
    // Add constraint: x = a => y = b;
    inline void conduct(int x, bool a, int y, bool b) {
        // size_t should = 2 * (std::max(x, y) + 1);
        // if (G.size() < should) G.resize(should);
        G[x << 1 | a].push_back(y << 1 | b);
    }
    inline void same(int x, int y) {
        conduct(x, true, y, true);
        conduct(y, true, x, true);
        conduct(x, false, y, false);
        conduct(y, false, x, false);
    }
    inline void diff(int x, int y) {
        conduct(x, true, y, false);
        conduct(y, true, x, false);
        conduct(x, false, y, true);
        conduct(y, false, x, true);
    }
    inline void set(int x, bool v) {
        conduct(x, !v, x, v);
    }
    inline void init(void) { // find scc.
        int n = G.size(), cnt = 0, cc = 0;
        in = dfn = low = bel = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) tarjan(i, cnt, cc);
        }
    }
    inline bool has_solution(void) {
        int var = G.size() / 2;
        for (int i = 0; i < var; i++) {
            if (bel[i << 1] == bel[i << 1 | 1]) {
                return false;
            }
        }
        return true;
    }
    std::vector<int> solve(int n) {
        int var = G.size() / 2;
        std::vector<int> sol(n);
        for (int i = 0; i < var; i++) {
            sol[i] = bel[i << 1] > bel[i << 1 | 1];
        }
        return sol;
    }
};

#endif
