---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/alfred/math/comb.hpp
    title: src/alfred/math/comb.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/math/mod-int.hpp
    title: src/alfred/math/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/math/lagrange.hpp\"\n\n\n\n#line 1 \"src/alfred/math/comb.hpp\"\
    \n\n\n\n#line 1 \"src/alfred/math/mod-int.hpp\"\n\n\n#ifndef AFMT_MOD_INT\n#define\
    \ AFMT_MOD_INT\n\n#include <iostream>\n\ntemplate <int mod>\ninline int down(int\
    \ x) { return x >= mod ? x - mod : x; }\ntemplate <int mod>\nstruct ModInt {\n\
    \    int x;\n    ModInt(void) = default;\n    ModInt(int x) : x(x) {}\n    ModInt(long\
    \ long x) : x(x % mod) {}\n    friend std::istream &operator>>(std::istream &in,\
    \ ModInt &a) { return in >> a.x; }\n    friend std::ostream &operator<<(std::ostream\
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
    \ a, ModInt b) { return !(a == b); }\n};\ntemplate <int mod>\ninline void __print(ModInt<mod>\
    \ x) {\n    std::cerr << x;\n}\n\n#endif // AFMT_MOD_INT\n#line 5 \"src/alfred/math/comb.hpp\"\
    \n#include <vector>\n\ntemplate <class mint>\nstruct Comb {\n    int n;\n    std::vector<mint>\
    \ _fac, _invfac, _inv;\n    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n\
    \    Comb(int n) : Comb() { init(n); }\n    inline void init(int m) {\n      \
    \  _fac.resize(m + 1), _inv.resize(m + 1), _invfac.resize(m + 1);\n        for\
    \ (int i = n + 1; i <= m; i++) {\n            _fac[i] = _fac[i - 1] * i;\n   \
    \     }\n        _invfac[m] = ~_fac[m];\n        for (int i = m; i > n; i--) {\n\
    \            _invfac[i - 1] = _invfac[i] * i;\n            _inv[i] = _invfac[i]\
    \ * _fac[i - 1];\n        }\n        n = m;\n    }\n    inline mint fac(int m)\
    \ {\n        if (m > n) init(m);\n        return _fac[m];\n    }\n    inline mint\
    \ invfac(int m) {\n        if (m > n) init(m);\n        return _invfac[m];\n \
    \   }\n    inline mint inv(int m) {\n        if (m > n) init(m);\n        return\
    \ _inv[m];\n    }\n    inline mint binom(int n, int m) {\n        if (n < m ||\
    \ m < 0) return 0;\n        return fac(n) * invfac(m) * invfac(n - m);\n    }\n\
    };\n\n\n#line 1 \"src/alfred/math/mod-int.hpp\"\n\n\n#ifndef AFMT_MOD_INT\n#define\
    \ AFMT_MOD_INT\n\n#include <iostream>\n\ntemplate <int mod>\ninline int down(int\
    \ x) { return x >= mod ? x - mod : x; }\ntemplate <int mod>\nstruct ModInt {\n\
    \    int x;\n    ModInt(void) = default;\n    ModInt(int x) : x(x) {}\n    ModInt(long\
    \ long x) : x(x % mod) {}\n    friend std::istream &operator>>(std::istream &in,\
    \ ModInt &a) { return in >> a.x; }\n    friend std::ostream &operator<<(std::ostream\
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
    \ a, ModInt b) { return !(a == b); }\n};\ntemplate <int mod>\ninline void __print(ModInt<mod>\
    \ x) {\n    std::cerr << x;\n}\n\n#endif // AFMT_MOD_INT\n#line 7 \"src/alfred/math/lagrange.hpp\"\
    \n\nusing mint = ModInt<998244353>;\n\ninline mint lagrange(std::vector<mint>\
    \ &x, std::vector<mint> &y, mint k) {\n    mint ans = 0, cur;\n    const int n\
    \ = x.size();\n    for (int i = 0; i < n; i++) {\n        cur = y[i];\n      \
    \  for (int j = 0; j < n; j++) {\n            if (j == i) continue;\n        \
    \    cur *= (k - x[j]) / (x[i] - x[j]);\n        }\n        ans += cur;\n    }\n\
    \    return ans;\n}\n// y[0] is placeholder.\n// If for all integer x_i in [1,\
    \ n], we have f(x_i) = y_i (mod p), find f(k) mod p.\ninline mint cont_lagrange(std::vector<mint>\
    \ &y, mint k) {\n    mint ans = 0;\n    const int n = y.size() - 1;\n    Comb<mint>\
    \ comb(n);\n    std::vector<mint> pre(n + 1, 1), suf(n + 2, 1);\n    for (int\
    \ i = 1; i <= n; i++) pre[i] = pre[i - 1] * (k - i);\n    for (int i = n; i >=\
    \ 1; i--) suf[i] = suf[i + 1] * (k - i);\n    for (int i = 1; i <= n; i++) {\n\
    \        mint A = pre[i - 1] * suf[i + 1];\n        mint B = comb.fac(i - 1) *\
    \ comb.fac(n - i);\n        ans += ((n - i) & 1 ? -1 : 1) * y[i] * A / B;\n  \
    \  }\n    return ans;\n}\n// find 1^k + 2^k + ... + n^k. in O(k log k) of time\
    \ complexity.\ninline mint sum_of_kth_powers(mint n, int k) {\n    mint sum =\
    \ 0;\n    std::vector<mint> Y{0};\n    for (int i = 1; i <= k + 2; i++) {\n  \
    \      Y.push_back(sum += (mint)i ^ k);\n    }\n    return cont_lagrange(Y, n);\n\
    }\n\n\n"
  code: "#ifndef AFMT_LAGRANGE\n#define AFMT_LAGRANGE\n\n#include \"comb.hpp\"\n#include\
    \ \"mod-int.hpp\"\n#include <vector>\n\nusing mint = ModInt<998244353>;\n\ninline\
    \ mint lagrange(std::vector<mint> &x, std::vector<mint> &y, mint k) {\n    mint\
    \ ans = 0, cur;\n    const int n = x.size();\n    for (int i = 0; i < n; i++)\
    \ {\n        cur = y[i];\n        for (int j = 0; j < n; j++) {\n            if\
    \ (j == i) continue;\n            cur *= (k - x[j]) / (x[i] - x[j]);\n       \
    \ }\n        ans += cur;\n    }\n    return ans;\n}\n// y[0] is placeholder.\n\
    // If for all integer x_i in [1, n], we have f(x_i) = y_i (mod p), find f(k) mod\
    \ p.\ninline mint cont_lagrange(std::vector<mint> &y, mint k) {\n    mint ans\
    \ = 0;\n    const int n = y.size() - 1;\n    Comb<mint> comb(n);\n    std::vector<mint>\
    \ pre(n + 1, 1), suf(n + 2, 1);\n    for (int i = 1; i <= n; i++) pre[i] = pre[i\
    \ - 1] * (k - i);\n    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] * (k -\
    \ i);\n    for (int i = 1; i <= n; i++) {\n        mint A = pre[i - 1] * suf[i\
    \ + 1];\n        mint B = comb.fac(i - 1) * comb.fac(n - i);\n        ans += ((n\
    \ - i) & 1 ? -1 : 1) * y[i] * A / B;\n    }\n    return ans;\n}\n// find 1^k +\
    \ 2^k + ... + n^k. in O(k log k) of time complexity.\ninline mint sum_of_kth_powers(mint\
    \ n, int k) {\n    mint sum = 0;\n    std::vector<mint> Y{0};\n    for (int i\
    \ = 1; i <= k + 2; i++) {\n        Y.push_back(sum += (mint)i ^ k);\n    }\n \
    \   return cont_lagrange(Y, n);\n}\n\n#endif // AFMT_LAGRANGE\n"
  dependsOn:
  - src/alfred/math/comb.hpp
  - src/alfred/math/mod-int.hpp
  isVerificationFile: false
  path: src/alfred/math/lagrange.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/lagrange.hpp
layout: document
redirect_from:
- /library/src/alfred/math/lagrange.hpp
- /library/src/alfred/math/lagrange.hpp.html
title: src/alfred/math/lagrange.hpp
---
