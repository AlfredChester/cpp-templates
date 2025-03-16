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
    - https://qoj.ac/submission/203196
    - https://qoj.ac/submission/353877
  bundledCode: "#line 1 \"src/jiangly/math/07A-Comb.hpp\"\n/**   \u7EC4\u5408\u6570\
    \uFF08\u5C0F\u8303\u56F4\u9884\u5904\u7406\uFF0C\u9006\u5143+\u6768\u8F89\u4E09\
    \u89D2\uFF09\r\n *    2024-03-14: https://qoj.ac/submission/353877\r\n *    2023-10-06:\
    \ https://qoj.ac/submission/203196\r\n**/\r\nconstexpr int P = 1000000007;\r\n\
    constexpr int L = 10000;\r\n\r\nint fac[L + 1], invfac[L + 1];\r\nint sumbinom[L\
    \ + 1][7];\r\n\r\nint binom(int n, int m) {\r\n    if (n < m || m < 0) {\r\n \
    \       return 0;\r\n    }\r\n    return 1LL * fac[n] * invfac[m] % P * invfac[n\
    \ - m] % P;\r\n}\r\n\r\nint power(int a, int b) {\r\n    int res = 1;\r\n    for\
    \ (; b; b /= 2, a = 1LL * a * a % P) {\r\n        if (b % 2) {\r\n           \
    \ res = 1LL * res * a % P;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\
    \nint main() {\r\n    fac[0] = 1;\r\n    for (int i = 1; i <= L; i++) {\r\n  \
    \      fac[i] = 1LL * fac[i - 1] * i % P;\r\n    }\r\n    invfac[L] = power(fac[L],\
    \ P - 2);\r\n    for (int i = L; i; i--) {\r\n        invfac[i - 1] = 1LL * invfac[i]\
    \ * i % P;\r\n    }\r\n\r\n    sumbinom[0][0] = 1;\r\n    for (int i = 1; i <=\
    \ L; i++) {\r\n        for (int j = 0; j < 7; j++) {\r\n            sumbinom[i][j]\
    \ = (sumbinom[i - 1][j] + sumbinom[i - 1][(j + 6) % 7]) % P;\r\n        }\r\n\
    \    }\r\n}\n"
  code: "/**   \u7EC4\u5408\u6570\uFF08\u5C0F\u8303\u56F4\u9884\u5904\u7406\uFF0C\u9006\
    \u5143+\u6768\u8F89\u4E09\u89D2\uFF09\r\n *    2024-03-14: https://qoj.ac/submission/353877\r\
    \n *    2023-10-06: https://qoj.ac/submission/203196\r\n**/\r\nconstexpr int P\
    \ = 1000000007;\r\nconstexpr int L = 10000;\r\n\r\nint fac[L + 1], invfac[L +\
    \ 1];\r\nint sumbinom[L + 1][7];\r\n\r\nint binom(int n, int m) {\r\n    if (n\
    \ < m || m < 0) {\r\n        return 0;\r\n    }\r\n    return 1LL * fac[n] * invfac[m]\
    \ % P * invfac[n - m] % P;\r\n}\r\n\r\nint power(int a, int b) {\r\n    int res\
    \ = 1;\r\n    for (; b; b /= 2, a = 1LL * a * a % P) {\r\n        if (b % 2) {\r\
    \n            res = 1LL * res * a % P;\r\n        }\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nint main() {\r\n    fac[0] = 1;\r\n    for (int i = 1; i <= L; i++)\
    \ {\r\n        fac[i] = 1LL * fac[i - 1] * i % P;\r\n    }\r\n    invfac[L] =\
    \ power(fac[L], P - 2);\r\n    for (int i = L; i; i--) {\r\n        invfac[i -\
    \ 1] = 1LL * invfac[i] * i % P;\r\n    }\r\n\r\n    sumbinom[0][0] = 1;\r\n  \
    \  for (int i = 1; i <= L; i++) {\r\n        for (int j = 0; j < 7; j++) {\r\n\
    \            sumbinom[i][j] = (sumbinom[i - 1][j] + sumbinom[i - 1][(j + 6) %\
    \ 7]) % P;\r\n        }\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/07A-Comb.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/07A-Comb.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/07A-Comb.hpp
- /library/src/jiangly/math/07A-Comb.hpp.html
title: src/jiangly/math/07A-Comb.hpp
---
