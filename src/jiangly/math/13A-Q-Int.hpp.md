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
    - https://qoj.ac/submission/163986
  bundledCode: "#line 1 \"src/jiangly/math/13A-Q-Int.hpp\"\n/**   \u751F\u6210\u51FD\
    \u6570\uFF08q-int\uFF09\r\n *    2023-09-04: https://qoj.ac/submission/163986\r\
    \n**/\r\nusing i64 = long long;\r\nusing i128 = __int128;\r\n\r\ni64 power(i64\
    \ a, i64 b, i64 p) {\r\n    i64 res = 1;\r\n    for (; b; b /= 2, a = i128(a)\
    \ * a % p) {\r\n        if (b % 2) {\r\n            res = i128(res) * a % p;\r\
    \n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nstd::pair<int, int> qint(int\
    \ q, int n, int p) {\r\n    q %= p;\r\n    for (int x = 2; x * x <= n; x++) {\r\
    \n        if (n % x == 0) {\r\n            auto [v1, e1] = qint(q, x, p);\r\n\
    \            auto [v2, e2] = qint(power(q, x, p), n / x, p);\r\n            return\
    \ {1LL * v1 * v2 % p, e1 + e2};\r\n        }\r\n    }\r\n    if (q == 1) {\r\n\
    \        if (n == p) {\r\n            return {0, 1};\r\n        }\r\n        return\
    \ {n, 0};\r\n    }\r\n    // std::cerr << q << \" \" << n << \" \" << p << \"\\\
    n\";\r\n    i64 v = 1 - power(q, n, 1LL * p * p);\r\n    if (v < 0) {\r\n    \
    \    v += 1LL * p * p;\r\n    }\r\n    assert(v != 0);\r\n    int inv = power(1\
    \ - q + p, p - 2, p);\r\n    if (v % p == 0) {\r\n        return {(v / p) * inv\
    \ % p, 1};\r\n    } else {\r\n        return {v % p * inv % p, 0};\r\n    }\r\n\
    }\n"
  code: "/**   \u751F\u6210\u51FD\u6570\uFF08q-int\uFF09\r\n *    2023-09-04: https://qoj.ac/submission/163986\r\
    \n**/\r\nusing i64 = long long;\r\nusing i128 = __int128;\r\n\r\ni64 power(i64\
    \ a, i64 b, i64 p) {\r\n    i64 res = 1;\r\n    for (; b; b /= 2, a = i128(a)\
    \ * a % p) {\r\n        if (b % 2) {\r\n            res = i128(res) * a % p;\r\
    \n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nstd::pair<int, int> qint(int\
    \ q, int n, int p) {\r\n    q %= p;\r\n    for (int x = 2; x * x <= n; x++) {\r\
    \n        if (n % x == 0) {\r\n            auto [v1, e1] = qint(q, x, p);\r\n\
    \            auto [v2, e2] = qint(power(q, x, p), n / x, p);\r\n            return\
    \ {1LL * v1 * v2 % p, e1 + e2};\r\n        }\r\n    }\r\n    if (q == 1) {\r\n\
    \        if (n == p) {\r\n            return {0, 1};\r\n        }\r\n        return\
    \ {n, 0};\r\n    }\r\n    // std::cerr << q << \" \" << n << \" \" << p << \"\\\
    n\";\r\n    i64 v = 1 - power(q, n, 1LL * p * p);\r\n    if (v < 0) {\r\n    \
    \    v += 1LL * p * p;\r\n    }\r\n    assert(v != 0);\r\n    int inv = power(1\
    \ - q + p, p - 2, p);\r\n    if (v % p == 0) {\r\n        return {(v / p) * inv\
    \ % p, 1};\r\n    } else {\r\n        return {v % p * inv % p, 0};\r\n    }\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/13A-Q-Int.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/13A-Q-Int.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/13A-Q-Int.hpp
- /library/src/jiangly/math/13A-Q-Int.hpp.html
title: src/jiangly/math/13A-Q-Int.hpp
---
