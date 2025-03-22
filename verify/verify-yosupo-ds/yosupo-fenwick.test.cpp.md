---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/fenwick.hpp
    title: src/alfred/data_structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-fenwick.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"\
    src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\ninline void optimizeIO(void)\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL), std::cout.tie(NULL);\n\
    }\n#line 1 \"src/alfred/data_structure/fenwick.hpp\"\n\n\n\n#line 5 \"src/alfred/data_structure/fenwick.hpp\"\
    \n\ntemplate <class T>\nstruct Fenwick {\n    std::vector<T> c;\n    inline int\
    \ lowbit(int x) { return x & -x; }\n    inline void merge(T &x, T &y) { x = x\
    \ + y; }\n    inline T subtract(T x, T y) { return x - y; }\n    inline void update(size_t\
    \ pos, T x) {\n        for (pos++; pos < c.size(); pos += lowbit(pos)) merge(c[pos],\
    \ x);\n    }\n    inline void clear(void) {\n        for (auto &x : c) x = T();\n\
    \    }\n    inline T query(size_t pos) {\n        T ans = T();\n        for (pos++;\
    \ pos; pos ^= lowbit(pos)) merge(ans, c[pos]);\n        return ans;\n    }\n \
    \   inline T query(size_t l, size_t r) {\n        return l == 0 ? query(r) : subtract(query(r),\
    \ query(l - 1));\n    }\n    inline int kth(const T k) {\n        int ans = 0;\n\
    \        for (int i = 1 << std::__lg(c.size() - 1); i; i >>= 1) {\n          \
    \  if (ans + i < (int)c.size() && c[ans + i] <= k) {\n                k -= c[ans\
    \ + i], ans += i;\n            }\n        }\n        return ans;\n    }\n    Fenwick(size_t\
    \ len) : c(len + 2) {}\n};\n\n\n#line 6 \"verify/verify-yosupo-ds/yosupo-fenwick.test.cpp\"\
    \n\nint main(int argc, char const *argv[]) {\n    int n, q, opt, x, v;\n    optimizeIO(),\
    \ std::cin >> n >> q;\n\n    Fenwick<long long> C(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        std::cin >> x, C.update(i, x);\n    }\n\n    while (q--)\
    \ {\n        std::cin >> opt >> x >> v;\n        if (opt == 0) {\n           \
    \ C.update(x, v);\n        } else {\n            std::cout << C.query(x, v - 1)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/fenwick.hpp\"\
    \n#include <iostream>\n\nint main(int argc, char const *argv[]) {\n    int n,\
    \ q, opt, x, v;\n    optimizeIO(), std::cin >> n >> q;\n\n    Fenwick<long long>\
    \ C(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> x, C.update(i,\
    \ x);\n    }\n\n    while (q--) {\n        std::cin >> opt >> x >> v;\n      \
    \  if (opt == 0) {\n            C.update(x, v);\n        } else {\n          \
    \  std::cout << C.query(x, v - 1) << '\\n';\n        }\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/fenwick.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-fenwick.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 22:07:10+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-fenwick.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-fenwick.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-fenwick.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-fenwick.test.cpp
---
