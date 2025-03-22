---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/alfred/graph/lca.hpp
    title: src/alfred/graph/lca.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/string/suffix-array.hpp
    title: src/alfred/string/suffix-array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aizu-string/aizu-suffix-array.test.cpp
    title: verify/verify-aizu-string/aizu-suffix-array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
    title: verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/data_structure/sparse-table.hpp\"\n\n\n\n#include\
    \ <limits>\n#include <numeric>\n#include <vector>\n\ntemplate <class T>\nstruct\
    \ MaxInfo {\n    T val;\n    MaxInfo(void) { val = std::numeric_limits<T>::min();\
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
    \        }\n        return ans;\n    }\n};\n\n\n"
  code: "#ifndef AFDS_SPARSE_TABLE\n#define AFDS_SPARSE_TABLE\n\n#include <limits>\n\
    #include <numeric>\n#include <vector>\n\ntemplate <class T>\nstruct MaxInfo {\n\
    \    T val;\n    MaxInfo(void) { val = std::numeric_limits<T>::min(); }\n    template\
    \ <class InitT>\n    MaxInfo(InitT x) { val = x; }\n    MaxInfo operator+(MaxInfo\
    \ &x) {\n        return {std::max(val, x.val)};\n    }\n};\ntemplate <class T>\n\
    struct MinInfo {\n    T val;\n    MinInfo(void) { val = std::numeric_limits<T>::max();\
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
    \        }\n        return ans;\n    }\n};\n\n#endif // AFDS_SPARSE_TABLE\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/sparse-table.hpp
  requiredBy:
  - src/alfred/string/suffix-array.hpp
  - src/alfred/graph/lca.hpp
  timestamp: '2025-03-22 09:26:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aizu-string/aizu-suffix-array.test.cpp
  - verify/verify-yosupo-ds/yosupo-sparse-table.test.cpp
documentation_of: src/alfred/data_structure/sparse-table.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/sparse-table.hpp
- /library/src/alfred/data_structure/sparse-table.hpp.html
title: src/alfred/data_structure/sparse-table.hpp
---
