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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62915815
  bundledCode: "#line 1 \"src/jiangly/graph/06C-Max-Flow.hpp\"\n/**   \u6700\u5927\
    \u6D41\uFF08MaxFlow \u65B0\u7248\uFF09\r\n *    2023-07-21: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62915815\r\
    \n**/\r\nconstexpr int inf = 1E9;\r\ntemplate<class T>\r\nstruct MaxFlow {\r\n\
    \    struct _Edge {\r\n        int to;\r\n        T cap;\r\n        _Edge(int\
    \ to, T cap) : to(to), cap(cap) {}\r\n    };\r\n    \r\n    int n;\r\n    std::vector<_Edge>\
    \ e;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<int> cur, h;\r\
    \n    \r\n    MaxFlow() {}\r\n    MaxFlow(int n) {\r\n        init(n);\r\n   \
    \ }\r\n    \r\n    void init(int n) {\r\n        this->n = n;\r\n        e.clear();\r\
    \n        g.assign(n, {});\r\n        cur.resize(n);\r\n        h.resize(n);\r\
    \n    }\r\n    \r\n    bool bfs(int s, int t) {\r\n        h.assign(n, -1);\r\n\
    \        std::queue<int> que;\r\n        h[s] = 0;\r\n        que.push(s);\r\n\
    \        while (!que.empty()) {\r\n            const int u = que.front();\r\n\
    \            que.pop();\r\n            for (int i : g[u]) {\r\n              \
    \  auto [v, c] = e[i];\r\n                if (c > 0 && h[v] == -1) {\r\n     \
    \               h[v] = h[u] + 1;\r\n                    if (v == t) {\r\n    \
    \                    return true;\r\n                    }\r\n               \
    \     que.push(v);\r\n                }\r\n            }\r\n        }\r\n    \
    \    return false;\r\n    }\r\n    \r\n    T dfs(int u, int t, T f) {\r\n    \
    \    if (u == t) {\r\n            return f;\r\n        }\r\n        auto r = f;\r\
    \n        for (int &i = cur[u]; i < int(g[u].size()); ++i) {\r\n            const\
    \ int j = g[u][i];\r\n            auto [v, c] = e[j];\r\n            if (c > 0\
    \ && h[v] == h[u] + 1) {\r\n                auto a = dfs(v, t, std::min(r, c));\r\
    \n                e[j].cap -= a;\r\n                e[j ^ 1].cap += a;\r\n   \
    \             r -= a;\r\n                if (r == 0) {\r\n                   \
    \ return f;\r\n                }\r\n            }\r\n        }\r\n        return\
    \ f - r;\r\n    }\r\n    void addEdge(int u, int v, T c) {\r\n        g[u].push_back(e.size());\r\
    \n        e.emplace_back(v, c);\r\n        g[v].push_back(e.size());\r\n     \
    \   e.emplace_back(u, 0);\r\n    }\r\n    T flow(int s, int t) {\r\n        T\
    \ ans = 0;\r\n        while (bfs(s, t)) {\r\n            cur.assign(n, 0);\r\n\
    \            ans += dfs(s, t, std::numeric_limits<T>::max());\r\n        }\r\n\
    \        return ans;\r\n    }\r\n    \r\n    std::vector<bool> minCut() {\r\n\
    \        std::vector<bool> c(n);\r\n        for (int i = 0; i < n; i++) {\r\n\
    \            c[i] = (h[i] != -1);\r\n        }\r\n        return c;\r\n    }\r\
    \n    \r\n    struct Edge {\r\n        int from;\r\n        int to;\r\n      \
    \  T cap;\r\n        T flow;\r\n    };\r\n    std::vector<Edge> edges() {\r\n\
    \        std::vector<Edge> a;\r\n        for (int i = 0; i < e.size(); i += 2)\
    \ {\r\n            Edge x;\r\n            x.from = e[i + 1].to;\r\n          \
    \  x.to = e[i].to;\r\n            x.cap = e[i].cap + e[i + 1].cap;\r\n       \
    \     x.flow = e[i + 1].cap;\r\n            a.push_back(x);\r\n        }\r\n \
    \       return a;\r\n    }\r\n};\n"
  code: "/**   \u6700\u5927\u6D41\uFF08MaxFlow \u65B0\u7248\uFF09\r\n *    2023-07-21:\
    \ https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62915815\r\n\
    **/\r\nconstexpr int inf = 1E9;\r\ntemplate<class T>\r\nstruct MaxFlow {\r\n \
    \   struct _Edge {\r\n        int to;\r\n        T cap;\r\n        _Edge(int to,\
    \ T cap) : to(to), cap(cap) {}\r\n    };\r\n    \r\n    int n;\r\n    std::vector<_Edge>\
    \ e;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<int> cur, h;\r\
    \n    \r\n    MaxFlow() {}\r\n    MaxFlow(int n) {\r\n        init(n);\r\n   \
    \ }\r\n    \r\n    void init(int n) {\r\n        this->n = n;\r\n        e.clear();\r\
    \n        g.assign(n, {});\r\n        cur.resize(n);\r\n        h.resize(n);\r\
    \n    }\r\n    \r\n    bool bfs(int s, int t) {\r\n        h.assign(n, -1);\r\n\
    \        std::queue<int> que;\r\n        h[s] = 0;\r\n        que.push(s);\r\n\
    \        while (!que.empty()) {\r\n            const int u = que.front();\r\n\
    \            que.pop();\r\n            for (int i : g[u]) {\r\n              \
    \  auto [v, c] = e[i];\r\n                if (c > 0 && h[v] == -1) {\r\n     \
    \               h[v] = h[u] + 1;\r\n                    if (v == t) {\r\n    \
    \                    return true;\r\n                    }\r\n               \
    \     que.push(v);\r\n                }\r\n            }\r\n        }\r\n    \
    \    return false;\r\n    }\r\n    \r\n    T dfs(int u, int t, T f) {\r\n    \
    \    if (u == t) {\r\n            return f;\r\n        }\r\n        auto r = f;\r\
    \n        for (int &i = cur[u]; i < int(g[u].size()); ++i) {\r\n            const\
    \ int j = g[u][i];\r\n            auto [v, c] = e[j];\r\n            if (c > 0\
    \ && h[v] == h[u] + 1) {\r\n                auto a = dfs(v, t, std::min(r, c));\r\
    \n                e[j].cap -= a;\r\n                e[j ^ 1].cap += a;\r\n   \
    \             r -= a;\r\n                if (r == 0) {\r\n                   \
    \ return f;\r\n                }\r\n            }\r\n        }\r\n        return\
    \ f - r;\r\n    }\r\n    void addEdge(int u, int v, T c) {\r\n        g[u].push_back(e.size());\r\
    \n        e.emplace_back(v, c);\r\n        g[v].push_back(e.size());\r\n     \
    \   e.emplace_back(u, 0);\r\n    }\r\n    T flow(int s, int t) {\r\n        T\
    \ ans = 0;\r\n        while (bfs(s, t)) {\r\n            cur.assign(n, 0);\r\n\
    \            ans += dfs(s, t, std::numeric_limits<T>::max());\r\n        }\r\n\
    \        return ans;\r\n    }\r\n    \r\n    std::vector<bool> minCut() {\r\n\
    \        std::vector<bool> c(n);\r\n        for (int i = 0; i < n; i++) {\r\n\
    \            c[i] = (h[i] != -1);\r\n        }\r\n        return c;\r\n    }\r\
    \n    \r\n    struct Edge {\r\n        int from;\r\n        int to;\r\n      \
    \  T cap;\r\n        T flow;\r\n    };\r\n    std::vector<Edge> edges() {\r\n\
    \        std::vector<Edge> a;\r\n        for (int i = 0; i < e.size(); i += 2)\
    \ {\r\n            Edge x;\r\n            x.from = e[i + 1].to;\r\n          \
    \  x.to = e[i].to;\r\n            x.cap = e[i].cap + e[i + 1].cap;\r\n       \
    \     x.flow = e[i + 1].cap;\r\n            a.push_back(x);\r\n        }\r\n \
    \       return a;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/06C-Max-Flow.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/06C-Max-Flow.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/06C-Max-Flow.hpp
- /library/src/jiangly/graph/06C-Max-Flow.hpp.html
title: src/jiangly/graph/06C-Max-Flow.hpp
---
