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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63378373
    - https://qoj.ac/submission/384405
  bundledCode: "#line 1 \"src/jiangly/string/02-Z-Func.hpp\"\n/**   Z\u51FD\u6570\r\
    \n *    2023-08-11: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63378373\r\
    \n *    2024-04-09: https://qoj.ac/submission/384405 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstd::vector<int> Z(std::string s) {\r\n    int n = s.size();\r\n    std::vector<int>\
    \ z(n + 1);\r\n    z[0] = n;\r\n    for (int i = 1, j = 1; i < n; i++) {\r\n \
    \       z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));\r\n        while\
    \ (i + z[i] < n && s[z[i]] == s[i + z[i]]) {\r\n            z[i]++;\r\n      \
    \  }\r\n        if (i + z[i] > j + z[j]) {\r\n            j = i;\r\n        }\r\
    \n    }\r\n    return z;\r\n}\r\n\r\n"
  code: "/**   Z\u51FD\u6570\r\n *    2023-08-11: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63378373\r\
    \n *    2024-04-09: https://qoj.ac/submission/384405 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstd::vector<int> Z(std::string s) {\r\n    int n = s.size();\r\n    std::vector<int>\
    \ z(n + 1);\r\n    z[0] = n;\r\n    for (int i = 1, j = 1; i < n; i++) {\r\n \
    \       z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));\r\n        while\
    \ (i + z[i] < n && s[z[i]] == s[i + z[i]]) {\r\n            z[i]++;\r\n      \
    \  }\r\n        if (i + z[i] > j + z[j]) {\r\n            j = i;\r\n        }\r\
    \n    }\r\n    return z;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/02-Z-Func.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/02-Z-Func.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/02-Z-Func.hpp
- /library/src/jiangly/string/02-Z-Func.hpp.html
title: src/jiangly/string/02-Z-Func.hpp
---
