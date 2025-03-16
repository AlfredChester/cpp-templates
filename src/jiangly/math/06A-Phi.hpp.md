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
    - https://atcoder.jp/contests/tenka1-2017/submissions/46411797
  bundledCode: "#line 1 \"src/jiangly/math/06A-Phi.hpp\"\n/**   \u6B27\u62C9\u51FD\
    \u6570\uFF08\u6C42\u89E3\u5355\u4E2A\u6570\u7684\u6B27\u62C9\u51FD\u6570\uFF09\
    \r\n *    2023-10-09: https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\
    \n**/\r\nint phi(int n) {\r\n    int res = n;\r\n    for (int i = 2; i * i <=\
    \ n; i++) {\r\n        if (n % i == 0) {\r\n            while (n % i == 0) {\r\
    \n                n /= i;\r\n            }\r\n            res = res / i * (i -\
    \ 1);\r\n        }\r\n    }\r\n    if (n > 1) {\r\n        res = res / n * (n\
    \ - 1);\r\n    }\r\n    return res;\r\n}\n"
  code: "/**   \u6B27\u62C9\u51FD\u6570\uFF08\u6C42\u89E3\u5355\u4E2A\u6570\u7684\u6B27\
    \u62C9\u51FD\u6570\uFF09\r\n *    2023-10-09: https://atcoder.jp/contests/tenka1-2017/submissions/46411797\r\
    \n**/\r\nint phi(int n) {\r\n    int res = n;\r\n    for (int i = 2; i * i <=\
    \ n; i++) {\r\n        if (n % i == 0) {\r\n            while (n % i == 0) {\r\
    \n                n /= i;\r\n            }\r\n            res = res / i * (i -\
    \ 1);\r\n        }\r\n    }\r\n    if (n > 1) {\r\n        res = res / n * (n\
    \ - 1);\r\n    }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/06A-Phi.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/06A-Phi.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/06A-Phi.hpp
- /library/src/jiangly/math/06A-Phi.hpp.html
title: src/jiangly/math/06A-Phi.hpp
---
