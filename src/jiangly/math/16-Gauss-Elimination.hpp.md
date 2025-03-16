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
    - https://www.codechef.com/viewsolution/39942900
  bundledCode: "#line 1 \"src/jiangly/math/16-Gauss-Elimination.hpp\"\n/**   \u9AD8\
    \u65AF\u6D88\u5143\uFF08guess\uFF09\u3010\u4E45\u8FDC\u3011\n *    2020-12-02:\
    \ https://www.codechef.com/viewsolution/39942900\n **/\nstd::vector<double> gauss(std::vector<std::vector<double>>\
    \ a, std::vector<double> b) {\n    int n = a.size();\n    for (int i = 0; i <\
    \ n; ++i) {\n        double x = a[i][i];\n        for (int j = i; j < n; ++j)\
    \ a[i][j] /= x;\n        b[i] /= x;\n        for (int j = 0; j < n; ++j) {\n \
    \           if (i == j) continue;\n            x = a[j][i];\n            for (int\
    \ k = i; k < n; ++k) a[j][k] -= a[i][k] * x;\n            b[j] -= b[i] * x;\n\
    \        }\n    }\n    return b;\n}\n"
  code: "/**   \u9AD8\u65AF\u6D88\u5143\uFF08guess\uFF09\u3010\u4E45\u8FDC\u3011\n\
    \ *    2020-12-02: https://www.codechef.com/viewsolution/39942900\n **/\nstd::vector<double>\
    \ gauss(std::vector<std::vector<double>> a, std::vector<double> b) {\n    int\
    \ n = a.size();\n    for (int i = 0; i < n; ++i) {\n        double x = a[i][i];\n\
    \        for (int j = i; j < n; ++j) a[i][j] /= x;\n        b[i] /= x;\n     \
    \   for (int j = 0; j < n; ++j) {\n            if (i == j) continue;\n       \
    \     x = a[j][i];\n            for (int k = i; k < n; ++k) a[j][k] -= a[i][k]\
    \ * x;\n            b[j] -= b[i] * x;\n        }\n    }\n    return b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/16-Gauss-Elimination.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/16-Gauss-Elimination.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/16-Gauss-Elimination.hpp
- /library/src/jiangly/math/16-Gauss-Elimination.hpp.html
title: src/jiangly/math/16-Gauss-Elimination.hpp
---
