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
  bundledCode: "#line 1 \"src/alfred/data_structure/cancel-dsu.hpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\nstruct CancelDSU {\n    std::stack<int> S;\n    std::vector<int>\
    \ fa, siz;\n    CancelDSU(int n) : fa(n + 1), siz(n + 1, 1) {\n        std::iota(fa.begin(),\
    \ fa.end(), 0);\n    }\n    inline int find(int x) {\n        return fa[x] ==\
    \ x ? x : find(fa[x]);\n    }\n    inline bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    inline void merge(int u, int v) {\n        int\
    \ fu = find(u), fv = find(v);\n        if (fu == fv) return S.push(-1);\n    \
    \    if (siz[fu] < siz[fv]) std::swap(fu, fv);\n        siz[fu] += siz[fv], fa[fv]\
    \ = fu, S.push(fv);\n    }\n    inline void _cancel(void) {\n        if (S.empty())\
    \ return;\n        if (S.top() == -1) return S.pop();\n        siz[fa[S.top()]]\
    \ -= siz[S.top()];\n        fa[S.top()] = S.top(), S.pop();\n    }\n    inline\
    \ void cancel(int t = 1) {\n        while (t--) _cancel();\n    }\n};\n\n\n"
  code: "#ifndef AFDS_CANCEL_DSU\n#define AFDS_CANCEL_DSU\n\n#include <bits/stdc++.h>\n\
    \nstruct CancelDSU {\n    std::stack<int> S;\n    std::vector<int> fa, siz;\n\
    \    CancelDSU(int n) : fa(n + 1), siz(n + 1, 1) {\n        std::iota(fa.begin(),\
    \ fa.end(), 0);\n    }\n    inline int find(int x) {\n        return fa[x] ==\
    \ x ? x : find(fa[x]);\n    }\n    inline bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    inline void merge(int u, int v) {\n        int\
    \ fu = find(u), fv = find(v);\n        if (fu == fv) return S.push(-1);\n    \
    \    if (siz[fu] < siz[fv]) std::swap(fu, fv);\n        siz[fu] += siz[fv], fa[fv]\
    \ = fu, S.push(fv);\n    }\n    inline void _cancel(void) {\n        if (S.empty())\
    \ return;\n        if (S.top() == -1) return S.pop();\n        siz[fa[S.top()]]\
    \ -= siz[S.top()];\n        fa[S.top()] = S.top(), S.pop();\n    }\n    inline\
    \ void cancel(int t = 1) {\n        while (t--) _cancel();\n    }\n};\n\n#endif\
    \ // AFDS_CANCEL_DSU"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/cancel-dsu.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/cancel-dsu.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/cancel-dsu.hpp
- /library/src/alfred/data_structure/cancel-dsu.hpp.html
title: src/alfred/data_structure/cancel-dsu.hpp
---
