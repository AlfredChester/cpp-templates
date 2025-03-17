---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/appear-statistics.hpp
    title: src/alfred/data_structure/appear-statistics.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/discretization.hpp
    title: src/alfred/data_structure/discretization.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    \n#line 1 \"src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\n\
    inline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL),\
    \ std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/data_structure/appear-statistics.hpp\"\
    \n\n\n\n#line 1 \"src/alfred/data_structure/discretization.hpp\"\n\n\n\n#line\
    \ 6 \"src/alfred/data_structure/discretization.hpp\"\n\ntemplate <class _Tp>\n\
    struct Mess {\n    std::vector<_Tp> v;\n    bool initialized = false;\n    inline\
    \ _Tp origin(int idx) { return v[idx - 1]; }\n    inline void insert(_Tp x) {\
    \ v.push_back(x); }\n    template <typename T, typename... V>\n    inline void\
    \ insert(T x, V... v) { insert(x), insert(v...); }\n    inline void init(void)\
    \ {\n        std::sort(v.begin(), v.end()), initialized = true;\n        v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n    }\n    inline void clear(void) { v.clear(), initialized\
    \ = false; }\n    inline int query(_Tp x) {\n        if (!initialized) init();\n\
    \        return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;\n   \
    \ }\n    inline bool exist(_Tp x) { return origin(query(x)) == x; }\n};\n\n\n\
    #line 6 \"src/alfred/data_structure/appear-statistics.hpp\"\n\ntemplate <class\
    \ T>\nclass AppearStats { // Appear Statistics.\nprivate:\n    Mess<T> M;\n  \
    \  size_t n;\n    std::vector<std::vector<int>> pos;\n\npublic:\n    AppearStats(void)\
    \ : n(0) {}\n    AppearStats(std::vector<T> &init) : n(init.size()) { _init(init);\
    \ }\n    inline void _init(std::vector<T> &init) {\n        for (auto item : init)\
    \ M.insert(item);\n        n = init.size(), M.init(), pos.resize(M.v.size());\n\
    \        for (size_t i = 0; i < n; i++) {\n            pos[M.query(init[i]) -\
    \ 1].push_back(i);\n        }\n    }\n    // Use\u300Cbase\u300Das the beginning\
    \ of index, return -1 if x doesn't exist.\n    inline int first(int l, int r,\
    \ T x, int base = 0) {\n        l -= base, r -= base;\n        if (!M.exist(x))\
    \ return -1;\n        std::vector<int> &P = pos[M.query(x) - 1];\n        auto\
    \ it = std::lower_bound(P.begin(), P.end(), l);\n        return it == P.end()\
    \ || *it > r ? -1 : *it + base;\n    }\n    // Use\u300Cbase\u300Das the beginning\
    \ of index, return -1 if x doesn't exist.\n    inline int last(int l, int r, T\
    \ x, int base = 0) {\n        l -= base, r -= base;\n        if (!M.exist(x))\
    \ return -1;\n        std::vector<int> &P = pos[M.query(x) - 1];\n        auto\
    \ it = std::upper_bound(P.begin(), P.end(), r);\n        return it == P.begin()\
    \ || *std::prev(it) < l ? -1 : *std::prev(it) + base;\n    }\n    inline int count(int\
    \ l, int r, T x, int base = 0) {\n        l -= base, r -= base;\n        if (l\
    \ > r || !M.exist(x)) return 0;\n        std::vector<int> &P = pos[M.query(x)\
    \ - 1];\n        auto L = std::lower_bound(P.begin(), P.end(), l);\n        auto\
    \ R = std::upper_bound(P.begin(), P.end(), r);\n        if (L == P.end() || R\
    \ == P.begin()) return 0;\n        if (*L > r || *std::prev(R) < l) return 0;\n\
    \        return R - L;\n    }\n};\n\n\n#line 6 \"verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp\"\
    \n\nint main(int argc, char const *argv[]) {\n    int n, q, l, r, x;\n    optimizeIO(),\
    \ std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (auto &x : a) std::cin\
    \ >> x;\n\n    AppearStats<int> A(a);\n    while (q--) {\n        std::cin >>\
    \ l >> r >> x;\n        std::cout << A.count(l, r - 1, x) << '\\n';\n    }\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/appear-statistics.hpp\"\
    \n#include <iostream>\n\nint main(int argc, char const *argv[]) {\n    int n,\
    \ q, l, r, x;\n    optimizeIO(), std::cin >> n >> q;\n    std::vector<int> a(n);\n\
    \    for (auto &x : a) std::cin >> x;\n\n    AppearStats<int> A(a);\n    while\
    \ (q--) {\n        std::cin >> l >> r >> x;\n        std::cout << A.count(l, r\
    \ - 1, x) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/appear-statistics.hpp
  - src/alfred/data_structure/discretization.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
---
