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
    - https://atcoder.jp/contests/tupc2022/submissions/39391116
  bundledCode: "#line 1 \"src/jiangly/math/04-Mu-Sieve.hpp\"\n/**   \u83AB\u6BD4\u4E4C\
    \u65AF\u51FD\u6570\u7B5B\uFF08\u83AB\u6BD4\u4E4C\u65AF\u51FD\u6570/\u53CD\u6F14\
    \uFF09\r\n *    2023-03-04: https://atcoder.jp/contests/tupc2022/submissions/39391116\r\
    \n**/\r\nstd::unordered_map<int, Z> fMu;\r\n\r\nconstexpr int N = 1E7;\r\nstd::vector<int>\
    \ minp, primes;\r\nstd::vector<Z> mu;\r\n\r\nvoid sieve(int n) {\r\n    minp.assign(n\
    \ + 1, 0);\r\n    mu.resize(n);\r\n    primes.clear();\r\n    \r\n    mu[1] =\
    \ 1;\r\n    for (int i = 2; i <= n; i++) {\r\n        if (minp[i] == 0) {\r\n\
    \            mu[i] = -1;\r\n            minp[i] = i;\r\n            primes.push_back(i);\r\
    \n        }\r\n        \r\n        for (auto p : primes) {\r\n            if (i\
    \ * p > n) {\r\n                break;\r\n            }\r\n            minp[i\
    \ * p] = p;\r\n            if (p == minp[i]) {\r\n                break;\r\n \
    \           }\r\n            mu[i * p] = -mu[i];\r\n        }\r\n    }\r\n   \
    \ \r\n    for (int i = 1; i <= n; i++) {\r\n        mu[i] += mu[i - 1];\r\n  \
    \  }\r\n}\r\n\r\nZ sumMu(int n) {\r\n    if (n <= N) {\r\n        return mu[n];\r\
    \n    }\r\n    if (fMu.count(n)) {\r\n        return fMu[n];\r\n    }\r\n    if\
    \ (n == 0) {\r\n        return 0;\r\n    }\r\n    Z ans = 1;\r\n    for (int l\
    \ = 2, r; l <= n; l = r + 1) {\r\n        r = n / (n / l);\r\n        ans -= (r\
    \ - l + 1) * sumMu(n / l);\r\n    }\r\n    return ans;\r\n}\n"
  code: "/**   \u83AB\u6BD4\u4E4C\u65AF\u51FD\u6570\u7B5B\uFF08\u83AB\u6BD4\u4E4C\u65AF\
    \u51FD\u6570/\u53CD\u6F14\uFF09\r\n *    2023-03-04: https://atcoder.jp/contests/tupc2022/submissions/39391116\r\
    \n**/\r\nstd::unordered_map<int, Z> fMu;\r\n\r\nconstexpr int N = 1E7;\r\nstd::vector<int>\
    \ minp, primes;\r\nstd::vector<Z> mu;\r\n\r\nvoid sieve(int n) {\r\n    minp.assign(n\
    \ + 1, 0);\r\n    mu.resize(n);\r\n    primes.clear();\r\n    \r\n    mu[1] =\
    \ 1;\r\n    for (int i = 2; i <= n; i++) {\r\n        if (minp[i] == 0) {\r\n\
    \            mu[i] = -1;\r\n            minp[i] = i;\r\n            primes.push_back(i);\r\
    \n        }\r\n        \r\n        for (auto p : primes) {\r\n            if (i\
    \ * p > n) {\r\n                break;\r\n            }\r\n            minp[i\
    \ * p] = p;\r\n            if (p == minp[i]) {\r\n                break;\r\n \
    \           }\r\n            mu[i * p] = -mu[i];\r\n        }\r\n    }\r\n   \
    \ \r\n    for (int i = 1; i <= n; i++) {\r\n        mu[i] += mu[i - 1];\r\n  \
    \  }\r\n}\r\n\r\nZ sumMu(int n) {\r\n    if (n <= N) {\r\n        return mu[n];\r\
    \n    }\r\n    if (fMu.count(n)) {\r\n        return fMu[n];\r\n    }\r\n    if\
    \ (n == 0) {\r\n        return 0;\r\n    }\r\n    Z ans = 1;\r\n    for (int l\
    \ = 2, r; l <= n; l = r + 1) {\r\n        r = n / (n / l);\r\n        ans -= (r\
    \ - l + 1) * sumMu(n / l);\r\n    }\r\n    return ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/04-Mu-Sieve.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/04-Mu-Sieve.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/04-Mu-Sieve.hpp
- /library/src/jiangly/math/04-Mu-Sieve.hpp.html
title: src/jiangly/math/04-Mu-Sieve.hpp
---
