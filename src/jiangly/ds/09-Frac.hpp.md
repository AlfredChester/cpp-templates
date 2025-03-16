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
  bundledCode: "#line 1 \"src/jiangly/ds/09-Frac.hpp\"\ntemplate<class T>\r\nstruct\
    \ Frac {\r\n    T num;\r\n    T den;\r\n    Frac(T num_, T den_) : num(num_),\
    \ den(den_) {\r\n        if (den < 0) {\r\n            den = -den;\r\n       \
    \     num = -num;\r\n        }\r\n    }\r\n    Frac() : Frac(0, 1) {}\r\n    Frac(T\
    \ num_) : Frac(num_, 1) {}\r\n    explicit operator double() const {\r\n     \
    \   return 1. * num / den;\r\n    }\r\n    Frac &operator+=(const Frac &rhs) {\r\
    \n        num = num * rhs.den + rhs.num * den;\r\n        den *= rhs.den;\r\n\
    \        return *this;\r\n    }\r\n    Frac &operator-=(const Frac &rhs) {\r\n\
    \        num = num * rhs.den - rhs.num * den;\r\n        den *= rhs.den;\r\n \
    \       return *this;\r\n    }\r\n    Frac &operator*=(const Frac &rhs) {\r\n\
    \        num *= rhs.num;\r\n        den *= rhs.den;\r\n        return *this;\r\
    \n    }\r\n    Frac &operator/=(const Frac &rhs) {\r\n        num *= rhs.den;\r\
    \n        den *= rhs.num;\r\n        if (den < 0) {\r\n            num = -num;\r\
    \n            den = -den;\r\n        }\r\n        return *this;\r\n    }\r\n \
    \   friend Frac operator+(Frac lhs, const Frac &rhs) {\r\n        return lhs +=\
    \ rhs;\r\n    }\r\n    friend Frac operator-(Frac lhs, const Frac &rhs) {\r\n\
    \        return lhs -= rhs;\r\n    }\r\n    friend Frac operator*(Frac lhs, const\
    \ Frac &rhs) {\r\n        return lhs *= rhs;\r\n    }\r\n    friend Frac operator/(Frac\
    \ lhs, const Frac &rhs) {\r\n        return lhs /= rhs;\r\n    }\r\n    friend\
    \ Frac operator-(const Frac &a) {\r\n        return Frac(-a.num, a.den);\r\n \
    \   }\r\n    friend bool operator==(const Frac &lhs, const Frac &rhs) {\r\n  \
    \      return lhs.num * rhs.den == rhs.num * lhs.den;\r\n    }\r\n    friend bool\
    \ operator!=(const Frac &lhs, const Frac &rhs) {\r\n        return lhs.num * rhs.den\
    \ != rhs.num * lhs.den;\r\n    }\r\n    friend bool operator<(const Frac &lhs,\
    \ const Frac &rhs) {\r\n        return lhs.num * rhs.den < rhs.num * lhs.den;\r\
    \n    }\r\n    friend bool operator>(const Frac &lhs, const Frac &rhs) {\r\n \
    \       return lhs.num * rhs.den > rhs.num * lhs.den;\r\n    }\r\n    friend bool\
    \ operator<=(const Frac &lhs, const Frac &rhs) {\r\n        return lhs.num * rhs.den\
    \ <= rhs.num * lhs.den;\r\n    }\r\n    friend bool operator>=(const Frac &lhs,\
    \ const Frac &rhs) {\r\n        return lhs.num * rhs.den >= rhs.num * lhs.den;\r\
    \n    }\r\n    friend std::ostream &operator<<(std::ostream &os, Frac x) {\r\n\
    \        T g = std::gcd(x.num, x.den);\r\n        if (x.den == g) {\r\n      \
    \      return os << x.num / g;\r\n        } else {\r\n            return os <<\
    \ x.num / g << \"/\" << x.den / g;\r\n        }\r\n    }\r\n};\r\n\r\n"
  code: "template<class T>\r\nstruct Frac {\r\n    T num;\r\n    T den;\r\n    Frac(T\
    \ num_, T den_) : num(num_), den(den_) {\r\n        if (den < 0) {\r\n       \
    \     den = -den;\r\n            num = -num;\r\n        }\r\n    }\r\n    Frac()\
    \ : Frac(0, 1) {}\r\n    Frac(T num_) : Frac(num_, 1) {}\r\n    explicit operator\
    \ double() const {\r\n        return 1. * num / den;\r\n    }\r\n    Frac &operator+=(const\
    \ Frac &rhs) {\r\n        num = num * rhs.den + rhs.num * den;\r\n        den\
    \ *= rhs.den;\r\n        return *this;\r\n    }\r\n    Frac &operator-=(const\
    \ Frac &rhs) {\r\n        num = num * rhs.den - rhs.num * den;\r\n        den\
    \ *= rhs.den;\r\n        return *this;\r\n    }\r\n    Frac &operator*=(const\
    \ Frac &rhs) {\r\n        num *= rhs.num;\r\n        den *= rhs.den;\r\n     \
    \   return *this;\r\n    }\r\n    Frac &operator/=(const Frac &rhs) {\r\n    \
    \    num *= rhs.den;\r\n        den *= rhs.num;\r\n        if (den < 0) {\r\n\
    \            num = -num;\r\n            den = -den;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n    friend Frac operator+(Frac lhs, const Frac &rhs) {\r\n\
    \        return lhs += rhs;\r\n    }\r\n    friend Frac operator-(Frac lhs, const\
    \ Frac &rhs) {\r\n        return lhs -= rhs;\r\n    }\r\n    friend Frac operator*(Frac\
    \ lhs, const Frac &rhs) {\r\n        return lhs *= rhs;\r\n    }\r\n    friend\
    \ Frac operator/(Frac lhs, const Frac &rhs) {\r\n        return lhs /= rhs;\r\n\
    \    }\r\n    friend Frac operator-(const Frac &a) {\r\n        return Frac(-a.num,\
    \ a.den);\r\n    }\r\n    friend bool operator==(const Frac &lhs, const Frac &rhs)\
    \ {\r\n        return lhs.num * rhs.den == rhs.num * lhs.den;\r\n    }\r\n   \
    \ friend bool operator!=(const Frac &lhs, const Frac &rhs) {\r\n        return\
    \ lhs.num * rhs.den != rhs.num * lhs.den;\r\n    }\r\n    friend bool operator<(const\
    \ Frac &lhs, const Frac &rhs) {\r\n        return lhs.num * rhs.den < rhs.num\
    \ * lhs.den;\r\n    }\r\n    friend bool operator>(const Frac &lhs, const Frac\
    \ &rhs) {\r\n        return lhs.num * rhs.den > rhs.num * lhs.den;\r\n    }\r\n\
    \    friend bool operator<=(const Frac &lhs, const Frac &rhs) {\r\n        return\
    \ lhs.num * rhs.den <= rhs.num * lhs.den;\r\n    }\r\n    friend bool operator>=(const\
    \ Frac &lhs, const Frac &rhs) {\r\n        return lhs.num * rhs.den >= rhs.num\
    \ * lhs.den;\r\n    }\r\n    friend std::ostream &operator<<(std::ostream &os,\
    \ Frac x) {\r\n        T g = std::gcd(x.num, x.den);\r\n        if (x.den == g)\
    \ {\r\n            return os << x.num / g;\r\n        } else {\r\n           \
    \ return os << x.num / g << \"/\" << x.den / g;\r\n        }\r\n    }\r\n};\r\n\
    \r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/09-Frac.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/09-Frac.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/09-Frac.hpp
- /library/src/jiangly/ds/09-Frac.hpp.html
title: src/jiangly/ds/09-Frac.hpp
---
