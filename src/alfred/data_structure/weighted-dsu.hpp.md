---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/data_structure/weighted-dsu.hpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\ntemplate <class T>\nstruct WeightedDSU {\n    std::vector<int>\
    \ fa;\n    std::vector<T> w;\n    WeightedDSU(int n) : fa(n + 1), w(n + 1) {\n\
    \        std::iota(fa.begin(), fa.end(), 0);\n    }\n    inline int find(int x)\
    \ {\n        if (fa[x] == x) return x;\n        int f = fa[x], f2 = find(f);\n\
    \        return w[x] += w[f], fa[x] = f2;\n    }\n    inline bool same(int x,\
    \ int y) {\n        return find(x) == find(y);\n    }\n    // Given info: a[x]\
    \ + v = a[y]\n    // Returns true if this operation has no conflict, false otherwise.\n\
    \    inline bool merge(int x, int y, T v) {\n        int fx = find(x), fy = find(y);\n\
    \        if (fx == fy) {\n            return w[x] + v == w[y];\n        }\n  \
    \      w[fy] = w[x] + v - w[y], fa[fy] = fx;\n        return true;\n    }\n  \
    \  inline T distance(int x, int y) {\n        return find(x), find(y), w[y] -\
    \ w[x];\n    }\n};\n\n\n"
  code: "#ifndef AFDS_WEIGHTED_DSU\n#define AFDS_WEIGHTED_DSU\n\n#include <bits/stdc++.h>\n\
    \ntemplate <class T>\nstruct WeightedDSU {\n    std::vector<int> fa;\n    std::vector<T>\
    \ w;\n    WeightedDSU(int n) : fa(n + 1), w(n + 1) {\n        std::iota(fa.begin(),\
    \ fa.end(), 0);\n    }\n    inline int find(int x) {\n        if (fa[x] == x)\
    \ return x;\n        int f = fa[x], f2 = find(f);\n        return w[x] += w[f],\
    \ fa[x] = f2;\n    }\n    inline bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n    // Given info: a[x] + v = a[y]\n    // Returns true\
    \ if this operation has no conflict, false otherwise.\n    inline bool merge(int\
    \ x, int y, T v) {\n        int fx = find(x), fy = find(y);\n        if (fx ==\
    \ fy) {\n            return w[x] + v == w[y];\n        }\n        w[fy] = w[x]\
    \ + v - w[y], fa[fy] = fx;\n        return true;\n    }\n    inline T distance(int\
    \ x, int y) {\n        return find(x), find(y), w[y] - w[x];\n    }\n};\n\n#endif\
    \ // AFDS_WEIGHTED_DSU"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/weighted-dsu.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/weighted-dsu.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/weighted-dsu.hpp
- /library/src/alfred/data_structure/weighted-dsu.hpp.html
title: src/alfred/data_structure/weighted-dsu.hpp
---
