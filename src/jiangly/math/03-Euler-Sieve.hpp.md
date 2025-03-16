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
    - https://qoj.ac/submission/251234
  bundledCode: "#line 1 \"src/jiangly/math/03-Euler-Sieve.hpp\"\n/**   \u6B27\u62C9\
    \u7B5B\r\n *    2023-11-14: https://qoj.ac/submission/251234\r\n**/\r\nstd::vector<int>\
    \ minp, primes;\r\n\r\nvoid sieve(int n) {\r\n    minp.assign(n + 1, 0);\r\n \
    \   primes.clear();\r\n    \r\n    for (int i = 2; i <= n; i++) {\r\n        if\
    \ (minp[i] == 0) {\r\n            minp[i] = i;\r\n            primes.push_back(i);\r\
    \n        }\r\n        \r\n        for (auto p : primes) {\r\n            if (i\
    \ * p > n) {\r\n                break;\r\n            }\r\n            minp[i\
    \ * p] = p;\r\n            if (p == minp[i]) {\r\n                break;\r\n \
    \           }\r\n        }\r\n    }\r\n}\r\n\r\nbool isprime(int n) {\r\n    return\
    \ minp[n] == n;\r\n}\n"
  code: "/**   \u6B27\u62C9\u7B5B\r\n *    2023-11-14: https://qoj.ac/submission/251234\r\
    \n**/\r\nstd::vector<int> minp, primes;\r\n\r\nvoid sieve(int n) {\r\n    minp.assign(n\
    \ + 1, 0);\r\n    primes.clear();\r\n    \r\n    for (int i = 2; i <= n; i++)\
    \ {\r\n        if (minp[i] == 0) {\r\n            minp[i] = i;\r\n           \
    \ primes.push_back(i);\r\n        }\r\n        \r\n        for (auto p : primes)\
    \ {\r\n            if (i * p > n) {\r\n                break;\r\n            }\r\
    \n            minp[i * p] = p;\r\n            if (p == minp[i]) {\r\n        \
    \        break;\r\n            }\r\n        }\r\n    }\r\n}\r\n\r\nbool isprime(int\
    \ n) {\r\n    return minp[n] == n;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/03-Euler-Sieve.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/03-Euler-Sieve.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/03-Euler-Sieve.hpp
- /library/src/jiangly/math/03-Euler-Sieve.hpp.html
title: src/jiangly/math/03-Euler-Sieve.hpp
---
