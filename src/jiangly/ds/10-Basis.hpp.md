---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/jiangly/ds/10-Basis.hpp\"\nstruct Basis {\r\n    int\
    \ a[20] {};\r\n    int t[20] {};\r\n    \r\n    Basis() {\r\n        std::fill(t,\
    \ t + 20, -1);\r\n    }\r\n    \r\n    void add(int x, int y = 1E9) {\r\n    \
    \    for (int i = 0; i < 20; i++) {\r\n            if (x >> i & 1) {\r\n     \
    \           if (y > t[i]) {\r\n                    std::swap(a[i], x);\r\n   \
    \                 std::swap(t[i], y);\r\n                }\r\n               \
    \ x ^= a[i];\r\n            }\r\n        }\r\n    }\r\n    \r\n    bool query(int\
    \ x, int y = 0) {\r\n        for (int i = 0; i < 20; i++) {\r\n            if\
    \ ((x >> i & 1) && t[i] >= y) {\r\n                x ^= a[i];\r\n            }\r\
    \n        }\r\n        return x == 0;\r\n    }\r\n};\n"
  code: "struct Basis {\r\n    int a[20] {};\r\n    int t[20] {};\r\n    \r\n    Basis()\
    \ {\r\n        std::fill(t, t + 20, -1);\r\n    }\r\n    \r\n    void add(int\
    \ x, int y = 1E9) {\r\n        for (int i = 0; i < 20; i++) {\r\n            if\
    \ (x >> i & 1) {\r\n                if (y > t[i]) {\r\n                    std::swap(a[i],\
    \ x);\r\n                    std::swap(t[i], y);\r\n                }\r\n    \
    \            x ^= a[i];\r\n            }\r\n        }\r\n    }\r\n    \r\n   \
    \ bool query(int x, int y = 0) {\r\n        for (int i = 0; i < 20; i++) {\r\n\
    \            if ((x >> i & 1) && t[i] >= y) {\r\n                x ^= a[i];\r\n\
    \            }\r\n        }\r\n        return x == 0;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/10-Basis.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/10-Basis.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/10-Basis.hpp
- /library/src/jiangly/ds/10-Basis.hpp.html
title: src/jiangly/ds/10-Basis.hpp
---
