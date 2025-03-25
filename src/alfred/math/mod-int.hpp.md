---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
    title: verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/math/mod-int.hpp\"\n\n\n#ifndef AFMT_MOD_INT\n\
    #define AFMT_MOD_INT\n\n#include <iostream>\n\ntemplate <int mod>\ninline int\
    \ down(int x) { return x >= mod ? x - mod : x; }\ntemplate <int mod>\ninline int\
    \ up(int x) { return x < 0 ? x + mod : x; }\ntemplate <int mod>\nstruct ModInt\
    \ {\n    int x;\n    ModInt(void) = default;\n    ModInt(int x) : x(up<mod>(x))\
    \ {}\n    ModInt(long long x) : x(x % mod) {}\n    friend std::istream &operator>>(std::istream\
    \ &in, ModInt &a) { return in >> a.x; }\n    friend std::ostream &operator<<(std::ostream\
    \ &out, ModInt a) { return out << a.x; }\n    friend ModInt operator+(ModInt a,\
    \ ModInt b) { return down<mod>(a.x + b.x); }\n    friend ModInt operator-(ModInt\
    \ a, ModInt b) { return down<mod>(a.x - b.x + mod); }\n    friend ModInt operator*(ModInt\
    \ a, ModInt b) { return (long long)a.x * b.x; }\n    friend ModInt operator/(ModInt\
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
    \ a, ModInt b) { return !(a == b); }\n};\ntemplate <int mod>\ninline void __print(ModInt<mod>\
    \ x) {\n    std::cerr << x;\n}\n\nusing m998 = ModInt<998244353>;\nusing m107\
    \ = ModInt<1000000007>;\n\n#endif // AFMT_MOD_INT\n"
  code: "\n\n#ifndef AFMT_MOD_INT\n#define AFMT_MOD_INT\n\n#include <iostream>\n\n\
    template <int mod>\ninline int down(int x) { return x >= mod ? x - mod : x; }\n\
    template <int mod>\ninline int up(int x) { return x < 0 ? x + mod : x; }\ntemplate\
    \ <int mod>\nstruct ModInt {\n    int x;\n    ModInt(void) = default;\n    ModInt(int\
    \ x) : x(up<mod>(x)) {}\n    ModInt(long long x) : x(x % mod) {}\n    friend std::istream\
    \ &operator>>(std::istream &in, ModInt &a) { return in >> a.x; }\n    friend std::ostream\
    \ &operator<<(std::ostream &out, ModInt a) { return out << a.x; }\n    friend\
    \ ModInt operator+(ModInt a, ModInt b) { return down<mod>(a.x + b.x); }\n    friend\
    \ ModInt operator-(ModInt a, ModInt b) { return down<mod>(a.x - b.x + mod); }\n\
    \    friend ModInt operator*(ModInt a, ModInt b) { return (long long)a.x * b.x;\
    \ }\n    friend ModInt operator/(ModInt a, ModInt b) { return a * ~b; }\n    friend\
    \ ModInt operator^(ModInt a, long long b) {\n        ModInt ans = 1;\n       \
    \ for (; b > 0; b >>= 1, a *= a)\n            if (b & 1) ans *= a;\n        return\
    \ ans;\n    }\n    friend ModInt operator~(ModInt a) { return a ^ (mod - 2); }\n\
    \    friend ModInt operator-(ModInt a) { return down<mod>(mod - a.x); }\n    friend\
    \ ModInt &operator+=(ModInt &a, ModInt b) { return a = a + b; }\n    friend ModInt\
    \ &operator-=(ModInt &a, ModInt b) { return a = a - b; }\n    friend ModInt &operator*=(ModInt\
    \ &a, ModInt b) { return a = a * b; }\n    friend ModInt &operator/=(ModInt &a,\
    \ ModInt b) { return a = a / b; }\n    friend ModInt &operator^=(ModInt &a, long\
    \ long b) { return a = a ^ b; }\n    friend ModInt &operator++(ModInt &a) { return\
    \ a += 1; }\n    friend ModInt operator++(ModInt &a, int) {\n        ModInt x\
    \ = a;\n        a += 1;\n        return x;\n    }\n    friend ModInt &operator--(ModInt\
    \ &a) { return a -= 1; }\n    friend ModInt operator--(ModInt &a, int) {\n   \
    \     ModInt x = a;\n        a -= 1;\n        return x;\n    }\n    friend bool\
    \ operator==(ModInt a, ModInt b) { return a.x == b.x; }\n    friend bool operator!=(ModInt\
    \ a, ModInt b) { return !(a == b); }\n};\ntemplate <int mod>\ninline void __print(ModInt<mod>\
    \ x) {\n    std::cerr << x;\n}\n\nusing m998 = ModInt<998244353>;\nusing m107\
    \ = ModInt<1000000007>;\n\n#endif // AFMT_MOD_INT\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/math/mod-int.hpp
  requiredBy: []
  timestamp: '2025-03-25 20:32:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
documentation_of: src/alfred/math/mod-int.hpp
layout: document
redirect_from:
- /library/src/alfred/math/mod-int.hpp
- /library/src/alfred/math/mod-int.hpp.html
title: src/alfred/math/mod-int.hpp
---
