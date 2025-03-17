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
  bundledCode: "#line 1 \"src/alfred/data_structure/fenwick.hpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\ntemplate <class T>\nstruct Fenwick {\n    std::vector<T>\
    \ c;\n    inline int lowbit(int x) { return x & -x; }\n    inline void merge(T\
    \ &x, T &y) { x = x + y; }\n    inline T subtract(T x, T y) { return x - y; }\n\
    \    inline void update(size_t pos, T x) {\n        for (pos++; pos < c.size();\
    \ pos += lowbit(pos)) merge(c[pos], x);\n    }\n    inline void clear(void) {\n\
    \        for (auto &x : c) x = T();\n    }\n    inline T query(size_t pos) {\n\
    \        T ans = T();\n        for (pos++; pos; pos ^= lowbit(pos)) merge(ans,\
    \ c[pos]);\n        return ans;\n    }\n    inline T query(size_t l, size_t r)\
    \ {\n        return l == 0 ? query(r) : subtract(query(r), query(l - 1));\n  \
    \  }\n    inline int kth(const T k) {\n        int ans = 0;\n        for (int\
    \ i = 1 << std::__lg(c.size() - 1); i; i >>= 1) {\n            if (ans + i < (int)c.size()\
    \ && c[ans + i] <= k) {\n                k -= c[ans + i], ans += i;\n        \
    \    }\n        }\n        return ans;\n    }\n    Fenwick(size_t len) : c(len\
    \ + 2) {}\n};\n\n\n"
  code: "#ifndef AFDS_FENWICK\n#define AFDS_FENWICK\n\n#include <bits/stdc++.h>\n\n\
    template <class T>\nstruct Fenwick {\n    std::vector<T> c;\n    inline int lowbit(int\
    \ x) { return x & -x; }\n    inline void merge(T &x, T &y) { x = x + y; }\n  \
    \  inline T subtract(T x, T y) { return x - y; }\n    inline void update(size_t\
    \ pos, T x) {\n        for (pos++; pos < c.size(); pos += lowbit(pos)) merge(c[pos],\
    \ x);\n    }\n    inline void clear(void) {\n        for (auto &x : c) x = T();\n\
    \    }\n    inline T query(size_t pos) {\n        T ans = T();\n        for (pos++;\
    \ pos; pos ^= lowbit(pos)) merge(ans, c[pos]);\n        return ans;\n    }\n \
    \   inline T query(size_t l, size_t r) {\n        return l == 0 ? query(r) : subtract(query(r),\
    \ query(l - 1));\n    }\n    inline int kth(const T k) {\n        int ans = 0;\n\
    \        for (int i = 1 << std::__lg(c.size() - 1); i; i >>= 1) {\n          \
    \  if (ans + i < (int)c.size() && c[ans + i] <= k) {\n                k -= c[ans\
    \ + i], ans += i;\n            }\n        }\n        return ans;\n    }\n    Fenwick(size_t\
    \ len) : c(len + 2) {}\n};\n\n#endif // AFDS_FENWICK\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/fenwick.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/fenwick.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/fenwick.hpp
- /library/src/alfred/data_structure/fenwick.hpp.html
title: src/alfred/data_structure/fenwick.hpp
---
