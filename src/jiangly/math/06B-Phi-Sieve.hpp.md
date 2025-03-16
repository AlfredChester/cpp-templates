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
    - https://qoj.ac/submission/187055
  bundledCode: "#line 1 \"src/jiangly/math/06B-Phi-Sieve.hpp\"\n/**   \u6B27\u62C9\
    \u51FD\u6570\uFF08\u6C42\u89E3\u5168\u90E8\u6570\u7684\u6B27\u62C9\u51FD\u6570\
    \uFF09\r\n *    2023-09-24: https://qoj.ac/submission/187055\r\n **/\r\nconstexpr\
    \ int N = 1E7;\r\nconstexpr int P = 1000003;\r\n\r\nbool isprime[N + 1];\r\nint\
    \ phi[N + 1];\r\nstd::vector<int> primes;\r\n\r\nvoid sieve(void) {\r\n    std::fill(isprime\
    \ + 2, isprime + N + 1, true);\r\n    phi[1] = 1;\r\n    for (int i = 2; i <=\
    \ N; i++) {\r\n        if (isprime[i]) {\r\n            primes.push_back(i);\r\
    \n            phi[i] = i - 1;\r\n        }\r\n        for (auto p : primes) {\r\
    \n            if (i * p > N) {\r\n                break;\r\n            }\r\n\
    \            isprime[i * p] = false;\r\n            if (i % p == 0) {\r\n    \
    \            phi[i * p] = phi[i] * p;\r\n                break;\r\n          \
    \  }\r\n            phi[i * p] = phi[i] * (p - 1);\r\n        }\r\n    }\r\n}\n"
  code: "/**   \u6B27\u62C9\u51FD\u6570\uFF08\u6C42\u89E3\u5168\u90E8\u6570\u7684\u6B27\
    \u62C9\u51FD\u6570\uFF09\r\n *    2023-09-24: https://qoj.ac/submission/187055\r\
    \n **/\r\nconstexpr int N = 1E7;\r\nconstexpr int P = 1000003;\r\n\r\nbool isprime[N\
    \ + 1];\r\nint phi[N + 1];\r\nstd::vector<int> primes;\r\n\r\nvoid sieve(void)\
    \ {\r\n    std::fill(isprime + 2, isprime + N + 1, true);\r\n    phi[1] = 1;\r\
    \n    for (int i = 2; i <= N; i++) {\r\n        if (isprime[i]) {\r\n        \
    \    primes.push_back(i);\r\n            phi[i] = i - 1;\r\n        }\r\n    \
    \    for (auto p : primes) {\r\n            if (i * p > N) {\r\n             \
    \   break;\r\n            }\r\n            isprime[i * p] = false;\r\n       \
    \     if (i % p == 0) {\r\n                phi[i * p] = phi[i] * p;\r\n      \
    \          break;\r\n            }\r\n            phi[i * p] = phi[i] * (p - 1);\r\
    \n        }\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/06B-Phi-Sieve.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/06B-Phi-Sieve.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/06B-Phi-Sieve.hpp
- /library/src/jiangly/math/06B-Phi-Sieve.hpp.html
title: src/jiangly/math/06B-Phi-Sieve.hpp
---
