---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/prefix-sum.hpp
    title: src/alfred/data_structure/prefix-sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-static-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 2 \"src/alfred/config/io-sync-off.hpp\"\
    \n\n#include <bits/stdc++.h>\n\ninline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(NULL), std::cout.tie(NULL);\n}\n#line 3 \"src/alfred/data_structure/prefix-sum.hpp\"\
    \n\ntemplate <class T>\nclass Sum {\nprivate:\n    size_t n;\n    std::vector<T>\
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
    \  return sum[x2][y2] - s1 - s2 + s3;\n    }\n};\n#line 6 \"verify/verify-yosupo-ds/yosupo-static-sum.test.cpp\"\
    \n\nint main(int argc, char const *argv[]) {\n    int n, q, l, r;\n    optimizeIO(),\
    \ std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        std::cin >> a[i];\n    }\n    Sum<long long> S(a);\n    while\
    \ (q--) {\n        std::cin >> l >> r;\n        std::cout << S.query(l, r - 1)\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/prefix-sum.hpp\"\
    \n#include <iostream>\n\nint main(int argc, char const *argv[]) {\n    int n,\
    \ q, l, r;\n    optimizeIO(), std::cin >> n >> q;\n    std::vector<int> a(n);\n\
    \    for (int i = 0; i < n; i++) {\n        std::cin >> a[i];\n    }\n    Sum<long\
    \ long> S(a);\n    while (q--) {\n        std::cin >> l >> r;\n        std::cout\
    \ << S.query(l, r - 1) << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/prefix-sum.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
  requiredBy: []
  timestamp: '2025-02-18 18:50:53+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-static-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
---
