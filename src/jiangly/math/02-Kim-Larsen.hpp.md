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
    - https://qoj.ac/submission/164735
  bundledCode: "#line 1 \"src/jiangly/math/02-Kim-Larsen.hpp\"\n/**   \u57FA\u59C6\
    \u62C9\u5C14\u68EE\u516C\u5F0F\r\n *    2023-09-05: https://qoj.ac/submission/164735\r\
    \n**/\r\nconst int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};\r\n\
    \r\nbool isLeap(int y) {\r\n    return y % 400 == 0 || (y % 4 == 0 && y % 100\
    \ != 0);\r\n}\r\n\r\nint daysInMonth(int y, int m) {\r\n    return d[m - 1] +\
    \ (isLeap(y) && m == 2);\r\n}\r\n\r\nint getDay(int y, int m, int d) {\r\n   \
    \ int ans = 0;\r\n    for (int i = 1970; i < y; i++) {\r\n        ans += 365 +\
    \ isLeap(i);\r\n    }\r\n    for (int i = 1; i < m; i++) {\r\n        ans += daysInMonth(y,\
    \ i);\r\n    }\r\n    ans += d;\r\n    return (ans + 2) % 7 + 1;\r\n}\n"
  code: "/**   \u57FA\u59C6\u62C9\u5C14\u68EE\u516C\u5F0F\r\n *    2023-09-05: https://qoj.ac/submission/164735\r\
    \n**/\r\nconst int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};\r\n\
    \r\nbool isLeap(int y) {\r\n    return y % 400 == 0 || (y % 4 == 0 && y % 100\
    \ != 0);\r\n}\r\n\r\nint daysInMonth(int y, int m) {\r\n    return d[m - 1] +\
    \ (isLeap(y) && m == 2);\r\n}\r\n\r\nint getDay(int y, int m, int d) {\r\n   \
    \ int ans = 0;\r\n    for (int i = 1970; i < y; i++) {\r\n        ans += 365 +\
    \ isLeap(i);\r\n    }\r\n    for (int i = 1; i < m; i++) {\r\n        ans += daysInMonth(y,\
    \ i);\r\n    }\r\n    ans += d;\r\n    return (ans + 2) % 7 + 1;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/02-Kim-Larsen.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/02-Kim-Larsen.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/02-Kim-Larsen.hpp
- /library/src/jiangly/math/02-Kim-Larsen.hpp.html
title: src/jiangly/math/02-Kim-Larsen.hpp
---
