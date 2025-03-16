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
  bundledCode: "#line 1 \"src/jiangly/math/08-Prime.hpp\"\ni64 mul(i64 a, i64 b, i64\
    \ m) {\r\n    return static_cast<__int128>(a) * b % m;\r\n}\r\ni64 power(i64 a,\
    \ i64 b, i64 m) {\r\n    i64 res = 1 % m;\r\n    for (; b; b >>= 1, a = mul(a,\
    \ a, m))\r\n        if (b & 1)\r\n            res = mul(res, a, m);\r\n    return\
    \ res;\r\n}\r\nbool isprime(i64 n) {\r\n    if (n < 2)\r\n        return false;\r\
    \n    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};\r\n    int\
    \ s = __builtin_ctzll(n - 1);\r\n    i64 d = (n - 1) >> s;\r\n    for (auto a\
    \ : A) {\r\n        if (a == n)\r\n            return true;\r\n        i64 x =\
    \ power(a, d, n);\r\n        if (x == 1 || x == n - 1)\r\n            continue;\r\
    \n        bool ok = false;\r\n        for (int i = 0; i < s - 1; ++i) {\r\n  \
    \          x = mul(x, x, n);\r\n            if (x == n - 1) {\r\n            \
    \    ok = true;\r\n                break;\r\n            }\r\n        }\r\n  \
    \      if (!ok)\r\n            return false;\r\n    }\r\n    return true;\r\n\
    }\r\nstd::vector<i64> factorize(i64 n) {\r\n    std::vector<i64> p;\r\n    std::function<void(i64)>\
    \ f = [&](i64 n) {\r\n        if (n <= 10000) {\r\n            for (int i = 2;\
    \ i * i <= n; ++i)\r\n                for (; n % i == 0; n /= i)\r\n         \
    \           p.push_back(i);\r\n            if (n > 1)\r\n                p.push_back(n);\r\
    \n            return;\r\n        }\r\n        if (isprime(n)) {\r\n          \
    \  p.push_back(n);\r\n            return;\r\n        }\r\n        auto g = [&](i64\
    \ x) {\r\n            return (mul(x, x, n) + 1) % n;\r\n        };\r\n       \
    \ i64 x0 = 2;\r\n        while (true) {\r\n            i64 x = x0;\r\n       \
    \     i64 y = x0;\r\n            i64 d = 1;\r\n            i64 power = 1, lam\
    \ = 0;\r\n            i64 v = 1;\r\n            while (d == 1) {\r\n         \
    \       y = g(y);\r\n                ++lam;\r\n                v = mul(v, std::abs(x\
    \ - y), n);\r\n                if (lam % 127 == 0) {\r\n                    d\
    \ = std::gcd(v, n);\r\n                    v = 1;\r\n                }\r\n   \
    \             if (power == lam) {\r\n                    x = y;\r\n          \
    \          power *= 2;\r\n                    lam = 0;\r\n                   \
    \ d = std::gcd(v, n);\r\n                    v = 1;\r\n                }\r\n \
    \           }\r\n            if (d != n) {\r\n                f(d);\r\n      \
    \          f(n / d);\r\n                return;\r\n            }\r\n         \
    \   ++x0;\r\n        }\r\n    };\r\n    f(n);\r\n    std::sort(p.begin(), p.end());\r\
    \n    return p;\r\n}\r\n\r\n"
  code: "i64 mul(i64 a, i64 b, i64 m) {\r\n    return static_cast<__int128>(a) * b\
    \ % m;\r\n}\r\ni64 power(i64 a, i64 b, i64 m) {\r\n    i64 res = 1 % m;\r\n  \
    \  for (; b; b >>= 1, a = mul(a, a, m))\r\n        if (b & 1)\r\n            res\
    \ = mul(res, a, m);\r\n    return res;\r\n}\r\nbool isprime(i64 n) {\r\n    if\
    \ (n < 2)\r\n        return false;\r\n    static constexpr int A[] = {2, 3, 5,\
    \ 7, 11, 13, 17, 19, 23};\r\n    int s = __builtin_ctzll(n - 1);\r\n    i64 d\
    \ = (n - 1) >> s;\r\n    for (auto a : A) {\r\n        if (a == n)\r\n       \
    \     return true;\r\n        i64 x = power(a, d, n);\r\n        if (x == 1 ||\
    \ x == n - 1)\r\n            continue;\r\n        bool ok = false;\r\n       \
    \ for (int i = 0; i < s - 1; ++i) {\r\n            x = mul(x, x, n);\r\n     \
    \       if (x == n - 1) {\r\n                ok = true;\r\n                break;\r\
    \n            }\r\n        }\r\n        if (!ok)\r\n            return false;\r\
    \n    }\r\n    return true;\r\n}\r\nstd::vector<i64> factorize(i64 n) {\r\n  \
    \  std::vector<i64> p;\r\n    std::function<void(i64)> f = [&](i64 n) {\r\n  \
    \      if (n <= 10000) {\r\n            for (int i = 2; i * i <= n; ++i)\r\n \
    \               for (; n % i == 0; n /= i)\r\n                    p.push_back(i);\r\
    \n            if (n > 1)\r\n                p.push_back(n);\r\n            return;\r\
    \n        }\r\n        if (isprime(n)) {\r\n            p.push_back(n);\r\n  \
    \          return;\r\n        }\r\n        auto g = [&](i64 x) {\r\n         \
    \   return (mul(x, x, n) + 1) % n;\r\n        };\r\n        i64 x0 = 2;\r\n  \
    \      while (true) {\r\n            i64 x = x0;\r\n            i64 y = x0;\r\n\
    \            i64 d = 1;\r\n            i64 power = 1, lam = 0;\r\n           \
    \ i64 v = 1;\r\n            while (d == 1) {\r\n                y = g(y);\r\n\
    \                ++lam;\r\n                v = mul(v, std::abs(x - y), n);\r\n\
    \                if (lam % 127 == 0) {\r\n                    d = std::gcd(v,\
    \ n);\r\n                    v = 1;\r\n                }\r\n                if\
    \ (power == lam) {\r\n                    x = y;\r\n                    power\
    \ *= 2;\r\n                    lam = 0;\r\n                    d = std::gcd(v,\
    \ n);\r\n                    v = 1;\r\n                }\r\n            }\r\n\
    \            if (d != n) {\r\n                f(d);\r\n                f(n / d);\r\
    \n                return;\r\n            }\r\n            ++x0;\r\n        }\r\
    \n    };\r\n    f(n);\r\n    std::sort(p.begin(), p.end());\r\n    return p;\r\
    \n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/08-Prime.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/08-Prime.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/08-Prime.hpp
- /library/src/jiangly/math/08-Prime.hpp.html
title: src/jiangly/math/08-Prime.hpp
---
