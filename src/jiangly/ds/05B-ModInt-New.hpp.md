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
  bundledCode: "#line 1 \"src/jiangly/ds/05B-ModInt-New.hpp\"\ntemplate <class T>\r\
    \nconstexpr T power(T a, i64 b) {\r\n    T res = 1;\r\n    for (; b; b /= 2, a\
    \ *= a) {\r\n        if (b % 2) {\r\n            res *= a;\r\n        }\r\n  \
    \  }\r\n    return res;\r\n}\r\n\r\nconstexpr i64 mul(i64 a, i64 b, i64 p) {\r\
    \n    i64 res = a * b - i64(1.L * a * b / p) * p;\r\n    res %= p;\r\n    if (res\
    \ < 0) {\r\n        res += p;\r\n    }\r\n    return res;\r\n}\r\ntemplate <i64\
    \ P>\r\nstruct MLong {\r\n    i64 x;\r\n    constexpr MLong() : x{} {}\r\n   \
    \ constexpr MLong(i64 x) : x{norm(x % getMod())} {}\r\n\r\n    static i64 Mod;\r\
    \n    constexpr static i64 getMod() {\r\n        if (P > 0) {\r\n            return\
    \ P;\r\n        } else {\r\n            return Mod;\r\n        }\r\n    }\r\n\
    \    constexpr static void setMod(i64 Mod_) {\r\n        Mod = Mod_;\r\n    }\r\
    \n    constexpr i64 norm(i64 x) const {\r\n        if (x < 0) {\r\n          \
    \  x += getMod();\r\n        }\r\n        if (x >= getMod()) {\r\n           \
    \ x -= getMod();\r\n        }\r\n        return x;\r\n    }\r\n    constexpr i64\
    \ val() const {\r\n        return x;\r\n    }\r\n    explicit constexpr operator\
    \ i64() const {\r\n        return x;\r\n    }\r\n    constexpr MLong operator-()\
    \ const {\r\n        MLong res;\r\n        res.x = norm(getMod() - x);\r\n   \
    \     return res;\r\n    }\r\n    constexpr MLong inv() const {\r\n        assert(x\
    \ != 0);\r\n        return power(*this, getMod() - 2);\r\n    }\r\n    constexpr\
    \ MLong &operator*=(MLong rhs) & {\r\n        x = mul(x, rhs.x, getMod());\r\n\
    \        return *this;\r\n    }\r\n    constexpr MLong &operator+=(MLong rhs)\
    \ & {\r\n        x = norm(x + rhs.x);\r\n        return *this;\r\n    }\r\n  \
    \  constexpr MLong &operator-=(MLong rhs) & {\r\n        x = norm(x - rhs.x);\r\
    \n        return *this;\r\n    }\r\n    constexpr MLong &operator/=(MLong rhs)\
    \ & {\r\n        return *this *= rhs.inv();\r\n    }\r\n    friend constexpr MLong\
    \ operator*(MLong lhs, MLong rhs) {\r\n        MLong res = lhs;\r\n        res\
    \ *= rhs;\r\n        return res;\r\n    }\r\n    friend constexpr MLong operator+(MLong\
    \ lhs, MLong rhs) {\r\n        MLong res = lhs;\r\n        res += rhs;\r\n   \
    \     return res;\r\n    }\r\n    friend constexpr MLong operator-(MLong lhs,\
    \ MLong rhs) {\r\n        MLong res = lhs;\r\n        res -= rhs;\r\n        return\
    \ res;\r\n    }\r\n    friend constexpr MLong operator/(MLong lhs, MLong rhs)\
    \ {\r\n        MLong res = lhs;\r\n        res /= rhs;\r\n        return res;\r\
    \n    }\r\n    friend constexpr std::istream &operator>>(std::istream &is, MLong\
    \ &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = MLong(v);\r\n   \
    \     return is;\r\n    }\r\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const MLong &a) {\r\n        return os << a.val();\r\n    }\r\n    friend\
    \ constexpr bool operator==(MLong lhs, MLong rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend constexpr bool operator!=(MLong lhs, MLong\
    \ rhs) {\r\n        return lhs.val() != rhs.val();\r\n    }\r\n};\r\n\r\ntemplate\
    \ <>\r\ni64 MLong<0LL>::Mod = i64(1E18) + 9;\r\n\r\ntemplate <int P>\r\nstruct\
    \ MInt {\r\n    int x;\r\n    constexpr MInt() : x{} {}\r\n    constexpr MInt(i64\
    \ x) : x{norm(x % getMod())} {}\r\n\r\n    static int Mod;\r\n    constexpr static\
    \ int getMod() {\r\n        if (P > 0) {\r\n            return P;\r\n        }\
    \ else {\r\n            return Mod;\r\n        }\r\n    }\r\n    constexpr static\
    \ void setMod(int Mod_) {\r\n        Mod = Mod_;\r\n    }\r\n    constexpr int\
    \ norm(int x) const {\r\n        if (x < 0) {\r\n            x += getMod();\r\n\
    \        }\r\n        if (x >= getMod()) {\r\n            x -= getMod();\r\n \
    \       }\r\n        return x;\r\n    }\r\n    constexpr int val() const {\r\n\
    \        return x;\r\n    }\r\n    explicit constexpr operator int() const {\r\
    \n        return x;\r\n    }\r\n    constexpr MInt operator-() const {\r\n   \
    \     MInt res;\r\n        res.x = norm(getMod() - x);\r\n        return res;\r\
    \n    }\r\n    constexpr MInt inv() const {\r\n        assert(x != 0);\r\n   \
    \     return power(*this, getMod() - 2);\r\n    }\r\n    constexpr MInt &operator*=(MInt\
    \ rhs) & {\r\n        x = 1LL * x * rhs.x % getMod();\r\n        return *this;\r\
    \n    }\r\n    constexpr MInt &operator+=(MInt rhs) & {\r\n        x = norm(x\
    \ + rhs.x);\r\n        return *this;\r\n    }\r\n    constexpr MInt &operator-=(MInt\
    \ rhs) & {\r\n        x = norm(x - rhs.x);\r\n        return *this;\r\n    }\r\
    \n    constexpr MInt &operator/=(MInt rhs) & {\r\n        return *this *= rhs.inv();\r\
    \n    }\r\n    friend constexpr MInt operator*(MInt lhs, MInt rhs) {\r\n     \
    \   MInt res = lhs;\r\n        res *= rhs;\r\n        return res;\r\n    }\r\n\
    \    friend constexpr MInt operator+(MInt lhs, MInt rhs) {\r\n        MInt res\
    \ = lhs;\r\n        res += rhs;\r\n        return res;\r\n    }\r\n    friend\
    \ constexpr MInt operator-(MInt lhs, MInt rhs) {\r\n        MInt res = lhs;\r\n\
    \        res -= rhs;\r\n        return res;\r\n    }\r\n    friend constexpr MInt\
    \ operator/(MInt lhs, MInt rhs) {\r\n        MInt res = lhs;\r\n        res /=\
    \ rhs;\r\n        return res;\r\n    }\r\n    friend constexpr std::istream &operator>>(std::istream\
    \ &is, MInt &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = MInt(v);\r\
    \n        return is;\r\n    }\r\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const MInt &a) {\r\n        return os << a.val();\r\n    }\r\n    friend\
    \ constexpr bool operator==(MInt lhs, MInt rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend constexpr bool operator!=(MInt lhs, MInt\
    \ rhs) {\r\n        return lhs.val() != rhs.val();\r\n    }\r\n};\r\n\r\ntemplate\
    \ <>\r\nint MInt<0>::Mod = 998244353;\r\n\r\ntemplate <int V, int P>\r\nconstexpr\
    \ MInt<P> CInv = MInt<P>(V).inv();\r\n\r\nconstexpr int P = 1000000007;\r\nusing\
    \ Z = MInt<P>;\r\n"
  code: "template <class T>\r\nconstexpr T power(T a, i64 b) {\r\n    T res = 1;\r\
    \n    for (; b; b /= 2, a *= a) {\r\n        if (b % 2) {\r\n            res *=\
    \ a;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\r\nconstexpr i64 mul(i64\
    \ a, i64 b, i64 p) {\r\n    i64 res = a * b - i64(1.L * a * b / p) * p;\r\n  \
    \  res %= p;\r\n    if (res < 0) {\r\n        res += p;\r\n    }\r\n    return\
    \ res;\r\n}\r\ntemplate <i64 P>\r\nstruct MLong {\r\n    i64 x;\r\n    constexpr\
    \ MLong() : x{} {}\r\n    constexpr MLong(i64 x) : x{norm(x % getMod())} {}\r\n\
    \r\n    static i64 Mod;\r\n    constexpr static i64 getMod() {\r\n        if (P\
    \ > 0) {\r\n            return P;\r\n        } else {\r\n            return Mod;\r\
    \n        }\r\n    }\r\n    constexpr static void setMod(i64 Mod_) {\r\n     \
    \   Mod = Mod_;\r\n    }\r\n    constexpr i64 norm(i64 x) const {\r\n        if\
    \ (x < 0) {\r\n            x += getMod();\r\n        }\r\n        if (x >= getMod())\
    \ {\r\n            x -= getMod();\r\n        }\r\n        return x;\r\n    }\r\
    \n    constexpr i64 val() const {\r\n        return x;\r\n    }\r\n    explicit\
    \ constexpr operator i64() const {\r\n        return x;\r\n    }\r\n    constexpr\
    \ MLong operator-() const {\r\n        MLong res;\r\n        res.x = norm(getMod()\
    \ - x);\r\n        return res;\r\n    }\r\n    constexpr MLong inv() const {\r\
    \n        assert(x != 0);\r\n        return power(*this, getMod() - 2);\r\n  \
    \  }\r\n    constexpr MLong &operator*=(MLong rhs) & {\r\n        x = mul(x, rhs.x,\
    \ getMod());\r\n        return *this;\r\n    }\r\n    constexpr MLong &operator+=(MLong\
    \ rhs) & {\r\n        x = norm(x + rhs.x);\r\n        return *this;\r\n    }\r\
    \n    constexpr MLong &operator-=(MLong rhs) & {\r\n        x = norm(x - rhs.x);\r\
    \n        return *this;\r\n    }\r\n    constexpr MLong &operator/=(MLong rhs)\
    \ & {\r\n        return *this *= rhs.inv();\r\n    }\r\n    friend constexpr MLong\
    \ operator*(MLong lhs, MLong rhs) {\r\n        MLong res = lhs;\r\n        res\
    \ *= rhs;\r\n        return res;\r\n    }\r\n    friend constexpr MLong operator+(MLong\
    \ lhs, MLong rhs) {\r\n        MLong res = lhs;\r\n        res += rhs;\r\n   \
    \     return res;\r\n    }\r\n    friend constexpr MLong operator-(MLong lhs,\
    \ MLong rhs) {\r\n        MLong res = lhs;\r\n        res -= rhs;\r\n        return\
    \ res;\r\n    }\r\n    friend constexpr MLong operator/(MLong lhs, MLong rhs)\
    \ {\r\n        MLong res = lhs;\r\n        res /= rhs;\r\n        return res;\r\
    \n    }\r\n    friend constexpr std::istream &operator>>(std::istream &is, MLong\
    \ &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = MLong(v);\r\n   \
    \     return is;\r\n    }\r\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const MLong &a) {\r\n        return os << a.val();\r\n    }\r\n    friend\
    \ constexpr bool operator==(MLong lhs, MLong rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend constexpr bool operator!=(MLong lhs, MLong\
    \ rhs) {\r\n        return lhs.val() != rhs.val();\r\n    }\r\n};\r\n\r\ntemplate\
    \ <>\r\ni64 MLong<0LL>::Mod = i64(1E18) + 9;\r\n\r\ntemplate <int P>\r\nstruct\
    \ MInt {\r\n    int x;\r\n    constexpr MInt() : x{} {}\r\n    constexpr MInt(i64\
    \ x) : x{norm(x % getMod())} {}\r\n\r\n    static int Mod;\r\n    constexpr static\
    \ int getMod() {\r\n        if (P > 0) {\r\n            return P;\r\n        }\
    \ else {\r\n            return Mod;\r\n        }\r\n    }\r\n    constexpr static\
    \ void setMod(int Mod_) {\r\n        Mod = Mod_;\r\n    }\r\n    constexpr int\
    \ norm(int x) const {\r\n        if (x < 0) {\r\n            x += getMod();\r\n\
    \        }\r\n        if (x >= getMod()) {\r\n            x -= getMod();\r\n \
    \       }\r\n        return x;\r\n    }\r\n    constexpr int val() const {\r\n\
    \        return x;\r\n    }\r\n    explicit constexpr operator int() const {\r\
    \n        return x;\r\n    }\r\n    constexpr MInt operator-() const {\r\n   \
    \     MInt res;\r\n        res.x = norm(getMod() - x);\r\n        return res;\r\
    \n    }\r\n    constexpr MInt inv() const {\r\n        assert(x != 0);\r\n   \
    \     return power(*this, getMod() - 2);\r\n    }\r\n    constexpr MInt &operator*=(MInt\
    \ rhs) & {\r\n        x = 1LL * x * rhs.x % getMod();\r\n        return *this;\r\
    \n    }\r\n    constexpr MInt &operator+=(MInt rhs) & {\r\n        x = norm(x\
    \ + rhs.x);\r\n        return *this;\r\n    }\r\n    constexpr MInt &operator-=(MInt\
    \ rhs) & {\r\n        x = norm(x - rhs.x);\r\n        return *this;\r\n    }\r\
    \n    constexpr MInt &operator/=(MInt rhs) & {\r\n        return *this *= rhs.inv();\r\
    \n    }\r\n    friend constexpr MInt operator*(MInt lhs, MInt rhs) {\r\n     \
    \   MInt res = lhs;\r\n        res *= rhs;\r\n        return res;\r\n    }\r\n\
    \    friend constexpr MInt operator+(MInt lhs, MInt rhs) {\r\n        MInt res\
    \ = lhs;\r\n        res += rhs;\r\n        return res;\r\n    }\r\n    friend\
    \ constexpr MInt operator-(MInt lhs, MInt rhs) {\r\n        MInt res = lhs;\r\n\
    \        res -= rhs;\r\n        return res;\r\n    }\r\n    friend constexpr MInt\
    \ operator/(MInt lhs, MInt rhs) {\r\n        MInt res = lhs;\r\n        res /=\
    \ rhs;\r\n        return res;\r\n    }\r\n    friend constexpr std::istream &operator>>(std::istream\
    \ &is, MInt &a) {\r\n        i64 v;\r\n        is >> v;\r\n        a = MInt(v);\r\
    \n        return is;\r\n    }\r\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const MInt &a) {\r\n        return os << a.val();\r\n    }\r\n    friend\
    \ constexpr bool operator==(MInt lhs, MInt rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend constexpr bool operator!=(MInt lhs, MInt\
    \ rhs) {\r\n        return lhs.val() != rhs.val();\r\n    }\r\n};\r\n\r\ntemplate\
    \ <>\r\nint MInt<0>::Mod = 998244353;\r\n\r\ntemplate <int V, int P>\r\nconstexpr\
    \ MInt<P> CInv = MInt<P>(V).inv();\r\n\r\nconstexpr int P = 1000000007;\r\nusing\
    \ Z = MInt<P>;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/05B-ModInt-New.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/05B-ModInt-New.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/05B-ModInt-New.hpp
- /library/src/jiangly/ds/05B-ModInt-New.hpp.html
title: src/jiangly/ds/05B-ModInt-New.hpp
---
