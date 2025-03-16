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
    - https://qoj.ac/submission/188993
  bundledCode: "#line 1 \"src/jiangly/string/09A-Trie.hpp\"\n/**   \u5B57\u5178\u6811\
    \ Trie\uFF08\u4F8B\u9898\uFF09\r\n *    2023-09-26: https://qoj.ac/submission/188993\r\
    \n**/\r\nconstexpr int N = 1 << 18;\r\n\r\nint mx[30][N];\r\n\r\nvoid build(int\
    \ d, int p, int l, int r, const std::vector<int> &v) {\r\n    if (r - l == 1)\
    \ {\r\n        mx[d][p] = v[l];\r\n        return;\r\n    }\r\n    int m = (l\
    \ + r) / 2;\r\n    build(d, 2 * p, l, m, v);\r\n    build(d, 2 * p + 1, m, r,\
    \ v);\r\n    mx[d][p] = std::max(mx[d][2 * p], mx[d][2 * p + 1]);\r\n}\r\n\r\n\
    int query(int d, int p, int l, int r, int x, int y) {\r\n    if (l >= y || r <=\
    \ x) {\r\n        return -1;\r\n    }\r\n    if (l >= x && r <= y) {\r\n     \
    \   return mx[d][p];\r\n    }\r\n    int m = (l + r) / 2;\r\n    return std::max(query(d,\
    \ 2 * p, l, m, x, y), query(d, 2 * p + 1, m, r, x, y));\r\n}\r\n\r\nint main()\
    \ {\r\n    int N, Q;\r\n    std::cin >> N >> Q;\r\n    \r\n    std::vector<int>\
    \ A(N);\r\n    for (int i = 0; i < N; i++) {\r\n        std::cin >> A[i];\r\n\
    \    }\r\n    \r\n    std::vector nxt(N + 1, std::vector<int>(30, N));\r\n   \
    \ for (int i = N - 1; i >= 0; i--) {\r\n        nxt[i] = nxt[i + 1];\r\n     \
    \   for (int j = 0; j < 30; j++) {\r\n            if (A[i] >> j & 1) {\r\n   \
    \             nxt[i][j] = i;\r\n            }\r\n        }\r\n    }\r\n    \r\n\
    \    std::vector lst(N + 1, std::vector<int>(30, 0));\r\n    for (int i = 0; i\
    \ < N; i++) {\r\n        lst[i + 1] = lst[i];\r\n        for (int j = 0; j < 30;\
    \ j++) {\r\n            if (A[i] >> j & 1) {\r\n                lst[i + 1][j]\
    \ = i + 1;\r\n            }\r\n        }\r\n    }\r\n    std::vector<int> val(N,\
    \ -1);\r\n    for (int j = 29; j >= 0; j--) {\r\n        for (int i = 0; i < N;\
    \ i++) {\r\n            if (A[i] >> j & 1) {\r\n                val[i] = j;\r\n\
    \            }\r\n        }\r\n        build(j, 1, 0, N, val);\r\n    }\r\n}\n"
  code: "/**   \u5B57\u5178\u6811 Trie\uFF08\u4F8B\u9898\uFF09\r\n *    2023-09-26:\
    \ https://qoj.ac/submission/188993\r\n**/\r\nconstexpr int N = 1 << 18;\r\n\r\n\
    int mx[30][N];\r\n\r\nvoid build(int d, int p, int l, int r, const std::vector<int>\
    \ &v) {\r\n    if (r - l == 1) {\r\n        mx[d][p] = v[l];\r\n        return;\r\
    \n    }\r\n    int m = (l + r) / 2;\r\n    build(d, 2 * p, l, m, v);\r\n    build(d,\
    \ 2 * p + 1, m, r, v);\r\n    mx[d][p] = std::max(mx[d][2 * p], mx[d][2 * p +\
    \ 1]);\r\n}\r\n\r\nint query(int d, int p, int l, int r, int x, int y) {\r\n \
    \   if (l >= y || r <= x) {\r\n        return -1;\r\n    }\r\n    if (l >= x &&\
    \ r <= y) {\r\n        return mx[d][p];\r\n    }\r\n    int m = (l + r) / 2;\r\
    \n    return std::max(query(d, 2 * p, l, m, x, y), query(d, 2 * p + 1, m, r, x,\
    \ y));\r\n}\r\n\r\nint main() {\r\n    int N, Q;\r\n    std::cin >> N >> Q;\r\n\
    \    \r\n    std::vector<int> A(N);\r\n    for (int i = 0; i < N; i++) {\r\n \
    \       std::cin >> A[i];\r\n    }\r\n    \r\n    std::vector nxt(N + 1, std::vector<int>(30,\
    \ N));\r\n    for (int i = N - 1; i >= 0; i--) {\r\n        nxt[i] = nxt[i + 1];\r\
    \n        for (int j = 0; j < 30; j++) {\r\n            if (A[i] >> j & 1) {\r\
    \n                nxt[i][j] = i;\r\n            }\r\n        }\r\n    }\r\n  \
    \  \r\n    std::vector lst(N + 1, std::vector<int>(30, 0));\r\n    for (int i\
    \ = 0; i < N; i++) {\r\n        lst[i + 1] = lst[i];\r\n        for (int j = 0;\
    \ j < 30; j++) {\r\n            if (A[i] >> j & 1) {\r\n                lst[i\
    \ + 1][j] = i + 1;\r\n            }\r\n        }\r\n    }\r\n    std::vector<int>\
    \ val(N, -1);\r\n    for (int j = 29; j >= 0; j--) {\r\n        for (int i = 0;\
    \ i < N; i++) {\r\n            if (A[i] >> j & 1) {\r\n                val[i]\
    \ = j;\r\n            }\r\n        }\r\n        build(j, 1, 0, N, val);\r\n  \
    \  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/09A-Trie.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/09A-Trie.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/09A-Trie.hpp
- /library/src/jiangly/string/09A-Trie.hpp.html
title: src/jiangly/string/09A-Trie.hpp
---
