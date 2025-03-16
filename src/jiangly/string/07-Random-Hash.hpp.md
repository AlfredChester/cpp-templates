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
  bundledCode: "#line 1 \"src/jiangly/string/07-Random-Hash.hpp\"\n#include <bits/stdc++.h>\r\
    \n\r\nusing i64 = long long;\r\n\r\nbool isprime(int n) {\r\n    if (n <= 1) {\r\
    \n        return false;\r\n    }\r\n    for (int i = 2; i * i <= n; i++) {\r\n\
    \        if (n % i == 0) {\r\n            return false;\r\n        }\r\n    }\r\
    \n    return true;\r\n}\r\n\r\nint findPrime(int n) {\r\n    while (!isprime(n))\
    \ {\r\n        n++;\r\n    }\r\n    return n;\r\n}\r\n\r\nusing Hash = std::array<int,\
    \ 2>;\r\n\r\nint main() {\r\n    std::ios::sync_with_stdio(false);\r\n    std::cin.tie(nullptr);\r\
    \n    \r\n    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \n    \r\n    const int P = findPrime(rng() % 900000000 + 100000000);\r\n    \r\
    \n    std::string s, x;\r\n    std::cin >> s >> x;\r\n    \r\n    int n = s.length();\r\
    \n    int m = x.length();\r\n    \r\n    std::vector<int> h(n + 1), p(n + 1);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        h[i + 1] = (10LL * h[i] + s[i]\
    \ - '0') % P;\r\n    }\r\n    p[0] = 1;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        p[i + 1] = 10LL * p[i] % P;\r\n    }\r\n    \r\n    auto get = [&](int\
    \ l, int r) {\r\n        return (h[r] + 1LL * (P - h[l]) * p[r - l]) % P;\r\n\
    \    };\r\n    \r\n    int px = 0;\r\n    for (auto c : x) {\r\n        px = (10LL\
    \ * px + c - '0') % P;\r\n    }\r\n    \r\n    for (int i = 0; i <= n - 2 * (m\
    \ - 1); i++) {\r\n        if ((get(i, i + m - 1) + get(i + m - 1, i + 2 * m -\
    \ 2)) % P == px) {\r\n            std::cout << i + 1 << \" \" << i + m - 1 <<\
    \ \"\\n\";\r\n            std::cout << i + m << \" \" << i + 2 * m - 2 << \"\\\
    n\";\r\n            return 0;\r\n        }\r\n    }\r\n    \r\n    std::vector<int>\
    \ z(m + 1), f(n + 1);\r\n    z[0] = m;\r\n    \r\n    for (int i = 1, j = -1;\
    \ i < m; i++) {\r\n        if (j != -1) {\r\n            z[i] = std::max(0, std::min(j\
    \ + z[j] - i, z[i - j]));\r\n        }\r\n        while (z[i] + i < m && x[z[i]]\
    \ == x[z[i] + i]) {\r\n            z[i]++;\r\n        }\r\n        if (j == -1\
    \ || i + z[i] > j + z[j]) {\r\n            j = i;\r\n        }\r\n    }\r\n  \
    \  for (int i = 0, j = -1; i < n; i++) {\r\n        if (j != -1) {\r\n       \
    \     f[i] = std::max(0, std::min(j + f[j] - i, z[i - j]));\r\n        }\r\n \
    \       while (f[i] + i < n && f[i] < m && x[f[i]] == s[f[i] + i]) {\r\n     \
    \       f[i]++;\r\n        }\r\n        if (j == -1 || i + f[i] > j + f[j]) {\r\
    \n            j = i;\r\n        }\r\n    }\r\n    \r\n    for (int i = 0; i +\
    \ m <= n; i++) {\r\n        int l = std::min(m, f[i]);\r\n        \r\n       \
    \ for (auto j : { m - l, m - l - 1 }) {\r\n            if (j <= 0) {\r\n     \
    \           continue;\r\n            }\r\n            if (j <= i && (get(i - j,\
    \ i) + get(i, i + m)) % P == px) {\r\n                std::cout << i - j + 1 <<\
    \ \" \" << i << \"\\n\";\r\n                std::cout << i + 1 << \" \" << i +\
    \ m << \"\\n\";\r\n                return 0;\r\n            }\r\n            if\
    \ (i + m + j <= n && (get(i, i + m) + get(i + m, i + m + j)) % P == px) {\r\n\
    \                std::cout << i + 1 << \" \" << i + m << \"\\n\";\r\n        \
    \        std::cout << i + m + 1 << \" \" << i + m + j << \"\\n\";\r\n        \
    \        return 0;\r\n            }\r\n        }\r\n    }\r\n    \r\n    return\
    \ 0;\r\n}\r\n\r\n"
  code: "#include <bits/stdc++.h>\r\n\r\nusing i64 = long long;\r\n\r\nbool isprime(int\
    \ n) {\r\n    if (n <= 1) {\r\n        return false;\r\n    }\r\n    for (int\
    \ i = 2; i * i <= n; i++) {\r\n        if (n % i == 0) {\r\n            return\
    \ false;\r\n        }\r\n    }\r\n    return true;\r\n}\r\n\r\nint findPrime(int\
    \ n) {\r\n    while (!isprime(n)) {\r\n        n++;\r\n    }\r\n    return n;\r\
    \n}\r\n\r\nusing Hash = std::array<int, 2>;\r\n\r\nint main() {\r\n    std::ios::sync_with_stdio(false);\r\
    \n    std::cin.tie(nullptr);\r\n    \r\n    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \n    \r\n    const int P = findPrime(rng() % 900000000 + 100000000);\r\n    \r\
    \n    std::string s, x;\r\n    std::cin >> s >> x;\r\n    \r\n    int n = s.length();\r\
    \n    int m = x.length();\r\n    \r\n    std::vector<int> h(n + 1), p(n + 1);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        h[i + 1] = (10LL * h[i] + s[i]\
    \ - '0') % P;\r\n    }\r\n    p[0] = 1;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        p[i + 1] = 10LL * p[i] % P;\r\n    }\r\n    \r\n    auto get = [&](int\
    \ l, int r) {\r\n        return (h[r] + 1LL * (P - h[l]) * p[r - l]) % P;\r\n\
    \    };\r\n    \r\n    int px = 0;\r\n    for (auto c : x) {\r\n        px = (10LL\
    \ * px + c - '0') % P;\r\n    }\r\n    \r\n    for (int i = 0; i <= n - 2 * (m\
    \ - 1); i++) {\r\n        if ((get(i, i + m - 1) + get(i + m - 1, i + 2 * m -\
    \ 2)) % P == px) {\r\n            std::cout << i + 1 << \" \" << i + m - 1 <<\
    \ \"\\n\";\r\n            std::cout << i + m << \" \" << i + 2 * m - 2 << \"\\\
    n\";\r\n            return 0;\r\n        }\r\n    }\r\n    \r\n    std::vector<int>\
    \ z(m + 1), f(n + 1);\r\n    z[0] = m;\r\n    \r\n    for (int i = 1, j = -1;\
    \ i < m; i++) {\r\n        if (j != -1) {\r\n            z[i] = std::max(0, std::min(j\
    \ + z[j] - i, z[i - j]));\r\n        }\r\n        while (z[i] + i < m && x[z[i]]\
    \ == x[z[i] + i]) {\r\n            z[i]++;\r\n        }\r\n        if (j == -1\
    \ || i + z[i] > j + z[j]) {\r\n            j = i;\r\n        }\r\n    }\r\n  \
    \  for (int i = 0, j = -1; i < n; i++) {\r\n        if (j != -1) {\r\n       \
    \     f[i] = std::max(0, std::min(j + f[j] - i, z[i - j]));\r\n        }\r\n \
    \       while (f[i] + i < n && f[i] < m && x[f[i]] == s[f[i] + i]) {\r\n     \
    \       f[i]++;\r\n        }\r\n        if (j == -1 || i + f[i] > j + f[j]) {\r\
    \n            j = i;\r\n        }\r\n    }\r\n    \r\n    for (int i = 0; i +\
    \ m <= n; i++) {\r\n        int l = std::min(m, f[i]);\r\n        \r\n       \
    \ for (auto j : { m - l, m - l - 1 }) {\r\n            if (j <= 0) {\r\n     \
    \           continue;\r\n            }\r\n            if (j <= i && (get(i - j,\
    \ i) + get(i, i + m)) % P == px) {\r\n                std::cout << i - j + 1 <<\
    \ \" \" << i << \"\\n\";\r\n                std::cout << i + 1 << \" \" << i +\
    \ m << \"\\n\";\r\n                return 0;\r\n            }\r\n            if\
    \ (i + m + j <= n && (get(i, i + m) + get(i + m, i + m + j)) % P == px) {\r\n\
    \                std::cout << i + 1 << \" \" << i + m << \"\\n\";\r\n        \
    \        std::cout << i + m + 1 << \" \" << i + m + j << \"\\n\";\r\n        \
    \        return 0;\r\n            }\r\n        }\r\n    }\r\n    \r\n    return\
    \ 0;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/07-Random-Hash.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/07-Random-Hash.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/07-Random-Hash.hpp
- /library/src/jiangly/string/07-Random-Hash.hpp.html
title: src/jiangly/string/07-Random-Hash.hpp
---
