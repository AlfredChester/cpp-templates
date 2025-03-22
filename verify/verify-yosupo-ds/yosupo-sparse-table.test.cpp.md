---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/sparse-table.hpp
    title: src/alfred/data_structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"src/alfred/config/io-sync-off.hpp\"\
    \n#include <bits/stdc++.h>\n\ninline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(NULL), std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/data_structure/sparse-table.hpp\"\
    \n\n\n\n#line 7 \"src/alfred/data_structure/sparse-table.hpp\"\n\ntemplate <class\
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
    \      if (l > r) return T();\n        T ans = T();\n        for (int i = std::__lg(r\
    \ - l + 1); i >= 0; i--) {\n            if ((1 << i) <= r - l + 1) {\n       \
    \         ans = ans + ST[l][i];\n                l += 1 << i;\n            }\n\
    \        }\n        return ans;\n    }\n};\n\n\n#line 6 \"verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp\"\
    \n\nint n, q, l, r;\n\nint main(int argc, char const *argv[]) {\n    optimizeIO(),\
    \ std::cin >> n >> q;\n\n    std::vector<int> a(n);\n    for (auto &x : a) std::cin\
    \ >> x;\n\n    SparseTable<MinInfo<int>> ST(a);\n\n    while (q--) {\n       \
    \ std::cin >> l >> r;\n        std::cout << ST.query(l, r - 1).val << '\\n';\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/sparse-table.hpp\"\
    \n#include <iostream>\n\nint n, q, l, r;\n\nint main(int argc, char const *argv[])\
    \ {\n    optimizeIO(), std::cin >> n >> q;\n\n    std::vector<int> a(n);\n   \
    \ for (auto &x : a) std::cin >> x;\n\n    SparseTable<MinInfo<int>> ST(a);\n\n\
    \    while (q--) {\n        std::cin >> l >> r;\n        std::cout << ST.query(l,\
    \ r - 1).val << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
  requiredBy: []
  timestamp: '2025-03-22 09:26:13+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
---
