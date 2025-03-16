---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/alfred/data_structure/prefix-sum.hpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T>\nclass Sum {\nprivate:\n    size_t n;\n    std::vector<T>\
    \ sum;\n\npublic:\n    Sum(void) : n(0) {}\n    template <class InitT>\n    Sum(std::vector<InitT>\
    \ &init) { _init(init); }\n    template <class InitT>\n    inline void _init(std::vector<InitT>\
    \ &init) {\n        if (init.empty()) return;\n        sum.resize(n = init.size()),\
    \ sum[0] = init[0];\n        for (size_t i = 1; i < n; i++) {\n            sum[i]\
    \ = sum[i - 1] + init[i];\n        }\n    }\n    inline T query(int l, int r)\
    \ {\n        if (l > r) return T();\n        return l == 0 ? sum[r] : sum[r] -\
    \ sum[l - 1];\n    }\n};\ntemplate <class T>\nclass GridSum {\nprivate:\n    size_t\
    \ n, m;\n    std::vector<std::vector<T>> sum;\n\npublic:\n    GridSum(void) :\
    \ n(0), m(0) {}\n    template <class InitT>\n    GridSum(std::vector<std::vector<InitT>>\
    \ &init) { _init(init); }\n    template <class InitT>\n    inline void _init(std::vector<std::vector<InitT>>\
    \ &init) {\n        if (init.empty()) return;\n        n = init.size(), m = init[0].size();\n\
    \        sum.assign(n, std::vector<T>(m)), sum[0][0] = init[0][0];\n        for\
    \ (size_t i = 1; i < n; i++) {\n            sum[i][0] = sum[i - 1][0] + init[i][0];\n\
    \        }\n        for (size_t i = 1; i < m; i++) {\n            sum[0][i] =\
    \ sum[0][i - 1] + init[0][i];\n        }\n        for (size_t i = 1; i < n; i++)\
    \ {\n            for (size_t j = 1; j < m; j++) {\n                sum[i][j] =\
    \ sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + init[i][j];\n          \
    \  }\n        }\n    }\n    inline T query(int x1, int y1, int x2, int y2) {\n\
    \        T s1 = x1 == 0 ? 0 : sum[x1 - 1][y2];\n        T s2 = y1 == 0 ? 0 : sum[x2][y1\
    \ - 1];\n        T s3 = x1 == 0 || y1 == 0 ? 0 : sum[x1 - 1][y1 - 1];\n      \
    \  return sum[x2][y2] - s1 - s2 + s3;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\ntemplate <class T>\nclass Sum {\n\
    private:\n    size_t n;\n    std::vector<T> sum;\n\npublic:\n    Sum(void) : n(0)\
    \ {}\n    template <class InitT>\n    Sum(std::vector<InitT> &init) { _init(init);\
    \ }\n    template <class InitT>\n    inline void _init(std::vector<InitT> &init)\
    \ {\n        if (init.empty()) return;\n        sum.resize(n = init.size()), sum[0]\
    \ = init[0];\n        for (size_t i = 1; i < n; i++) {\n            sum[i] = sum[i\
    \ - 1] + init[i];\n        }\n    }\n    inline T query(int l, int r) {\n    \
    \    if (l > r) return T();\n        return l == 0 ? sum[r] : sum[r] - sum[l -\
    \ 1];\n    }\n};\ntemplate <class T>\nclass GridSum {\nprivate:\n    size_t n,\
    \ m;\n    std::vector<std::vector<T>> sum;\n\npublic:\n    GridSum(void) : n(0),\
    \ m(0) {}\n    template <class InitT>\n    GridSum(std::vector<std::vector<InitT>>\
    \ &init) { _init(init); }\n    template <class InitT>\n    inline void _init(std::vector<std::vector<InitT>>\
    \ &init) {\n        if (init.empty()) return;\n        n = init.size(), m = init[0].size();\n\
    \        sum.assign(n, std::vector<T>(m)), sum[0][0] = init[0][0];\n        for\
    \ (size_t i = 1; i < n; i++) {\n            sum[i][0] = sum[i - 1][0] + init[i][0];\n\
    \        }\n        for (size_t i = 1; i < m; i++) {\n            sum[0][i] =\
    \ sum[0][i - 1] + init[0][i];\n        }\n        for (size_t i = 1; i < n; i++)\
    \ {\n            for (size_t j = 1; j < m; j++) {\n                sum[i][j] =\
    \ sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + init[i][j];\n          \
    \  }\n        }\n    }\n    inline T query(int x1, int y1, int x2, int y2) {\n\
    \        T s1 = x1 == 0 ? 0 : sum[x1 - 1][y2];\n        T s2 = y1 == 0 ? 0 : sum[x2][y1\
    \ - 1];\n        T s3 = x1 == 0 || y1 == 0 ? 0 : sum[x1 - 1][y1 - 1];\n      \
    \  return sum[x2][y2] - s1 - s2 + s3;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/prefix-sum.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
documentation_of: src/alfred/data_structure/prefix-sum.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/prefix-sum.hpp
- /library/src/alfred/data_structure/prefix-sum.hpp.html
title: src/alfred/data_structure/prefix-sum.hpp
---
