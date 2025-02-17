#pragma once

#include "../data_structure/sparse-table.hpp"
#include <bits/stdc++.h>

std::vector<int> G[100010]; // requires a previous graph definition.

class LCAImpl {
private:
    std::vector<int> dfn, seq; // dfn and seq are (internally) zero indexed.
    static std::vector<int> d;
    struct EulerTourInfo {
        int val;
        EulerTourInfo(void) : val(0) {}
        EulerTourInfo(int x) : val(x) {}
        EulerTourInfo operator+(EulerTourInfo &x) {
            return d[val] < d[x.val] ? val : x.val;
        }
    };
    SparseTable<EulerTourInfo> lca; // 0 indexed.
    inline void _dfs(int x, int fa) {
        dfn[x] = seq.size();
        seq.push_back(x), d[x] = d[fa] + 1;
        for (auto &y : G[x]) {
            if (y == fa) continue;
            _dfs(y, x), seq.push_back(x);
        }
    }

public:
    inline void init(int n) {
        d.assign(n + 1, 0), dfn.assign(n + 1, 0);
        seq.clear(), _dfs(1, 0), lca.init(seq);
    }
    inline int LCA(int u, int v) {
        if (u == 0 || v == 0) return u | v;
        if (dfn[u] > dfn[v]) std::swap(u, v);
        return lca.query(dfn[u], dfn[v]).val;
    }
} LCA;
std::vector<int> LCAImpl::d;
