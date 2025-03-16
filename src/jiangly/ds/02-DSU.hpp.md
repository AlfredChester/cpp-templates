---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
  bundledCode: "#line 1 \"src/jiangly/ds/02-DSU.hpp\"\n/**   \u5E76\u67E5\u96C6\uFF08\
    DSU\uFF09\r\n *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142\r\
    \n**/\r\nstruct DSU {\r\n    std::vector<int> f, siz;\r\n    \r\n    DSU() {}\r\
    \n    DSU(int n) {\r\n        init(n);\r\n    }\r\n    \r\n    void init(int n)\
    \ {\r\n        f.resize(n);\r\n        std::iota(f.begin(), f.end(), 0);\r\n \
    \       siz.assign(n, 1);\r\n    }\r\n    \r\n    int find(int x) {\r\n      \
    \  while (x != f[x]) {\r\n            x = f[x] = f[f[x]];\r\n        }\r\n   \
    \     return x;\r\n    }\r\n    \r\n    bool same(int x, int y) {\r\n        return\
    \ find(x) == find(y);\r\n    }\r\n    \r\n    bool merge(int x, int y) {\r\n \
    \       x = find(x);\r\n        y = find(y);\r\n        if (x == y) {\r\n    \
    \        return false;\r\n        }\r\n        siz[x] += siz[y];\r\n        f[y]\
    \ = x;\r\n        return true;\r\n    }\r\n    \r\n    int size(int x) {\r\n \
    \       return siz[find(x)];\r\n    }\r\n};\n"
  code: "/**   \u5E76\u67E5\u96C6\uFF08DSU\uFF09\r\n *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142\r\
    \n**/\r\nstruct DSU {\r\n    std::vector<int> f, siz;\r\n    \r\n    DSU() {}\r\
    \n    DSU(int n) {\r\n        init(n);\r\n    }\r\n    \r\n    void init(int n)\
    \ {\r\n        f.resize(n);\r\n        std::iota(f.begin(), f.end(), 0);\r\n \
    \       siz.assign(n, 1);\r\n    }\r\n    \r\n    int find(int x) {\r\n      \
    \  while (x != f[x]) {\r\n            x = f[x] = f[f[x]];\r\n        }\r\n   \
    \     return x;\r\n    }\r\n    \r\n    bool same(int x, int y) {\r\n        return\
    \ find(x) == find(y);\r\n    }\r\n    \r\n    bool merge(int x, int y) {\r\n \
    \       x = find(x);\r\n        y = find(y);\r\n        if (x == y) {\r\n    \
    \        return false;\r\n        }\r\n        siz[x] += siz[y];\r\n        f[y]\
    \ = x;\r\n        return true;\r\n    }\r\n    \r\n    int size(int x) {\r\n \
    \       return siz[find(x)];\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/02-DSU.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/02-DSU.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/02-DSU.hpp
- /library/src/jiangly/ds/02-DSU.hpp.html
title: src/jiangly/ds/02-DSU.hpp
---
