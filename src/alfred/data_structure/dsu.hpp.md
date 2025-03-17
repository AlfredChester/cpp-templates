---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
    title: verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/data_structure/dsu.hpp\"\n\n\n\n#include <numeric>\n\
    #include <vector>\n\nstruct DSU {\n    std::vector<int> fa, siz;\n    DSU(int\
    \ n) : fa(n + 1), siz(n + 1, 1) {\n        std::iota(fa.begin(), fa.end(), 0);\n\
    \    }\n    inline int find(int x) {\n        return fa[x] == x ? x : fa[x] =\
    \ find(fa[x]);\n    }\n    inline bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n    // true if x and y were not in the same set, false otherwise.\n\
    \    inline bool merge(int x, int y) {\n        int fx = find(x), fy = find(y);\n\
    \        if (fx == fy) return false;\n        if (siz[fx] < siz[fy]) std::swap(fx,\
    \ fy);\n        fa[fy] = fx, siz[fx] += siz[fy], siz[fy] = 0;\n        return\
    \ true;\n    }\n    // x -> y, a.k.a let x be son of y (disable merge by rank).\n\
    \    inline bool directed_merge(int x, int y) {\n        int fx = find(x), fy\
    \ = find(y);\n        if (fx == fy) return false;\n        fa[fx] = fy, siz[fy]\
    \ += siz[fx], siz[fx] = 0;\n        return true;\n    }\n};\n\n\n"
  code: "#ifndef AFDS_DSU\n#define AFDS_DSU\n\n#include <numeric>\n#include <vector>\n\
    \nstruct DSU {\n    std::vector<int> fa, siz;\n    DSU(int n) : fa(n + 1), siz(n\
    \ + 1, 1) {\n        std::iota(fa.begin(), fa.end(), 0);\n    }\n    inline int\
    \ find(int x) {\n        return fa[x] == x ? x : fa[x] = find(fa[x]);\n    }\n\
    \    inline bool same(int x, int y) {\n        return find(x) == find(y);\n  \
    \  }\n    // true if x and y were not in the same set, false otherwise.\n    inline\
    \ bool merge(int x, int y) {\n        int fx = find(x), fy = find(y);\n      \
    \  if (fx == fy) return false;\n        if (siz[fx] < siz[fy]) std::swap(fx, fy);\n\
    \        fa[fy] = fx, siz[fx] += siz[fy], siz[fy] = 0;\n        return true;\n\
    \    }\n    // x -> y, a.k.a let x be son of y (disable merge by rank).\n    inline\
    \ bool directed_merge(int x, int y) {\n        int fx = find(x), fy = find(y);\n\
    \        if (fx == fy) return false;\n        fa[fx] = fy, siz[fy] += siz[fx],\
    \ siz[fx] = 0;\n        return true;\n    }\n};\n\n#endif // AFDS_DSU"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/dsu.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-unionfind.test.cpp
documentation_of: src/alfred/data_structure/dsu.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/dsu.hpp
- /library/src/alfred/data_structure/dsu.hpp.html
title: src/alfred/data_structure/dsu.hpp
---
