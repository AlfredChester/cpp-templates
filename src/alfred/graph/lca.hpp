#ifndef AFGR_LCA
#define AFGR_LCA

#include "../data_structure/sparse-table.hpp"
#include <vector>

// requires a previous graph definition.
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
} LCA;
std::vector<int> LCAImpl::d;

struct LCAInfo {
    int val;
    LCAInfo(void) : val(-1) {}
    template <class InitT>
    LCAInfo(InitT x) { val = x; }
    LCAInfo operator+(LCAInfo &x) {
        return {LCA.LCA(val, x.val)};
    }
}; // for range lca.

#endif // AFGR_LCA
