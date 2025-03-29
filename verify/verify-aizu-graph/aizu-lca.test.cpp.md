---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/fast-io.hpp
    title: src/alfred/config/fast-io.hpp
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/sparse-table.hpp
    title: src/alfred/data_structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/graph/lca.hpp
    title: src/alfred/graph/lca.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"verify/verify-aizu-graph/aizu-lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n\n#line\
    \ 1 \"src/alfred/config/fast-io.hpp\"\n#include <iostream>\n\nclass FastIO {\n\
    private:\n    int siz = 100000;\n    char *buf, *p1, *p2;\n\npublic:\n    inline\
    \ char nc(void) {\n        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1,\
    \ siz, stdin), p1 == p2) ? EOF : *p1++;\n    }\n    inline void pc(char c) { putchar(c);\
    \ }\n    FastIO(void) { buf = (char *)malloc(siz); }\n    FastIO(int n) : siz(n)\
    \ { buf = (char *)malloc(siz); } // n characters.\n    ~FastIO(void) { free(buf);\
    \ }\n    inline void resize(int n) {\n        siz = n;\n        buf = (char *)realloc(buf,\
    \ siz);\n    }\n} __buf;\n\ninline void reset_size(int siz) {\n    __buf.resize(siz);\n\
    }\n\ntemplate <class T>\ninline void fast_read(T &x) {\n    x = 0;\n    static\
    \ char c = __buf.nc();\n    while (c < '0' || c > '9') c = __buf.nc();\n    while\
    \ (c >= '0' && c <= '9') {\n        x = (x << 1) + (x << 3) + (c ^ 48), c = __buf.nc();\n\
    \    }\n}\ntemplate <class T>\ninline void write(T x) {\n    if (x < 0) putchar('-'),\
    \ x = -x;\n    if (x > 9) write(x / 10);\n    putchar((x % 10) ^ 48);\n}\ntemplate\
    \ <class T>\ninline void writeln(T x) {\n    write(x), puts(\"\");\n}\ntemplate\
    \ <typename T, typename... V>\ninline void writeln(T x, V... v) {\n    write(x),\
    \ putchar(' '), writeln(v...);\n}\ntemplate <typename T, typename... V>\ninline\
    \ void fast_read(T &t, V &...v) {\n    fast_read(t), fast_read(v...);\n}\n#line\
    \ 1 \"src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\ninline\
    \ void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL),\
    \ std::cout.tie(NULL);\n}\n#line 6 \"verify/verify-aizu-graph/aizu-lca.test.cpp\"\
    \n\nint n, k, c, q, u, v;\nstd::vector<int> G[100010];\n\n#line 1 \"src/alfred/graph/lca.hpp\"\
    \n\n\n\n#line 1 \"src/alfred/data_structure/sparse-table.hpp\"\n\n\n\n#line 7\
    \ \"src/alfred/data_structure/sparse-table.hpp\"\n\ntemplate <class T>\nstruct\
    \ MaxInfo {\n    T val;\n    MaxInfo(void) { val = std::numeric_limits<T>::min();\
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
    \      if (l > r) return T();\n        T ans = T();\n        for (int i = std::__lg(r\
    \ - l + 1); i >= 0; i--) {\n            if ((1 << i) <= r - l + 1) {\n       \
    \         ans = ans + ST[l][i];\n                l += 1 << i;\n            }\n\
    \        }\n        return ans;\n    }\n};\n\n\n#line 6 \"src/alfred/graph/lca.hpp\"\
    \n\n// requires a previous graph definition.\nclass LCAImpl {\nprivate:\n    std::vector<int>\
    \ dfn, seq; // dfn and seq are (internally) zero indexed.\n    static std::vector<int>\
    \ d;\n    struct EulerTourInfo {\n        int val;\n        EulerTourInfo(void)\
    \ : val(0) {}\n        EulerTourInfo(int x) : val(x) {}\n        EulerTourInfo\
    \ operator+(EulerTourInfo &x) {\n            return d[val] < d[x.val] ? val :\
    \ x.val;\n        }\n    };\n    SparseTable<EulerTourInfo> lca; // 0 indexed.\n\
    \    inline void _dfs(int x, int fa) {\n        dfn[x] = seq.size();\n       \
    \ seq.push_back(x), d[x] = d[fa] + 1;\n        for (auto &y : G[x]) {\n      \
    \      if (y == fa) continue;\n            _dfs(y, x), seq.push_back(x);\n   \
    \     }\n    }\n\npublic:\n    inline void init(int n, int rt = 1) {\n       \
    \ d.assign(n + 1, 0), dfn.assign(n + 1, 0);\n        seq.clear(), _dfs(rt, 0),\
    \ lca.init(seq);\n    }\n    inline int LCA(int u, int v) {\n        if (u ==\
    \ -1) return v;\n        if (v == -1) return u;\n        if (dfn[u] > dfn[v])\
    \ std::swap(u, v);\n        return lca.query(dfn[u], dfn[v]).val;\n    }\n   \
    \ inline int dis(int u, int v) {\n        return d[u] + d[v] - 2 * d[LCA(u, v)];\n\
    \    }\n} LCA;\nstd::vector<int> LCAImpl::d;\n\nstruct LCAInfo {\n    int val;\n\
    \    LCAInfo(void) : val(-1) {}\n    template <class InitT>\n    LCAInfo(InitT\
    \ x) { val = x; }\n    LCAInfo operator+(LCAInfo &x) {\n        return {LCA.LCA(val,\
    \ x.val)};\n    }\n}; // for range lca.\n\n\n#line 11 \"verify/verify-aizu-graph/aizu-lca.test.cpp\"\
    \n\nint main(int argc, char const *argv[]) {\n    optimizeIO(), fast_read(n);\n\
    \    for (int i = 0; i < n; i++) {\n        fast_read(k);\n        while (k--)\
    \ {\n            fast_read(c);\n            G[i].push_back(c);\n        }\n  \
    \  }\n    LCA.init(n, 0);\n    fast_read(q);\n    while (q--) {\n        fast_read(u,\
    \ v);\n        writeln(LCA.LCA(u, v));\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../src/alfred/config/fast-io.hpp\"\n#include \"../../src/alfred/config/io-sync-off.hpp\"\
    \n#include <iostream>\n\nint n, k, c, q, u, v;\nstd::vector<int> G[100010];\n\n\
    #include \"../../src/alfred/graph/lca.hpp\"\n\nint main(int argc, char const *argv[])\
    \ {\n    optimizeIO(), fast_read(n);\n    for (int i = 0; i < n; i++) {\n    \
    \    fast_read(k);\n        while (k--) {\n            fast_read(c);\n       \
    \     G[i].push_back(c);\n        }\n    }\n    LCA.init(n, 0);\n    fast_read(q);\n\
    \    while (q--) {\n        fast_read(u, v);\n        writeln(LCA.LCA(u, v));\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/fast-io.hpp
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/graph/lca.hpp
  - src/alfred/data_structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/verify-aizu-graph/aizu-lca.test.cpp
  requiredBy: []
  timestamp: '2025-03-29 12:01:17+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aizu-graph/aizu-lca.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aizu-graph/aizu-lca.test.cpp
- /verify/verify/verify-aizu-graph/aizu-lca.test.cpp.html
title: verify/verify-aizu-graph/aizu-lca.test.cpp
---
