#ifndef AFGR_LCA
#define AFGR_LCA

#include "../data_structure/sparse-table.hpp"
#include "graph.hpp"
#include <vector>

// requires a previous graph definition.
template <class T = null_type>
class LCAImpl {
private:
    Graph<T> G;
    std::vector<int> dfn, seq, d; // dfn, seq and d are (internally) zero indexed.
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
        for (Graph<T>::Edge &edge : G[x]) {
            if (edge.to == fa) continue;
            _dfs(edge.to, x), seq.push_back(edge.to);
        }
    }

public:
    LCAImpl(void) = default;
    LCAImpl(Graph<T> _G, int rt = 1) : G(_G) {
        init(G.G.size(), rt);
    }
    inline void init(int n, int rt = 1) {
        d.assign(n + 1, 0), dfn.assign(n + 1, 0);
        seq.clear(), _dfs(rt, 0), lca.init(seq);
    }
    inline int LCA(int u, int v) {
        if (u == -1) return v;
        if (v == -1) return u;
        if (dfn[u] > dfn[v]) std::swap(u, v);
        return lca.query(dfn[u], dfn[v]).val;
    }
    inline int dis(int u, int v) {
        return d[u] + d[v] - 2 * d[LCA(u, v)];
    }
};

#endif // AFGR_LCA
