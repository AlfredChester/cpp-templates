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
    - https://qoj.ac/submission/187270
    - https://qoj.ac/submission/381482
  bundledCode: "#line 1 \"src/jiangly/string/03B-Suffix-Array.hpp\"\n/**   \u540E\u7F00\
    \u6570\u7EC4\uFF08SA\u53CA\u5176\u5E94\u7528 \u65B0\u7248\uFF09\r\n *    2023-09-24:\
    \ https://qoj.ac/submission/187270\r\n *    2024-04-07: https://qoj.ac/submission/381482\r\
    \n**/\r\nstruct SA {\r\n    int n;\r\n    std::vector<int> sa, rk, lc;\r\n\r\n\
    \    SA(std::string s) {\r\n        n = s.size();\r\n        sa.resize(n);\r\n\
    \        lc.resize(n - 1);\r\n        rk.resize(n);\r\n        std::iota(sa.begin(),\
    \ sa.end(), 0);\r\n        std::sort(sa.begin(), sa.end(),\r\n            [&](int\
    \ a, int b) {\r\n                return s[a] < s[b];\r\n            });\r\n  \
    \      rk[sa[0]] = 0;\r\n        for (int i = 1; i < n; i++) {\r\n           \
    \ rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);\r\n        }\r\n   \
    \     int k = 1;\r\n        std::vector<int> tmp, cnt(n);\r\n        tmp.reserve(n);\r\
    \n        while (rk[sa[n - 1]] < n - 1) {\r\n            tmp.clear();\r\n    \
    \        for (int i = 0; i < k; i++) {\r\n                tmp.push_back(n - k\
    \ + i);\r\n            }\r\n            for (auto i : sa) {\r\n              \
    \  if (i >= k) {\r\n                    tmp.push_back(i - k);\r\n            \
    \    }\r\n            }\r\n            std::fill(cnt.begin(), cnt.end(), 0);\r\
    \n            for (int i = 0; i < n; i++) {\r\n                cnt[rk[i]]++;\r\
    \n            }\r\n            for (int i = 1; i < n; i++) {\r\n             \
    \   cnt[i] += cnt[i - 1];\r\n            }\r\n            for (int i = n - 1;\
    \ i >= 0; i--) {\r\n                sa[--cnt[rk[tmp[i]]]] = tmp[i];\r\n      \
    \      }\r\n            std::swap(rk, tmp);\r\n            rk[sa[0]] = 0;\r\n\
    \            for (int i = 1; i < n; i++) {\r\n                rk[sa[i]] = rk[sa[i\
    \ - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1]\
    \ + k] < tmp[sa[i] + k]);\r\n            }\r\n            k *= 2;\r\n        }\r\
    \n        for (int i = 0, j = 0; i < n; i++) {\r\n            if (rk[i] == 0)\
    \ {\r\n                j = 0;\r\n            } else {\r\n                for (j\
    \ -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1]\
    \ + j]; ) {\r\n                    j++;\r\n                }\r\n             \
    \   lc[rk[i] - 1] = j;\r\n            }\r\n        }\r\n    }\r\n};\r\n\r\nvoid\
    \ solve() {\r\n    constexpr int K = 21;\r\n    std::vector st(K, std::vector<int>(l\
    \ - 1));\r\n    st[0] = lc;\r\n    for (int j = 0; j < K - 1; j++) {\r\n     \
    \   for (int i = 0; i + (2 << j) <= l - 1; i++) {\r\n            st[j + 1][i]\
    \ = std::min(st[j][i], st[j][i + (1 << j)]);\r\n        }\r\n    }\r\n    \r\n\
    \    auto rmq = [&](int l, int r) {\r\n        int k = std::__lg(r - l);\r\n \
    \       return std::min(st[k][l], st[k][r - (1 << k)]);\r\n    };\r\n\r\n    auto\
    \ lcp = [&](int i, int j) {\r\n        if (i == j || i == n || j == n) {\r\n \
    \           return std::min(n - i, n - j);\r\n        }\r\n        int a = rk[i];\r\
    \n        int b = rk[j];\r\n        if (a > b) {\r\n            std::swap(a, b);\r\
    \n        }\r\n        return std::min({n - i, n - j, rmq(a, b)});\r\n    };\r\
    \n    \r\n    auto lcs = [&](int i, int j) {\r\n        if (i == j || i == 0 ||\
    \ j == 0) {\r\n            return std::min(i, j);\r\n        }\r\n        int\
    \ a = rk[n + n - i];\r\n        int b = rk[n + n - j];\r\n        if (a > b) {\r\
    \n            std::swap(a, b);\r\n        }\r\n        return std::min({i, j,\
    \ rmq(a, b)});\r\n    };\r\n}\n"
  code: "/**   \u540E\u7F00\u6570\u7EC4\uFF08SA\u53CA\u5176\u5E94\u7528 \u65B0\u7248\
    \uFF09\r\n *    2023-09-24: https://qoj.ac/submission/187270\r\n *    2024-04-07:\
    \ https://qoj.ac/submission/381482\r\n**/\r\nstruct SA {\r\n    int n;\r\n   \
    \ std::vector<int> sa, rk, lc;\r\n\r\n    SA(std::string s) {\r\n        n = s.size();\r\
    \n        sa.resize(n);\r\n        lc.resize(n - 1);\r\n        rk.resize(n);\r\
    \n        std::iota(sa.begin(), sa.end(), 0);\r\n        std::sort(sa.begin(),\
    \ sa.end(),\r\n            [&](int a, int b) {\r\n                return s[a]\
    \ < s[b];\r\n            });\r\n        rk[sa[0]] = 0;\r\n        for (int i =\
    \ 1; i < n; i++) {\r\n            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i\
    \ - 1]]);\r\n        }\r\n        int k = 1;\r\n        std::vector<int> tmp,\
    \ cnt(n);\r\n        tmp.reserve(n);\r\n        while (rk[sa[n - 1]] < n - 1)\
    \ {\r\n            tmp.clear();\r\n            for (int i = 0; i < k; i++) {\r\
    \n                tmp.push_back(n - k + i);\r\n            }\r\n            for\
    \ (auto i : sa) {\r\n                if (i >= k) {\r\n                    tmp.push_back(i\
    \ - k);\r\n                }\r\n            }\r\n            std::fill(cnt.begin(),\
    \ cnt.end(), 0);\r\n            for (int i = 0; i < n; i++) {\r\n            \
    \    cnt[rk[i]]++;\r\n            }\r\n            for (int i = 1; i < n; i++)\
    \ {\r\n                cnt[i] += cnt[i - 1];\r\n            }\r\n            for\
    \ (int i = n - 1; i >= 0; i--) {\r\n                sa[--cnt[rk[tmp[i]]]] = tmp[i];\r\
    \n            }\r\n            std::swap(rk, tmp);\r\n            rk[sa[0]] =\
    \ 0;\r\n            for (int i = 1; i < n; i++) {\r\n                rk[sa[i]]\
    \ = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i\
    \ - 1] + k] < tmp[sa[i] + k]);\r\n            }\r\n            k *= 2;\r\n   \
    \     }\r\n        for (int i = 0, j = 0; i < n; i++) {\r\n            if (rk[i]\
    \ == 0) {\r\n                j = 0;\r\n            } else {\r\n              \
    \  for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i]\
    \ - 1] + j]; ) {\r\n                    j++;\r\n                }\r\n        \
    \        lc[rk[i] - 1] = j;\r\n            }\r\n        }\r\n    }\r\n};\r\n\r\
    \nvoid solve() {\r\n    constexpr int K = 21;\r\n    std::vector st(K, std::vector<int>(l\
    \ - 1));\r\n    st[0] = lc;\r\n    for (int j = 0; j < K - 1; j++) {\r\n     \
    \   for (int i = 0; i + (2 << j) <= l - 1; i++) {\r\n            st[j + 1][i]\
    \ = std::min(st[j][i], st[j][i + (1 << j)]);\r\n        }\r\n    }\r\n    \r\n\
    \    auto rmq = [&](int l, int r) {\r\n        int k = std::__lg(r - l);\r\n \
    \       return std::min(st[k][l], st[k][r - (1 << k)]);\r\n    };\r\n\r\n    auto\
    \ lcp = [&](int i, int j) {\r\n        if (i == j || i == n || j == n) {\r\n \
    \           return std::min(n - i, n - j);\r\n        }\r\n        int a = rk[i];\r\
    \n        int b = rk[j];\r\n        if (a > b) {\r\n            std::swap(a, b);\r\
    \n        }\r\n        return std::min({n - i, n - j, rmq(a, b)});\r\n    };\r\
    \n    \r\n    auto lcs = [&](int i, int j) {\r\n        if (i == j || i == 0 ||\
    \ j == 0) {\r\n            return std::min(i, j);\r\n        }\r\n        int\
    \ a = rk[n + n - i];\r\n        int b = rk[n + n - j];\r\n        if (a > b) {\r\
    \n            std::swap(a, b);\r\n        }\r\n        return std::min({i, j,\
    \ rmq(a, b)});\r\n    };\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/03B-Suffix-Array.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/03B-Suffix-Array.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/03B-Suffix-Array.hpp
- /library/src/jiangly/string/03B-Suffix-Array.hpp.html
title: src/jiangly/string/03B-Suffix-Array.hpp
---
