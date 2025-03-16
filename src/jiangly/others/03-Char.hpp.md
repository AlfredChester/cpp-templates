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
    - https://qoj.ac/submission/355156
  bundledCode: "#line 1 \"src/jiangly/others/03-Char.hpp\"\n/**   \u5927\u5C0F\u5199\
    \u8F6C\u6362\u3001\u83B7\u53D6\u5B57\u6BCD\u5E8F\r\n *    2024-03-16: https://qoj.ac/submission/355156\r\
    \n**/\r\nvoid rev(std::string &s) {\r\n    int l = s.size();\r\n    for (int i\
    \ = 1; i < l; i += 2) {\r\n        if (std::isupper(s[i])) {\r\n            s[i]\
    \ = std::tolower(s[i]);\r\n        } else {\r\n            s[i] = std::toupper(s[i]);\r\
    \n        }\r\n    }\r\n}\r\n\r\nint get(char c) {\r\n    int x;\r\n    if (std::islower(c))\
    \ {\r\n        x = c - 'a';\r\n    } else {\r\n        x = 26 + c - 'A';\r\n \
    \   }\r\n    return x;\r\n}\n"
  code: "/**   \u5927\u5C0F\u5199\u8F6C\u6362\u3001\u83B7\u53D6\u5B57\u6BCD\u5E8F\r\
    \n *    2024-03-16: https://qoj.ac/submission/355156\r\n**/\r\nvoid rev(std::string\
    \ &s) {\r\n    int l = s.size();\r\n    for (int i = 1; i < l; i += 2) {\r\n \
    \       if (std::isupper(s[i])) {\r\n            s[i] = std::tolower(s[i]);\r\n\
    \        } else {\r\n            s[i] = std::toupper(s[i]);\r\n        }\r\n \
    \   }\r\n}\r\n\r\nint get(char c) {\r\n    int x;\r\n    if (std::islower(c))\
    \ {\r\n        x = c - 'a';\r\n    } else {\r\n        x = 26 + c - 'A';\r\n \
    \   }\r\n    return x;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/others/03-Char.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/others/03-Char.hpp
layout: document
redirect_from:
- /library/src/jiangly/others/03-Char.hpp
- /library/src/jiangly/others/03-Char.hpp.html
title: src/jiangly/others/03-Char.hpp
---
