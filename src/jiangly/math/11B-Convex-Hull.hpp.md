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
    - https://qoj.ac/submission/379920)
  bundledCode: "#line 1 \"src/jiangly/math/11B-Convex-Hull.hpp\"\n/**   \u9759\u6001\
    \u51F8\u5305\uFF08with. Point\uFF0C\u65B0\u7248\uFF09\r\n *    2024-04-06: https://qoj.ac/submission/379920)\r\
    \n**/\r\nstruct Point {\r\n    i64 x;\r\n    i64 y;\r\n    Point() : x{0}, y{0}\
    \ {}\r\n    Point(i64 x_, i64 y_) : x{x_}, y{y_} {}\r\n};\r\n\r\ni64 dot(Point\
    \ a, Point b) {\r\n    return a.x * b.x + a.y * b.y;\r\n}\r\n\r\ni64 cross(Point\
    \ a, Point b) {\r\n    return a.x * b.y - a.y * b.x;\r\n}\r\n\r\nPoint operator+(Point\
    \ a, Point b) {\r\n    return Point(a.x + b.x, a.y + b.y);\r\n}\r\n\r\nPoint operator-(Point\
    \ a, Point b) {\r\n    return Point(a.x - b.x, a.y - b.y);\r\n}\r\n\r\nauto getHull(std::vector<Point>\
    \ p) {\r\n    std::sort(p.begin(), p.end(),\r\n        [&](auto a, auto b) {\r\
    \n            return a.x < b.x || (a.x == b.x && a.y < b.y);\r\n        });\r\n\
    \    \r\n    std::vector<Point> hi, lo;\r\n    for (auto p : p) {\r\n        while\
    \ (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0)\
    \ {\r\n            hi.pop_back();\r\n        }\r\n        while (!hi.empty() &&\
    \ hi.back().x == p.x) {\r\n            hi.pop_back();\r\n        }\r\n       \
    \ hi.push_back(p);\r\n        while (lo.size() > 1 && cross(lo.back() - lo[lo.size()\
    \ - 2], p - lo.back()) <= 0) {\r\n            lo.pop_back();\r\n        }\r\n\
    \        if (lo.empty() || lo.back().x < p.x) {\r\n            lo.push_back(p);\r\
    \n        }\r\n    }\r\n    return std::make_pair(hi, lo);\r\n}\r\n\r\nconst double\
    \ inf = INFINITY;\n"
  code: "/**   \u9759\u6001\u51F8\u5305\uFF08with. Point\uFF0C\u65B0\u7248\uFF09\r\
    \n *    2024-04-06: https://qoj.ac/submission/379920)\r\n**/\r\nstruct Point {\r\
    \n    i64 x;\r\n    i64 y;\r\n    Point() : x{0}, y{0} {}\r\n    Point(i64 x_,\
    \ i64 y_) : x{x_}, y{y_} {}\r\n};\r\n\r\ni64 dot(Point a, Point b) {\r\n    return\
    \ a.x * b.x + a.y * b.y;\r\n}\r\n\r\ni64 cross(Point a, Point b) {\r\n    return\
    \ a.x * b.y - a.y * b.x;\r\n}\r\n\r\nPoint operator+(Point a, Point b) {\r\n \
    \   return Point(a.x + b.x, a.y + b.y);\r\n}\r\n\r\nPoint operator-(Point a, Point\
    \ b) {\r\n    return Point(a.x - b.x, a.y - b.y);\r\n}\r\n\r\nauto getHull(std::vector<Point>\
    \ p) {\r\n    std::sort(p.begin(), p.end(),\r\n        [&](auto a, auto b) {\r\
    \n            return a.x < b.x || (a.x == b.x && a.y < b.y);\r\n        });\r\n\
    \    \r\n    std::vector<Point> hi, lo;\r\n    for (auto p : p) {\r\n        while\
    \ (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0)\
    \ {\r\n            hi.pop_back();\r\n        }\r\n        while (!hi.empty() &&\
    \ hi.back().x == p.x) {\r\n            hi.pop_back();\r\n        }\r\n       \
    \ hi.push_back(p);\r\n        while (lo.size() > 1 && cross(lo.back() - lo[lo.size()\
    \ - 2], p - lo.back()) <= 0) {\r\n            lo.pop_back();\r\n        }\r\n\
    \        if (lo.empty() || lo.back().x < p.x) {\r\n            lo.push_back(p);\r\
    \n        }\r\n    }\r\n    return std::make_pair(hi, lo);\r\n}\r\n\r\nconst double\
    \ inf = INFINITY;"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/11B-Convex-Hull.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/11B-Convex-Hull.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/11B-Convex-Hull.hpp
- /library/src/jiangly/math/11B-Convex-Hull.hpp.html
title: src/jiangly/math/11B-Convex-Hull.hpp
---
