---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/sparse-table.hpp
    title: src/alfred/data_structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/graph/lca.hpp\"\n\n\n\n#line 1 \"src/alfred/data_structure/sparse-table.hpp\"\
    \n\n\n\n#include <limits>\n#include <numeric>\n#include <vector>\n\ntemplate <class\
    \ T>\nstruct MaxInfo {\n    T val;\n    MaxInfo(void) { val = std::numeric_limits<T>::min();\
    \ }\n    template <class InitT>\n    MaxInfo(InitT x) { val = x; }\n    MaxInfo\
    \ operator+(MaxInfo &x) {\n        return {std::max(val, x.val)};\n    }\n};\n\
    template <class T>\nstruct MinInfo {\n    T val;\n    MinInfo(void) { val = std::numeric_limits<T>::max();\
    \ }\n    template <class InitT>\n    MinInfo(InitT x) { val = x; }\n    MinInfo\
    \ operator+(MinInfo &x) {\n        return {std::min(val, x.val)};\n    }\n};\n\
    template <class T>\nstruct GcdInfo {\n    T val;\n    GcdInfo(void) { val = T();\
    \ }\n    template <class InitT>\n    GcdInfo(InitT x) { val = x; }\n    GcdInfo\
    \ operator+(GcdInfo &x) {\n#if __cplusplus >= 201703L\n        return {std::gcd(x.val,\
    \ val)};\n#else\n        return {__gcd(x.val, val)};\n#endif\n    }\n};\ntemplate\
    \ <class T>\nclass SparseTable {\nprivate:\n    int n;\n    std::vector<std::vector<T>>\
    \ ST;\n\npublic:\n    SparseTable(void) {}\n    SparseTable(int N) : n(N), ST(N,\
    \ std::vector<T>(std::__lg(N) + 1)) {}\n    template <class InitT>\n    SparseTable(std::vector<InitT>\
    \ &_init) : SparseTable(_init.size()) { init(_init, true); }\n    template <class\
    \ InitT>\n    inline void init(std::vector<InitT> &_init, bool internal = false)\
    \ {\n        if (!internal) {\n            n = _init.size();\n            ST.assign(n,\
    \ std::vector<T>(std::__lg(n) + 1));\n        }\n        for (int i = 0; i < n;\
    \ i++) ST[i][0] = T(_init[i]);\n        for (int i = 1; (1 << i) <= n; i++) {\n\
    \            for (int j = 0; j + (1 << i) - 1 < n; j++) {\n                ST[j][i]\
    \ = ST[j][i - 1] + ST[j + (1 << (i - 1))][i - 1];\n            }\n        }\n\
    \    }\n    inline T query(int l, int r) { // 0 based\n        if (l > r) return\
    \ T();\n        int w = std::__lg(r - l + 1);\n        return ST[l][w] + ST[r\
    \ - (1 << w) + 1][w];\n    }\n    inline T disjoint_query(int l, int r) {\n  \
    \      T ans = T();\n        for (int i = l; i <= r; i += (1 << std::__lg(r -\
    \ i + 1))) {\n            ans = ans + ST[i][std::__lg(r - i + 1)];\n        }\n\
    \        return ans;\n    }\n};\n\n\n#line 6 \"src/alfred/graph/lca.hpp\"\n\n\
    // std::vector<int> G[100010]; // requires a previous graph definition.\n\nclass\
    \ LCAImpl {\nprivate:\n    std::vector<int> dfn, seq; // dfn and seq are (internally)\
    \ zero indexed.\n    static std::vector<int> d;\n    struct EulerTourInfo {\n\
    \        int val;\n        EulerTourInfo(void) : val(0) {}\n        EulerTourInfo(int\
    \ x) : val(x) {}\n        EulerTourInfo operator+(EulerTourInfo &x) {\n      \
    \      return d[val] < d[x.val] ? val : x.val;\n        }\n    };\n    SparseTable<EulerTourInfo>\
    \ lca; // 0 indexed.\n    inline void _dfs(int x, int fa) {\n        dfn[x] =\
    \ seq.size();\n        seq.push_back(x), d[x] = d[fa] + 1;\n        for (auto\
    \ &y : G[x]) {\n            if (y == fa) continue;\n            _dfs(y, x), seq.push_back(x);\n\
    \        }\n    }\n\npublic:\n    inline void init(int n) {\n        d.assign(n\
    \ + 1, 0), dfn.assign(n + 1, 0);\n        seq.clear(), _dfs(1, 0), lca.init(seq);\n\
    \    }\n    inline int LCA(int u, int v) {\n        if (u == 0 || v == 0) return\
    \ u | v;\n        if (dfn[u] > dfn[v]) std::swap(u, v);\n        return lca.query(dfn[u],\
    \ dfn[v]).val;\n    }\n} LCA;\nstd::vector<int> LCAImpl::d;\n\n\n"
  code: "#ifndef AFGR_LCA\n#define AFGR_LCA\n\n#include \"../data_structure/sparse-table.hpp\"\
    \n#include <vector>\n\n// std::vector<int> G[100010]; // requires a previous graph\
    \ definition.\n\nclass LCAImpl {\nprivate:\n    std::vector<int> dfn, seq; //\
    \ dfn and seq are (internally) zero indexed.\n    static std::vector<int> d;\n\
    \    struct EulerTourInfo {\n        int val;\n        EulerTourInfo(void) : val(0)\
    \ {}\n        EulerTourInfo(int x) : val(x) {}\n        EulerTourInfo operator+(EulerTourInfo\
    \ &x) {\n            return d[val] < d[x.val] ? val : x.val;\n        }\n    };\n\
    \    SparseTable<EulerTourInfo> lca; // 0 indexed.\n    inline void _dfs(int x,\
    \ int fa) {\n        dfn[x] = seq.size();\n        seq.push_back(x), d[x] = d[fa]\
    \ + 1;\n        for (auto &y : G[x]) {\n            if (y == fa) continue;\n \
    \           _dfs(y, x), seq.push_back(x);\n        }\n    }\n\npublic:\n    inline\
    \ void init(int n) {\n        d.assign(n + 1, 0), dfn.assign(n + 1, 0);\n    \
    \    seq.clear(), _dfs(1, 0), lca.init(seq);\n    }\n    inline int LCA(int u,\
    \ int v) {\n        if (u == 0 || v == 0) return u | v;\n        if (dfn[u] >\
    \ dfn[v]) std::swap(u, v);\n        return lca.query(dfn[u], dfn[v]).val;\n  \
    \  }\n} LCA;\nstd::vector<int> LCAImpl::d;\n\n#endif // AFGR_LCA"
  dependsOn:
  - src/alfred/data_structure/sparse-table.hpp
  isVerificationFile: false
  path: src/alfred/graph/lca.hpp
  requiredBy: []
  timestamp: '2025-03-20 21:53:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/graph/lca.hpp
layout: document
redirect_from:
- /library/src/alfred/graph/lca.hpp
- /library/src/alfred/graph/lca.hpp.html
title: src/alfred/graph/lca.hpp
---
