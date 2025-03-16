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
    - https://qoj.ac/submission/188519
    - https://qoj.ac/submission/190463
  bundledCode: "#line 1 \"src/jiangly/math/10-Solid-Geometry.hpp\"\n/**   \u7ACB\u4F53\
    \u51E0\u4F55\r\n *    2023-09-25 (i64): https://qoj.ac/submission/188519\r\n *\
    \    2023-09-28 (double): https://qoj.ac/submission/190463\r\n**/\r\nusing i64\
    \ = long long;\r\nusing real = double;\r\n\r\nstruct Point {\r\n    real x = 0;\r\
    \n    real y = 0;\r\n    real z = 0;\r\n};\r\n\r\nPoint operator+(const Point\
    \ &a, const Point &b) {\r\n    return {a.x + b.x, a.y + b.y, a.z + b.z};\r\n}\r\
    \n\r\nPoint operator-(const Point &a, const Point &b) {\r\n    return {a.x - b.x,\
    \ a.y - b.y, a.z - b.z};\r\n}\r\n\r\nPoint operator*(const Point &a, real b) {\r\
    \n    return {a.x * b, a.y * b, a.z * b};\r\n}\r\n\r\nPoint operator/(const Point\
    \ &a, real b) {\r\n    return {a.x / b, a.y / b, a.z / b};\r\n}\r\n\r\nreal length(const\
    \ Point &a) {\r\n    return std::hypot(a.x, a.y, a.z);\r\n}\r\n\r\nPoint normalize(const\
    \ Point &a) {\r\n    real l = length(a);\r\n    return {a.x / l, a.y / l, a.z\
    \ / l};\r\n}\r\n\r\nreal getAng(real a, real b, real c) {\r\n    return std::acos((a\
    \ * a + b * b - c * c) / 2 / a / b);\r\n}\r\n\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const Point &a) {\r\n    return os << \"(\" << a.x << \", \" << a.y <<\
    \ \", \" << a.z << \")\";\r\n}\r\n\r\nreal dot(const Point &a, const Point &b)\
    \ {\r\n    return a.x * b.x + a.y * b.y + a.z * b.z;\r\n}\r\n\r\nPoint cross(const\
    \ Point &a, const Point &b) {\r\n    return {\r\n        a.y * b.z - a.z * b.y,\r\
    \n        a.z * b.x - a.x * b.z,\r\n        a.x * b.y - a.y * b.x\r\n    };\r\n\
    }\n"
  code: "/**   \u7ACB\u4F53\u51E0\u4F55\r\n *    2023-09-25 (i64): https://qoj.ac/submission/188519\r\
    \n *    2023-09-28 (double): https://qoj.ac/submission/190463\r\n**/\r\nusing\
    \ i64 = long long;\r\nusing real = double;\r\n\r\nstruct Point {\r\n    real x\
    \ = 0;\r\n    real y = 0;\r\n    real z = 0;\r\n};\r\n\r\nPoint operator+(const\
    \ Point &a, const Point &b) {\r\n    return {a.x + b.x, a.y + b.y, a.z + b.z};\r\
    \n}\r\n\r\nPoint operator-(const Point &a, const Point &b) {\r\n    return {a.x\
    \ - b.x, a.y - b.y, a.z - b.z};\r\n}\r\n\r\nPoint operator*(const Point &a, real\
    \ b) {\r\n    return {a.x * b, a.y * b, a.z * b};\r\n}\r\n\r\nPoint operator/(const\
    \ Point &a, real b) {\r\n    return {a.x / b, a.y / b, a.z / b};\r\n}\r\n\r\n\
    real length(const Point &a) {\r\n    return std::hypot(a.x, a.y, a.z);\r\n}\r\n\
    \r\nPoint normalize(const Point &a) {\r\n    real l = length(a);\r\n    return\
    \ {a.x / l, a.y / l, a.z / l};\r\n}\r\n\r\nreal getAng(real a, real b, real c)\
    \ {\r\n    return std::acos((a * a + b * b - c * c) / 2 / a / b);\r\n}\r\n\r\n\
    std::ostream &operator<<(std::ostream &os, const Point &a) {\r\n    return os\
    \ << \"(\" << a.x << \", \" << a.y << \", \" << a.z << \")\";\r\n}\r\n\r\nreal\
    \ dot(const Point &a, const Point &b) {\r\n    return a.x * b.x + a.y * b.y +\
    \ a.z * b.z;\r\n}\r\n\r\nPoint cross(const Point &a, const Point &b) {\r\n   \
    \ return {\r\n        a.y * b.z - a.z * b.y,\r\n        a.z * b.x - a.x * b.z,\r\
    \n        a.x * b.y - a.y * b.x\r\n    };\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/10-Solid-Geometry.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/10-Solid-Geometry.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/10-Solid-Geometry.hpp
- /library/src/jiangly/math/10-Solid-Geometry.hpp.html
title: src/jiangly/math/10-Solid-Geometry.hpp
---
