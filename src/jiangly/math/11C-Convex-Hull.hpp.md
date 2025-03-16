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
    - https://loj.ac/s/1370861
  bundledCode: "#line 1 \"src/jiangly/math/11C-Convex-Hull.hpp\"\n/**   \u9759\u6001\
    \u51F8\u5305\uFF08with. std::complex\uFF09\r\n *    2022-02-04: https://loj.ac/s/1370861\r\
    \n**/\r\nusing Point = std::complex<i64>;\r\n\r\n#define x real\r\n#define y imag\r\
    \n\r\nauto dot(const Point &a, const Point &b) {\r\n    return (std::conj(a) *\
    \ b).x();\r\n}\r\n\r\nauto cross(const Point &a, const Point &b) {\r\n    return\
    \ (std::conj(a) * b).y();\r\n}\r\n\r\nauto rot(const Point &p) {\r\n    return\
    \ Point(-p.y(), p.x());\r\n}\r\n\r\nauto complexHull(std::vector<Point> a) {\r\
    \n    std::sort(a.begin(), a.end(), [&](auto a, auto b) {\r\n        if (a.x()\
    \ != b.x()) {\r\n            return a.x() < b.x();\r\n        } else {\r\n   \
    \         return a.y() < b.y();\r\n        }\r\n    });\r\n\r\n    std::vector<Point>\
    \ l, h;\r\n\r\n    for (auto p : a) {\r\n        while (l.size() > 1 && cross(l.back()\
    \ - l[l.size() - 2], p - l.back()) <= 0) {\r\n            l.pop_back();\r\n  \
    \      }\r\n\r\n        while (h.size() > 1 && cross(h.back() - h[h.size() - 2],\
    \ p - h.back()) >= 0) {\r\n            h.pop_back();\r\n        }\r\n\r\n    \
    \    l.push_back(p);\r\n        h.push_back(p);\r\n    }\r\n\r\n    std::reverse(h.begin(),\
    \ h.end());\r\n\r\n    h.insert(h.end(), l.begin() + 1, l.end() - 1);\r\n\r\n\
    \    return h;\r\n}\r\n\r\nint sgn(Point p) {\r\n    if (p.y() > 0 || (p.y() ==\
    \ 0 && p.x() < 0)) {\r\n        return 0;\r\n    } else {\r\n        return 1;\r\
    \n    }\r\n}\n"
  code: "/**   \u9759\u6001\u51F8\u5305\uFF08with. std::complex\uFF09\r\n *    2022-02-04:\
    \ https://loj.ac/s/1370861\r\n**/\r\nusing Point = std::complex<i64>;\r\n\r\n\
    #define x real\r\n#define y imag\r\n\r\nauto dot(const Point &a, const Point &b)\
    \ {\r\n    return (std::conj(a) * b).x();\r\n}\r\n\r\nauto cross(const Point &a,\
    \ const Point &b) {\r\n    return (std::conj(a) * b).y();\r\n}\r\n\r\nauto rot(const\
    \ Point &p) {\r\n    return Point(-p.y(), p.x());\r\n}\r\n\r\nauto complexHull(std::vector<Point>\
    \ a) {\r\n    std::sort(a.begin(), a.end(), [&](auto a, auto b) {\r\n        if\
    \ (a.x() != b.x()) {\r\n            return a.x() < b.x();\r\n        } else {\r\
    \n            return a.y() < b.y();\r\n        }\r\n    });\r\n\r\n    std::vector<Point>\
    \ l, h;\r\n\r\n    for (auto p : a) {\r\n        while (l.size() > 1 && cross(l.back()\
    \ - l[l.size() - 2], p - l.back()) <= 0) {\r\n            l.pop_back();\r\n  \
    \      }\r\n\r\n        while (h.size() > 1 && cross(h.back() - h[h.size() - 2],\
    \ p - h.back()) >= 0) {\r\n            h.pop_back();\r\n        }\r\n\r\n    \
    \    l.push_back(p);\r\n        h.push_back(p);\r\n    }\r\n\r\n    std::reverse(h.begin(),\
    \ h.end());\r\n\r\n    h.insert(h.end(), l.begin() + 1, l.end() - 1);\r\n\r\n\
    \    return h;\r\n}\r\n\r\nint sgn(Point p) {\r\n    if (p.y() > 0 || (p.y() ==\
    \ 0 && p.x() < 0)) {\r\n        return 0;\r\n    } else {\r\n        return 1;\r\
    \n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/11C-Convex-Hull.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/11C-Convex-Hull.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/11C-Convex-Hull.hpp
- /library/src/jiangly/math/11C-Convex-Hull.hpp.html
title: src/jiangly/math/11C-Convex-Hull.hpp
---
