#ifndef AFGR_LCA
#define AFGR_LCA

#include "graph.hpp"
#include <vector>

// TODO Rename this to tree.

template <class T = null_type>
class LCAImpl {
private:
    Graph<T> G;
    std::vector<int> dfn, seq, d; // dfn, seq and d are (internally) zero indexed.
    // so far, what I can do is to internally implement a sparse table.
    std::vector<std::vector<int>> ST;
    inline void _dfs(int x, int fa) {
        dfn[x] = seq.size();
        seq.push_back(x), d[x] = d[fa] + 1;
        for (auto &edge : G[x]) {
            if (edge.to == fa) continue;
            _dfs(edge.to, x), seq.push_back(x);
        }
    }
    inline int query(int l, int r) {
        int k = std::__lg(r - l + 1);
        return merge(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
    inline int merge(int x, int y) {
        return d[x] < d[y] ? x : y;
    }

public:
    LCAImpl(void) = default;
    LCAImpl(Graph<T> _G, int rt = 1) : G(_G) {
        init(G.size(), rt);
    }
    inline void init(int n, int rt = 1) {
        d.assign(n + 1, 0), seq.clear();
        dfn.assign(n + 1, 0), _dfs(rt, 0);
        int m = seq.size(), lg = std::__lg(m);
        ST.assign(m, std::vector<int>(lg + 1));
        for (int i = 0; i < m; i++) ST[i][0] = seq[i];
        for (int j = 1; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= m; i++) {
                ST[i][j] = merge(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline int LCA(int u, int v) {
        if (u == -1) return v;
        if (v == -1) return u;
        if (dfn[u] > dfn[v]) std::swap(u, v);
        return query(dfn[u], dfn[v]);
    }
    inline int dis(int u, int v) {
        return d[u] + d[v] - 2 * d[LCA(u, v)];
    }
};

#endif // AFGR_LCA
