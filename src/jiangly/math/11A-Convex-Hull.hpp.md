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
    - https://cf.dianhsu.com/gym/104288/submission/201412835
  bundledCode: "#line 1 \"src/jiangly/math/11A-Convex-Hull.hpp\"\n/**   \u9759\u6001\
    \u51F8\u5305\uFF08with. Point\uFF0C\u65E7\u7248\uFF09\r\n *    2023-04-09: https://cf.dianhsu.com/gym/104288/submission/201412835\r\
    \n**/\r\nstruct Point {\r\n    i64 x;\r\n    i64 y;\r\n    Point(i64 x = 0, i64\
    \ y = 0) : x(x), y(y) {}\r\n};\r\n\r\nbool operator==(const Point &a, const Point\
    \ &b) {\r\n    return a.x == b.x && a.y == b.y;\r\n}\r\n\r\nPoint operator+(const\
    \ Point &a, const Point &b) {\r\n    return Point(a.x + b.x, a.y + b.y);\r\n}\r\
    \n\r\nPoint operator-(const Point &a, const Point &b) {\r\n    return Point(a.x\
    \ - b.x, a.y - b.y);\r\n}\r\n\r\ni64 dot(const Point &a, const Point &b) {\r\n\
    \    return a.x * b.x + a.y * b.y;\r\n}\r\n\r\ni64 cross(const Point &a, const\
    \ Point &b) {\r\n    return a.x * b.y - a.y * b.x;\r\n}\r\n\r\nvoid norm(std::vector<Point>\
    \ &h) {\r\n    int i = 0;\r\n    for (int j = 0; j < int(h.size()); j++) {\r\n\
    \        if (h[j].y < h[i].y || (h[j].y == h[i].y && h[j].x < h[i].x)) {\r\n \
    \           i = j;\r\n        }\r\n    }\r\n    std::rotate(h.begin(), h.begin()\
    \ + i, h.end());\r\n}\r\n\r\nint sgn(const Point &a) {\r\n    return a.y > 0 ||\
    \ (a.y == 0 && a.x > 0) ? 0 : 1;\r\n}\r\n\r\nstd::vector<Point> getHull(std::vector<Point>\
    \ p) {\r\n    std::vector<Point> h, l;\r\n    std::sort(p.begin(), p.end(), [&](auto\
    \ a, auto b) {\r\n        if (a.x != b.x) {\r\n            return a.x < b.x;\r\
    \n        } else {\r\n            return a.y < b.y;\r\n        }\r\n    });\r\n\
    \    p.erase(std::unique(p.begin(), p.end()), p.end());\r\n    if (p.size() <=\
    \ 1) {\r\n        return p;\r\n    }\r\n    \r\n    for (auto a : p) {\r\n   \
    \     while (h.size() > 1 && cross(a - h.back(), a - h[h.size() - 2]) <= 0) {\r\
    \n            h.pop_back();\r\n        }\r\n        while (l.size() > 1 && cross(a\
    \ - l.back(), a - l[l.size() - 2]) >= 0) {\r\n            l.pop_back();\r\n  \
    \      }\r\n        l.push_back(a);\r\n        h.push_back(a);\r\n    }\r\n  \
    \  \r\n    l.pop_back();\r\n    std::reverse(h.begin(), h.end());\r\n    h.pop_back();\r\
    \n    l.insert(l.end(), h.begin(), h.end());\r\n    return l;\r\n}\n"
  code: "/**   \u9759\u6001\u51F8\u5305\uFF08with. Point\uFF0C\u65E7\u7248\uFF09\r\
    \n *    2023-04-09: https://cf.dianhsu.com/gym/104288/submission/201412835\r\n\
    **/\r\nstruct Point {\r\n    i64 x;\r\n    i64 y;\r\n    Point(i64 x = 0, i64\
    \ y = 0) : x(x), y(y) {}\r\n};\r\n\r\nbool operator==(const Point &a, const Point\
    \ &b) {\r\n    return a.x == b.x && a.y == b.y;\r\n}\r\n\r\nPoint operator+(const\
    \ Point &a, const Point &b) {\r\n    return Point(a.x + b.x, a.y + b.y);\r\n}\r\
    \n\r\nPoint operator-(const Point &a, const Point &b) {\r\n    return Point(a.x\
    \ - b.x, a.y - b.y);\r\n}\r\n\r\ni64 dot(const Point &a, const Point &b) {\r\n\
    \    return a.x * b.x + a.y * b.y;\r\n}\r\n\r\ni64 cross(const Point &a, const\
    \ Point &b) {\r\n    return a.x * b.y - a.y * b.x;\r\n}\r\n\r\nvoid norm(std::vector<Point>\
    \ &h) {\r\n    int i = 0;\r\n    for (int j = 0; j < int(h.size()); j++) {\r\n\
    \        if (h[j].y < h[i].y || (h[j].y == h[i].y && h[j].x < h[i].x)) {\r\n \
    \           i = j;\r\n        }\r\n    }\r\n    std::rotate(h.begin(), h.begin()\
    \ + i, h.end());\r\n}\r\n\r\nint sgn(const Point &a) {\r\n    return a.y > 0 ||\
    \ (a.y == 0 && a.x > 0) ? 0 : 1;\r\n}\r\n\r\nstd::vector<Point> getHull(std::vector<Point>\
    \ p) {\r\n    std::vector<Point> h, l;\r\n    std::sort(p.begin(), p.end(), [&](auto\
    \ a, auto b) {\r\n        if (a.x != b.x) {\r\n            return a.x < b.x;\r\
    \n        } else {\r\n            return a.y < b.y;\r\n        }\r\n    });\r\n\
    \    p.erase(std::unique(p.begin(), p.end()), p.end());\r\n    if (p.size() <=\
    \ 1) {\r\n        return p;\r\n    }\r\n    \r\n    for (auto a : p) {\r\n   \
    \     while (h.size() > 1 && cross(a - h.back(), a - h[h.size() - 2]) <= 0) {\r\
    \n            h.pop_back();\r\n        }\r\n        while (l.size() > 1 && cross(a\
    \ - l.back(), a - l[l.size() - 2]) >= 0) {\r\n            l.pop_back();\r\n  \
    \      }\r\n        l.push_back(a);\r\n        h.push_back(a);\r\n    }\r\n  \
    \  \r\n    l.pop_back();\r\n    std::reverse(h.begin(), h.end());\r\n    h.pop_back();\r\
    \n    l.insert(l.end(), h.begin(), h.end());\r\n    return l;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/11A-Convex-Hull.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/11A-Convex-Hull.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/11A-Convex-Hull.hpp
- /library/src/jiangly/math/11A-Convex-Hull.hpp.html
title: src/jiangly/math/11A-Convex-Hull.hpp
---
