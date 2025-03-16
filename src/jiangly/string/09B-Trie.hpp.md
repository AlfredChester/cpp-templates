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
    - https://cf.dianhsu.com/gym/105222/submission/266217560?version=1.5
    - https://codeforces.com/contest/1980/submission/263960334
    - https://qoj.ac/submission/188957
  bundledCode: "#line 1 \"src/jiangly/string/09B-Trie.hpp\"\n```cpp\r\n    /**   \u5B57\
    \u5178\u6811 Trie\r\n     *    2023-09-26: https://qoj.ac/submission/188957\r\n\
    \     **/\r\n    constexpr i64 inf = 1E18;\r\n\r\nconstexpr int N = 1E6 + 10;\r\
    \n\r\nint trie[N][26];\r\nint tot;\r\n\r\nint newNode() {\r\n    tot++;\r\n  \
    \  std::fill(trie[tot], trie[tot] + 26, 0);\r\n    val[tot] = inf;\r\n    return\
    \ tot;\r\n}\r\n\r\nvoid solve() {\r\n    //* init\r\n    tot = 0;\r\n    newNode();\r\
    \n\r\n    //* insert\r\n    for (int i = 0; i < N; i++) {\r\n        int p = 1;\r\
    \n        int l = S[i].size();\r\n        for (int j = 0; j < l; j++) {\r\n  \
    \          int x = S[i][j] - 'a';\r\n            if (!trie[p][x]) {\r\n      \
    \          trie[p][x] = newNode();\r\n            }\r\n            p = trie[p][x];\r\
    \n            //* \u5904\u7406\r\n            //* val[p] = std::min(val[p], l\
    \ + K + f[(K - (l - j - 1) % K) % K]);\r\n        }\r\n    }\r\n\r\n    //* query\r\
    \n    for (int i = 0; i < L; i++) {\r\n        int p = 1;\r\n        for (int\
    \ j = i; j < L; j++) {\r\n            int x = T[j] - 'a';\r\n            p = trie[p][x];\r\
    \n            if (!p) {\r\n                continue;\r\n            }\r\n    \
    \        //* \u5904\u7406\r\n            //* dp[j + 1] = std::min(dp[j + 1], dp[i]\
    \ + val[p]);\r\n        }\r\n    }\r\n}\r\n```\r\n\r\n```cpp\r\n    /**   \u5B57\
    \u5178\u6811 Trie\r\n     *    2024-06-18: https://cf.dianhsu.com/gym/105222/submission/266217560?version=1.5\r\
    \n     **/\r\n    int tot;\r\nint trie[N][2];\r\nint f[N];\r\n\r\nint newNode()\
    \ {\r\n    int x = ++tot;\r\n    trie[x][0] = trie[x][1] = 0;\r\n    f[x] = inf;\r\
    \n    return x;\r\n}\r\nvoid add(int x, int i) {\r\n    int p = 1;\r\n    for\
    \ (int j = 29; j >= 0; j--) {\r\n        int &q = trie[p][x >> j & 1];\r\n   \
    \     if (q == 0) {\r\n            q = newNode();\r\n        }\r\n        p =\
    \ q;\r\n        f[p] = std::min(f[p], i);\r\n    }\r\n}\r\n\r\nint query(int a,\
    \ int b) {\r\n    int ans1 = inf, ans2 = inf;\r\n    int p = 1;\r\n    for (int\
    \ i = 29; i >= 0; i--) {\r\n        int d = a >> i & 1;\r\n        int e = b >>\
    \ i & 1;\r\n        if (e) {\r\n            ans1 = std::min(ans1, f[trie[p][d]]);\r\
    \n        } else {\r\n            ans2 = std::min(ans2, f[trie[p][d ^ 1]]);\r\n\
    \        }\r\n        p = trie[p][e ^ d];\r\n    }\r\n    ans1 = std::min(ans1,\
    \ f[p]);\r\n    ans2 = std::min(ans2, f[p]);\r\n    if (ans1 == inf || ans2 ==\
    \ inf) {\r\n        return -1;\r\n    }\r\n    return std::max({1, ans1, ans2});\r\
    \n}\r\n```\r\n\r\n```cpp\r\n    /**   \u5B57\u5178\u6811 Trie\r\n     *    2024-06-03:\
    \ https://codeforces.com/contest/1980/submission/263960334\r\n     **/\r\n   \
    \ int trie[N][2];\r\nint cnt[N][2];\r\n\r\nint tot = 0;\r\nint newNode() {\r\n\
    \    int x = ++tot;\r\n    trie[x][0] = trie[x][1] = 0;\r\n    cnt[x][0] = cnt[x][1]\
    \ = 0;\r\n    return x;\r\n}\r\n\r\nvoid add(int x, int d, int t = 1) {\r\n  \
    \  int p = 1;\r\n    cnt[p][d] += t;\r\n    for (int i = 29; i >= 0; i--) {\r\n\
    \        int u = x >> i & 1;\r\n        if (!trie[p][u]) {\r\n            trie[p][u]\
    \ = newNode();\r\n        }\r\n        p = trie[p][u];\r\n        cnt[p][d] +=\
    \ t;\r\n    }\r\n}\r\n\r\nint query(int x, int d) {\r\n    int p = 1;\r\n    if\
    \ (!cnt[p][d]) {\r\n        return 0;\r\n    }\r\n    int ans = 0;\r\n    for\
    \ (int i = 29; i >= 0; i--) {\r\n        int u = x >> i & 1;\r\n        if (cnt[trie[p][u\
    \ ^ 1]][d]) {\r\n            ans |= 1 << i;\r\n            p = trie[p][u ^ 1];\r\
    \n        } else {\r\n            p = trie[p][u];\r\n        }\r\n    }\r\n  \
    \  return ans;\r\n}\r\n```\n"
  code: "```cpp\r\n    /**   \u5B57\u5178\u6811 Trie\r\n     *    2023-09-26: https://qoj.ac/submission/188957\r\
    \n     **/\r\n    constexpr i64 inf = 1E18;\r\n\r\nconstexpr int N = 1E6 + 10;\r\
    \n\r\nint trie[N][26];\r\nint tot;\r\n\r\nint newNode() {\r\n    tot++;\r\n  \
    \  std::fill(trie[tot], trie[tot] + 26, 0);\r\n    val[tot] = inf;\r\n    return\
    \ tot;\r\n}\r\n\r\nvoid solve() {\r\n    //* init\r\n    tot = 0;\r\n    newNode();\r\
    \n\r\n    //* insert\r\n    for (int i = 0; i < N; i++) {\r\n        int p = 1;\r\
    \n        int l = S[i].size();\r\n        for (int j = 0; j < l; j++) {\r\n  \
    \          int x = S[i][j] - 'a';\r\n            if (!trie[p][x]) {\r\n      \
    \          trie[p][x] = newNode();\r\n            }\r\n            p = trie[p][x];\r\
    \n            //* \u5904\u7406\r\n            //* val[p] = std::min(val[p], l\
    \ + K + f[(K - (l - j - 1) % K) % K]);\r\n        }\r\n    }\r\n\r\n    //* query\r\
    \n    for (int i = 0; i < L; i++) {\r\n        int p = 1;\r\n        for (int\
    \ j = i; j < L; j++) {\r\n            int x = T[j] - 'a';\r\n            p = trie[p][x];\r\
    \n            if (!p) {\r\n                continue;\r\n            }\r\n    \
    \        //* \u5904\u7406\r\n            //* dp[j + 1] = std::min(dp[j + 1], dp[i]\
    \ + val[p]);\r\n        }\r\n    }\r\n}\r\n```\r\n\r\n```cpp\r\n    /**   \u5B57\
    \u5178\u6811 Trie\r\n     *    2024-06-18: https://cf.dianhsu.com/gym/105222/submission/266217560?version=1.5\r\
    \n     **/\r\n    int tot;\r\nint trie[N][2];\r\nint f[N];\r\n\r\nint newNode()\
    \ {\r\n    int x = ++tot;\r\n    trie[x][0] = trie[x][1] = 0;\r\n    f[x] = inf;\r\
    \n    return x;\r\n}\r\nvoid add(int x, int i) {\r\n    int p = 1;\r\n    for\
    \ (int j = 29; j >= 0; j--) {\r\n        int &q = trie[p][x >> j & 1];\r\n   \
    \     if (q == 0) {\r\n            q = newNode();\r\n        }\r\n        p =\
    \ q;\r\n        f[p] = std::min(f[p], i);\r\n    }\r\n}\r\n\r\nint query(int a,\
    \ int b) {\r\n    int ans1 = inf, ans2 = inf;\r\n    int p = 1;\r\n    for (int\
    \ i = 29; i >= 0; i--) {\r\n        int d = a >> i & 1;\r\n        int e = b >>\
    \ i & 1;\r\n        if (e) {\r\n            ans1 = std::min(ans1, f[trie[p][d]]);\r\
    \n        } else {\r\n            ans2 = std::min(ans2, f[trie[p][d ^ 1]]);\r\n\
    \        }\r\n        p = trie[p][e ^ d];\r\n    }\r\n    ans1 = std::min(ans1,\
    \ f[p]);\r\n    ans2 = std::min(ans2, f[p]);\r\n    if (ans1 == inf || ans2 ==\
    \ inf) {\r\n        return -1;\r\n    }\r\n    return std::max({1, ans1, ans2});\r\
    \n}\r\n```\r\n\r\n```cpp\r\n    /**   \u5B57\u5178\u6811 Trie\r\n     *    2024-06-03:\
    \ https://codeforces.com/contest/1980/submission/263960334\r\n     **/\r\n   \
    \ int trie[N][2];\r\nint cnt[N][2];\r\n\r\nint tot = 0;\r\nint newNode() {\r\n\
    \    int x = ++tot;\r\n    trie[x][0] = trie[x][1] = 0;\r\n    cnt[x][0] = cnt[x][1]\
    \ = 0;\r\n    return x;\r\n}\r\n\r\nvoid add(int x, int d, int t = 1) {\r\n  \
    \  int p = 1;\r\n    cnt[p][d] += t;\r\n    for (int i = 29; i >= 0; i--) {\r\n\
    \        int u = x >> i & 1;\r\n        if (!trie[p][u]) {\r\n            trie[p][u]\
    \ = newNode();\r\n        }\r\n        p = trie[p][u];\r\n        cnt[p][d] +=\
    \ t;\r\n    }\r\n}\r\n\r\nint query(int x, int d) {\r\n    int p = 1;\r\n    if\
    \ (!cnt[p][d]) {\r\n        return 0;\r\n    }\r\n    int ans = 0;\r\n    for\
    \ (int i = 29; i >= 0; i--) {\r\n        int u = x >> i & 1;\r\n        if (cnt[trie[p][u\
    \ ^ 1]][d]) {\r\n            ans |= 1 << i;\r\n            p = trie[p][u ^ 1];\r\
    \n        } else {\r\n            p = trie[p][u];\r\n        }\r\n    }\r\n  \
    \  return ans;\r\n}\r\n```"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/09B-Trie.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/09B-Trie.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/09B-Trie.hpp
- /library/src/jiangly/string/09B-Trie.hpp.html
title: src/jiangly/string/09B-Trie.hpp
---
