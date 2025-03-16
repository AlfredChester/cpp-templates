---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1915/submission/239262801
  bundledCode: "#line 1 \"src/jiangly/ds/01B-Fenwick.hpp\"\n/**   \u6811\u72B6\u6570\
    \u7EC4\uFF08Fenwick \u65B0\u7248\uFF09\r\n *    2023-12-28: https://codeforces.com/contest/1915/submission/239262801\r\
    \n**/\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n    int n;\r\n    std::vector<T>\
    \ a;\r\n    \r\n    Fenwick(int n_ = 0) {\r\n        init(n_);\r\n    }\r\n  \
    \  \r\n    void init(int n_) {\r\n        n = n_;\r\n        a.assign(n, T{});\r\
    \n    }\r\n    \r\n    void add(int x, const T &v) {\r\n        for (int i = x\
    \ + 1; i <= n; i += i & -i) {\r\n            a[i - 1] = a[i - 1] + v;\r\n    \
    \    }\r\n    }\r\n    \r\n    T sum(int x) {\r\n        T ans{};\r\n        for\
    \ (int i = x; i > 0; i -= i & -i) {\r\n            ans = ans + a[i - 1];\r\n \
    \       }\r\n        return ans;\r\n    }\r\n    \r\n    T rangeSum(int l, int\
    \ r) {\r\n        return sum(r) - sum(l);\r\n    }\r\n    \r\n    int select(const\
    \ T &k) {\r\n        int x = 0;\r\n        T cur{};\r\n        for (int i = 1\
    \ << std::__lg(n); i; i /= 2) {\r\n            if (x + i <= n && cur + a[x + i\
    \ - 1] <= k) {\r\n                x += i;\r\n                cur = cur + a[x -\
    \ 1];\r\n            }\r\n        }\r\n        return x;\r\n    }\r\n};\n"
  code: "/**   \u6811\u72B6\u6570\u7EC4\uFF08Fenwick \u65B0\u7248\uFF09\r\n *    2023-12-28:\
    \ https://codeforces.com/contest/1915/submission/239262801\r\n**/\r\ntemplate\
    \ <typename T>\r\nstruct Fenwick {\r\n    int n;\r\n    std::vector<T> a;\r\n\
    \    \r\n    Fenwick(int n_ = 0) {\r\n        init(n_);\r\n    }\r\n    \r\n \
    \   void init(int n_) {\r\n        n = n_;\r\n        a.assign(n, T{});\r\n  \
    \  }\r\n    \r\n    void add(int x, const T &v) {\r\n        for (int i = x +\
    \ 1; i <= n; i += i & -i) {\r\n            a[i - 1] = a[i - 1] + v;\r\n      \
    \  }\r\n    }\r\n    \r\n    T sum(int x) {\r\n        T ans{};\r\n        for\
    \ (int i = x; i > 0; i -= i & -i) {\r\n            ans = ans + a[i - 1];\r\n \
    \       }\r\n        return ans;\r\n    }\r\n    \r\n    T rangeSum(int l, int\
    \ r) {\r\n        return sum(r) - sum(l);\r\n    }\r\n    \r\n    int select(const\
    \ T &k) {\r\n        int x = 0;\r\n        T cur{};\r\n        for (int i = 1\
    \ << std::__lg(n); i; i /= 2) {\r\n            if (x + i <= n && cur + a[x + i\
    \ - 1] <= k) {\r\n                x += i;\r\n                cur = cur + a[x -\
    \ 1];\r\n            }\r\n        }\r\n        return x;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/01B-Fenwick.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/01B-Fenwick.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/01B-Fenwick.hpp
- /library/src/jiangly/ds/01B-Fenwick.hpp.html
title: src/jiangly/ds/01B-Fenwick.hpp
---
