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
    - https://codeforces.com/contest/1874/submission/226069129
    - https://codeforces.com/contest/293/submission/228297248
    - https://qoj.ac/submission/183430
    - https://qoj.ac/submission/343317
  bundledCode: "#line 1 \"src/jiangly/others/02-Math-Func.hpp\"\nusing i64 = long\
    \ long;\r\nusing i128 = __int128;\r\n\r\n/**   \u4E0A\u53D6\u6574\u4E0B\u53D6\u6574\
    \r\n *    2023-10-15: https://codeforces.com/contest/293/submission/228297248\r\
    \n**/\r\ni64 ceilDiv(i64 n, i64 m) {\r\n    if (n >= 0) {\r\n        return (n\
    \ + m - 1) / m;\r\n    } else {\r\n        return n / m;\r\n    }\r\n}\r\n \r\n\
    i64 floorDiv(i64 n, i64 m) {\r\n    if (n >= 0) {\r\n        return n / m;\r\n\
    \    } else {\r\n        return (n - m + 1) / m;\r\n    }\r\n}\r\n\r\n/**   \u6700\
    \u5927\u503C\u8D4B\u503C\r\n *    2023-09-30: https://codeforces.com/contest/1874/submission/226069129\r\
    \n**/\r\ntemplate<class T>\r\nvoid chmax(T &a, T b) {\r\n    if (a < b) {\r\n\
    \        a = b;\r\n    }\r\n}\r\n\r\n/**   \u6700\u5927\u516C\u7EA6\u6570\r\n\
    \ *    -: -\r\n**/\r\ni128 gcd(i128 a, i128 b) {\r\n    return b ? gcd(b, a %\
    \ b) : a;\r\n}\r\n\r\n/**   \u7CBE\u786E\u5F00\u5E73\u65B9\r\n *    2024-03-02:\
    \ https://qoj.ac/submission/343317\r\n**/\r\ni64 sqrt(i64 n) {\r\n    i64 s =\
    \ std::sqrt(n);\r\n    while (s * s > n) {\r\n        s--;\r\n    }\r\n    while\
    \ ((s + 1) * (s + 1) <= n) {\r\n        s++;\r\n    }\r\n    return s;\r\n}\r\n\
    \r\n/**   \u7CBE\u786E\u5F00\u5E73\u65B9\r\n *    2023-09-19: https://qoj.ac/submission/183430\r\
    \n**/\r\ni64 get(i64 n) {\r\n    i64 u = std::sqrt(2.0L * n);\r\n    while (u\
    \ * (u + 1) / 2 < n) {\r\n        u++;\r\n    }\r\n    while (u * (u - 1) / 2\
    \ + 1 > n) {\r\n        u--;\r\n    }\r\n    return u;\r\n}\n"
  code: "using i64 = long long;\r\nusing i128 = __int128;\r\n\r\n/**   \u4E0A\u53D6\
    \u6574\u4E0B\u53D6\u6574\r\n *    2023-10-15: https://codeforces.com/contest/293/submission/228297248\r\
    \n**/\r\ni64 ceilDiv(i64 n, i64 m) {\r\n    if (n >= 0) {\r\n        return (n\
    \ + m - 1) / m;\r\n    } else {\r\n        return n / m;\r\n    }\r\n}\r\n \r\n\
    i64 floorDiv(i64 n, i64 m) {\r\n    if (n >= 0) {\r\n        return n / m;\r\n\
    \    } else {\r\n        return (n - m + 1) / m;\r\n    }\r\n}\r\n\r\n/**   \u6700\
    \u5927\u503C\u8D4B\u503C\r\n *    2023-09-30: https://codeforces.com/contest/1874/submission/226069129\r\
    \n**/\r\ntemplate<class T>\r\nvoid chmax(T &a, T b) {\r\n    if (a < b) {\r\n\
    \        a = b;\r\n    }\r\n}\r\n\r\n/**   \u6700\u5927\u516C\u7EA6\u6570\r\n\
    \ *    -: -\r\n**/\r\ni128 gcd(i128 a, i128 b) {\r\n    return b ? gcd(b, a %\
    \ b) : a;\r\n}\r\n\r\n/**   \u7CBE\u786E\u5F00\u5E73\u65B9\r\n *    2024-03-02:\
    \ https://qoj.ac/submission/343317\r\n**/\r\ni64 sqrt(i64 n) {\r\n    i64 s =\
    \ std::sqrt(n);\r\n    while (s * s > n) {\r\n        s--;\r\n    }\r\n    while\
    \ ((s + 1) * (s + 1) <= n) {\r\n        s++;\r\n    }\r\n    return s;\r\n}\r\n\
    \r\n/**   \u7CBE\u786E\u5F00\u5E73\u65B9\r\n *    2023-09-19: https://qoj.ac/submission/183430\r\
    \n**/\r\ni64 get(i64 n) {\r\n    i64 u = std::sqrt(2.0L * n);\r\n    while (u\
    \ * (u + 1) / 2 < n) {\r\n        u++;\r\n    }\r\n    while (u * (u - 1) / 2\
    \ + 1 > n) {\r\n        u--;\r\n    }\r\n    return u;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/others/02-Math-Func.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/others/02-Math-Func.hpp
layout: document
redirect_from:
- /library/src/jiangly/others/02-Math-Func.hpp
- /library/src/jiangly/others/02-Math-Func.hpp.html
title: src/jiangly/others/02-Math-Func.hpp
---
