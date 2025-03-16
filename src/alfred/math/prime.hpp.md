---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/alfred/math/speed-of-light-power.hpp
    title: src/alfred/math/speed-of-light-power.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/alfred/math/prime.hpp\"\n\n// O(sqrt(x)) to judge if\
    \ x is a prime.\n// It will be re-written in Miller-rabin sometime.\nconstexpr\
    \ bool is_prime(long long x) {\n    if (x < 2) return false;\n    for (long long\
    \ i = 2; i * i <= x; i++) {\n        if (x % i == 0) return false;\n    }\n  \
    \  return true;\n}\n"
  code: "#pragma once\n\n// O(sqrt(x)) to judge if x is a prime.\n// It will be re-written\
    \ in Miller-rabin sometime.\nconstexpr bool is_prime(long long x) {\n    if (x\
    \ < 2) return false;\n    for (long long i = 2; i * i <= x; i++) {\n        if\
    \ (x % i == 0) return false;\n    }\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/math/prime.hpp
  requiredBy:
  - src/alfred/math/speed-of-light-power.hpp
  timestamp: '2025-02-28 18:44:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/prime.hpp
layout: document
redirect_from:
- /library/src/alfred/math/prime.hpp
- /library/src/alfred/math/prime.hpp.html
title: src/alfred/math/prime.hpp
---
