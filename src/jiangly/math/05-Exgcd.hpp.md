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
    - https://qoj.ac/submission/165983
  bundledCode: "#line 1 \"src/jiangly/math/05-Exgcd.hpp\"\n/**   \u6269\u5C55\u6B27\
    \u51E0\u91CC\u5F97\uFF08exgcd\uFF09\r\n *    2023-10-09: https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\
    \n**/\r\nint exgcd(int a, int b, int &x, int &y) {\r\n    if (!b) {\r\n      \
    \  x = 1, y = 0;\r\n        return a;\r\n    }\r\n    int g = exgcd(b, a % b,\
    \ y, x);\r\n    y -= a / b * x;\r\n    return g;\r\n}\r\n\r\n/**   \u6269\u5C55\
    \u6B27\u51E0\u91CC\u5F97\uFF08exgcd\uFF09\r\n *    2023-09-05: https://qoj.ac/submission/165983\r\
    \n**/\r\nstd::array<i64, 3> exgcd(i64 a, i64 b) {\r\n    if (!b) {\r\n       \
    \ return {a, 1, 0};\r\n    }\r\n    auto [g, x, y] = exgcd(b, a % b);\r\n    return\
    \ {g, y, x - a / b * y};\r\n}\n"
  code: "/**   \u6269\u5C55\u6B27\u51E0\u91CC\u5F97\uFF08exgcd\uFF09\r\n *    2023-10-09:\
    \ https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\n**/\r\nint exgcd(int\
    \ a, int b, int &x, int &y) {\r\n    if (!b) {\r\n        x = 1, y = 0;\r\n  \
    \      return a;\r\n    }\r\n    int g = exgcd(b, a % b, y, x);\r\n    y -= a\
    \ / b * x;\r\n    return g;\r\n}\r\n\r\n/**   \u6269\u5C55\u6B27\u51E0\u91CC\u5F97\
    \uFF08exgcd\uFF09\r\n *    2023-09-05: https://qoj.ac/submission/165983\r\n**/\r\
    \nstd::array<i64, 3> exgcd(i64 a, i64 b) {\r\n    if (!b) {\r\n        return\
    \ {a, 1, 0};\r\n    }\r\n    auto [g, x, y] = exgcd(b, a % b);\r\n    return {g,\
    \ y, x - a / b * y};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/05-Exgcd.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/05-Exgcd.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/05-Exgcd.hpp
- /library/src/jiangly/math/05-Exgcd.hpp.html
title: src/jiangly/math/05-Exgcd.hpp
---
