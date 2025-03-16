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
    - https://cf.dianhsu.com/gym/105222/submission/266217560
    - https://codeforces.com/contest/1980/submission/263960334
  bundledCode: "#line 1 \"src/jiangly/string/09C-Trie.hpp\"\n/**   \u5B57\u5178\u6811\
    \ Trie\n *    2024-06-18: https://cf.dianhsu.com/gym/105222/submission/266217560\n\
    \ *    2024-06-04: https://codeforces.com/contest/1980/submission/263960334\n\
    \ **/\nconstexpr int N = 1E7;\nconstexpr int inf = 1E9;\nint tot;\nint trie[N][2];\n\
    int f[N];\n\nint newNode() {\n    int x = ++tot;\n    trie[x][0] = trie[x][1]\
    \ = 0;\n    f[x] = inf;\n    return x;\n}\nvoid add(int x, int i) {\n    int p\
    \ = 1;\n    for (int j = 29; j >= 0; j--) {\n        int &q = trie[p][x >> j &\
    \ 1];\n        if (q == 0) {\n            q = newNode();\n        }\n        p\
    \ = q;\n        f[p] = std::min(f[p], i);\n    }\n}\n\nint query(int a, int b)\
    \ {\n    int ans1 = inf, ans2 = inf;\n    int p = 1;\n    for (int i = 29; i >=\
    \ 0; i--) {\n        int d = a >> i & 1;\n        int e = b >> i & 1;\n      \
    \  if (e) {\n            ans1 = std::min(ans1, f[trie[p][d]]);\n        } else\
    \ {\n            ans2 = std::min(ans2, f[trie[p][d ^ 1]]);\n        }\n      \
    \  p = trie[p][e ^ d];\n    }\n    ans1 = std::min(ans1, f[p]);\n    ans2 = std::min(ans2,\
    \ f[p]);\n    if (ans1 == inf || ans2 == inf) {\n        return -1;\n    }\n \
    \   return std::max({1, ans1, ans2});\n}\n"
  code: "/**   \u5B57\u5178\u6811 Trie\n *    2024-06-18: https://cf.dianhsu.com/gym/105222/submission/266217560\n\
    \ *    2024-06-04: https://codeforces.com/contest/1980/submission/263960334\n\
    \ **/\nconstexpr int N = 1E7;\nconstexpr int inf = 1E9;\nint tot;\nint trie[N][2];\n\
    int f[N];\n\nint newNode() {\n    int x = ++tot;\n    trie[x][0] = trie[x][1]\
    \ = 0;\n    f[x] = inf;\n    return x;\n}\nvoid add(int x, int i) {\n    int p\
    \ = 1;\n    for (int j = 29; j >= 0; j--) {\n        int &q = trie[p][x >> j &\
    \ 1];\n        if (q == 0) {\n            q = newNode();\n        }\n        p\
    \ = q;\n        f[p] = std::min(f[p], i);\n    }\n}\n\nint query(int a, int b)\
    \ {\n    int ans1 = inf, ans2 = inf;\n    int p = 1;\n    for (int i = 29; i >=\
    \ 0; i--) {\n        int d = a >> i & 1;\n        int e = b >> i & 1;\n      \
    \  if (e) {\n            ans1 = std::min(ans1, f[trie[p][d]]);\n        } else\
    \ {\n            ans2 = std::min(ans2, f[trie[p][d ^ 1]]);\n        }\n      \
    \  p = trie[p][e ^ d];\n    }\n    ans1 = std::min(ans1, f[p]);\n    ans2 = std::min(ans2,\
    \ f[p]);\n    if (ans1 == inf || ans2 == inf) {\n        return -1;\n    }\n \
    \   return std::max({1, ans1, ans2});\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/09C-Trie.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/09C-Trie.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/09C-Trie.hpp
- /library/src/jiangly/string/09C-Trie.hpp.html
title: src/jiangly/string/09C-Trie.hpp
---
