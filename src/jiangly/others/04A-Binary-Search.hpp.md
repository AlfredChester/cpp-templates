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
    - https://qoj.ac/submission/182628
    - https://qoj.ac/submission/182752
  bundledCode: "#line 1 \"src/jiangly/others/04A-Binary-Search.hpp\"\n/**   \u4E8C\
    \u5206\u7B97\u6CD5\uFF08\u6574\u6570\u57DF\uFF09\uFF1A \u524D\u9A71\r\n *    2023-09-18:\
    \ https://qoj.ac/submission/182628\r\n**/\r\nint lo = 1, hi = 1E9;\r\nwhile (lo\
    \ < hi) {\r\n    int m = (lo + hi + 1) / 2;\r\n    if (check(m)) {\r\n       \
    \ lo = m;\r\n    } else {\r\n        hi = m - 1;\r\n    }\r\n}\r\nstd::cout <<\
    \ lo << \"\\n\";\r\n\r\n/**   \u4E8C\u5206\u7B97\u6CD5\uFF08\u6574\u6570\u57DF\
    \uFF09\uFF1A\u540E\u7EE7\r\n *    2023-09-18: https://qoj.ac/submission/182752\r\
    \n**/\r\nint lo = 1, hi = n;\r\nwhile (lo < hi) {\r\n    int m = (lo + hi) / 2;\r\
    \n    if (check(m)) {\r\n        hi = m;\r\n    } else {\r\n        lo = m + 1;\r\
    \n    }\r\n}\r\nstd::cout << lo << \"\\n\";\n"
  code: "/**   \u4E8C\u5206\u7B97\u6CD5\uFF08\u6574\u6570\u57DF\uFF09\uFF1A \u524D\
    \u9A71\r\n *    2023-09-18: https://qoj.ac/submission/182628\r\n**/\r\nint lo\
    \ = 1, hi = 1E9;\r\nwhile (lo < hi) {\r\n    int m = (lo + hi + 1) / 2;\r\n  \
    \  if (check(m)) {\r\n        lo = m;\r\n    } else {\r\n        hi = m - 1;\r\
    \n    }\r\n}\r\nstd::cout << lo << \"\\n\";\r\n\r\n/**   \u4E8C\u5206\u7B97\u6CD5\
    \uFF08\u6574\u6570\u57DF\uFF09\uFF1A\u540E\u7EE7\r\n *    2023-09-18: https://qoj.ac/submission/182752\r\
    \n**/\r\nint lo = 1, hi = n;\r\nwhile (lo < hi) {\r\n    int m = (lo + hi) / 2;\r\
    \n    if (check(m)) {\r\n        hi = m;\r\n    } else {\r\n        lo = m + 1;\r\
    \n    }\r\n}\r\nstd::cout << lo << \"\\n\";"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/others/04A-Binary-Search.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/others/04A-Binary-Search.hpp
layout: document
redirect_from:
- /library/src/jiangly/others/04A-Binary-Search.hpp
- /library/src/jiangly/others/04A-Binary-Search.hpp.html
title: src/jiangly/others/04A-Binary-Search.hpp
---
