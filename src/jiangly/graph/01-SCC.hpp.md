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
    - https://codeforces.com/contest/1835/submission/210147209
  bundledCode: "#line 1 \"src/jiangly/graph/01-SCC.hpp\"\n/**   \u5F3A\u8FDE\u901A\
    \u5206\u91CF\u7F29\u70B9\uFF08SCC\uFF09\r\n *    2023-06-18: https://codeforces.com/contest/1835/submission/210147209\r\
    \n**/\r\nstruct SCC {\r\n    int n;\r\n    std::vector<std::vector<int>> adj;\r\
    \n    std::vector<int> stk;\r\n    std::vector<int> dfn, low, bel;\r\n    int\
    \ cur, cnt;\r\n    \r\n    SCC() {}\r\n    SCC(int n) {\r\n        init(n);\r\n\
    \    }\r\n    \r\n    void init(int n) {\r\n        this->n = n;\r\n        adj.assign(n,\
    \ {});\r\n        dfn.assign(n, -1);\r\n        low.resize(n);\r\n        bel.assign(n,\
    \ -1);\r\n        stk.clear();\r\n        cur = cnt = 0;\r\n    }\r\n    \r\n\
    \    void addEdge(int u, int v) {\r\n        adj[u].push_back(v);\r\n    }\r\n\
    \    \r\n    void dfs(int x) {\r\n        dfn[x] = low[x] = cur++;\r\n       \
    \ stk.push_back(x);\r\n        \r\n        for (auto y : adj[x]) {\r\n       \
    \     if (dfn[y] == -1) {\r\n                dfs(y);\r\n                low[x]\
    \ = std::min(low[x], low[y]);\r\n            } else if (bel[y] == -1) {\r\n  \
    \              low[x] = std::min(low[x], dfn[y]);\r\n            }\r\n       \
    \ }\r\n        \r\n        if (dfn[x] == low[x]) {\r\n            int y;\r\n \
    \           do {\r\n                y = stk.back();\r\n                bel[y]\
    \ = cnt;\r\n                stk.pop_back();\r\n            } while (y != x);\r\
    \n            cnt++;\r\n        }\r\n    }\r\n    \r\n    std::vector<int> work()\
    \ {\r\n        for (int i = 0; i < n; i++) {\r\n            if (dfn[i] == -1)\
    \ {\r\n                dfs(i);\r\n            }\r\n        }\r\n        return\
    \ bel;\r\n    }\r\n};\n"
  code: "/**   \u5F3A\u8FDE\u901A\u5206\u91CF\u7F29\u70B9\uFF08SCC\uFF09\r\n *   \
    \ 2023-06-18: https://codeforces.com/contest/1835/submission/210147209\r\n**/\r\
    \nstruct SCC {\r\n    int n;\r\n    std::vector<std::vector<int>> adj;\r\n   \
    \ std::vector<int> stk;\r\n    std::vector<int> dfn, low, bel;\r\n    int cur,\
    \ cnt;\r\n    \r\n    SCC() {}\r\n    SCC(int n) {\r\n        init(n);\r\n   \
    \ }\r\n    \r\n    void init(int n) {\r\n        this->n = n;\r\n        adj.assign(n,\
    \ {});\r\n        dfn.assign(n, -1);\r\n        low.resize(n);\r\n        bel.assign(n,\
    \ -1);\r\n        stk.clear();\r\n        cur = cnt = 0;\r\n    }\r\n    \r\n\
    \    void addEdge(int u, int v) {\r\n        adj[u].push_back(v);\r\n    }\r\n\
    \    \r\n    void dfs(int x) {\r\n        dfn[x] = low[x] = cur++;\r\n       \
    \ stk.push_back(x);\r\n        \r\n        for (auto y : adj[x]) {\r\n       \
    \     if (dfn[y] == -1) {\r\n                dfs(y);\r\n                low[x]\
    \ = std::min(low[x], low[y]);\r\n            } else if (bel[y] == -1) {\r\n  \
    \              low[x] = std::min(low[x], dfn[y]);\r\n            }\r\n       \
    \ }\r\n        \r\n        if (dfn[x] == low[x]) {\r\n            int y;\r\n \
    \           do {\r\n                y = stk.back();\r\n                bel[y]\
    \ = cnt;\r\n                stk.pop_back();\r\n            } while (y != x);\r\
    \n            cnt++;\r\n        }\r\n    }\r\n    \r\n    std::vector<int> work()\
    \ {\r\n        for (int i = 0; i < n; i++) {\r\n            if (dfn[i] == -1)\
    \ {\r\n                dfs(i);\r\n            }\r\n        }\r\n        return\
    \ bel;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/01-SCC.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/01-SCC.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/01-SCC.hpp
- /library/src/jiangly/graph/01-SCC.hpp.html
title: src/jiangly/graph/01-SCC.hpp
---
