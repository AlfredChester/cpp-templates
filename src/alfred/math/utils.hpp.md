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
  bundledCode: "#line 1 \"src/alfred/math/utils.hpp\"\n\n\n\n// O(sqrt(x)) to judge\
    \ if x is a prime.\n// It will be re-written in Miller-rabin sometime.\nconstexpr\
    \ bool is_prime(long long x) {\n    if (x < 2) return false;\n    for (long long\
    \ i = 2; i * i <= x; i++) {\n        if (x % i == 0) return false;\n    }\n  \
    \  return true;\n}\n\ntemplate <class T>\ninline T gcd(T a, T b) {\n    return\
    \ b == 0 ? a : gcd(b, a % b);\n}\n\ntemplate <class T>\ninline T lcm(T a, T b)\
    \ {\n    return a / gcd(a, b) * b;\n}\n\n\n"
  code: "#ifndef AFMT_PRIME\n#define AFMT_PRIME\n\n// O(sqrt(x)) to judge if x is\
    \ a prime.\n// It will be re-written in Miller-rabin sometime.\nconstexpr bool\
    \ is_prime(long long x) {\n    if (x < 2) return false;\n    for (long long i\
    \ = 2; i * i <= x; i++) {\n        if (x % i == 0) return false;\n    }\n    return\
    \ true;\n}\n\ntemplate <class T>\ninline T gcd(T a, T b) {\n    return b == 0\
    \ ? a : gcd(b, a % b);\n}\n\ntemplate <class T>\ninline T lcm(T a, T b) {\n  \
    \  return a / gcd(a, b) * b;\n}\n\n#endif // AFMT_PRIME\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/math/utils.hpp
  requiredBy:
  - src/alfred/math/speed-of-light-power.hpp
  timestamp: '2025-03-22 17:56:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/utils.hpp
layout: document
redirect_from:
- /library/src/alfred/math/utils.hpp
- /library/src/alfred/math/utils.hpp.html
title: src/alfred/math/utils.hpp
---
