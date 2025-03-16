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
    - https://qoj.ac/submission/164128
  bundledCode: "#line 1 \"src/jiangly/math/13B-Q-Binomial.hpp\"\n/**   \u751F\u6210\
    \u51FD\u6570\uFF08q-Binomial\uFF09\r\n *    2023-09-04: https://qoj.ac/submission/164128\r\
    \n**/\r\nint power(int a, int b, int p) {\r\n    int res = 1;\r\n    for (; b;\
    \ b /= 2, a = 1LL * a * a % p) {\r\n        if (b % 2) {\r\n            res =\
    \ 1LL * res * a % p;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nint\
    \ qint(int n, int q, int p) {\r\n    return 1LL * (power(q, n, p) - 1) * power(q\
    \ - 1, p - 2, p) % p;\r\n}\r\n\r\nint qBinomial(int n, int k, int q, int p) {\r\
    \n    if (q == 0) {\r\n        return 1;\r\n    }\r\n    int r = 0;\r\n    int\
    \ x = 1;\r\n    do {\r\n        x = 1LL * x * q % p;\r\n        r++;\r\n    }\
    \ while (x != 1);\r\n    \r\n    if (n / r > k / r + (n - k) / r) {\r\n      \
    \  return 0;\r\n    }\r\n    int num = 1, den = 1;\r\n    for (int i = 1; i <=\
    \ k % r; i++) {\r\n        num = 1LL * num * qint(n % r - i + 1, q, p) % p;\r\n\
    \        den = 1LL * den * qint(i, q, p) % p;\r\n    }\r\n    n /= r, k /= r;\r\
    \n    while (n > 0 || k > 0) {\r\n        if (n % p < k % p) {\r\n           \
    \ return 0;\r\n        }\r\n        for (int i = 1; i <= k % p; i++) {\r\n   \
    \         num = 1LL * num * (n % p - i + 1) % p;\r\n            den = 1LL * den\
    \ * i % p;\r\n        }\r\n        n /= p, k /= p;\r\n    }\r\n    int ans = 1LL\
    \ * num * power(den, p - 2, p) % p;\r\n    return ans;\r\n}\n"
  code: "/**   \u751F\u6210\u51FD\u6570\uFF08q-Binomial\uFF09\r\n *    2023-09-04:\
    \ https://qoj.ac/submission/164128\r\n**/\r\nint power(int a, int b, int p) {\r\
    \n    int res = 1;\r\n    for (; b; b /= 2, a = 1LL * a * a % p) {\r\n       \
    \ if (b % 2) {\r\n            res = 1LL * res * a % p;\r\n        }\r\n    }\r\
    \n    return res;\r\n}\r\n\r\nint qint(int n, int q, int p) {\r\n    return 1LL\
    \ * (power(q, n, p) - 1) * power(q - 1, p - 2, p) % p;\r\n}\r\n\r\nint qBinomial(int\
    \ n, int k, int q, int p) {\r\n    if (q == 0) {\r\n        return 1;\r\n    }\r\
    \n    int r = 0;\r\n    int x = 1;\r\n    do {\r\n        x = 1LL * x * q % p;\r\
    \n        r++;\r\n    } while (x != 1);\r\n    \r\n    if (n / r > k / r + (n\
    \ - k) / r) {\r\n        return 0;\r\n    }\r\n    int num = 1, den = 1;\r\n \
    \   for (int i = 1; i <= k % r; i++) {\r\n        num = 1LL * num * qint(n % r\
    \ - i + 1, q, p) % p;\r\n        den = 1LL * den * qint(i, q, p) % p;\r\n    }\r\
    \n    n /= r, k /= r;\r\n    while (n > 0 || k > 0) {\r\n        if (n % p < k\
    \ % p) {\r\n            return 0;\r\n        }\r\n        for (int i = 1; i <=\
    \ k % p; i++) {\r\n            num = 1LL * num * (n % p - i + 1) % p;\r\n    \
    \        den = 1LL * den * i % p;\r\n        }\r\n        n /= p, k /= p;\r\n\
    \    }\r\n    int ans = 1LL * num * power(den, p - 2, p) % p;\r\n    return ans;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/13B-Q-Binomial.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/13B-Q-Binomial.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/13B-Q-Binomial.hpp
- /library/src/jiangly/math/13B-Q-Binomial.hpp.html
title: src/jiangly/math/13B-Q-Binomial.hpp
---
