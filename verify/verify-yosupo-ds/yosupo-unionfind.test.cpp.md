---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/dsu.hpp
    title: src/alfred/data_structure/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"src/alfred/config/io-sync-off.hpp\"\
    \n#include <bits/stdc++.h>\n\ninline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(NULL), std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/data_structure/dsu.hpp\"\
    \n\n\n\n#line 5 \"src/alfred/data_structure/dsu.hpp\"\n\nstruct DSU {\n    std::vector<int>\
    \ fa, siz;\n    DSU(int n) : fa(n + 1), siz(n + 1, 1) {\n        std::iota(fa.begin(),\
    \ fa.end(), 0);\n    }\n    inline int find(int x) {\n        return fa[x] ==\
    \ x ? x : fa[x] = find(fa[x]);\n    }\n    inline bool same(int x, int y) {\n\
    \        return find(x) == find(y);\n    }\n    // true if x and y were not in\
    \ the same set, false otherwise.\n    inline bool merge(int x, int y) {\n    \
    \    int fx = find(x), fy = find(y);\n        if (fx == fy) return false;\n  \
    \      if (siz[fx] < siz[fy]) std::swap(fx, fy);\n        fa[fy] = fx, siz[fx]\
    \ += siz[fy], siz[fy] = 0;\n        return true;\n    }\n    // x -> y, a.k.a\
    \ let x be son of y (disable merge by rank).\n    inline bool directed_merge(int\
    \ x, int y) {\n        int fx = find(x), fy = find(y);\n        if (fx == fy)\
    \ return false;\n        fa[fx] = fy, siz[fy] += siz[fx], siz[fx] = 0;\n     \
    \   return true;\n    }\n};\n\n\n#line 6 \"verify/verify-yosupo-ds/yosupo-unionfind.test.cpp\"\
    \n\nint main(int argc, char const *argv[]) {\n    int n, q, opt, u, v;\n    optimizeIO(),\
    \ std::cin >> n >> q;\n\n    DSU D(n);\n    while (q--) {\n        std::cin >>\
    \ opt >> u >> v;\n        if (opt == 0) {\n            D.merge(u, v);\n      \
    \  } else {\n            std::cout << D.same(u, v) << '\\n';\n        }\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/dsu.hpp\"\
    \n#include <iostream>\n\nint main(int argc, char const *argv[]) {\n    int n,\
    \ q, opt, u, v;\n    optimizeIO(), std::cin >> n >> q;\n\n    DSU D(n);\n    while\
    \ (q--) {\n        std::cin >> opt >> u >> v;\n        if (opt == 0) {\n     \
    \       D.merge(u, v);\n        } else {\n            std::cout << D.same(u, v)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/dsu.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-unionfind.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
---
