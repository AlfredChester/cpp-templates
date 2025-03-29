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
  bundledCode: "#line 1 \"src/alfred/data_structure/sum.hpp\"\n\n\n\n#include <numeric>\n\
    #include <vector>\n\ntemplate <class T>\nclass Sum {\nprivate:\n    int n;\n \
    \   std::vector<T> _pre, _suf;\n\npublic:\n    Sum(void) : n(0) {}\n    template\
    \ <class InitT>\n    Sum(std::vector<InitT> &_init) { init(_init); }\n    template\
    \ <class InitT>\n    inline void init(std::vector<InitT> &_init) {\n        if\
    \ (_init.empty()) return;\n        _pre.resize(n = _init.size()), _suf.resize(n);\n\
    \        _pre[0] = _init[0], _suf[n - 1] = _init[n - 1];\n        for (int i =\
    \ 1; i < n; i++) {\n            _pre[i] = _pre[i - 1] + _init[i];\n        }\n\
    \        for (int i = n - 2; i >= 0; i--) {\n            _suf[i] = _suf[i + 1]\
    \ + _init[i];\n        }\n    }\n    inline T query(int l, int r) {\n        if\
    \ (l > r) return T();\n        return l == 0 ? _pre[r] : _pre[r] - _pre[l - 1];\n\
    \    }\n    inline const T pre(int x) { return _pre[x]; }\n    inline const T\
    \ suf(int x) { return _suf[x]; }\n};\n\ntemplate <class T>\nclass GridSum {\n\
    private:\n    size_t n, m;\n    std::vector<std::vector<T>> sum;\n\npublic:\n\
    \    GridSum(void) : n(0), m(0) {}\n    template <class InitT>\n    GridSum(std::vector<std::vector<InitT>>\
    \ &_init) { init(_init); }\n    template <class InitT>\n    inline void init(std::vector<std::vector<InitT>>\
    \ &_init) {\n        if (_init.empty()) return;\n        n = _init.size(), m =\
    \ _init[0].size();\n        sum.assign(n, std::vector<T>(m)), sum[0][0] = _init[0][0];\n\
    \        for (size_t i = 1; i < n; i++) {\n            sum[i][0] = sum[i - 1][0]\
    \ + _init[i][0];\n        }\n        for (size_t i = 1; i < m; i++) {\n      \
    \      sum[0][i] = sum[0][i - 1] + _init[0][i];\n        }\n        for (size_t\
    \ i = 1; i < n; i++) {\n            for (size_t j = 1; j < m; j++) {\n       \
    \         sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + _init[i][j];\n\
    \            }\n        }\n    }\n    inline T query(int x1, int y1, int x2, int\
    \ y2) {\n        T s1 = x1 == 0 ? 0 : sum[x1 - 1][y2];\n        T s2 = y1 == 0\
    \ ? 0 : sum[x2][y1 - 1];\n        T s3 = x1 == 0 || y1 == 0 ? 0 : sum[x1 - 1][y1\
    \ - 1];\n        return sum[x2][y2] - s1 - s2 + s3;\n    }\n};\n\ntemplate <class\
    \ T>\nclass SubsetSum {\nprivate:\n    int n;\n    std::vector<T> sum;\n\npublic:\n\
    \    SubsetSum(void) : n(0) {}\n    template <class InitT>\n    SubsetSum(std::vector<InitT>\
    \ &_init)\n        : n(_init.size()), sum(_init) { init(_init, true); }\n    template\
    \ <class InitT>\n    inline void init(std::vector<InitT> &_init, bool internal\
    \ = false) {\n        if (!internal) {\n            n = _init.size(), sum = _init;\n\
    \        }\n        for (int i = 0; (1 << i) <= n; i++) {\n            for (int\
    \ S = 0; S < n; S++) {\n                if (S >> i & 1) sum[S] += sum[S ^ (1 <<\
    \ i)];\n            }\n        }\n    }\n    inline T query(int mask) { return\
    \ sum[mask]; }\n};\n\n\n"
  code: "#ifndef AFDS_SUM\n#define AFDS_SUM\n\n#include <numeric>\n#include <vector>\n\
    \ntemplate <class T>\nclass Sum {\nprivate:\n    int n;\n    std::vector<T> _pre,\
    \ _suf;\n\npublic:\n    Sum(void) : n(0) {}\n    template <class InitT>\n    Sum(std::vector<InitT>\
    \ &_init) { init(_init); }\n    template <class InitT>\n    inline void init(std::vector<InitT>\
    \ &_init) {\n        if (_init.empty()) return;\n        _pre.resize(n = _init.size()),\
    \ _suf.resize(n);\n        _pre[0] = _init[0], _suf[n - 1] = _init[n - 1];\n \
    \       for (int i = 1; i < n; i++) {\n            _pre[i] = _pre[i - 1] + _init[i];\n\
    \        }\n        for (int i = n - 2; i >= 0; i--) {\n            _suf[i] =\
    \ _suf[i + 1] + _init[i];\n        }\n    }\n    inline T query(int l, int r)\
    \ {\n        if (l > r) return T();\n        return l == 0 ? _pre[r] : _pre[r]\
    \ - _pre[l - 1];\n    }\n    inline const T pre(int x) { return _pre[x]; }\n \
    \   inline const T suf(int x) { return _suf[x]; }\n};\n\ntemplate <class T>\n\
    class GridSum {\nprivate:\n    size_t n, m;\n    std::vector<std::vector<T>> sum;\n\
    \npublic:\n    GridSum(void) : n(0), m(0) {}\n    template <class InitT>\n   \
    \ GridSum(std::vector<std::vector<InitT>> &_init) { init(_init); }\n    template\
    \ <class InitT>\n    inline void init(std::vector<std::vector<InitT>> &_init)\
    \ {\n        if (_init.empty()) return;\n        n = _init.size(), m = _init[0].size();\n\
    \        sum.assign(n, std::vector<T>(m)), sum[0][0] = _init[0][0];\n        for\
    \ (size_t i = 1; i < n; i++) {\n            sum[i][0] = sum[i - 1][0] + _init[i][0];\n\
    \        }\n        for (size_t i = 1; i < m; i++) {\n            sum[0][i] =\
    \ sum[0][i - 1] + _init[0][i];\n        }\n        for (size_t i = 1; i < n; i++)\
    \ {\n            for (size_t j = 1; j < m; j++) {\n                sum[i][j] =\
    \ sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + _init[i][j];\n         \
    \   }\n        }\n    }\n    inline T query(int x1, int y1, int x2, int y2) {\n\
    \        T s1 = x1 == 0 ? 0 : sum[x1 - 1][y2];\n        T s2 = y1 == 0 ? 0 : sum[x2][y1\
    \ - 1];\n        T s3 = x1 == 0 || y1 == 0 ? 0 : sum[x1 - 1][y1 - 1];\n      \
    \  return sum[x2][y2] - s1 - s2 + s3;\n    }\n};\n\ntemplate <class T>\nclass\
    \ SubsetSum {\nprivate:\n    int n;\n    std::vector<T> sum;\n\npublic:\n    SubsetSum(void)\
    \ : n(0) {}\n    template <class InitT>\n    SubsetSum(std::vector<InitT> &_init)\n\
    \        : n(_init.size()), sum(_init) { init(_init, true); }\n    template <class\
    \ InitT>\n    inline void init(std::vector<InitT> &_init, bool internal = false)\
    \ {\n        if (!internal) {\n            n = _init.size(), sum = _init;\n  \
    \      }\n        for (int i = 0; (1 << i) <= n; i++) {\n            for (int\
    \ S = 0; S < n; S++) {\n                if (S >> i & 1) sum[S] += sum[S ^ (1 <<\
    \ i)];\n            }\n        }\n    }\n    inline T query(int mask) { return\
    \ sum[mask]; }\n};\n\n#endif // AFDS_SUM\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/sum.hpp
  requiredBy: []
  timestamp: '2025-03-29 12:06:08+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-static-sum.test.cpp
documentation_of: src/alfred/data_structure/sum.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/sum.hpp
- /library/src/alfred/data_structure/sum.hpp.html
title: src/alfred/data_structure/sum.hpp
---
