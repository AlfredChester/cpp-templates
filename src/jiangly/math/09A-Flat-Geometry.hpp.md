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
    - https://qoj.ac/submission/185408
  bundledCode: "#line 1 \"src/jiangly/math/09A-Flat-Geometry.hpp\"\n/**   \u5E73\u9762\
    \u51E0\u4F55\uFF08Point\uFF09\r\n *    2023-09-22: https://qoj.ac/submission/185408\r\
    \n**/\r\ntemplate<class T>\r\nstruct Point {\r\n    T x;\r\n    T y;\r\n    Point(const\
    \ T &x_ = 0, const T &y_ = 0) : x(x_), y(y_) {}\r\n    \r\n    template<class\
    \ U>\r\n    operator Point<U>() {\r\n        return Point<U>(U(x), U(y));\r\n\
    \    }\r\n    Point &operator+=(const Point &p) & {\r\n        x += p.x;\r\n \
    \       y += p.y;\r\n        return *this;\r\n    }\r\n    Point &operator-=(const\
    \ Point &p) & {\r\n        x -= p.x;\r\n        y -= p.y;\r\n        return *this;\r\
    \n    }\r\n    Point &operator*=(const T &v) & {\r\n        x *= v;\r\n      \
    \  y *= v;\r\n        return *this;\r\n    }\r\n    Point &operator/=(const T\
    \ &v) & {\r\n        x /= v;\r\n        y /= v;\r\n        return *this;\r\n \
    \   }\r\n    Point operator-() const {\r\n        return Point(-x, -y);\r\n  \
    \  }\r\n    friend Point operator+(Point a, const Point &b) {\r\n        return\
    \ a += b;\r\n    }\r\n    friend Point operator-(Point a, const Point &b) {\r\n\
    \        return a -= b;\r\n    }\r\n    friend Point operator*(Point a, const\
    \ T &b) {\r\n        return a *= b;\r\n    }\r\n    friend Point operator/(Point\
    \ a, const T &b) {\r\n        return a /= b;\r\n    }\r\n    friend Point operator*(const\
    \ T &a, Point b) {\r\n        return b *= a;\r\n    }\r\n    friend bool operator==(const\
    \ Point &a, const Point &b) {\r\n        return a.x == b.x && a.y == b.y;\r\n\
    \    }\r\n    friend std::istream &operator>>(std::istream &is, Point &p) {\r\n\
    \        return is >> p.x >> p.y;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point &p) {\r\n        return os << \"(\" << p.x << \", \" << p.y\
    \ << \")\";\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Line {\r\n    Point<T>\
    \ a;\r\n    Point<T> b;\r\n    Line(const Point<T> &a_ = Point<T>(), const Point<T>\
    \ &b_ = Point<T>()) : a(a_), b(b_) {}\r\n};\r\n\r\ntemplate<class T>\r\nT dot(const\
    \ Point<T> &a, const Point<T> &b) {\r\n    return a.x * b.x + a.y * b.y;\r\n}\r\
    \n\r\ntemplate<class T>\r\nT cross(const Point<T> &a, const Point<T> &b) {\r\n\
    \    return a.x * b.y - a.y * b.x;\r\n}\r\n\r\ntemplate<class T>\r\nT square(const\
    \ Point<T> &p) {\r\n    return dot(p, p);\r\n}\r\n\r\ntemplate<class T>\r\ndouble\
    \ length(const Point<T> &p) {\r\n    return std::sqrt(square(p));\r\n}\r\n\r\n\
    template<class T>\r\ndouble length(const Line<T> &l) {\r\n    return length(l.a\
    \ - l.b);\r\n}\r\n\r\ntemplate<class T>\r\nPoint<T> normalize(const Point<T> &p)\
    \ {\r\n    return p / length(p);\r\n}\r\n\r\ntemplate<class T>\r\nbool parallel(const\
    \ Line<T> &l1, const Line<T> &l2) {\r\n    return cross(l1.b - l1.a, l2.b - l2.a)\
    \ == 0;\r\n}\r\n\r\ntemplate<class T>\r\ndouble distance(const Point<T> &a, const\
    \ Point<T> &b) {\r\n    return length(a - b);\r\n}\r\n\r\ntemplate<class T>\r\n\
    double distancePL(const Point<T> &p, const Line<T> &l) {\r\n    return std::abs(cross(l.a\
    \ - l.b, l.a - p)) / length(l);\r\n}\r\n\r\ntemplate<class T>\r\ndouble distancePS(const\
    \ Point<T> &p, const Line<T> &l) {\r\n    if (dot(p - l.a, l.b - l.a) < 0) {\r\
    \n        return distance(p, l.a);\r\n    }\r\n    if (dot(p - l.b, l.a - l.b)\
    \ < 0) {\r\n        return distance(p, l.b);\r\n    }\r\n    return distancePL(p,\
    \ l);\r\n}\r\n\r\ntemplate<class T>\r\nPoint<T> rotate(const Point<T> &a) {\r\n\
    \    return Point(-a.y, a.x);\r\n}\r\n\r\ntemplate<class T>\r\nint sgn(const Point<T>\
    \ &a) {\r\n    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;\r\n}\r\n\r\n\
    template<class T>\r\nbool pointOnLineLeft(const Point<T> &p, const Line<T> &l)\
    \ {\r\n    return cross(l.b - l.a, p - l.a) > 0;\r\n}\r\n\r\ntemplate<class T>\r\
    \nPoint<T> lineIntersection(const Line<T> &l1, const Line<T> &l2) {\r\n    return\
    \ l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a,\
    \ l1.a - l1.b));\r\n}\r\n\r\ntemplate<class T>\r\nbool pointOnSegment(const Point<T>\
    \ &p, const Line<T> &l) {\r\n    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x,\
    \ l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x)\r\n        && std::min(l.a.y,\
    \ l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);\r\n}\r\n\r\ntemplate<class T>\r\
    \nbool pointInPolygon(const Point<T> &a, const std::vector<Point<T>> &p) {\r\n\
    \    int n = p.size();\r\n    for (int i = 0; i < n; i++) {\r\n        if (pointOnSegment(a,\
    \ Line(p[i], p[(i + 1) % n]))) {\r\n            return true;\r\n        }\r\n\
    \    }\r\n    \r\n    int t = 0;\r\n    for (int i = 0; i < n; i++) {\r\n    \
    \    auto u = p[i];\r\n        auto v = p[(i + 1) % n];\r\n        if (u.x < a.x\
    \ && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {\r\n            t ^= 1;\r\n\
    \        }\r\n        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u,\
    \ v))) {\r\n            t ^= 1;\r\n        }\r\n    }\r\n    \r\n    return t\
    \ == 1;\r\n}\r\n\r\n// 0 : not intersect\r\n// 1 : strictly intersect\r\n// 2\
    \ : overlap\r\n// 3 : intersect at endpoint\r\ntemplate<class T>\r\nstd::tuple<int,\
    \ Point<T>, Point<T>> segmentIntersection(const Line<T> &l1, const Line<T> &l2)\
    \ {\r\n    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x)) {\r\n    \
    \    return {0, Point<T>(), Point<T>()};\r\n    }\r\n    if (std::min(l1.a.x,\
    \ l1.b.x) > std::max(l2.a.x, l2.b.x)) {\r\n        return {0, Point<T>(), Point<T>()};\r\
    \n    }\r\n    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y)) {\r\n\
    \        return {0, Point<T>(), Point<T>()};\r\n    }\r\n    if (std::min(l1.a.y,\
    \ l1.b.y) > std::max(l2.a.y, l2.b.y)) {\r\n        return {0, Point<T>(), Point<T>()};\r\
    \n    }\r\n    if (cross(l1.b - l1.a, l2.b - l2.a) == 0) {\r\n        if (cross(l1.b\
    \ - l1.a, l2.a - l1.a) != 0) {\r\n            return {0, Point<T>(), Point<T>()};\r\
    \n        } else {\r\n            auto maxx1 = std::max(l1.a.x, l1.b.x);\r\n \
    \           auto minx1 = std::min(l1.a.x, l1.b.x);\r\n            auto maxy1 =\
    \ std::max(l1.a.y, l1.b.y);\r\n            auto miny1 = std::min(l1.a.y, l1.b.y);\r\
    \n            auto maxx2 = std::max(l2.a.x, l2.b.x);\r\n            auto minx2\
    \ = std::min(l2.a.x, l2.b.x);\r\n            auto maxy2 = std::max(l2.a.y, l2.b.y);\r\
    \n            auto miny2 = std::min(l2.a.y, l2.b.y);\r\n            Point<T> p1(std::max(minx1,\
    \ minx2), std::max(miny1, miny2));\r\n            Point<T> p2(std::min(maxx1,\
    \ maxx2), std::min(maxy1, maxy2));\r\n            if (!pointOnSegment(p1, l1))\
    \ {\r\n                std::swap(p1.y, p2.y);\r\n            }\r\n           \
    \ if (p1 == p2) {\r\n                return {3, p1, p2};\r\n            } else\
    \ {\r\n                return {2, p1, p2};\r\n            }\r\n        }\r\n \
    \   }\r\n    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);\r\n    auto cp2 = cross(l2.a\
    \ - l1.b, l2.b - l1.b);\r\n    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);\r\n\
    \    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);\r\n    \r\n    if ((cp1 > 0 &&\
    \ cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) || (cp3 < 0 && cp4\
    \ < 0)) {\r\n        return {0, Point<T>(), Point<T>()};\r\n    }\r\n    \r\n\
    \    Point p = lineIntersection(l1, l2);\r\n    if (cp1 != 0 && cp2 != 0 && cp3\
    \ != 0 && cp4 != 0) {\r\n        return {1, p, p};\r\n    } else {\r\n       \
    \ return {3, p, p};\r\n    }\r\n}\r\n\r\ntemplate<class T>\r\ndouble distanceSS(const\
    \ Line<T> &l1, const Line<T> &l2) {\r\n    if (std::get<0>(segmentIntersection(l1,\
    \ l2)) != 0) {\r\n        return 0.0;\r\n    }\r\n    return std::min({distancePS(l1.a,\
    \ l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});\r\n\
    }\r\n\r\ntemplate<class T>\r\nbool segmentInPolygon(const Line<T> &l, const std::vector<Point<T>>\
    \ &p) {\r\n    int n = p.size();\r\n    if (!pointInPolygon(l.a, p)) {\r\n   \
    \     return false;\r\n    }\r\n    if (!pointInPolygon(l.b, p)) {\r\n       \
    \ return false;\r\n    }\r\n    for (int i = 0; i < n; i++) {\r\n        auto\
    \ u = p[i];\r\n        auto v = p[(i + 1) % n];\r\n        auto w = p[(i + 2)\
    \ % n];\r\n        auto [t, p1, p2] = segmentIntersection(l, Line(u, v));\r\n\
    \        \r\n        if (t == 1) {\r\n            return false;\r\n        }\r\
    \n        if (t == 0) {\r\n            continue;\r\n        }\r\n        if (t\
    \ == 2) {\r\n            if (pointOnSegment(v, l) && v != l.a && v != l.b) {\r\
    \n                if (cross(v - u, w - v) > 0) {\r\n                    return\
    \ false;\r\n                }\r\n            }\r\n        } else {\r\n       \
    \     if (p1 != u && p1 != v) {\r\n                if (pointOnLineLeft(l.a, Line(v,\
    \ u))\r\n                    || pointOnLineLeft(l.b, Line(v, u))) {\r\n      \
    \              return false;\r\n                }\r\n            } else if (p1\
    \ == v) {\r\n                if (l.a == v) {\r\n                    if (pointOnLineLeft(u,\
    \ l)) {\r\n                        if (pointOnLineLeft(w, l)\r\n             \
    \               && pointOnLineLeft(w, Line(u, v))) {\r\n                     \
    \       return false;\r\n                        }\r\n                    } else\
    \ {\r\n                        if (pointOnLineLeft(w, l)\r\n                 \
    \           || pointOnLineLeft(w, Line(u, v))) {\r\n                         \
    \   return false;\r\n                        }\r\n                    }\r\n  \
    \              } else if (l.b == v) {\r\n                    if (pointOnLineLeft(u,\
    \ Line(l.b, l.a))) {\r\n                        if (pointOnLineLeft(w, Line(l.b,\
    \ l.a))\r\n                            && pointOnLineLeft(w, Line(u, v))) {\r\n\
    \                            return false;\r\n                        }\r\n  \
    \                  } else {\r\n                        if (pointOnLineLeft(w,\
    \ Line(l.b, l.a))\r\n                            || pointOnLineLeft(w, Line(u,\
    \ v))) {\r\n                            return false;\r\n                    \
    \    }\r\n                    }\r\n                } else {\r\n              \
    \      if (pointOnLineLeft(u, l)) {\r\n                        if (pointOnLineLeft(w,\
    \ Line(l.b, l.a))\r\n                            || pointOnLineLeft(w, Line(u,\
    \ v))) {\r\n                            return false;\r\n                    \
    \    }\r\n                    } else {\r\n                        if (pointOnLineLeft(w,\
    \ l)\r\n                            || pointOnLineLeft(w, Line(u, v))) {\r\n \
    \                           return false;\r\n                        }\r\n   \
    \                 }\r\n                }\r\n            }\r\n        }\r\n   \
    \ }\r\n    return true;\r\n}\r\n\r\ntemplate<class T>\r\nstd::vector<Point<T>>\
    \ hp(std::vector<Line<T>> lines) {\r\n    std::sort(lines.begin(), lines.end(),\
    \ [&](auto l1, auto l2) {\r\n        auto d1 = l1.b - l1.a;\r\n        auto d2\
    \ = l2.b - l2.a;\r\n        \r\n        if (sgn(d1) != sgn(d2)) {\r\n        \
    \    return sgn(d1) == 1;\r\n        }\r\n        \r\n        return cross(d1,\
    \ d2) > 0;\r\n    });\r\n    \r\n    std::deque<Line<T>> ls;\r\n    std::deque<Point<T>>\
    \ ps;\r\n    for (auto l : lines) {\r\n        if (ls.empty()) {\r\n         \
    \   ls.push_back(l);\r\n            continue;\r\n        }\r\n        \r\n   \
    \     while (!ps.empty() && !pointOnLineLeft(ps.back(), l)) {\r\n            ps.pop_back();\r\
    \n            ls.pop_back();\r\n        }\r\n        \r\n        while (!ps.empty()\
    \ && !pointOnLineLeft(ps[0], l)) {\r\n            ps.pop_front();\r\n        \
    \    ls.pop_front();\r\n        }\r\n        \r\n        if (cross(l.b - l.a,\
    \ ls.back().b - ls.back().a) == 0) {\r\n            if (dot(l.b - l.a, ls.back().b\
    \ - ls.back().a) > 0) {\r\n                \r\n                if (!pointOnLineLeft(ls.back().a,\
    \ l)) {\r\n                    assert(ls.size() == 1);\r\n                   \
    \ ls[0] = l;\r\n                }\r\n                continue;\r\n           \
    \ }\r\n            return {};\r\n        }\r\n        \r\n        ps.push_back(lineIntersection(ls.back(),\
    \ l));\r\n        ls.push_back(l);\r\n    }\r\n    \r\n    while (!ps.empty()\
    \ && !pointOnLineLeft(ps.back(), ls[0])) {\r\n        ps.pop_back();\r\n     \
    \   ls.pop_back();\r\n    }\r\n    if (ls.size() <= 2) {\r\n        return {};\r\
    \n    }\r\n    ps.push_back(lineIntersection(ls[0], ls.back()));\r\n    \r\n \
    \   return std::vector(ps.begin(), ps.end());\r\n}\r\n\r\nusing real = long double;\r\
    \nusing P = Point<real>;\r\n\r\nconstexpr real eps = 0;\n"
  code: "/**   \u5E73\u9762\u51E0\u4F55\uFF08Point\uFF09\r\n *    2023-09-22: https://qoj.ac/submission/185408\r\
    \n**/\r\ntemplate<class T>\r\nstruct Point {\r\n    T x;\r\n    T y;\r\n    Point(const\
    \ T &x_ = 0, const T &y_ = 0) : x(x_), y(y_) {}\r\n    \r\n    template<class\
    \ U>\r\n    operator Point<U>() {\r\n        return Point<U>(U(x), U(y));\r\n\
    \    }\r\n    Point &operator+=(const Point &p) & {\r\n        x += p.x;\r\n \
    \       y += p.y;\r\n        return *this;\r\n    }\r\n    Point &operator-=(const\
    \ Point &p) & {\r\n        x -= p.x;\r\n        y -= p.y;\r\n        return *this;\r\
    \n    }\r\n    Point &operator*=(const T &v) & {\r\n        x *= v;\r\n      \
    \  y *= v;\r\n        return *this;\r\n    }\r\n    Point &operator/=(const T\
    \ &v) & {\r\n        x /= v;\r\n        y /= v;\r\n        return *this;\r\n \
    \   }\r\n    Point operator-() const {\r\n        return Point(-x, -y);\r\n  \
    \  }\r\n    friend Point operator+(Point a, const Point &b) {\r\n        return\
    \ a += b;\r\n    }\r\n    friend Point operator-(Point a, const Point &b) {\r\n\
    \        return a -= b;\r\n    }\r\n    friend Point operator*(Point a, const\
    \ T &b) {\r\n        return a *= b;\r\n    }\r\n    friend Point operator/(Point\
    \ a, const T &b) {\r\n        return a /= b;\r\n    }\r\n    friend Point operator*(const\
    \ T &a, Point b) {\r\n        return b *= a;\r\n    }\r\n    friend bool operator==(const\
    \ Point &a, const Point &b) {\r\n        return a.x == b.x && a.y == b.y;\r\n\
    \    }\r\n    friend std::istream &operator>>(std::istream &is, Point &p) {\r\n\
    \        return is >> p.x >> p.y;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point &p) {\r\n        return os << \"(\" << p.x << \", \" << p.y\
    \ << \")\";\r\n    }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Line {\r\n    Point<T>\
    \ a;\r\n    Point<T> b;\r\n    Line(const Point<T> &a_ = Point<T>(), const Point<T>\
    \ &b_ = Point<T>()) : a(a_), b(b_) {}\r\n};\r\n\r\ntemplate<class T>\r\nT dot(const\
    \ Point<T> &a, const Point<T> &b) {\r\n    return a.x * b.x + a.y * b.y;\r\n}\r\
    \n\r\ntemplate<class T>\r\nT cross(const Point<T> &a, const Point<T> &b) {\r\n\
    \    return a.x * b.y - a.y * b.x;\r\n}\r\n\r\ntemplate<class T>\r\nT square(const\
    \ Point<T> &p) {\r\n    return dot(p, p);\r\n}\r\n\r\ntemplate<class T>\r\ndouble\
    \ length(const Point<T> &p) {\r\n    return std::sqrt(square(p));\r\n}\r\n\r\n\
    template<class T>\r\ndouble length(const Line<T> &l) {\r\n    return length(l.a\
    \ - l.b);\r\n}\r\n\r\ntemplate<class T>\r\nPoint<T> normalize(const Point<T> &p)\
    \ {\r\n    return p / length(p);\r\n}\r\n\r\ntemplate<class T>\r\nbool parallel(const\
    \ Line<T> &l1, const Line<T> &l2) {\r\n    return cross(l1.b - l1.a, l2.b - l2.a)\
    \ == 0;\r\n}\r\n\r\ntemplate<class T>\r\ndouble distance(const Point<T> &a, const\
    \ Point<T> &b) {\r\n    return length(a - b);\r\n}\r\n\r\ntemplate<class T>\r\n\
    double distancePL(const Point<T> &p, const Line<T> &l) {\r\n    return std::abs(cross(l.a\
    \ - l.b, l.a - p)) / length(l);\r\n}\r\n\r\ntemplate<class T>\r\ndouble distancePS(const\
    \ Point<T> &p, const Line<T> &l) {\r\n    if (dot(p - l.a, l.b - l.a) < 0) {\r\
    \n        return distance(p, l.a);\r\n    }\r\n    if (dot(p - l.b, l.a - l.b)\
    \ < 0) {\r\n        return distance(p, l.b);\r\n    }\r\n    return distancePL(p,\
    \ l);\r\n}\r\n\r\ntemplate<class T>\r\nPoint<T> rotate(const Point<T> &a) {\r\n\
    \    return Point(-a.y, a.x);\r\n}\r\n\r\ntemplate<class T>\r\nint sgn(const Point<T>\
    \ &a) {\r\n    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;\r\n}\r\n\r\n\
    template<class T>\r\nbool pointOnLineLeft(const Point<T> &p, const Line<T> &l)\
    \ {\r\n    return cross(l.b - l.a, p - l.a) > 0;\r\n}\r\n\r\ntemplate<class T>\r\
    \nPoint<T> lineIntersection(const Line<T> &l1, const Line<T> &l2) {\r\n    return\
    \ l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a,\
    \ l1.a - l1.b));\r\n}\r\n\r\ntemplate<class T>\r\nbool pointOnSegment(const Point<T>\
    \ &p, const Line<T> &l) {\r\n    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x,\
    \ l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x)\r\n        && std::min(l.a.y,\
    \ l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);\r\n}\r\n\r\ntemplate<class T>\r\
    \nbool pointInPolygon(const Point<T> &a, const std::vector<Point<T>> &p) {\r\n\
    \    int n = p.size();\r\n    for (int i = 0; i < n; i++) {\r\n        if (pointOnSegment(a,\
    \ Line(p[i], p[(i + 1) % n]))) {\r\n            return true;\r\n        }\r\n\
    \    }\r\n    \r\n    int t = 0;\r\n    for (int i = 0; i < n; i++) {\r\n    \
    \    auto u = p[i];\r\n        auto v = p[(i + 1) % n];\r\n        if (u.x < a.x\
    \ && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {\r\n            t ^= 1;\r\n\
    \        }\r\n        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u,\
    \ v))) {\r\n            t ^= 1;\r\n        }\r\n    }\r\n    \r\n    return t\
    \ == 1;\r\n}\r\n\r\n// 0 : not intersect\r\n// 1 : strictly intersect\r\n// 2\
    \ : overlap\r\n// 3 : intersect at endpoint\r\ntemplate<class T>\r\nstd::tuple<int,\
    \ Point<T>, Point<T>> segmentIntersection(const Line<T> &l1, const Line<T> &l2)\
    \ {\r\n    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x)) {\r\n    \
    \    return {0, Point<T>(), Point<T>()};\r\n    }\r\n    if (std::min(l1.a.x,\
    \ l1.b.x) > std::max(l2.a.x, l2.b.x)) {\r\n        return {0, Point<T>(), Point<T>()};\r\
    \n    }\r\n    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y)) {\r\n\
    \        return {0, Point<T>(), Point<T>()};\r\n    }\r\n    if (std::min(l1.a.y,\
    \ l1.b.y) > std::max(l2.a.y, l2.b.y)) {\r\n        return {0, Point<T>(), Point<T>()};\r\
    \n    }\r\n    if (cross(l1.b - l1.a, l2.b - l2.a) == 0) {\r\n        if (cross(l1.b\
    \ - l1.a, l2.a - l1.a) != 0) {\r\n            return {0, Point<T>(), Point<T>()};\r\
    \n        } else {\r\n            auto maxx1 = std::max(l1.a.x, l1.b.x);\r\n \
    \           auto minx1 = std::min(l1.a.x, l1.b.x);\r\n            auto maxy1 =\
    \ std::max(l1.a.y, l1.b.y);\r\n            auto miny1 = std::min(l1.a.y, l1.b.y);\r\
    \n            auto maxx2 = std::max(l2.a.x, l2.b.x);\r\n            auto minx2\
    \ = std::min(l2.a.x, l2.b.x);\r\n            auto maxy2 = std::max(l2.a.y, l2.b.y);\r\
    \n            auto miny2 = std::min(l2.a.y, l2.b.y);\r\n            Point<T> p1(std::max(minx1,\
    \ minx2), std::max(miny1, miny2));\r\n            Point<T> p2(std::min(maxx1,\
    \ maxx2), std::min(maxy1, maxy2));\r\n            if (!pointOnSegment(p1, l1))\
    \ {\r\n                std::swap(p1.y, p2.y);\r\n            }\r\n           \
    \ if (p1 == p2) {\r\n                return {3, p1, p2};\r\n            } else\
    \ {\r\n                return {2, p1, p2};\r\n            }\r\n        }\r\n \
    \   }\r\n    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);\r\n    auto cp2 = cross(l2.a\
    \ - l1.b, l2.b - l1.b);\r\n    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);\r\n\
    \    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);\r\n    \r\n    if ((cp1 > 0 &&\
    \ cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) || (cp3 < 0 && cp4\
    \ < 0)) {\r\n        return {0, Point<T>(), Point<T>()};\r\n    }\r\n    \r\n\
    \    Point p = lineIntersection(l1, l2);\r\n    if (cp1 != 0 && cp2 != 0 && cp3\
    \ != 0 && cp4 != 0) {\r\n        return {1, p, p};\r\n    } else {\r\n       \
    \ return {3, p, p};\r\n    }\r\n}\r\n\r\ntemplate<class T>\r\ndouble distanceSS(const\
    \ Line<T> &l1, const Line<T> &l2) {\r\n    if (std::get<0>(segmentIntersection(l1,\
    \ l2)) != 0) {\r\n        return 0.0;\r\n    }\r\n    return std::min({distancePS(l1.a,\
    \ l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});\r\n\
    }\r\n\r\ntemplate<class T>\r\nbool segmentInPolygon(const Line<T> &l, const std::vector<Point<T>>\
    \ &p) {\r\n    int n = p.size();\r\n    if (!pointInPolygon(l.a, p)) {\r\n   \
    \     return false;\r\n    }\r\n    if (!pointInPolygon(l.b, p)) {\r\n       \
    \ return false;\r\n    }\r\n    for (int i = 0; i < n; i++) {\r\n        auto\
    \ u = p[i];\r\n        auto v = p[(i + 1) % n];\r\n        auto w = p[(i + 2)\
    \ % n];\r\n        auto [t, p1, p2] = segmentIntersection(l, Line(u, v));\r\n\
    \        \r\n        if (t == 1) {\r\n            return false;\r\n        }\r\
    \n        if (t == 0) {\r\n            continue;\r\n        }\r\n        if (t\
    \ == 2) {\r\n            if (pointOnSegment(v, l) && v != l.a && v != l.b) {\r\
    \n                if (cross(v - u, w - v) > 0) {\r\n                    return\
    \ false;\r\n                }\r\n            }\r\n        } else {\r\n       \
    \     if (p1 != u && p1 != v) {\r\n                if (pointOnLineLeft(l.a, Line(v,\
    \ u))\r\n                    || pointOnLineLeft(l.b, Line(v, u))) {\r\n      \
    \              return false;\r\n                }\r\n            } else if (p1\
    \ == v) {\r\n                if (l.a == v) {\r\n                    if (pointOnLineLeft(u,\
    \ l)) {\r\n                        if (pointOnLineLeft(w, l)\r\n             \
    \               && pointOnLineLeft(w, Line(u, v))) {\r\n                     \
    \       return false;\r\n                        }\r\n                    } else\
    \ {\r\n                        if (pointOnLineLeft(w, l)\r\n                 \
    \           || pointOnLineLeft(w, Line(u, v))) {\r\n                         \
    \   return false;\r\n                        }\r\n                    }\r\n  \
    \              } else if (l.b == v) {\r\n                    if (pointOnLineLeft(u,\
    \ Line(l.b, l.a))) {\r\n                        if (pointOnLineLeft(w, Line(l.b,\
    \ l.a))\r\n                            && pointOnLineLeft(w, Line(u, v))) {\r\n\
    \                            return false;\r\n                        }\r\n  \
    \                  } else {\r\n                        if (pointOnLineLeft(w,\
    \ Line(l.b, l.a))\r\n                            || pointOnLineLeft(w, Line(u,\
    \ v))) {\r\n                            return false;\r\n                    \
    \    }\r\n                    }\r\n                } else {\r\n              \
    \      if (pointOnLineLeft(u, l)) {\r\n                        if (pointOnLineLeft(w,\
    \ Line(l.b, l.a))\r\n                            || pointOnLineLeft(w, Line(u,\
    \ v))) {\r\n                            return false;\r\n                    \
    \    }\r\n                    } else {\r\n                        if (pointOnLineLeft(w,\
    \ l)\r\n                            || pointOnLineLeft(w, Line(u, v))) {\r\n \
    \                           return false;\r\n                        }\r\n   \
    \                 }\r\n                }\r\n            }\r\n        }\r\n   \
    \ }\r\n    return true;\r\n}\r\n\r\ntemplate<class T>\r\nstd::vector<Point<T>>\
    \ hp(std::vector<Line<T>> lines) {\r\n    std::sort(lines.begin(), lines.end(),\
    \ [&](auto l1, auto l2) {\r\n        auto d1 = l1.b - l1.a;\r\n        auto d2\
    \ = l2.b - l2.a;\r\n        \r\n        if (sgn(d1) != sgn(d2)) {\r\n        \
    \    return sgn(d1) == 1;\r\n        }\r\n        \r\n        return cross(d1,\
    \ d2) > 0;\r\n    });\r\n    \r\n    std::deque<Line<T>> ls;\r\n    std::deque<Point<T>>\
    \ ps;\r\n    for (auto l : lines) {\r\n        if (ls.empty()) {\r\n         \
    \   ls.push_back(l);\r\n            continue;\r\n        }\r\n        \r\n   \
    \     while (!ps.empty() && !pointOnLineLeft(ps.back(), l)) {\r\n            ps.pop_back();\r\
    \n            ls.pop_back();\r\n        }\r\n        \r\n        while (!ps.empty()\
    \ && !pointOnLineLeft(ps[0], l)) {\r\n            ps.pop_front();\r\n        \
    \    ls.pop_front();\r\n        }\r\n        \r\n        if (cross(l.b - l.a,\
    \ ls.back().b - ls.back().a) == 0) {\r\n            if (dot(l.b - l.a, ls.back().b\
    \ - ls.back().a) > 0) {\r\n                \r\n                if (!pointOnLineLeft(ls.back().a,\
    \ l)) {\r\n                    assert(ls.size() == 1);\r\n                   \
    \ ls[0] = l;\r\n                }\r\n                continue;\r\n           \
    \ }\r\n            return {};\r\n        }\r\n        \r\n        ps.push_back(lineIntersection(ls.back(),\
    \ l));\r\n        ls.push_back(l);\r\n    }\r\n    \r\n    while (!ps.empty()\
    \ && !pointOnLineLeft(ps.back(), ls[0])) {\r\n        ps.pop_back();\r\n     \
    \   ls.pop_back();\r\n    }\r\n    if (ls.size() <= 2) {\r\n        return {};\r\
    \n    }\r\n    ps.push_back(lineIntersection(ls[0], ls.back()));\r\n    \r\n \
    \   return std::vector(ps.begin(), ps.end());\r\n}\r\n\r\nusing real = long double;\r\
    \nusing P = Point<real>;\r\n\r\nconstexpr real eps = 0;"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/09A-Flat-Geometry.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/09A-Flat-Geometry.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/09A-Flat-Geometry.hpp
- /library/src/jiangly/math/09A-Flat-Geometry.hpp.html
title: src/jiangly/math/09A-Flat-Geometry.hpp
---
