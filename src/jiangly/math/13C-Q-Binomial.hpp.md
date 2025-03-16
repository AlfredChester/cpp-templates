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
    - https://codeforces.com/contest/896/submission/219861532
  bundledCode: "#line 1 \"src/jiangly/math/13C-Q-Binomial.hpp\"\n/**   \u751F\u6210\
    \u51FD\u6570\uFF08Binomial \u4EFB\u610F\u6A21\u6570\u4E8C\u9879\u5F0F\uFF09\r\n\
    \ *    2023-08-22: https://codeforces.com/contest/896/submission/219861532\r\n\
    **/\r\nstd::vector<std::pair<int, int>> factorize(int n) {\r\n    std::vector<std::pair<int,\
    \ int>> factors;\r\n    for (int i = 2; static_cast<long long>(i) * i <= n; i++)\
    \ {\r\n        if (n % i == 0) {\r\n            int t = 0;\r\n            for\
    \ (; n % i == 0; n /= i)\r\n                ++t;\r\n            factors.emplace_back(i,\
    \ t);\r\n        }\r\n    }\r\n    if (n > 1)\r\n        factors.emplace_back(n,\
    \ 1);\r\n    return factors;\r\n}\r\nconstexpr int power(int base, i64 exp) {\r\
    \n    int res = 1;\r\n    for (; exp > 0; base *= base, exp /= 2) {\r\n      \
    \  if (exp % 2 == 1) {\r\n            res *= base;\r\n        }\r\n    }\r\n \
    \   return res;\r\n}\r\nconstexpr int power(int base, i64 exp, int mod) {\r\n\
    \    int res = 1 % mod;\r\n    for (; exp > 0; base = 1LL * base * base % mod,\
    \ exp /= 2) {\r\n        if (exp % 2 == 1) {\r\n            res = 1LL * res *\
    \ base % mod;\r\n        }\r\n    }\r\n    return res;\r\n}\r\nint inverse(int\
    \ a, int m) {\r\n    int g = m, r = a, x = 0, y = 1;\r\n    while (r != 0) {\r\
    \n        int q = g / r;\r\n        g %= r;\r\n        std::swap(g, r);\r\n  \
    \      x -= q * y;\r\n        std::swap(x, y);\r\n    }\r\n    return x < 0 ?\
    \ x + m : x;\r\n}\r\nint solveModuloEquations(const std::vector<std::pair<int,\
    \ int>> &e) {\r\n    int m = 1;\r\n    for (std::size_t i = 0; i < e.size(); i++)\
    \ {\r\n        m *= e[i].first;\r\n    }\r\n    int res = 0;\r\n    for (std::size_t\
    \ i = 0; i < e.size(); i++) {\r\n        int p = e[i].first;\r\n        res =\
    \ (res + 1LL * e[i].second * (m / p) * inverse(m / p, p)) % m;\r\n    }\r\n  \
    \  return res;\r\n}\r\nconstexpr int N = 1E5;\r\nclass Binomial {\r\n    const\
    \ int mod;\r\nprivate:\r\n    const std::vector<std::pair<int, int>> factors;\r\
    \n    std::vector<int> pk;\r\n    std::vector<std::vector<int>> prod;\r\n    static\
    \ constexpr i64 exponent(i64 n, int p) {\r\n        i64 res = 0;\r\n        for\
    \ (n /= p; n > 0; n /= p) {\r\n            res += n;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    int product(i64 n, std::size_t i) {\r\n        int res\
    \ = 1;\r\n        int p = factors[i].first;\r\n        for (; n > 0; n /= p) {\r\
    \n            res = 1LL * res * power(prod[i].back(), n / pk[i], pk[i]) % pk[i]\
    \ * prod[i][n % pk[i]] % pk[i];\r\n        }\r\n        return res;\r\n    }\r\
    \npublic:\r\n    Binomial(int mod) : mod(mod), factors(factorize(mod)) {\r\n \
    \       pk.resize(factors.size());\r\n        prod.resize(factors.size());\r\n\
    \        for (std::size_t i = 0; i < factors.size(); i++) {\r\n            int\
    \ p = factors[i].first;\r\n            int k = factors[i].second;\r\n        \
    \    pk[i] = power(p, k);\r\n            prod[i].resize(std::min(N + 1, pk[i]));\r\
    \n            prod[i][0] = 1;\r\n            for (int j = 1; j < prod[i].size();\
    \ j++) {\r\n                if (j % p == 0) {\r\n                    prod[i][j]\
    \ = prod[i][j - 1];\r\n                } else {\r\n                    prod[i][j]\
    \ = 1LL * prod[i][j - 1] * j % pk[i];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n    int operator()(i64 n, i64 m) {\r\n        if (n < m\
    \ || m < 0) {\r\n            return 0;\r\n        }\r\n        std::vector<std::pair<int,\
    \ int>> ans(factors.size());\r\n        for (int i = 0; i < factors.size(); i++)\
    \ {\r\n            int p = factors[i].first;\r\n            int k = factors[i].second;\r\
    \n            int e = exponent(n, p) - exponent(m, p) - exponent(n - m, p);\r\n\
    \            if (e >= k) {\r\n                ans[i] = std::make_pair(pk[i], 0);\r\
    \n            } else {\r\n                int pn = product(n, i);\r\n        \
    \        int pm = product(m, i);\r\n                int pd = product(n - m, i);\r\
    \n                int res = 1LL * pn * inverse(pm, pk[i]) % pk[i] * inverse(pd,\
    \ pk[i]) % pk[i] * power(p, e) % pk[i];\r\n                ans[i] = std::make_pair(pk[i],\
    \ res);\r\n            }\r\n        }\r\n        return solveModuloEquations(ans);\r\
    \n    }\r\n};\n"
  code: "/**   \u751F\u6210\u51FD\u6570\uFF08Binomial \u4EFB\u610F\u6A21\u6570\u4E8C\
    \u9879\u5F0F\uFF09\r\n *    2023-08-22: https://codeforces.com/contest/896/submission/219861532\r\
    \n**/\r\nstd::vector<std::pair<int, int>> factorize(int n) {\r\n    std::vector<std::pair<int,\
    \ int>> factors;\r\n    for (int i = 2; static_cast<long long>(i) * i <= n; i++)\
    \ {\r\n        if (n % i == 0) {\r\n            int t = 0;\r\n            for\
    \ (; n % i == 0; n /= i)\r\n                ++t;\r\n            factors.emplace_back(i,\
    \ t);\r\n        }\r\n    }\r\n    if (n > 1)\r\n        factors.emplace_back(n,\
    \ 1);\r\n    return factors;\r\n}\r\nconstexpr int power(int base, i64 exp) {\r\
    \n    int res = 1;\r\n    for (; exp > 0; base *= base, exp /= 2) {\r\n      \
    \  if (exp % 2 == 1) {\r\n            res *= base;\r\n        }\r\n    }\r\n \
    \   return res;\r\n}\r\nconstexpr int power(int base, i64 exp, int mod) {\r\n\
    \    int res = 1 % mod;\r\n    for (; exp > 0; base = 1LL * base * base % mod,\
    \ exp /= 2) {\r\n        if (exp % 2 == 1) {\r\n            res = 1LL * res *\
    \ base % mod;\r\n        }\r\n    }\r\n    return res;\r\n}\r\nint inverse(int\
    \ a, int m) {\r\n    int g = m, r = a, x = 0, y = 1;\r\n    while (r != 0) {\r\
    \n        int q = g / r;\r\n        g %= r;\r\n        std::swap(g, r);\r\n  \
    \      x -= q * y;\r\n        std::swap(x, y);\r\n    }\r\n    return x < 0 ?\
    \ x + m : x;\r\n}\r\nint solveModuloEquations(const std::vector<std::pair<int,\
    \ int>> &e) {\r\n    int m = 1;\r\n    for (std::size_t i = 0; i < e.size(); i++)\
    \ {\r\n        m *= e[i].first;\r\n    }\r\n    int res = 0;\r\n    for (std::size_t\
    \ i = 0; i < e.size(); i++) {\r\n        int p = e[i].first;\r\n        res =\
    \ (res + 1LL * e[i].second * (m / p) * inverse(m / p, p)) % m;\r\n    }\r\n  \
    \  return res;\r\n}\r\nconstexpr int N = 1E5;\r\nclass Binomial {\r\n    const\
    \ int mod;\r\nprivate:\r\n    const std::vector<std::pair<int, int>> factors;\r\
    \n    std::vector<int> pk;\r\n    std::vector<std::vector<int>> prod;\r\n    static\
    \ constexpr i64 exponent(i64 n, int p) {\r\n        i64 res = 0;\r\n        for\
    \ (n /= p; n > 0; n /= p) {\r\n            res += n;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n    int product(i64 n, std::size_t i) {\r\n        int res\
    \ = 1;\r\n        int p = factors[i].first;\r\n        for (; n > 0; n /= p) {\r\
    \n            res = 1LL * res * power(prod[i].back(), n / pk[i], pk[i]) % pk[i]\
    \ * prod[i][n % pk[i]] % pk[i];\r\n        }\r\n        return res;\r\n    }\r\
    \npublic:\r\n    Binomial(int mod) : mod(mod), factors(factorize(mod)) {\r\n \
    \       pk.resize(factors.size());\r\n        prod.resize(factors.size());\r\n\
    \        for (std::size_t i = 0; i < factors.size(); i++) {\r\n            int\
    \ p = factors[i].first;\r\n            int k = factors[i].second;\r\n        \
    \    pk[i] = power(p, k);\r\n            prod[i].resize(std::min(N + 1, pk[i]));\r\
    \n            prod[i][0] = 1;\r\n            for (int j = 1; j < prod[i].size();\
    \ j++) {\r\n                if (j % p == 0) {\r\n                    prod[i][j]\
    \ = prod[i][j - 1];\r\n                } else {\r\n                    prod[i][j]\
    \ = 1LL * prod[i][j - 1] * j % pk[i];\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n    int operator()(i64 n, i64 m) {\r\n        if (n < m\
    \ || m < 0) {\r\n            return 0;\r\n        }\r\n        std::vector<std::pair<int,\
    \ int>> ans(factors.size());\r\n        for (int i = 0; i < factors.size(); i++)\
    \ {\r\n            int p = factors[i].first;\r\n            int k = factors[i].second;\r\
    \n            int e = exponent(n, p) - exponent(m, p) - exponent(n - m, p);\r\n\
    \            if (e >= k) {\r\n                ans[i] = std::make_pair(pk[i], 0);\r\
    \n            } else {\r\n                int pn = product(n, i);\r\n        \
    \        int pm = product(m, i);\r\n                int pd = product(n - m, i);\r\
    \n                int res = 1LL * pn * inverse(pm, pk[i]) % pk[i] * inverse(pd,\
    \ pk[i]) % pk[i] * power(p, e) % pk[i];\r\n                ans[i] = std::make_pair(pk[i],\
    \ res);\r\n            }\r\n        }\r\n        return solveModuloEquations(ans);\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/13C-Q-Binomial.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/13C-Q-Binomial.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/13C-Q-Binomial.hpp
- /library/src/jiangly/math/13C-Q-Binomial.hpp.html
title: src/jiangly/math/13C-Q-Binomial.hpp
---
