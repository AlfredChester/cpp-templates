---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"src/alfred/math/comb.hpp\"\n\n\n\n#include <vector>\n\n\
    template <class mint>\nstruct Comb {\n    int n;\n    std::vector<mint> _fac,\
    \ _invfac, _inv;\n    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n   \
    \ Comb(int n) : Comb() { init(n); }\n    inline void init(int m) {\n        _fac.resize(m\
    \ + 1), _inv.resize(m + 1), _invfac.resize(m + 1);\n        for (int i = n + 1;\
    \ i <= m; i++) {\n            _fac[i] = _fac[i - 1] * i;\n        }\n        _invfac[m]\
    \ = ~_fac[m];\n        for (int i = m; i > n; i--) {\n            _invfac[i -\
    \ 1] = _invfac[i] * i;\n            _inv[i] = _invfac[i] * _fac[i - 1];\n    \
    \    }\n        n = m;\n    }\n    inline mint fac(int m) {\n        if (m > n)\
    \ init(m);\n        return _fac[m];\n    }\n    inline mint invfac(int m) {\n\
    \        if (m > n) init(m);\n        return _invfac[m];\n    }\n    inline mint\
    \ inv(int m) {\n        if (m > n) init(m);\n        return _inv[m];\n    }\n\
    \    inline mint binom(int n, int m) {\n        if (n < m || m < 0) return 0;\n\
    \        return fac(n) * invfac(m) * invfac(n - m);\n    }\n};\n\n\n"
  code: "#ifndef AFMT_COMB\n#define AFMT_COMB\n\n#include <vector>\n\ntemplate <class\
    \ mint>\nstruct Comb {\n    int n;\n    std::vector<mint> _fac, _invfac, _inv;\n\
    \    Comb(void) : n{0}, _fac{1}, _invfac{1}, _inv{0} {}\n    Comb(int n) : Comb()\
    \ { init(n); }\n    inline void init(int m) {\n        _fac.resize(m + 1), _inv.resize(m\
    \ + 1), _invfac.resize(m + 1);\n        for (int i = n + 1; i <= m; i++) {\n \
    \           _fac[i] = _fac[i - 1] * i;\n        }\n        _invfac[m] = ~_fac[m];\n\
    \        for (int i = m; i > n; i--) {\n            _invfac[i - 1] = _invfac[i]\
    \ * i;\n            _inv[i] = _invfac[i] * _fac[i - 1];\n        }\n        n\
    \ = m;\n    }\n    inline mint fac(int m) {\n        if (m > n) init(m);\n   \
    \     return _fac[m];\n    }\n    inline mint invfac(int m) {\n        if (m >\
    \ n) init(m);\n        return _invfac[m];\n    }\n    inline mint inv(int m) {\n\
    \        if (m > n) init(m);\n        return _inv[m];\n    }\n    inline mint\
    \ binom(int n, int m) {\n        if (n < m || m < 0) return 0;\n        return\
    \ fac(n) * invfac(m) * invfac(n - m);\n    }\n};\n\n#endif // AFMT_COMB"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/math/comb.hpp
  requiredBy:
  - src/alfred/math/lagrange.hpp
  timestamp: '2025-03-25 21:09:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/comb.hpp
layout: document
redirect_from:
- /library/src/alfred/math/comb.hpp
- /library/src/alfred/math/comb.hpp.html
title: src/alfred/math/comb.hpp
---
