---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/alfred/math/mod-int.hpp
    title: src/alfred/math/mod-int.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/alfred/math/lagrange.hpp
    title: src/alfred/math/lagrange.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/alfred/math/comb.hpp\"\n\n#line 2 \"src/alfred/math/mod-int.hpp\"\
    \n\n#include <bits/stdc++.h>\n\ntemplate <int mod>\ninline int down(int x) { return\
    \ x >= mod ? x - mod : x; }\ntemplate <int mod>\nstruct ModInt {\n    int x;\n\
    \    ModInt(void) = default;\n    ModInt(int x) : x(x) {}\n    ModInt(long long\
    \ x) : x(x % mod) {}\n    friend std::istream &operator>>(std::istream &in, ModInt\
    \ &a) { return in >> a.x; }\n    friend std::ostream &operator<<(std::ostream\
    \ &out, ModInt a) { return out << a.x; }\n    friend ModInt operator+(ModInt a,\
    \ ModInt b) { return down<mod>(a.x + b.x); }\n    friend ModInt operator-(ModInt\
    \ a, ModInt b) { return down<mod>(a.x - b.x + mod); }\n    friend ModInt operator*(ModInt\
    \ a, ModInt b) { return (long long)a.x * b.x % mod; }\n    friend ModInt operator/(ModInt\
    \ a, ModInt b) { return a * ~b; }\n    friend ModInt operator^(ModInt a, long\
    \ long b) {\n        ModInt ans = 1;\n        for (; b > 0; b >>= 1, a *= a)\n\
    \            if (b & 1) ans *= a;\n        return ans;\n    }\n    friend ModInt\
    \ operator~(ModInt a) { return a ^ (mod - 2); }\n    friend ModInt operator-(ModInt\
    \ a) { return down<mod>(mod - a.x); }\n    friend ModInt &operator+=(ModInt &a,\
    \ ModInt b) { return a = a + b; }\n    friend ModInt &operator-=(ModInt &a, ModInt\
    \ b) { return a = a - b; }\n    friend ModInt &operator*=(ModInt &a, ModInt b)\
    \ { return a = a * b; }\n    friend ModInt &operator/=(ModInt &a, ModInt b) {\
    \ return a = a / b; }\n    friend ModInt &operator^=(ModInt &a, long long b) {\
    \ return a = a ^ b; }\n    friend ModInt &operator++(ModInt &a) { return a +=\
    \ 1; }\n    friend ModInt operator++(ModInt &a, int) {\n        ModInt x = a;\n\
    \        a += 1;\n        return x;\n    }\n    friend ModInt &operator--(ModInt\
    \ &a) { return a -= 1; }\n    friend ModInt operator--(ModInt &a, int) {\n   \
    \     ModInt x = a;\n        a -= 1;\n        return x;\n    }\n    friend bool\
    \ operator==(ModInt a, ModInt b) { return a.x == b.x; }\n    friend bool operator!=(ModInt\
    \ a, ModInt b) { return !(a == b); }\n};\ninline void __print(mint x) { std::cerr\
    \ << x; }\n#line 5 \"src/alfred/math/comb.hpp\"\n\ntemplate <class mint>\nstruct\
    \ Comb {\n    int n;\n    std::vector<mint> _fac, _invfac, _inv;\n    Comb(void)\
    \ : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n    Comb(int n) : Comb() { init(n);\
    \ }\n    inline void init(int m) {\n        _fac.resize(m + 1), _inv.resize(m\
    \ + 1), _invfac.resize(m + 1);\n        for (int i = n + 1; i <= m; i++) {\n \
    \           _fac[i] = _fac[i - 1] * i;\n        }\n        _invfac[m] = ~_fac[m];\n\
    \        for (int i = m; i > n; i--) {\n            _invfac[i - 1] = _invfac[i]\
    \ * i;\n            _inv[i] = _invfac[i] * _fac[i - 1];\n        }\n        n\
    \ = m;\n    }\n    inline mint fac(int m) {\n        if (m > n) init(m);\n   \
    \     return _fac[m];\n    }\n    inline mint invfac(int m) {\n        if (m >\
    \ n) init(m);\n        return _invfac[m];\n    }\n    inline mint inv(int m) {\n\
    \        if (m > n) init(m);\n        return _inv[m];\n    }\n    inline mint\
    \ binom(int n, int m) {\n        if (n < m || m < 0) return 0;\n        return\
    \ fac(n) * invfac(m) * invfac(n - m);\n    }\n};\n\nusing mint = ModInt<998244353>;\n\
    Comb<mint> comb;\n"
  code: "#pragma once\n\n#include \"mod-int.hpp\"\n#include <bits/stdc++.h>\n\ntemplate\
    \ <class mint>\nstruct Comb {\n    int n;\n    std::vector<mint> _fac, _invfac,\
    \ _inv;\n    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n    Comb(int\
    \ n) : Comb() { init(n); }\n    inline void init(int m) {\n        _fac.resize(m\
    \ + 1), _inv.resize(m + 1), _invfac.resize(m + 1);\n        for (int i = n + 1;\
    \ i <= m; i++) {\n            _fac[i] = _fac[i - 1] * i;\n        }\n        _invfac[m]\
    \ = ~_fac[m];\n        for (int i = m; i > n; i--) {\n            _invfac[i -\
    \ 1] = _invfac[i] * i;\n            _inv[i] = _invfac[i] * _fac[i - 1];\n    \
    \    }\n        n = m;\n    }\n    inline mint fac(int m) {\n        if (m > n)\
    \ init(m);\n        return _fac[m];\n    }\n    inline mint invfac(int m) {\n\
    \        if (m > n) init(m);\n        return _invfac[m];\n    }\n    inline mint\
    \ inv(int m) {\n        if (m > n) init(m);\n        return _inv[m];\n    }\n\
    \    inline mint binom(int n, int m) {\n        if (n < m || m < 0) return 0;\n\
    \        return fac(n) * invfac(m) * invfac(n - m);\n    }\n};\n\nusing mint =\
    \ ModInt<998244353>;\nComb<mint> comb;"
  dependsOn:
  - src/alfred/math/mod-int.hpp
  isVerificationFile: false
  path: src/alfred/math/comb.hpp
  requiredBy:
  - src/alfred/math/lagrange.hpp
  timestamp: '2025-02-28 18:17:33+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/comb.hpp
layout: document
redirect_from:
- /library/src/alfred/math/comb.hpp
- /library/src/alfred/math/comb.hpp.html
title: src/alfred/math/comb.hpp
---
