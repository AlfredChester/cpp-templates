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
    - https://qoj.ac/submission/343378
  bundledCode: "#line 1 \"src/jiangly/string/08-LCP.hpp\"\n/**   \u6700\u957F\u516C\
    \u5171\u524D\u7F00 LCP\uFF08\u4F8B\u9898\uFF09\r\n *    2024-03-02: https://qoj.ac/submission/343378\r\
    \n**/\r\nconstexpr int L = 2E6 + 10;\r\n\r\nint len[L];\r\nint lnk[L];\r\nint\
    \ nxt[L][26];\r\n\r\nint f[L];\r\nint tot = 1;\r\n\r\nstd::vector<int> adj[L];\r\
    \n\r\nint extend(int p, int c) {\r\n    if (nxt[p][c]) {\r\n        int q = nxt[p][c];\r\
    \n        if (len[q] == len[p] + 1) {\r\n            return q;\r\n        }\r\n\
    \        int r = ++tot;\r\n        len[r] = len[p] + 1;\r\n        lnk[r] = lnk[q];\r\
    \n        std::copy(nxt[q], nxt[q] + 26, nxt[r]);\r\n        lnk[q] = r;\r\n \
    \       while (nxt[p][c] == q) {\r\n            nxt[p][c] = r;\r\n           \
    \ p = lnk[p];\r\n        }\r\n        return r;\r\n    }\r\n    int cur = ++tot;\r\
    \n    len[cur] = len[p] + 1;\r\n    while (!nxt[p][c]) {\r\n        nxt[p][c]\
    \ = cur;\r\n        p = lnk[p];\r\n    }\r\n    lnk[cur] = extend(p, c);\r\n \
    \   return cur;\r\n}\r\n\r\nint main() {\r\n    std::ios::sync_with_stdio(false);\r\
    \n    std::cin.tie(nullptr);\r\n\r\n    std::fill(nxt[0], nxt[0] + 26, 1);\r\n\
    \    len[0] = -1;\r\n\r\n    int N;\r\n    std::cin >> N;\r\n\r\n    std::vector<std::string>\
    \ S(N);\r\n    for (int i = 0; i < N; i++) {\r\n        std::cin >> S[i];\r\n\
    \        int p = 1;\r\n        for (auto c : S[i]) {\r\n            p = extend(p,\
    \ c - 'a');\r\n            if (f[p] != -1) {\r\n                if (f[p] == 0)\
    \ {\r\n                    f[p] = i + 1;\r\n                } else if (f[p] !=\
    \ i + 1) {\r\n                    f[p] = -1;\r\n                }\r\n        \
    \    }\r\n        }\r\n    }\r\n\r\n    for (int i = 1; i <= tot; i++) {\r\n \
    \       adj[lnk[i]].push_back(i);\r\n    }\r\n}\n"
  code: "/**   \u6700\u957F\u516C\u5171\u524D\u7F00 LCP\uFF08\u4F8B\u9898\uFF09\r\n\
    \ *    2024-03-02: https://qoj.ac/submission/343378\r\n**/\r\nconstexpr int L\
    \ = 2E6 + 10;\r\n\r\nint len[L];\r\nint lnk[L];\r\nint nxt[L][26];\r\n\r\nint\
    \ f[L];\r\nint tot = 1;\r\n\r\nstd::vector<int> adj[L];\r\n\r\nint extend(int\
    \ p, int c) {\r\n    if (nxt[p][c]) {\r\n        int q = nxt[p][c];\r\n      \
    \  if (len[q] == len[p] + 1) {\r\n            return q;\r\n        }\r\n     \
    \   int r = ++tot;\r\n        len[r] = len[p] + 1;\r\n        lnk[r] = lnk[q];\r\
    \n        std::copy(nxt[q], nxt[q] + 26, nxt[r]);\r\n        lnk[q] = r;\r\n \
    \       while (nxt[p][c] == q) {\r\n            nxt[p][c] = r;\r\n           \
    \ p = lnk[p];\r\n        }\r\n        return r;\r\n    }\r\n    int cur = ++tot;\r\
    \n    len[cur] = len[p] + 1;\r\n    while (!nxt[p][c]) {\r\n        nxt[p][c]\
    \ = cur;\r\n        p = lnk[p];\r\n    }\r\n    lnk[cur] = extend(p, c);\r\n \
    \   return cur;\r\n}\r\n\r\nint main() {\r\n    std::ios::sync_with_stdio(false);\r\
    \n    std::cin.tie(nullptr);\r\n\r\n    std::fill(nxt[0], nxt[0] + 26, 1);\r\n\
    \    len[0] = -1;\r\n\r\n    int N;\r\n    std::cin >> N;\r\n\r\n    std::vector<std::string>\
    \ S(N);\r\n    for (int i = 0; i < N; i++) {\r\n        std::cin >> S[i];\r\n\
    \        int p = 1;\r\n        for (auto c : S[i]) {\r\n            p = extend(p,\
    \ c - 'a');\r\n            if (f[p] != -1) {\r\n                if (f[p] == 0)\
    \ {\r\n                    f[p] = i + 1;\r\n                } else if (f[p] !=\
    \ i + 1) {\r\n                    f[p] = -1;\r\n                }\r\n        \
    \    }\r\n        }\r\n    }\r\n\r\n    for (int i = 1; i <= tot; i++) {\r\n \
    \       adj[lnk[i]].push_back(i);\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/08-LCP.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/08-LCP.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/08-LCP.hpp
- /library/src/jiangly/string/08-LCP.hpp.html
title: src/jiangly/string/08-LCP.hpp
---
