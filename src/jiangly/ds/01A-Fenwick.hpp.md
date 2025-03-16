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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63382128
  bundledCode: "#line 1 \"src/jiangly/ds/01A-Fenwick.hpp\"\n/**   \u6811\u72B6\u6570\
    \u7EC4\uFF08Fenwick \u65E7\u7248\uFF09\r\n *    2023-08-11: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63382128\r\
    \n**/\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n    int n;\r\n    std::vector<T>\
    \ a;\r\n    \r\n    Fenwick(int n = 0) {\r\n        init(n);\r\n    }\r\n    \r\
    \n    void init(int n) {\r\n        this->n = n;\r\n        a.assign(n, T());\r\
    \n    }\r\n    \r\n    void add(int x, T v) {\r\n        for (int i = x + 1; i\
    \ <= n; i += i & -i) {\r\n            a[i - 1] += v;\r\n        }\r\n    }\r\n\
    \    \r\n    T sum(int x) {\r\n        auto ans = T();\r\n        for (int i =\
    \ x; i > 0; i -= i & -i) {\r\n            ans += a[i - 1];\r\n        }\r\n  \
    \      return ans;\r\n    }\r\n    \r\n    T rangeSum(int l, int r) {\r\n    \
    \    return sum(r) - sum(l);\r\n    }\r\n    \r\n    int kth(T k) {\r\n      \
    \  int x = 0;\r\n        for (int i = 1 << std::__lg(n); i; i /= 2) {\r\n    \
    \        if (x + i <= n && k >= a[x + i - 1]) {\r\n                x += i;\r\n\
    \                k -= a[x - 1];\r\n            }\r\n        }\r\n        return\
    \ x;\r\n    }\r\n};\n"
  code: "/**   \u6811\u72B6\u6570\u7EC4\uFF08Fenwick \u65E7\u7248\uFF09\r\n *    2023-08-11:\
    \ https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63382128\r\n\
    **/\r\ntemplate <typename T>\r\nstruct Fenwick {\r\n    int n;\r\n    std::vector<T>\
    \ a;\r\n    \r\n    Fenwick(int n = 0) {\r\n        init(n);\r\n    }\r\n    \r\
    \n    void init(int n) {\r\n        this->n = n;\r\n        a.assign(n, T());\r\
    \n    }\r\n    \r\n    void add(int x, T v) {\r\n        for (int i = x + 1; i\
    \ <= n; i += i & -i) {\r\n            a[i - 1] += v;\r\n        }\r\n    }\r\n\
    \    \r\n    T sum(int x) {\r\n        auto ans = T();\r\n        for (int i =\
    \ x; i > 0; i -= i & -i) {\r\n            ans += a[i - 1];\r\n        }\r\n  \
    \      return ans;\r\n    }\r\n    \r\n    T rangeSum(int l, int r) {\r\n    \
    \    return sum(r) - sum(l);\r\n    }\r\n    \r\n    int kth(T k) {\r\n      \
    \  int x = 0;\r\n        for (int i = 1 << std::__lg(n); i; i /= 2) {\r\n    \
    \        if (x + i <= n && k >= a[x + i - 1]) {\r\n                x += i;\r\n\
    \                k -= a[x - 1];\r\n            }\r\n        }\r\n        return\
    \ x;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/01A-Fenwick.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/01A-Fenwick.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/01A-Fenwick.hpp
- /library/src/jiangly/ds/01A-Fenwick.hpp.html
title: src/jiangly/ds/01A-Fenwick.hpp
---
