---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/math/computation-geometry.hpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\n// Caution: This computation geometry template is pure shit\n\
    //          because of the terrible math level of the author.\n//          It\
    \ will be rewritten some time.\ntemplate <class T>\nstruct Point {\n    T x, y;\n\
    \    Point(void) = default;\n    Point(T X, T Y) : x(X), y(Y) {}\n    inline bool\
    \ operator==(const Point B) {\n        return x == B.x && y == B.y;\n    }\n \
    \   friend std::ostream &operator<<(std::ostream &out, Point P) {\n        return\
    \ out << \"(\" << P.x << \", \" << P.y << \")\";\n    }\n    friend std::istream\
    \ &operator>>(std::istream &in, Point &P) {\n        return in >> P.x >> P.y;\n\
    \    }\n};\ntemplate <class T>\nstruct Line {\n    T A, B, C; // Ax + By + C =\
    \ 0\n    Line(void) = default;\n    Line(T a, T b, T c) : A(a), B(b), C(c) {}\
    \ // Ax + By + C = 0\n    Line(T k, T b) : A(k), B(-1), C(b) {}     // y = kx\
    \ + b\n};\ntemplate <class T>\ninline int sign(T x) {\n    return x == 0 ? 0 :\
    \ (x < 0 ? -1 : 1);\n}\ntemplate <class T>\ninline bool parallel(Line<T> P, Line<T>\
    \ Q) {\n    return P.A * Q.B == P.B * Q.A;\n}\ntemplate <class T>\ninline Point<T>\
    \ intersect(Line<T> P, Line<T> Q) {\n    assert(!parallel(P, Q));\n    return\
    \ Point<T>{\n        (P.C * Q.B - Q.C * P.B) / (Q.A * P.B - P.A * Q.B),\n    \
    \    (P.C * Q.A - Q.C * P.A) / (P.A * Q.B - Q.A * P.B)\n    };\n}\ntemplate <class\
    \ T>\ninline Line<T> get_line(Point<T> P, Point<T> Q) {\n    assert(!(P == Q));\n\
    \    if (P.x == Q.x) {\n        return Line<T>(-1, 0, P.x);\n    } else if (P.y\
    \ == Q.y) {\n        return Line<T>(0, -1, P.y);\n    } else {\n        return\
    \ Line<T>(\n            Q.y - P.y, P.x - Q.x, P.y * Q.x - P.x * Q.y\n        );\n\
    \    }\n}\ntemplate <class T>\ninline bool point_on_line(Point<T> P, Line<T> L)\
    \ {\n    return L.A * P.x + L.B * P.y + L.C == 0;\n}\ntemplate <class T>\ninline\
    \ T dis_square(Point<T> P, Point<T> Q) {\n    return (P.x - Q.x) * (P.x - Q.x)\
    \ + (P.y - Q.y) * (P.y - Q.y);\n}\n\n\n"
  code: "#ifndef AFMT_COMPUTATION_GEOMETRY\n#define AFMT_COMPUTATION_GEOMETRY\n\n\
    #include <bits/stdc++.h>\n\n// Caution: This computation geometry template is\
    \ pure shit\n//          because of the terrible math level of the author.\n//\
    \          It will be rewritten some time.\ntemplate <class T>\nstruct Point {\n\
    \    T x, y;\n    Point(void) = default;\n    Point(T X, T Y) : x(X), y(Y) {}\n\
    \    inline bool operator==(const Point B) {\n        return x == B.x && y ==\
    \ B.y;\n    }\n    friend std::ostream &operator<<(std::ostream &out, Point P)\
    \ {\n        return out << \"(\" << P.x << \", \" << P.y << \")\";\n    }\n  \
    \  friend std::istream &operator>>(std::istream &in, Point &P) {\n        return\
    \ in >> P.x >> P.y;\n    }\n};\ntemplate <class T>\nstruct Line {\n    T A, B,\
    \ C; // Ax + By + C = 0\n    Line(void) = default;\n    Line(T a, T b, T c) :\
    \ A(a), B(b), C(c) {} // Ax + By + C = 0\n    Line(T k, T b) : A(k), B(-1), C(b)\
    \ {}     // y = kx + b\n};\ntemplate <class T>\ninline int sign(T x) {\n    return\
    \ x == 0 ? 0 : (x < 0 ? -1 : 1);\n}\ntemplate <class T>\ninline bool parallel(Line<T>\
    \ P, Line<T> Q) {\n    return P.A * Q.B == P.B * Q.A;\n}\ntemplate <class T>\n\
    inline Point<T> intersect(Line<T> P, Line<T> Q) {\n    assert(!parallel(P, Q));\n\
    \    return Point<T>{\n        (P.C * Q.B - Q.C * P.B) / (Q.A * P.B - P.A * Q.B),\n\
    \        (P.C * Q.A - Q.C * P.A) / (P.A * Q.B - Q.A * P.B)\n    };\n}\ntemplate\
    \ <class T>\ninline Line<T> get_line(Point<T> P, Point<T> Q) {\n    assert(!(P\
    \ == Q));\n    if (P.x == Q.x) {\n        return Line<T>(-1, 0, P.x);\n    } else\
    \ if (P.y == Q.y) {\n        return Line<T>(0, -1, P.y);\n    } else {\n     \
    \   return Line<T>(\n            Q.y - P.y, P.x - Q.x, P.y * Q.x - P.x * Q.y\n\
    \        );\n    }\n}\ntemplate <class T>\ninline bool point_on_line(Point<T>\
    \ P, Line<T> L) {\n    return L.A * P.x + L.B * P.y + L.C == 0;\n}\ntemplate <class\
    \ T>\ninline T dis_square(Point<T> P, Point<T> Q) {\n    return (P.x - Q.x) *\
    \ (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);\n}\n\n#endif // AFMT_COMPUTATION_GEOMETRY\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/math/computation-geometry.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/computation-geometry.hpp
layout: document
redirect_from:
- /library/src/alfred/math/computation-geometry.hpp
- /library/src/alfred/math/computation-geometry.hpp.html
title: src/alfred/math/computation-geometry.hpp
---
