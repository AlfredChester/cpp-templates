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
  bundledCode: "#line 1 \"src/jiangly/string/01B-Manacher.hpp\"\nstd::vector<int>\
    \ manacher(std::vector<int> s) {\r\n    std::vector<int> t{0};\r\n    for (auto\
    \ c : s) {\r\n        t.push_back(c);\r\n        t.push_back(0);\r\n    }\r\n\
    \    int n = t.size();\r\n    std::vector<int> r(n);\r\n    for (int i = 0, j\
    \ = 0; i < n; i++) {\r\n        if (2 * j - i >= 0 && j + r[j] > i) {\r\n    \
    \        r[i] = std::min(r[2 * j - i], j + r[j] - i);\r\n        }\r\n       \
    \ while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {\r\n  \
    \          r[i] += 1;\r\n        }\r\n        if (i + r[i] > j + r[j]) {\r\n \
    \           j = i;\r\n        }\r\n    }\r\n    return r;\r\n}\r\n"
  code: "std::vector<int> manacher(std::vector<int> s) {\r\n    std::vector<int> t{0};\r\
    \n    for (auto c : s) {\r\n        t.push_back(c);\r\n        t.push_back(0);\r\
    \n    }\r\n    int n = t.size();\r\n    std::vector<int> r(n);\r\n    for (int\
    \ i = 0, j = 0; i < n; i++) {\r\n        if (2 * j - i >= 0 && j + r[j] > i) {\r\
    \n            r[i] = std::min(r[2 * j - i], j + r[j] - i);\r\n        }\r\n  \
    \      while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {\r\
    \n            r[i] += 1;\r\n        }\r\n        if (i + r[i] > j + r[j]) {\r\n\
    \            j = i;\r\n        }\r\n    }\r\n    return r;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/01B-Manacher.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/01B-Manacher.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/01B-Manacher.hpp
- /library/src/jiangly/string/01B-Manacher.hpp.html
title: src/jiangly/string/01B-Manacher.hpp
---
