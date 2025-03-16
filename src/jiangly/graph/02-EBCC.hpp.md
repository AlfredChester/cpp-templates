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
    - https://codeforces.com/contest/118/submission/205426518
  bundledCode: "#line 1 \"src/jiangly/graph/02-EBCC.hpp\"\n/**   \u5272\u8FB9\u4E0E\
    \u5272\u8FB9\u7F29\u70B9\uFF08EBCC\uFF09\r\n *    2023-05-11: https://codeforces.com/contest/118/submission/205426518\r\
    \n**/\r\nstd::set<std::pair<int, int>> E;\r\n\r\nstruct EBCC {\r\n    int n;\r\
    \n    std::vector<std::vector<int>> adj;\r\n    std::vector<int> stk;\r\n    std::vector<int>\
    \ dfn, low, bel;\r\n    int cur, cnt;\r\n    \r\n    EBCC() {}\r\n    EBCC(int\
    \ n) {\r\n        init(n);\r\n    }\r\n    \r\n    void init(int n) {\r\n    \
    \    this->n = n;\r\n        adj.assign(n, {});\r\n        dfn.assign(n, -1);\r\
    \n        low.resize(n);\r\n        bel.assign(n, -1);\r\n        stk.clear();\r\
    \n        cur = cnt = 0;\r\n    }\r\n    \r\n    void addEdge(int u, int v) {\r\
    \n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\n    }\r\n  \
    \  \r\n    void dfs(int x, int p) {\r\n        dfn[x] = low[x] = cur++;\r\n  \
    \      stk.push_back(x);\r\n        \r\n        for (auto y : adj[x]) {\r\n  \
    \          if (y == p) {\r\n                continue;\r\n            }\r\n   \
    \         if (dfn[y] == -1) {\r\n                E.emplace(x, y);\r\n        \
    \        dfs(y, x);\r\n                low[x] = std::min(low[x], low[y]);\r\n\
    \            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {\r\n               \
    \ E.emplace(x, y);\r\n                low[x] = std::min(low[x], dfn[y]);\r\n \
    \           }\r\n        }\r\n        \r\n        if (dfn[x] == low[x]) {\r\n\
    \            int y;\r\n            do {\r\n                y = stk.back();\r\n\
    \                bel[y] = cnt;\r\n                stk.pop_back();\r\n        \
    \    } while (y != x);\r\n            cnt++;\r\n        }\r\n    }\r\n    \r\n\
    \    std::vector<int> work() {\r\n        dfs(0, -1);\r\n        return bel;\r\
    \n    }\r\n    \r\n    struct Graph {\r\n        int n;\r\n        std::vector<std::pair<int,\
    \ int>> edges;\r\n        std::vector<int> siz;\r\n        std::vector<int> cnte;\r\
    \n    };\r\n    Graph compress() {\r\n        Graph g;\r\n        g.n = cnt;\r\
    \n        g.siz.resize(cnt);\r\n        g.cnte.resize(cnt);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g.siz[bel[i]]++;\r\n            for (auto\
    \ j : adj[i]) {\r\n                if (bel[i] < bel[j]) {\r\n                \
    \    g.edges.emplace_back(bel[i], bel[j]);\r\n                } else if (i < j)\
    \ {\r\n                    g.cnte[bel[i]]++;\r\n                }\r\n        \
    \    }\r\n        }\r\n        return g;\r\n    }\r\n};\n"
  code: "/**   \u5272\u8FB9\u4E0E\u5272\u8FB9\u7F29\u70B9\uFF08EBCC\uFF09\r\n *  \
    \  2023-05-11: https://codeforces.com/contest/118/submission/205426518\r\n**/\r\
    \nstd::set<std::pair<int, int>> E;\r\n\r\nstruct EBCC {\r\n    int n;\r\n    std::vector<std::vector<int>>\
    \ adj;\r\n    std::vector<int> stk;\r\n    std::vector<int> dfn, low, bel;\r\n\
    \    int cur, cnt;\r\n    \r\n    EBCC() {}\r\n    EBCC(int n) {\r\n        init(n);\r\
    \n    }\r\n    \r\n    void init(int n) {\r\n        this->n = n;\r\n        adj.assign(n,\
    \ {});\r\n        dfn.assign(n, -1);\r\n        low.resize(n);\r\n        bel.assign(n,\
    \ -1);\r\n        stk.clear();\r\n        cur = cnt = 0;\r\n    }\r\n    \r\n\
    \    void addEdge(int u, int v) {\r\n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\
    \n    }\r\n    \r\n    void dfs(int x, int p) {\r\n        dfn[x] = low[x] = cur++;\r\
    \n        stk.push_back(x);\r\n        \r\n        for (auto y : adj[x]) {\r\n\
    \            if (y == p) {\r\n                continue;\r\n            }\r\n \
    \           if (dfn[y] == -1) {\r\n                E.emplace(x, y);\r\n      \
    \          dfs(y, x);\r\n                low[x] = std::min(low[x], low[y]);\r\n\
    \            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {\r\n               \
    \ E.emplace(x, y);\r\n                low[x] = std::min(low[x], dfn[y]);\r\n \
    \           }\r\n        }\r\n        \r\n        if (dfn[x] == low[x]) {\r\n\
    \            int y;\r\n            do {\r\n                y = stk.back();\r\n\
    \                bel[y] = cnt;\r\n                stk.pop_back();\r\n        \
    \    } while (y != x);\r\n            cnt++;\r\n        }\r\n    }\r\n    \r\n\
    \    std::vector<int> work() {\r\n        dfs(0, -1);\r\n        return bel;\r\
    \n    }\r\n    \r\n    struct Graph {\r\n        int n;\r\n        std::vector<std::pair<int,\
    \ int>> edges;\r\n        std::vector<int> siz;\r\n        std::vector<int> cnte;\r\
    \n    };\r\n    Graph compress() {\r\n        Graph g;\r\n        g.n = cnt;\r\
    \n        g.siz.resize(cnt);\r\n        g.cnte.resize(cnt);\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g.siz[bel[i]]++;\r\n            for (auto\
    \ j : adj[i]) {\r\n                if (bel[i] < bel[j]) {\r\n                \
    \    g.edges.emplace_back(bel[i], bel[j]);\r\n                } else if (i < j)\
    \ {\r\n                    g.cnte[bel[i]]++;\r\n                }\r\n        \
    \    }\r\n        }\r\n        return g;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/02-EBCC.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/02-EBCC.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/02-EBCC.hpp
- /library/src/jiangly/graph/02-EBCC.hpp.html
title: src/jiangly/graph/02-EBCC.hpp
---
