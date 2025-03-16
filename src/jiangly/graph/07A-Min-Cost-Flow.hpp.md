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
    - https://codeforces.com/contest/1766/submission/184974697
  bundledCode: "#line 1 \"src/jiangly/graph/07A-Min-Cost-Flow.hpp\"\n/**   \u8D39\u7528\
    \u6D41\uFF08MCFGraph \u65E7\u7248\uFF09\r\n *    2022-12-12: https://codeforces.com/contest/1766/submission/184974697\r\
    \n *\r\n *    \u4E0B\u65B9\u4E3A\u6700\u5C0F\u8D39\u7528**\u6700\u5927\u6D41**\u6A21\
    \u677F\uFF0C\u5982\u9700\u6C42\u89E3\u6700\u5C0F\u8D39\u7528**\u53EF\u884C\u6D41\
    **\uFF0C\u9700\u8981\u53BB\u9664\u5EFA\u8FB9\u9650\u5236\r\n**/\r\nstruct MCFGraph\
    \ {\r\n    struct Edge {\r\n        int v, c, f;\r\n        Edge(int v, int c,\
    \ int f) : v(v), c(c), f(f) {}\r\n    };\r\n    const int n;\r\n    std::vector<Edge>\
    \ e;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<i64> h, dis;\r\
    \n    std::vector<int> pre;\r\n    bool dijkstra(int s, int t) {\r\n        dis.assign(n,\
    \ std::numeric_limits<i64>::max());\r\n        pre.assign(n, -1);\r\n        std::priority_queue<std::pair<i64,\
    \ int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> que;\r\
    \n        dis[s] = 0;\r\n        que.emplace(0, s);\r\n        while (!que.empty())\
    \ {\r\n            i64 d = que.top().first;\r\n            int u = que.top().second;\r\
    \n            que.pop();\r\n            if (dis[u] < d) continue;\r\n        \
    \    for (int i : g[u]) {\r\n                int v = e[i].v;\r\n             \
    \   int c = e[i].c;\r\n                int f = e[i].f;\r\n                if (c\
    \ > 0 && dis[v] > d + h[u] - h[v] + f) {\r\n                    dis[v] = d + h[u]\
    \ - h[v] + f;\r\n                    pre[v] = i;\r\n                    que.emplace(dis[v],\
    \ v);\r\n                }\r\n            }\r\n        }\r\n        return dis[t]\
    \ != std::numeric_limits<i64>::max();\r\n    }\r\n    MCFGraph(int n) : n(n),\
    \ g(n) {}\r\n    void addEdge(int u, int v, int c, int f) {\r\n        // if (f\
    \ < 0) {\r\n            g[u].push_back(e.size());\r\n            e.emplace_back(v,\
    \ 0, f);\r\n            g[v].push_back(e.size());\r\n            e.emplace_back(u,\
    \ c, -f);\r\n        // } else {\r\n        //     g[u].push_back(e.size());\r\
    \n        //     e.emplace_back(v, c, f);\r\n        //     g[v].push_back(e.size());\r\
    \n        //     e.emplace_back(u, 0, -f);\r\n        // }\r\n    }\r\n    std::pair<int,\
    \ i64> flow(int s, int t) {\r\n        int flow = 0;\r\n        i64 cost = 0;\r\
    \n        h.assign(n, 0);\r\n        while (dijkstra(s, t)) {\r\n            for\
    \ (int i = 0; i < n; ++i) h[i] += dis[i];\r\n            int aug = std::numeric_limits<int>::max();\r\
    \n            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug,\
    \ e[pre[i]].c);\r\n            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {\r\
    \n                e[pre[i]].c -= aug;\r\n                e[pre[i] ^ 1].c += aug;\r\
    \n            }\r\n            flow += aug;\r\n            cost += i64(aug) *\
    \ h[t];\r\n        }\r\n        return std::make_pair(flow, cost);\r\n    }\r\n\
    };\r\n\r\n"
  code: "/**   \u8D39\u7528\u6D41\uFF08MCFGraph \u65E7\u7248\uFF09\r\n *    2022-12-12:\
    \ https://codeforces.com/contest/1766/submission/184974697\r\n *\r\n *    \u4E0B\
    \u65B9\u4E3A\u6700\u5C0F\u8D39\u7528**\u6700\u5927\u6D41**\u6A21\u677F\uFF0C\u5982\
    \u9700\u6C42\u89E3\u6700\u5C0F\u8D39\u7528**\u53EF\u884C\u6D41**\uFF0C\u9700\u8981\
    \u53BB\u9664\u5EFA\u8FB9\u9650\u5236\r\n**/\r\nstruct MCFGraph {\r\n    struct\
    \ Edge {\r\n        int v, c, f;\r\n        Edge(int v, int c, int f) : v(v),\
    \ c(c), f(f) {}\r\n    };\r\n    const int n;\r\n    std::vector<Edge> e;\r\n\
    \    std::vector<std::vector<int>> g;\r\n    std::vector<i64> h, dis;\r\n    std::vector<int>\
    \ pre;\r\n    bool dijkstra(int s, int t) {\r\n        dis.assign(n, std::numeric_limits<i64>::max());\r\
    \n        pre.assign(n, -1);\r\n        std::priority_queue<std::pair<i64, int>,\
    \ std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> que;\r\n\
    \        dis[s] = 0;\r\n        que.emplace(0, s);\r\n        while (!que.empty())\
    \ {\r\n            i64 d = que.top().first;\r\n            int u = que.top().second;\r\
    \n            que.pop();\r\n            if (dis[u] < d) continue;\r\n        \
    \    for (int i : g[u]) {\r\n                int v = e[i].v;\r\n             \
    \   int c = e[i].c;\r\n                int f = e[i].f;\r\n                if (c\
    \ > 0 && dis[v] > d + h[u] - h[v] + f) {\r\n                    dis[v] = d + h[u]\
    \ - h[v] + f;\r\n                    pre[v] = i;\r\n                    que.emplace(dis[v],\
    \ v);\r\n                }\r\n            }\r\n        }\r\n        return dis[t]\
    \ != std::numeric_limits<i64>::max();\r\n    }\r\n    MCFGraph(int n) : n(n),\
    \ g(n) {}\r\n    void addEdge(int u, int v, int c, int f) {\r\n        // if (f\
    \ < 0) {\r\n            g[u].push_back(e.size());\r\n            e.emplace_back(v,\
    \ 0, f);\r\n            g[v].push_back(e.size());\r\n            e.emplace_back(u,\
    \ c, -f);\r\n        // } else {\r\n        //     g[u].push_back(e.size());\r\
    \n        //     e.emplace_back(v, c, f);\r\n        //     g[v].push_back(e.size());\r\
    \n        //     e.emplace_back(u, 0, -f);\r\n        // }\r\n    }\r\n    std::pair<int,\
    \ i64> flow(int s, int t) {\r\n        int flow = 0;\r\n        i64 cost = 0;\r\
    \n        h.assign(n, 0);\r\n        while (dijkstra(s, t)) {\r\n            for\
    \ (int i = 0; i < n; ++i) h[i] += dis[i];\r\n            int aug = std::numeric_limits<int>::max();\r\
    \n            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug,\
    \ e[pre[i]].c);\r\n            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {\r\
    \n                e[pre[i]].c -= aug;\r\n                e[pre[i] ^ 1].c += aug;\r\
    \n            }\r\n            flow += aug;\r\n            cost += i64(aug) *\
    \ h[t];\r\n        }\r\n        return std::make_pair(flow, cost);\r\n    }\r\n\
    };\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/07A-Min-Cost-Flow.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/07A-Min-Cost-Flow.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/07A-Min-Cost-Flow.hpp
- /library/src/jiangly/graph/07A-Min-Cost-Flow.hpp.html
title: src/jiangly/graph/07A-Min-Cost-Flow.hpp
---
