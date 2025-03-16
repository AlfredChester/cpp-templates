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
    - https://qoj.ac/submission/380047
    - https://qoj.ac/submission/384389
  bundledCode: "#line 1 \"src/jiangly/string/01A-Manacher.hpp\"\n/**   \u9A6C\u62C9\
    \u8F66\uFF08Manacher \u65E7\u7248\uFF09\r\n *    2024-04-06: https://qoj.ac/submission/380047\r\
    \n *    2024-04-09: https://qoj.ac/submission/384389 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstd::vector<int> manacher(std::string s) {\r\n    std::string t = \"\
    #\";\r\n    for (auto c : s) {\r\n        t += c;\r\n        t += '#';\r\n   \
    \ }\r\n    int n = t.size();\r\n    std::vector<int> r(n);\r\n    for (int i =\
    \ 0, j = 0; i < n; i++) {\r\n        if (2 * j - i >= 0 && j + r[j] > i) {\r\n\
    \            r[i] = std::min(r[2 * j - i], j + r[j] - i);\r\n        }\r\n   \
    \     while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {\r\n\
    \            r[i] += 1;\r\n        }\r\n        if (i + r[i] > j + r[j]) {\r\n\
    \            j = i;\r\n        }\r\n    }\r\n    return r;\r\n}\r\n\r\n"
  code: "/**   \u9A6C\u62C9\u8F66\uFF08Manacher \u65E7\u7248\uFF09\r\n *    2024-04-06:\
    \ https://qoj.ac/submission/380047\r\n *    2024-04-09: https://qoj.ac/submission/384389\
    \ \u3010\u6A21\u677F\u3011\r\n**/\r\nstd::vector<int> manacher(std::string s)\
    \ {\r\n    std::string t = \"#\";\r\n    for (auto c : s) {\r\n        t += c;\r\
    \n        t += '#';\r\n    }\r\n    int n = t.size();\r\n    std::vector<int>\
    \ r(n);\r\n    for (int i = 0, j = 0; i < n; i++) {\r\n        if (2 * j - i >=\
    \ 0 && j + r[j] > i) {\r\n            r[i] = std::min(r[2 * j - i], j + r[j] -\
    \ i);\r\n        }\r\n        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]]\
    \ == t[i + r[i]]) {\r\n            r[i] += 1;\r\n        }\r\n        if (i +\
    \ r[i] > j + r[j]) {\r\n            j = i;\r\n        }\r\n    }\r\n    return\
    \ r;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/01A-Manacher.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/01A-Manacher.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/01A-Manacher.hpp
- /library/src/jiangly/string/01A-Manacher.hpp.html
title: src/jiangly/string/01A-Manacher.hpp
---
