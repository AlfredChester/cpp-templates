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
    - https://qoj.ac/submission/353771
  bundledCode: "#line 1 \"src/jiangly/math/15-Matrix.hpp\"\n/**   \u77E9\u9635\uFF08\
    Matrix\uFF09\r\n *    2024-03-14: https://qoj.ac/submission/353771\r\n**/\r\n\
    using i64 = long long;\r\nusing u64 = unsigned long long;\r\n\r\nusing Matrix\
    \ = std::array<u64, 65>;\r\n\r\nMatrix operator*(const Matrix &a, const Matrix\
    \ &b) {\r\n    Matrix c{};\r\n    for (int i = 0; i <= 64; i++) {\r\n        for\
    \ (int j = 0; j <= 64; j++) {\r\n            if (j == 64 ? i == 64 : (a[i] >>\
    \ j & 1)) {\r\n                c[i] ^= b[j];\r\n            }\r\n        }\r\n\
    \    }\r\n    return c;\r\n}\r\n\r\nu64 operator*(u64 a, const Matrix &b) {\r\n\
    \    u64 c = 0;\r\n    for (int i = 0; i <= 64; i++) {\r\n        if (i == 64\
    \ || (a >> i & 1)) {\r\n            c ^= b[i];\r\n        }\r\n    }\r\n    return\
    \ c;\r\n}\r\n\r\nMatrix readMatrix() {\r\n    int m;\r\n    std::cin >> m;\r\n\
    \r\n    Matrix f{};\r\n    for (int i = 0; i < m; i++) {\r\n        int s, o;\r\
    \n        u64 A;\r\n        std::cin >> s >> o >> A;\r\n\r\n        if (o == 0)\
    \ {\r\n            for (int j = 0; j < 64; j++) {\r\n                if (A >>\
    \ ((j + s) % 64) & 1) {\r\n                    f[64] ^= 1ULL << ((j + s) % 64);\r\
    \n                } else {\r\n                    f[j] ^= 1ULL << ((j + s) % 64);\r\
    \n                }\r\n            }\r\n        } else {\r\n            for (int\
    \ j = 0; j < 64; j++) {\r\n                if (A >> ((j + s) % 64) & 1) {\r\n\
    \                    f[j] ^= 1ULL << ((j + s) % 64);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n\r\n    u64 B;\r\n    std::cin >> B;\r\
    \n    f[64] ^= B;\r\n\r\n    return f;\r\n}\n"
  code: "/**   \u77E9\u9635\uFF08Matrix\uFF09\r\n *    2024-03-14: https://qoj.ac/submission/353771\r\
    \n**/\r\nusing i64 = long long;\r\nusing u64 = unsigned long long;\r\n\r\nusing\
    \ Matrix = std::array<u64, 65>;\r\n\r\nMatrix operator*(const Matrix &a, const\
    \ Matrix &b) {\r\n    Matrix c{};\r\n    for (int i = 0; i <= 64; i++) {\r\n \
    \       for (int j = 0; j <= 64; j++) {\r\n            if (j == 64 ? i == 64 :\
    \ (a[i] >> j & 1)) {\r\n                c[i] ^= b[j];\r\n            }\r\n   \
    \     }\r\n    }\r\n    return c;\r\n}\r\n\r\nu64 operator*(u64 a, const Matrix\
    \ &b) {\r\n    u64 c = 0;\r\n    for (int i = 0; i <= 64; i++) {\r\n        if\
    \ (i == 64 || (a >> i & 1)) {\r\n            c ^= b[i];\r\n        }\r\n    }\r\
    \n    return c;\r\n}\r\n\r\nMatrix readMatrix() {\r\n    int m;\r\n    std::cin\
    \ >> m;\r\n\r\n    Matrix f{};\r\n    for (int i = 0; i < m; i++) {\r\n      \
    \  int s, o;\r\n        u64 A;\r\n        std::cin >> s >> o >> A;\r\n\r\n   \
    \     if (o == 0) {\r\n            for (int j = 0; j < 64; j++) {\r\n        \
    \        if (A >> ((j + s) % 64) & 1) {\r\n                    f[64] ^= 1ULL <<\
    \ ((j + s) % 64);\r\n                } else {\r\n                    f[j] ^= 1ULL\
    \ << ((j + s) % 64);\r\n                }\r\n            }\r\n        } else {\r\
    \n            for (int j = 0; j < 64; j++) {\r\n                if (A >> ((j +\
    \ s) % 64) & 1) {\r\n                    f[j] ^= 1ULL << ((j + s) % 64);\r\n \
    \               }\r\n            }\r\n        }\r\n    }\r\n\r\n    u64 B;\r\n\
    \    std::cin >> B;\r\n    f[64] ^= B;\r\n\r\n    return f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/15-Matrix.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/15-Matrix.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/15-Matrix.hpp
- /library/src/jiangly/math/15-Matrix.hpp.html
title: src/jiangly/math/15-Matrix.hpp
---
