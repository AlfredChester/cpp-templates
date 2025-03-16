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
    - https://qoj.ac/submission/244680
  bundledCode: "#line 1 \"src/jiangly/graph/07B-Min-Cost-Flow.hpp\"\n/**   MinCostFlow\
    \ \u65B0\u7248\r\n *    2023-11-09: https://qoj.ac/submission/244680\r\n**/\r\n\
    template<class T>\r\nstruct MinCostFlow {\r\n    struct _Edge {\r\n        int\
    \ to;\r\n        T cap;\r\n        T cost;\r\n        _Edge(int to_, T cap_, T\
    \ cost_) : to(to_), cap(cap_), cost(cost_) {}\r\n    };\r\n    int n;\r\n    std::vector<_Edge>\
    \ e;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<T> h, dis;\r\n\
    \    std::vector<int> pre;\r\n    bool dijkstra(int s, int t) {\r\n        dis.assign(n,\
    \ std::numeric_limits<T>::max());\r\n        pre.assign(n, -1);\r\n        std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\r\
    \n        dis[s] = 0;\r\n        que.emplace(0, s);\r\n        while (!que.empty())\
    \ {\r\n            T d = que.top().first;\r\n            int u = que.top().second;\r\
    \n            que.pop();\r\n            if (dis[u] != d) {\r\n               \
    \ continue;\r\n            }\r\n            for (int i : g[u]) {\r\n         \
    \       int v = e[i].to;\r\n                T cap = e[i].cap;\r\n            \
    \    T cost = e[i].cost;\r\n                if (cap > 0 && dis[v] > d + h[u] -\
    \ h[v] + cost) {\r\n                    dis[v] = d + h[u] - h[v] + cost;\r\n \
    \                   pre[v] = i;\r\n                    que.emplace(dis[v], v);\r\
    \n                }\r\n            }\r\n        }\r\n        return dis[t] !=\
    \ std::numeric_limits<T>::max();\r\n    }\r\n    MinCostFlow() {}\r\n    MinCostFlow(int\
    \ n_) {\r\n        init(n_);\r\n    }\r\n    void init(int n_) {\r\n        n\
    \ = n_;\r\n        e.clear();\r\n        g.assign(n, {});\r\n    }\r\n    void\
    \ addEdge(int u, int v, T cap, T cost) {\r\n        g[u].push_back(e.size());\r\
    \n        e.emplace_back(v, cap, cost);\r\n        g[v].push_back(e.size());\r\
    \n        e.emplace_back(u, 0, -cost);\r\n    }\r\n    std::pair<T, T> flow(int\
    \ s, int t) {\r\n        T flow = 0;\r\n        T cost = 0;\r\n        h.assign(n,\
    \ 0);\r\n        while (dijkstra(s, t)) {\r\n            for (int i = 0; i < n;\
    \ ++i) {\r\n                h[i] += dis[i];\r\n            }\r\n            T\
    \ aug = std::numeric_limits<int>::max();\r\n            for (int i = t; i != s;\
    \ i = e[pre[i] ^ 1].to) {\r\n                aug = std::min(aug, e[pre[i]].cap);\r\
    \n            }\r\n            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {\r\
    \n                e[pre[i]].cap -= aug;\r\n                e[pre[i] ^ 1].cap +=\
    \ aug;\r\n            }\r\n            flow += aug;\r\n            cost += aug\
    \ * h[t];\r\n        }\r\n        return std::make_pair(flow, cost);\r\n    }\r\
    \n    struct Edge {\r\n        int from;\r\n        int to;\r\n        T cap;\r\
    \n        T cost;\r\n        T flow;\r\n    };\r\n    std::vector<Edge> edges()\
    \ {\r\n        std::vector<Edge> a;\r\n        for (int i = 0; i < e.size(); i\
    \ += 2) {\r\n            Edge x;\r\n            x.from = e[i + 1].to;\r\n    \
    \        x.to = e[i].to;\r\n            x.cap = e[i].cap + e[i + 1].cap;\r\n \
    \           x.cost = e[i].cost;\r\n            x.flow = e[i + 1].cap;\r\n    \
    \        a.push_back(x);\r\n        }\r\n        return a;\r\n    }\r\n};\n"
  code: "/**   MinCostFlow \u65B0\u7248\r\n *    2023-11-09: https://qoj.ac/submission/244680\r\
    \n**/\r\ntemplate<class T>\r\nstruct MinCostFlow {\r\n    struct _Edge {\r\n \
    \       int to;\r\n        T cap;\r\n        T cost;\r\n        _Edge(int to_,\
    \ T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}\r\n    };\r\n    int n;\r\
    \n    std::vector<_Edge> e;\r\n    std::vector<std::vector<int>> g;\r\n    std::vector<T>\
    \ h, dis;\r\n    std::vector<int> pre;\r\n    bool dijkstra(int s, int t) {\r\n\
    \        dis.assign(n, std::numeric_limits<T>::max());\r\n        pre.assign(n,\
    \ -1);\r\n        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T,\
    \ int>>, std::greater<std::pair<T, int>>> que;\r\n        dis[s] = 0;\r\n    \
    \    que.emplace(0, s);\r\n        while (!que.empty()) {\r\n            T d =\
    \ que.top().first;\r\n            int u = que.top().second;\r\n            que.pop();\r\
    \n            if (dis[u] != d) {\r\n                continue;\r\n            }\r\
    \n            for (int i : g[u]) {\r\n                int v = e[i].to;\r\n   \
    \             T cap = e[i].cap;\r\n                T cost = e[i].cost;\r\n   \
    \             if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {\r\n          \
    \          dis[v] = d + h[u] - h[v] + cost;\r\n                    pre[v] = i;\r\
    \n                    que.emplace(dis[v], v);\r\n                }\r\n       \
    \     }\r\n        }\r\n        return dis[t] != std::numeric_limits<T>::max();\r\
    \n    }\r\n    MinCostFlow() {}\r\n    MinCostFlow(int n_) {\r\n        init(n_);\r\
    \n    }\r\n    void init(int n_) {\r\n        n = n_;\r\n        e.clear();\r\n\
    \        g.assign(n, {});\r\n    }\r\n    void addEdge(int u, int v, T cap, T\
    \ cost) {\r\n        g[u].push_back(e.size());\r\n        e.emplace_back(v, cap,\
    \ cost);\r\n        g[v].push_back(e.size());\r\n        e.emplace_back(u, 0,\
    \ -cost);\r\n    }\r\n    std::pair<T, T> flow(int s, int t) {\r\n        T flow\
    \ = 0;\r\n        T cost = 0;\r\n        h.assign(n, 0);\r\n        while (dijkstra(s,\
    \ t)) {\r\n            for (int i = 0; i < n; ++i) {\r\n                h[i] +=\
    \ dis[i];\r\n            }\r\n            T aug = std::numeric_limits<int>::max();\r\
    \n            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {\r\n            \
    \    aug = std::min(aug, e[pre[i]].cap);\r\n            }\r\n            for (int\
    \ i = t; i != s; i = e[pre[i] ^ 1].to) {\r\n                e[pre[i]].cap -= aug;\r\
    \n                e[pre[i] ^ 1].cap += aug;\r\n            }\r\n            flow\
    \ += aug;\r\n            cost += aug * h[t];\r\n        }\r\n        return std::make_pair(flow,\
    \ cost);\r\n    }\r\n    struct Edge {\r\n        int from;\r\n        int to;\r\
    \n        T cap;\r\n        T cost;\r\n        T flow;\r\n    };\r\n    std::vector<Edge>\
    \ edges() {\r\n        std::vector<Edge> a;\r\n        for (int i = 0; i < e.size();\
    \ i += 2) {\r\n            Edge x;\r\n            x.from = e[i + 1].to;\r\n  \
    \          x.to = e[i].to;\r\n            x.cap = e[i].cap + e[i + 1].cap;\r\n\
    \            x.cost = e[i].cost;\r\n            x.flow = e[i + 1].cap;\r\n   \
    \         a.push_back(x);\r\n        }\r\n        return a;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/07B-Min-Cost-Flow.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/07B-Min-Cost-Flow.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/07B-Min-Cost-Flow.hpp
- /library/src/jiangly/graph/07B-Min-Cost-Flow.hpp.html
title: src/jiangly/graph/07B-Min-Cost-Flow.hpp
---
