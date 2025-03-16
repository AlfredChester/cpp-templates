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
    - https://cf.dianhsu.com/gym/104288/submission/201412765
  bundledCode: "#line 1 \"src/jiangly/graph/06B-Max-Flow.hpp\"\n/**   \u6700\u5927\
    \u6D41\uFF08Flow \u65E7\u7248\u5176\u4E8C\uFF0C\u6D6E\u70B9\u6570\u5E94\u7528\uFF09\
    \r\n *    2022-04-09: https://cf.dianhsu.com/gym/104288/submission/201412765\r\
    \n**/\r\ntemplate<class T>\r\nstruct Flow {\r\n    const int n;\r\n    struct\
    \ Edge {\r\n        int to;\r\n        T cap;\r\n        Edge(int to, T cap) :\
    \ to(to), cap(cap) {}\r\n    };\r\n    std::vector<Edge> e;\r\n    std::vector<std::vector<int>>\
    \ g;\r\n    std::vector<int> cur, h;\r\n    Flow(int n) : n(n), g(n) {}\r\n  \
    \  \r\n    bool bfs(int s, int t) {\r\n        h.assign(n, -1);\r\n        std::queue<int>\
    \ que;\r\n        h[s] = 0;\r\n        que.push(s);\r\n        while (!que.empty())\
    \ {\r\n            const int u = que.front();\r\n            que.pop();\r\n  \
    \          for (int i : g[u]) {\r\n                auto [v, c] = e[i];\r\n   \
    \             if (c > 0 && h[v] == -1) {\r\n                    h[v] = h[u] +\
    \ 1;\r\n                    if (v == t) {\r\n                        return true;\r\
    \n                    }\r\n                    que.push(v);\r\n              \
    \  }\r\n            }\r\n        }\r\n        return false;\r\n    }\r\n    \r\
    \n    T dfs(int u, int t, T f) {\r\n        if (u == t) {\r\n            return\
    \ f;\r\n        }\r\n        auto r = f;\r\n        double res = 0;\r\n      \
    \  for (int &i = cur[u]; i < int(g[u].size()); ++i) {\r\n            const int\
    \ j = g[u][i];\r\n            auto [v, c] = e[j];\r\n            if (c > 0 &&\
    \ h[v] == h[u] + 1) {\r\n                auto a = dfs(v, t, std::min(r, c));\r\
    \n                res += a;\r\n                e[j].cap -= a;\r\n            \
    \    e[j ^ 1].cap += a;\r\n                r -= a;\r\n                if (r ==\
    \ 0) {\r\n                    return f;\r\n                }\r\n            }\r\
    \n        }\r\n        return res;\r\n    }\r\n    void addEdge(int u, int v,\
    \ T c) {\r\n        g[u].push_back(e.size());\r\n        e.emplace_back(v, c);\r\
    \n        g[v].push_back(e.size());\r\n        e.emplace_back(u, 0);\r\n    }\r\
    \n    T maxFlow(int s, int t) {\r\n        T ans = 0;\r\n        while (bfs(s,\
    \ t)) {\r\n            cur.assign(n, 0);\r\n            ans += dfs(s, t, 1E100);\r\
    \n        }\r\n        return ans;\r\n    }\r\n};\n"
  code: "/**   \u6700\u5927\u6D41\uFF08Flow \u65E7\u7248\u5176\u4E8C\uFF0C\u6D6E\u70B9\
    \u6570\u5E94\u7528\uFF09\r\n *    2022-04-09: https://cf.dianhsu.com/gym/104288/submission/201412765\r\
    \n**/\r\ntemplate<class T>\r\nstruct Flow {\r\n    const int n;\r\n    struct\
    \ Edge {\r\n        int to;\r\n        T cap;\r\n        Edge(int to, T cap) :\
    \ to(to), cap(cap) {}\r\n    };\r\n    std::vector<Edge> e;\r\n    std::vector<std::vector<int>>\
    \ g;\r\n    std::vector<int> cur, h;\r\n    Flow(int n) : n(n), g(n) {}\r\n  \
    \  \r\n    bool bfs(int s, int t) {\r\n        h.assign(n, -1);\r\n        std::queue<int>\
    \ que;\r\n        h[s] = 0;\r\n        que.push(s);\r\n        while (!que.empty())\
    \ {\r\n            const int u = que.front();\r\n            que.pop();\r\n  \
    \          for (int i : g[u]) {\r\n                auto [v, c] = e[i];\r\n   \
    \             if (c > 0 && h[v] == -1) {\r\n                    h[v] = h[u] +\
    \ 1;\r\n                    if (v == t) {\r\n                        return true;\r\
    \n                    }\r\n                    que.push(v);\r\n              \
    \  }\r\n            }\r\n        }\r\n        return false;\r\n    }\r\n    \r\
    \n    T dfs(int u, int t, T f) {\r\n        if (u == t) {\r\n            return\
    \ f;\r\n        }\r\n        auto r = f;\r\n        double res = 0;\r\n      \
    \  for (int &i = cur[u]; i < int(g[u].size()); ++i) {\r\n            const int\
    \ j = g[u][i];\r\n            auto [v, c] = e[j];\r\n            if (c > 0 &&\
    \ h[v] == h[u] + 1) {\r\n                auto a = dfs(v, t, std::min(r, c));\r\
    \n                res += a;\r\n                e[j].cap -= a;\r\n            \
    \    e[j ^ 1].cap += a;\r\n                r -= a;\r\n                if (r ==\
    \ 0) {\r\n                    return f;\r\n                }\r\n            }\r\
    \n        }\r\n        return res;\r\n    }\r\n    void addEdge(int u, int v,\
    \ T c) {\r\n        g[u].push_back(e.size());\r\n        e.emplace_back(v, c);\r\
    \n        g[v].push_back(e.size());\r\n        e.emplace_back(u, 0);\r\n    }\r\
    \n    T maxFlow(int s, int t) {\r\n        T ans = 0;\r\n        while (bfs(s,\
    \ t)) {\r\n            cur.assign(n, 0);\r\n            ans += dfs(s, t, 1E100);\r\
    \n        }\r\n        return ans;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/06B-Max-Flow.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/06B-Max-Flow.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/06B-Max-Flow.hpp
- /library/src/jiangly/graph/06B-Max-Flow.hpp.html
title: src/jiangly/graph/06B-Max-Flow.hpp
---
