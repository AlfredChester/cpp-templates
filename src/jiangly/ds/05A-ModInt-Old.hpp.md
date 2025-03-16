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
  bundledCode: "#line 1 \"src/jiangly/ds/05A-ModInt-Old.hpp\"\nconstexpr int P = 998244353;\r\
    \nusing i64 = long long;\r\n// assume -P <= x < 2P\r\nint norm(int x) {\r\n  \
    \  if (x < 0) {\r\n        x += P;\r\n    }\r\n    if (x >= P) {\r\n        x\
    \ -= P;\r\n    }\r\n    return x;\r\n}\r\ntemplate<class T>\r\nT power(T a, i64\
    \ b) {\r\n    T res = 1;\r\n    for (; b; b /= 2, a *= a) {\r\n        if (b %\
    \ 2) {\r\n            res *= a;\r\n        }\r\n    }\r\n    return res;\r\n}\r\
    \nstruct Z {\r\n    int x;\r\n    Z(int x = 0) : x(norm(x)) {}\r\n    Z(i64 x)\
    \ : x(norm(x % P)) {}\r\n    int val() const {\r\n        return x;\r\n    }\r\
    \n    Z operator-() const {\r\n        return Z(norm(P - x));\r\n    }\r\n   \
    \ Z inv() const {\r\n        assert(x != 0);\r\n        return power(*this, P\
    \ - 2);\r\n    }\r\n    Z &operator*=(const Z &rhs) {\r\n        x = i64(x) *\
    \ rhs.x % P;\r\n        return *this;\r\n    }\r\n    Z &operator+=(const Z &rhs)\
    \ {\r\n        x = norm(x + rhs.x);\r\n        return *this;\r\n    }\r\n    Z\
    \ &operator-=(const Z &rhs) {\r\n        x = norm(x - rhs.x);\r\n        return\
    \ *this;\r\n    }\r\n    Z &operator/=(const Z &rhs) {\r\n        return *this\
    \ *= rhs.inv();\r\n    }\r\n    friend Z operator*(const Z &lhs, const Z &rhs)\
    \ {\r\n        Z res = lhs;\r\n        res *= rhs;\r\n        return res;\r\n\
    \    }\r\n    friend Z operator+(const Z &lhs, const Z &rhs) {\r\n        Z res\
    \ = lhs;\r\n        res += rhs;\r\n        return res;\r\n    }\r\n    friend\
    \ Z operator-(const Z &lhs, const Z &rhs) {\r\n        Z res = lhs;\r\n      \
    \  res -= rhs;\r\n        return res;\r\n    }\r\n    friend Z operator/(const\
    \ Z &lhs, const Z &rhs) {\r\n        Z res = lhs;\r\n        res /= rhs;\r\n \
    \       return res;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, Z &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = Z(v);\r\n\
    \        return is;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Z &a) {\r\n        return os << a.val();\r\n    }\r\n};\r\n\r\n"
  code: "constexpr int P = 998244353;\r\nusing i64 = long long;\r\n// assume -P <=\
    \ x < 2P\r\nint norm(int x) {\r\n    if (x < 0) {\r\n        x += P;\r\n    }\r\
    \n    if (x >= P) {\r\n        x -= P;\r\n    }\r\n    return x;\r\n}\r\ntemplate<class\
    \ T>\r\nT power(T a, i64 b) {\r\n    T res = 1;\r\n    for (; b; b /= 2, a *=\
    \ a) {\r\n        if (b % 2) {\r\n            res *= a;\r\n        }\r\n    }\r\
    \n    return res;\r\n}\r\nstruct Z {\r\n    int x;\r\n    Z(int x = 0) : x(norm(x))\
    \ {}\r\n    Z(i64 x) : x(norm(x % P)) {}\r\n    int val() const {\r\n        return\
    \ x;\r\n    }\r\n    Z operator-() const {\r\n        return Z(norm(P - x));\r\
    \n    }\r\n    Z inv() const {\r\n        assert(x != 0);\r\n        return power(*this,\
    \ P - 2);\r\n    }\r\n    Z &operator*=(const Z &rhs) {\r\n        x = i64(x)\
    \ * rhs.x % P;\r\n        return *this;\r\n    }\r\n    Z &operator+=(const Z\
    \ &rhs) {\r\n        x = norm(x + rhs.x);\r\n        return *this;\r\n    }\r\n\
    \    Z &operator-=(const Z &rhs) {\r\n        x = norm(x - rhs.x);\r\n       \
    \ return *this;\r\n    }\r\n    Z &operator/=(const Z &rhs) {\r\n        return\
    \ *this *= rhs.inv();\r\n    }\r\n    friend Z operator*(const Z &lhs, const Z\
    \ &rhs) {\r\n        Z res = lhs;\r\n        res *= rhs;\r\n        return res;\r\
    \n    }\r\n    friend Z operator+(const Z &lhs, const Z &rhs) {\r\n        Z res\
    \ = lhs;\r\n        res += rhs;\r\n        return res;\r\n    }\r\n    friend\
    \ Z operator-(const Z &lhs, const Z &rhs) {\r\n        Z res = lhs;\r\n      \
    \  res -= rhs;\r\n        return res;\r\n    }\r\n    friend Z operator/(const\
    \ Z &lhs, const Z &rhs) {\r\n        Z res = lhs;\r\n        res /= rhs;\r\n \
    \       return res;\r\n    }\r\n    friend std::istream &operator>>(std::istream\
    \ &is, Z &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = Z(v);\r\n\
    \        return is;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Z &a) {\r\n        return os << a.val();\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/05A-ModInt-Old.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/05A-ModInt-Old.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/05A-ModInt-Old.hpp
- /library/src/jiangly/ds/05A-ModInt-Old.hpp.html
title: src/jiangly/ds/05A-ModInt-Old.hpp
---
