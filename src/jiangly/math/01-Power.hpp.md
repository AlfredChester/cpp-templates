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
    - https://atcoder.jp/contests/tenka1-2017/submissions/46411797
    - https://qoj.ac/submission/189343
  bundledCode: "#line 1 \"src/jiangly/math/01-Power.hpp\"\n/**   \u5FEB\u901F\u5E42\
    \ - \u666E\u901A\u7248\r\n *    2023-10-09: https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\
    \n**/\r\nint power(int a, i64 b, int p) {\r\n    int res = 1;\r\n    for (; b;\
    \ b /= 2, a = 1LL * a * a % p) {\r\n        if (b % 2) {\r\n            res =\
    \ 1LL * res * a % p;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\
    \   \u5FEB\u901F\u5E42 - \u624B\u5199\u4E58\u6CD5\r\n *    2023-09-27: https://qoj.ac/submission/189343\r\
    \n**/\r\nusing i64 = long long;\r\n\r\ni64 mul(i64 a, i64 b, i64 p) {\r\n    i64\
    \ c = a * b - i64(1.0L * a * b / p) * p;\r\n    c %= p;\r\n    if (c < 0) {\r\n\
    \        c += p;\r\n    }\r\n    return c;\r\n}\r\n\r\ni64 power(i64 a, i64 b,\
    \ i64 p) {\r\n    i64 res = 1;\r\n    for (; b; b /= 2, a = mul(a, a, p)) {\r\n\
    \        if (b % 2) {\r\n            res = mul(res, a, p);\r\n        }\r\n  \
    \  }\r\n    return res;\r\n}\n"
  code: "/**   \u5FEB\u901F\u5E42 - \u666E\u901A\u7248\r\n *    2023-10-09: https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\
    \n**/\r\nint power(int a, i64 b, int p) {\r\n    int res = 1;\r\n    for (; b;\
    \ b /= 2, a = 1LL * a * a % p) {\r\n        if (b % 2) {\r\n            res =\
    \ 1LL * res * a % p;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\n/**\
    \   \u5FEB\u901F\u5E42 - \u624B\u5199\u4E58\u6CD5\r\n *    2023-09-27: https://qoj.ac/submission/189343\r\
    \n**/\r\nusing i64 = long long;\r\n\r\ni64 mul(i64 a, i64 b, i64 p) {\r\n    i64\
    \ c = a * b - i64(1.0L * a * b / p) * p;\r\n    c %= p;\r\n    if (c < 0) {\r\n\
    \        c += p;\r\n    }\r\n    return c;\r\n}\r\n\r\ni64 power(i64 a, i64 b,\
    \ i64 p) {\r\n    i64 res = 1;\r\n    for (; b; b /= 2, a = mul(a, a, p)) {\r\n\
    \        if (b % 2) {\r\n            res = mul(res, a, p);\r\n        }\r\n  \
    \  }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/01-Power.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/01-Power.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/01-Power.hpp
- /library/src/jiangly/math/01-Power.hpp.html
title: src/jiangly/math/01-Power.hpp
---
