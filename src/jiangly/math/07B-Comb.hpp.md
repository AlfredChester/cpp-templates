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
    - https://codeforces.com/contest/1864/submission/220584872
  bundledCode: "#line 1 \"src/jiangly/math/07B-Comb.hpp\"\n/**   \u7EC4\u5408\u6570\
    \uFF08Comb, with. MInt & MLong\uFF09\r\n *    2023-08-26: https://codeforces.com/contest/1864/submission/220584872\r\
    \n**/\r\nstruct Comb {\r\n    int n;\r\n    std::vector<Z> _fac;\r\n    std::vector<Z>\
    \ _invfac;\r\n    std::vector<Z> _inv;\r\n    \r\n    Comb() : n{0}, _fac{1},\
    \ _invfac{1}, _inv{0} {}\r\n    Comb(int n) : Comb() {\r\n        init(n);\r\n\
    \    }\r\n    \r\n    void init(int m) {\r\n        m = std::min(m, Z::getMod()\
    \ - 1);\r\n        if (m <= n) return;\r\n        _fac.resize(m + 1);\r\n    \
    \    _invfac.resize(m + 1);\r\n        _inv.resize(m + 1);\r\n        \r\n   \
    \     for (int i = n + 1; i <= m; i++) {\r\n            _fac[i] = _fac[i - 1]\
    \ * i;\r\n        }\r\n        _invfac[m] = _fac[m].inv();\r\n        for (int\
    \ i = m; i > n; i--) {\r\n            _invfac[i - 1] = _invfac[i] * i;\r\n   \
    \         _inv[i] = _invfac[i] * _fac[i - 1];\r\n        }\r\n        n = m;\r\
    \n    }\r\n    \r\n    Z fac(int m) {\r\n        if (m > n) init(2 * m);\r\n \
    \       return _fac[m];\r\n    }\r\n    Z invfac(int m) {\r\n        if (m > n)\
    \ init(2 * m);\r\n        return _invfac[m];\r\n    }\r\n    Z inv(int m) {\r\n\
    \        if (m > n) init(2 * m);\r\n        return _inv[m];\r\n    }\r\n    Z\
    \ binom(int n, int m) {\r\n        if (n < m || m < 0) return 0;\r\n        return\
    \ fac(n) * invfac(m) * invfac(n - m);\r\n    }\r\n} comb;\r\n\r\n"
  code: "/**   \u7EC4\u5408\u6570\uFF08Comb, with. MInt & MLong\uFF09\r\n *    2023-08-26:\
    \ https://codeforces.com/contest/1864/submission/220584872\r\n**/\r\nstruct Comb\
    \ {\r\n    int n;\r\n    std::vector<Z> _fac;\r\n    std::vector<Z> _invfac;\r\
    \n    std::vector<Z> _inv;\r\n    \r\n    Comb() : n{0}, _fac{1}, _invfac{1},\
    \ _inv{0} {}\r\n    Comb(int n) : Comb() {\r\n        init(n);\r\n    }\r\n  \
    \  \r\n    void init(int m) {\r\n        m = std::min(m, Z::getMod() - 1);\r\n\
    \        if (m <= n) return;\r\n        _fac.resize(m + 1);\r\n        _invfac.resize(m\
    \ + 1);\r\n        _inv.resize(m + 1);\r\n        \r\n        for (int i = n +\
    \ 1; i <= m; i++) {\r\n            _fac[i] = _fac[i - 1] * i;\r\n        }\r\n\
    \        _invfac[m] = _fac[m].inv();\r\n        for (int i = m; i > n; i--) {\r\
    \n            _invfac[i - 1] = _invfac[i] * i;\r\n            _inv[i] = _invfac[i]\
    \ * _fac[i - 1];\r\n        }\r\n        n = m;\r\n    }\r\n    \r\n    Z fac(int\
    \ m) {\r\n        if (m > n) init(2 * m);\r\n        return _fac[m];\r\n    }\r\
    \n    Z invfac(int m) {\r\n        if (m > n) init(2 * m);\r\n        return _invfac[m];\r\
    \n    }\r\n    Z inv(int m) {\r\n        if (m > n) init(2 * m);\r\n        return\
    \ _inv[m];\r\n    }\r\n    Z binom(int n, int m) {\r\n        if (n < m || m <\
    \ 0) return 0;\r\n        return fac(n) * invfac(m) * invfac(n - m);\r\n    }\r\
    \n} comb;\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/07B-Comb.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/07B-Comb.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/07B-Comb.hpp
- /library/src/jiangly/math/07B-Comb.hpp.html
title: src/jiangly/math/07B-Comb.hpp
---
