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
    - https://qoj.ac/submission/176420
  bundledCode: "#line 1 \"src/jiangly/ds/143-BigInt.hpp\"\n/**   \u9AD8\u7CBE\u5EA6\
    \uFF08BigInt\uFF09\r\n *    2023-09-11: https://qoj.ac/submission/176420\r\n**/\r\
    \nconstexpr int N = 1000;\r\n\r\nstruct BigInt {\r\n    int a[N];\r\n    BigInt(int\
    \ x = 0) : a{} {\r\n        for (int i = 0; x; i++) {\r\n            a[i] = x\
    \ % 10;\r\n            x /= 10;\r\n        }\r\n    }\r\n    BigInt &operator*=(int\
    \ x) {\r\n        for (int i = 0; i < N; i++) {\r\n            a[i] *= x;\r\n\
    \        }\r\n        for (int i = 0; i < N - 1; i++) {\r\n            a[i + 1]\
    \ += a[i] / 10;\r\n            a[i] %= 10;\r\n        }\r\n        return *this;\r\
    \n    }\r\n    BigInt &operator/=(int x) {\r\n        for (int i = N - 1; i >=\
    \ 0; i--) {\r\n            if (i) {\r\n                a[i - 1] += a[i] % x *\
    \ 10;\r\n            }\r\n            a[i] /= x;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n    BigInt &operator+=(const BigInt &x) {\r\n        for\
    \ (int i = 0; i < N; i++) {\r\n            a[i] += x.a[i];\r\n            if (a[i]\
    \ >= 10) {\r\n                a[i + 1] += 1;\r\n                a[i] -= 10;\r\n\
    \            }\r\n        }\r\n        return *this;\r\n    }\r\n};\r\n\r\nstd::ostream\
    \ &operator<<(std::ostream &o, const BigInt &a) {\r\n    int t = N - 1;\r\n  \
    \  while (a.a[t] == 0) {\r\n        t--;\r\n    }\r\n    for (int i = t; i >=\
    \ 0; i--) {\r\n        o << a.a[i];\r\n    }\r\n    return o;\r\n}\n"
  code: "/**   \u9AD8\u7CBE\u5EA6\uFF08BigInt\uFF09\r\n *    2023-09-11: https://qoj.ac/submission/176420\r\
    \n**/\r\nconstexpr int N = 1000;\r\n\r\nstruct BigInt {\r\n    int a[N];\r\n \
    \   BigInt(int x = 0) : a{} {\r\n        for (int i = 0; x; i++) {\r\n       \
    \     a[i] = x % 10;\r\n            x /= 10;\r\n        }\r\n    }\r\n    BigInt\
    \ &operator*=(int x) {\r\n        for (int i = 0; i < N; i++) {\r\n          \
    \  a[i] *= x;\r\n        }\r\n        for (int i = 0; i < N - 1; i++) {\r\n  \
    \          a[i + 1] += a[i] / 10;\r\n            a[i] %= 10;\r\n        }\r\n\
    \        return *this;\r\n    }\r\n    BigInt &operator/=(int x) {\r\n       \
    \ for (int i = N - 1; i >= 0; i--) {\r\n            if (i) {\r\n             \
    \   a[i - 1] += a[i] % x * 10;\r\n            }\r\n            a[i] /= x;\r\n\
    \        }\r\n        return *this;\r\n    }\r\n    BigInt &operator+=(const BigInt\
    \ &x) {\r\n        for (int i = 0; i < N; i++) {\r\n            a[i] += x.a[i];\r\
    \n            if (a[i] >= 10) {\r\n                a[i + 1] += 1;\r\n        \
    \        a[i] -= 10;\r\n            }\r\n        }\r\n        return *this;\r\n\
    \    }\r\n};\r\n\r\nstd::ostream &operator<<(std::ostream &o, const BigInt &a)\
    \ {\r\n    int t = N - 1;\r\n    while (a.a[t] == 0) {\r\n        t--;\r\n   \
    \ }\r\n    for (int i = t; i >= 0; i--) {\r\n        o << a.a[i];\r\n    }\r\n\
    \    return o;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/143-BigInt.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/143-BigInt.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/143-BigInt.hpp
- /library/src/jiangly/ds/143-BigInt.hpp.html
title: src/jiangly/ds/143-BigInt.hpp
---
