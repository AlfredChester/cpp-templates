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
    - https://qoj.ac/submission/164445
  bundledCode: "#line 1 \"src/jiangly/math/09B-Flat-Geometry.hpp\"\n/**   \u5E73\u9762\
    \u51E0\u4F55\uFF08with. std::complex\uFF09\r\n *    2023-09-04: https://qoj.ac/submission/164445\r\
    \n**/\r\nusing Point = std::complex<long double>;\r\n\r\n#define x real\r\n#define\
    \ y imag\r\n\r\nlong double dot(const Point &a, const Point &b) {\r\n    return\
    \ (std::conj(a) * b).x();\r\n}\r\n\r\nlong double cross(const Point &a, const\
    \ Point &b) {\r\n    return (std::conj(a) * b).y();\r\n}\r\n\r\nlong double length(const\
    \ Point &a) {\r\n    return std::sqrt(dot(a, a));\r\n}\r\n\r\nlong double dist(const\
    \ Point &a, const Point &b) {\r\n    return length(a - b);\r\n}\r\n\r\nlong double\
    \ get(const Point &a, const Point &b, const Point &c, const Point &d) {\r\n  \
    \  auto e = a + (b - a) * cross(c - a, d - a) / cross(b - a, d - c);\r\n    return\
    \ dist(d, e);\r\n}\n"
  code: "/**   \u5E73\u9762\u51E0\u4F55\uFF08with. std::complex\uFF09\r\n *    2023-09-04:\
    \ https://qoj.ac/submission/164445\r\n**/\r\nusing Point = std::complex<long double>;\r\
    \n\r\n#define x real\r\n#define y imag\r\n\r\nlong double dot(const Point &a,\
    \ const Point &b) {\r\n    return (std::conj(a) * b).x();\r\n}\r\n\r\nlong double\
    \ cross(const Point &a, const Point &b) {\r\n    return (std::conj(a) * b).y();\r\
    \n}\r\n\r\nlong double length(const Point &a) {\r\n    return std::sqrt(dot(a,\
    \ a));\r\n}\r\n\r\nlong double dist(const Point &a, const Point &b) {\r\n    return\
    \ length(a - b);\r\n}\r\n\r\nlong double get(const Point &a, const Point &b, const\
    \ Point &c, const Point &d) {\r\n    auto e = a + (b - a) * cross(c - a, d - a)\
    \ / cross(b - a, d - c);\r\n    return dist(d, e);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/09B-Flat-Geometry.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/09B-Flat-Geometry.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/09B-Flat-Geometry.hpp
- /library/src/jiangly/math/09B-Flat-Geometry.hpp.html
title: src/jiangly/math/09B-Flat-Geometry.hpp
---
