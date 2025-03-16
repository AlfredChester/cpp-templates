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
    - https://qoj.ac/submission/161388
  bundledCode: "#line 1 \"src/jiangly/math/14-Simpson.hpp\"\n/**   \u81EA\u9002\u5E94\
    \u8F9B\u666E\u68EE\u6CD5 Simpson\r\n *    2023-09-02: https://qoj.ac/submission/161388\r\
    \n**/\r\nconst double Pi = std::acos(-1.0);\r\nconstexpr double EPS = 1e-9;\r\n\
    double v, r, d;\r\ndouble f(double x) {\r\n    double s = std::sin(x);\r\n   \
    \ return 1 / v / (std::sqrt(s * s + 3) - s);\r\n}\r\ndouble simpson(double l,\
    \ double r) {\r\n    return (f(l) + 4 * f((l + r) / 2) + f(r)) * (r - l) / 6;\r\
    \n}\r\ndouble integral(double l, double r, double eps, double st) {\r\n    double\
    \ mid = (l + r) / 2;\r\n    double sl = simpson(l, mid);\r\n    double sr = simpson(mid,\
    \ r);\r\n    if (std::abs(sl + sr - st) <= 15 * eps)\r\n        return sl + sr\
    \ + (sl + sr - st) / 15;\r\n    return integral(l, mid, eps / 2, sl) + integral(mid,\
    \ r, eps / 2, sr);\r\n}\r\ndouble integral(double l, double r) {\r\n    return\
    \ integral(l, r, EPS, simpson(l, r));\r\n}\n"
  code: "/**   \u81EA\u9002\u5E94\u8F9B\u666E\u68EE\u6CD5 Simpson\r\n *    2023-09-02:\
    \ https://qoj.ac/submission/161388\r\n**/\r\nconst double Pi = std::acos(-1.0);\r\
    \nconstexpr double EPS = 1e-9;\r\ndouble v, r, d;\r\ndouble f(double x) {\r\n\
    \    double s = std::sin(x);\r\n    return 1 / v / (std::sqrt(s * s + 3) - s);\r\
    \n}\r\ndouble simpson(double l, double r) {\r\n    return (f(l) + 4 * f((l + r)\
    \ / 2) + f(r)) * (r - l) / 6;\r\n}\r\ndouble integral(double l, double r, double\
    \ eps, double st) {\r\n    double mid = (l + r) / 2;\r\n    double sl = simpson(l,\
    \ mid);\r\n    double sr = simpson(mid, r);\r\n    if (std::abs(sl + sr - st)\
    \ <= 15 * eps)\r\n        return sl + sr + (sl + sr - st) / 15;\r\n    return\
    \ integral(l, mid, eps / 2, sl) + integral(mid, r, eps / 2, sr);\r\n}\r\ndouble\
    \ integral(double l, double r) {\r\n    return integral(l, r, EPS, simpson(l,\
    \ r));\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/14-Simpson.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/14-Simpson.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/14-Simpson.hpp
- /library/src/jiangly/math/14-Simpson.hpp.html
title: src/jiangly/math/14-Simpson.hpp
---
