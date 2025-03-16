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
    - https://qoj.ac/submission/350298
  bundledCode: "#line 1 \"src/jiangly/math/12C-Poly.hpp\"\n/**   \u591A\u9879\u5F0F\
    \u4E58\u6CD5\r\n *    2024-03-10: https://qoj.ac/submission/350298\r\n**/\r\n\
    constexpr int P = 998244353;\r\n\r\nint power(int a, int b) {\r\n    int res =\
    \ 1;\r\n    for (; b; b /= 2, a = 1LL * a * a % P) {\r\n        if (b % 2) {\r\
    \n            res = 1LL * res * a % P;\r\n        }\r\n    }\r\n    return res;\r\
    \n}\r\n\r\nstd::vector<int> rev, roots {0, 1};\r\n\r\nvoid dft(std::vector<int>\
    \ &a) {\r\n    int n = a.size();\r\n    if (int(rev.size()) != n) {\r\n      \
    \  int k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\r\
    \n        }\r\n    }\r\n    for (int i = 0; i < n; i++) {\r\n        if (rev[i]\
    \ < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n        }\r\n    }\r\n\
    \    if (roots.size() < n) {\r\n        int k = __builtin_ctz(roots.size());\r\
    \n        roots.resize(n);\r\n        while ((1 << k) < n) {\r\n            int\
    \ e = power(31, 1 << (__builtin_ctz(P - 1) - k - 1));\r\n            for (int\
    \ i = 1 << (k - 1); i < (1 << k); i++) {\r\n                roots[2 * i] = roots[i];\r\
    \n                roots[2 * i + 1] = 1LL * roots[i] * e % P;\r\n            }\r\
    \n            k++;\r\n        }\r\n    }\r\n\r\n    for (int k = 1; k < n; k *=\
    \ 2) {\r\n        for (int i = 0; i < n; i += 2 * k) {\r\n            for (int\
    \ j = 0; j < k; j++) {\r\n                int u = a[i + j];\r\n              \
    \  int v = 1LL * a[i + j + k] * roots[k + j] % P;\r\n                a[i + j]\
    \ = (u + v) % P;\r\n                a[i + j + k] = (u - v) % P;\r\n          \
    \  }\r\n        }\r\n    }\r\n}\r\n\r\nvoid idft(std::vector<int> &a) {\r\n  \
    \  int n = a.size();\r\n    std::reverse(a.begin() + 1, a.end());\r\n    dft(a);\r\
    \n    int inv = (1 - P) / n;\r\n    for (int i = 0; i < n; i++) {\r\n        a[i]\
    \ = 1LL * a[i] * inv % P;\r\n    }\r\n}\r\n\r\nstd::vector<int> mul(std::vector<int>\
    \ a, std::vector<int> b) {\r\n    int n = 1, tot = a.size() + b.size() - 1;\r\n\
    \    while (n < tot) {\r\n        n *= 2;\r\n    }\r\n    if (tot < 128) {\r\n\
    \        std::vector<int> c(a.size() + b.size() - 1);\r\n        for (int i =\
    \ 0; i < a.size(); i++) {\r\n            for (int j = 0; j < b.size(); j++) {\r\
    \n                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;\r\n         \
    \   }\r\n        }\r\n        return c;\r\n    }\r\n    a.resize(n);\r\n    b.resize(n);\r\
    \n    dft(a);\r\n    dft(b);\r\n    for (int i = 0; i < n; i++) {\r\n        a[i]\
    \ = 1LL * a[i] * b[i] % P;\r\n    }\r\n    idft(a);\r\n    a.resize(tot);\r\n\
    \    return a;\r\n}\n"
  code: "/**   \u591A\u9879\u5F0F\u4E58\u6CD5\r\n *    2024-03-10: https://qoj.ac/submission/350298\r\
    \n**/\r\nconstexpr int P = 998244353;\r\n\r\nint power(int a, int b) {\r\n   \
    \ int res = 1;\r\n    for (; b; b /= 2, a = 1LL * a * a % P) {\r\n        if (b\
    \ % 2) {\r\n            res = 1LL * res * a % P;\r\n        }\r\n    }\r\n   \
    \ return res;\r\n}\r\n\r\nstd::vector<int> rev, roots {0, 1};\r\n\r\nvoid dft(std::vector<int>\
    \ &a) {\r\n    int n = a.size();\r\n    if (int(rev.size()) != n) {\r\n      \
    \  int k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\r\
    \n        }\r\n    }\r\n    for (int i = 0; i < n; i++) {\r\n        if (rev[i]\
    \ < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n        }\r\n    }\r\n\
    \    if (roots.size() < n) {\r\n        int k = __builtin_ctz(roots.size());\r\
    \n        roots.resize(n);\r\n        while ((1 << k) < n) {\r\n            int\
    \ e = power(31, 1 << (__builtin_ctz(P - 1) - k - 1));\r\n            for (int\
    \ i = 1 << (k - 1); i < (1 << k); i++) {\r\n                roots[2 * i] = roots[i];\r\
    \n                roots[2 * i + 1] = 1LL * roots[i] * e % P;\r\n            }\r\
    \n            k++;\r\n        }\r\n    }\r\n\r\n    for (int k = 1; k < n; k *=\
    \ 2) {\r\n        for (int i = 0; i < n; i += 2 * k) {\r\n            for (int\
    \ j = 0; j < k; j++) {\r\n                int u = a[i + j];\r\n              \
    \  int v = 1LL * a[i + j + k] * roots[k + j] % P;\r\n                a[i + j]\
    \ = (u + v) % P;\r\n                a[i + j + k] = (u - v) % P;\r\n          \
    \  }\r\n        }\r\n    }\r\n}\r\n\r\nvoid idft(std::vector<int> &a) {\r\n  \
    \  int n = a.size();\r\n    std::reverse(a.begin() + 1, a.end());\r\n    dft(a);\r\
    \n    int inv = (1 - P) / n;\r\n    for (int i = 0; i < n; i++) {\r\n        a[i]\
    \ = 1LL * a[i] * inv % P;\r\n    }\r\n}\r\n\r\nstd::vector<int> mul(std::vector<int>\
    \ a, std::vector<int> b) {\r\n    int n = 1, tot = a.size() + b.size() - 1;\r\n\
    \    while (n < tot) {\r\n        n *= 2;\r\n    }\r\n    if (tot < 128) {\r\n\
    \        std::vector<int> c(a.size() + b.size() - 1);\r\n        for (int i =\
    \ 0; i < a.size(); i++) {\r\n            for (int j = 0; j < b.size(); j++) {\r\
    \n                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;\r\n         \
    \   }\r\n        }\r\n        return c;\r\n    }\r\n    a.resize(n);\r\n    b.resize(n);\r\
    \n    dft(a);\r\n    dft(b);\r\n    for (int i = 0; i < n; i++) {\r\n        a[i]\
    \ = 1LL * a[i] * b[i] % P;\r\n    }\r\n    idft(a);\r\n    a.resize(tot);\r\n\
    \    return a;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/12C-Poly.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/12C-Poly.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/12C-Poly.hpp
- /library/src/jiangly/math/12C-Poly.hpp.html
title: src/jiangly/math/12C-Poly.hpp
---
