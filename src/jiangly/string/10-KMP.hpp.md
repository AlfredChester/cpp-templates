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
    - https://qoj.ac/submission/253754
    - https://qoj.ac/submission/384408
  bundledCode: "#line 1 \"src/jiangly/string/10-KMP.hpp\"\n/**   \u524D\u7F00\u51FD\
    \u6570\uFF08KMP\uFF09\r\n *    2023-11-17: https://qoj.ac/submission/253754\r\n\
    \ *    2024-04-09: https://qoj.ac/submission/384408 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstd::vector<int> kmp(std::string s) {\r\n    int n = s.size();\r\n  \
    \  std::vector<int> f(n + 1);\r\n    for (int i = 1, j = 0; i < n; i++) {\r\n\
    \        while (j && s[i] != s[j]) {\r\n            j = f[j];\r\n        }\r\n\
    \        j += (s[i] == s[j]);\r\n        f[i + 1] = j;\r\n    }\r\n    return\
    \ f;\r\n}\n"
  code: "/**   \u524D\u7F00\u51FD\u6570\uFF08KMP\uFF09\r\n *    2023-11-17: https://qoj.ac/submission/253754\r\
    \n *    2024-04-09: https://qoj.ac/submission/384408 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstd::vector<int> kmp(std::string s) {\r\n    int n = s.size();\r\n  \
    \  std::vector<int> f(n + 1);\r\n    for (int i = 1, j = 0; i < n; i++) {\r\n\
    \        while (j && s[i] != s[j]) {\r\n            j = f[j];\r\n        }\r\n\
    \        j += (s[i] == s[j]);\r\n        f[i + 1] = j;\r\n    }\r\n    return\
    \ f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/10-KMP.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/10-KMP.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/10-KMP.hpp
- /library/src/jiangly/string/10-KMP.hpp.html
title: src/jiangly/string/10-KMP.hpp
---
