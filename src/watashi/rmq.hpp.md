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
  bundledCode: "#line 1 \"src/watashi/rmq.hpp\"\n#include <algorithm> // copy\n#include\
    \ <climits>   // CHAR_BIT\n\nusing namespace std;\n\ntemplate <typename T>\nstruct\
    \ RMQ {\n    int n;\n    vector<T> e;\n    vector<vector<int>> rmq;\n\n    static\
    \ const int INT_BIT = sizeof(4) * CHAR_BIT;\n    static inline int LG2(int i)\
    \ { return INT_BIT - 1 - __builtin_clz(i); }\n    static inline int BIN(int i)\
    \ { return 1 << i; }\n\n    int cmp(int l, int r) const {\n        return e[l]\
    \ <= e[r] ? l : r;\n    }\n\n    void init(int n, const T e[]) {\n        this->n\
    \ = n;\n        vector<T>(e, e + n).swap(this->e);\n\n        int m = 1;\n   \
    \     while (BIN(m) <= n) {\n            ++m;\n        }\n        vector<vector<int>>(m,\
    \ vector<int>(n)).swap(rmq);\n\n        for (int i = 0; i < n; ++i) {\n      \
    \      rmq[0][i] = i;\n        }\n        for (int i = 0; BIN(i + 1) <= n; ++i)\
    \ {\n            for (int j = 0; j + BIN(i + 1) <= n; ++j) {\n               \
    \ rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);\n            }\n       \
    \ }\n    }\n\n    int index(int l, int r) const {\n        int b = LG2(r - l);\n\
    \        return cmp(rmq[b][l], rmq[b][r - (1 << b)]);\n    }\n\n    T value(int\
    \ l, int r) const {\n        return e[index(l, r)];\n    }\n};\n"
  code: "#include <algorithm> // copy\n#include <climits>   // CHAR_BIT\n\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct RMQ {\n    int n;\n    vector<T> e;\n\
    \    vector<vector<int>> rmq;\n\n    static const int INT_BIT = sizeof(4) * CHAR_BIT;\n\
    \    static inline int LG2(int i) { return INT_BIT - 1 - __builtin_clz(i); }\n\
    \    static inline int BIN(int i) { return 1 << i; }\n\n    int cmp(int l, int\
    \ r) const {\n        return e[l] <= e[r] ? l : r;\n    }\n\n    void init(int\
    \ n, const T e[]) {\n        this->n = n;\n        vector<T>(e, e + n).swap(this->e);\n\
    \n        int m = 1;\n        while (BIN(m) <= n) {\n            ++m;\n      \
    \  }\n        vector<vector<int>>(m, vector<int>(n)).swap(rmq);\n\n        for\
    \ (int i = 0; i < n; ++i) {\n            rmq[0][i] = i;\n        }\n        for\
    \ (int i = 0; BIN(i + 1) <= n; ++i) {\n            for (int j = 0; j + BIN(i +\
    \ 1) <= n; ++j) {\n                rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);\n\
    \            }\n        }\n    }\n\n    int index(int l, int r) const {\n    \
    \    int b = LG2(r - l);\n        return cmp(rmq[b][l], rmq[b][r - (1 << b)]);\n\
    \    }\n\n    T value(int l, int r) const {\n        return e[index(l, r)];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/rmq.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/rmq.hpp
layout: document
redirect_from:
- /library/src/watashi/rmq.hpp
- /library/src/watashi/rmq.hpp.html
title: src/watashi/rmq.hpp
---
