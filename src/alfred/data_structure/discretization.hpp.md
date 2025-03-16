---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/appear-statistics.hpp
    title: src/alfred/data_structure/appear-statistics.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/alfred/data_structure/discretization.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\ntemplate <class _Tp>\nstruct Mess {\n    std::vector<_Tp>\
    \ v;\n    bool initialized = false;\n    inline _Tp origin(int idx) { return v[idx\
    \ - 1]; }\n    inline void insert(_Tp x) { v.push_back(x); }\n    template <typename\
    \ T, typename... V>\n    inline void insert(T x, V... v) { insert(x), insert(v...);\
    \ }\n    inline void init(void) {\n        sort(v.begin(), v.end()), initialized\
    \ = true;\n        v.erase(unique(v.begin(), v.end()), v.end());\n    }\n    inline\
    \ void clear(void) { v.clear(), initialized = false; }\n    inline int query(_Tp\
    \ x) {\n        if (!initialized) init();\n        return lower_bound(v.begin(),\
    \ v.end(), x) - v.begin() + 1;\n    }\n    inline bool exist(_Tp x) { return origin(query(x))\
    \ == x; }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\ntemplate <class _Tp>\nstruct\
    \ Mess {\n    std::vector<_Tp> v;\n    bool initialized = false;\n    inline _Tp\
    \ origin(int idx) { return v[idx - 1]; }\n    inline void insert(_Tp x) { v.push_back(x);\
    \ }\n    template <typename T, typename... V>\n    inline void insert(T x, V...\
    \ v) { insert(x), insert(v...); }\n    inline void init(void) {\n        sort(v.begin(),\
    \ v.end()), initialized = true;\n        v.erase(unique(v.begin(), v.end()), v.end());\n\
    \    }\n    inline void clear(void) { v.clear(), initialized = false; }\n    inline\
    \ int query(_Tp x) {\n        if (!initialized) init();\n        return lower_bound(v.begin(),\
    \ v.end(), x) - v.begin() + 1;\n    }\n    inline bool exist(_Tp x) { return origin(query(x))\
    \ == x; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/discretization.hpp
  requiredBy:
  - src/alfred/data_structure/appear-statistics.hpp
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-range-frequency.test.cpp
documentation_of: src/alfred/data_structure/discretization.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/discretization.hpp
- /library/src/alfred/data_structure/discretization.hpp.html
title: src/alfred/data_structure/discretization.hpp
---
