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
    - https://codeforces.com/contest/1863/submission/221214363
  bundledCode: "#line 1 \"src/jiangly/graph/08-HLD.hpp\"\n/**   \u6811\u94FE\u5256\
    \u5206\uFF08HLD\uFF09\r\n *    2023-08-31: https://codeforces.com/contest/1863/submission/221214363\r\
    \n**/\r\nstruct HLD {\r\n    int n;\r\n    std::vector<int> siz, top, dep, parent,\
    \ in, out, seq;\r\n    std::vector<std::vector<int>> adj;\r\n    int cur;\r\n\
    \    \r\n    HLD() {}\r\n    HLD(int n) {\r\n        init(n);\r\n    }\r\n   \
    \ void init(int n) {\r\n        this->n = n;\r\n        siz.resize(n);\r\n   \
    \     top.resize(n);\r\n        dep.resize(n);\r\n        parent.resize(n);\r\n\
    \        in.resize(n);\r\n        out.resize(n);\r\n        seq.resize(n);\r\n\
    \        cur = 0;\r\n        adj.assign(n, {});\r\n    }\r\n    void addEdge(int\
    \ u, int v) {\r\n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\
    \n    }\r\n    void work(int root = 0) {\r\n        top[root] = root;\r\n    \
    \    dep[root] = 0;\r\n        parent[root] = -1;\r\n        dfs1(root);\r\n \
    \       dfs2(root);\r\n    }\r\n    void dfs1(int u) {\r\n        if (parent[u]\
    \ != -1) {\r\n            adj[u].erase(std::find(adj[u].begin(), adj[u].end(),\
    \ parent[u]));\r\n        }\r\n        \r\n        siz[u] = 1;\r\n        for\
    \ (auto &v : adj[u]) {\r\n            parent[v] = u;\r\n            dep[v] = dep[u]\
    \ + 1;\r\n            dfs1(v);\r\n            siz[u] += siz[v];\r\n          \
    \  if (siz[v] > siz[adj[u][0]]) {\r\n                std::swap(v, adj[u][0]);\r\
    \n            }\r\n        }\r\n    }\r\n    void dfs2(int u) {\r\n        in[u]\
    \ = cur++;\r\n        seq[in[u]] = u;\r\n        for (auto v : adj[u]) {\r\n \
    \           top[v] = v == adj[u][0] ? top[u] : v;\r\n            dfs2(v);\r\n\
    \        }\r\n        out[u] = cur;\r\n    }\r\n    int lca(int u, int v) {\r\n\
    \        while (top[u] != top[v]) {\r\n            if (dep[top[u]] > dep[top[v]])\
    \ {\r\n                u = parent[top[u]];\r\n            } else {\r\n       \
    \         v = parent[top[v]];\r\n            }\r\n        }\r\n        return\
    \ dep[u] < dep[v] ? u : v;\r\n    }\r\n    \r\n    int dist(int u, int v) {\r\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\r\n    }\r\n    \r\n   \
    \ int jump(int u, int k) {\r\n        if (dep[u] < k) {\r\n            return\
    \ -1;\r\n        }\r\n        \r\n        int d = dep[u] - k;\r\n        \r\n\
    \        while (dep[top[u]] > d) {\r\n            u = parent[top[u]];\r\n    \
    \    }\r\n        \r\n        return seq[in[u] - dep[u] + d];\r\n    }\r\n   \
    \ \r\n    bool isAncester(int u, int v) {\r\n        return in[u] <= in[v] &&\
    \ in[v] < out[u];\r\n    }\r\n    \r\n    int rootedParent(int u, int v) {\r\n\
    \        std::swap(u, v);\r\n        if (u == v) {\r\n            return u;\r\n\
    \        }\r\n        if (!isAncester(u, v)) {\r\n            return parent[u];\r\
    \n        }\r\n        auto it = std::upper_bound(adj[u].begin(), adj[u].end(),\
    \ v, [&](int x, int y) {\r\n            return in[x] < in[y];\r\n        }) -\
    \ 1;\r\n        return *it;\r\n    }\r\n    \r\n    int rootedSize(int u, int\
    \ v) {\r\n        if (u == v) {\r\n            return n;\r\n        }\r\n    \
    \    if (!isAncester(v, u)) {\r\n            return siz[v];\r\n        }\r\n \
    \       return n - siz[rootedParent(u, v)];\r\n    }\r\n    \r\n    int rootedLca(int\
    \ a, int b, int c) {\r\n        return lca(a, b) ^ lca(b, c) ^ lca(c, a);\r\n\
    \    }\r\n};\n"
  code: "/**   \u6811\u94FE\u5256\u5206\uFF08HLD\uFF09\r\n *    2023-08-31: https://codeforces.com/contest/1863/submission/221214363\r\
    \n**/\r\nstruct HLD {\r\n    int n;\r\n    std::vector<int> siz, top, dep, parent,\
    \ in, out, seq;\r\n    std::vector<std::vector<int>> adj;\r\n    int cur;\r\n\
    \    \r\n    HLD() {}\r\n    HLD(int n) {\r\n        init(n);\r\n    }\r\n   \
    \ void init(int n) {\r\n        this->n = n;\r\n        siz.resize(n);\r\n   \
    \     top.resize(n);\r\n        dep.resize(n);\r\n        parent.resize(n);\r\n\
    \        in.resize(n);\r\n        out.resize(n);\r\n        seq.resize(n);\r\n\
    \        cur = 0;\r\n        adj.assign(n, {});\r\n    }\r\n    void addEdge(int\
    \ u, int v) {\r\n        adj[u].push_back(v);\r\n        adj[v].push_back(u);\r\
    \n    }\r\n    void work(int root = 0) {\r\n        top[root] = root;\r\n    \
    \    dep[root] = 0;\r\n        parent[root] = -1;\r\n        dfs1(root);\r\n \
    \       dfs2(root);\r\n    }\r\n    void dfs1(int u) {\r\n        if (parent[u]\
    \ != -1) {\r\n            adj[u].erase(std::find(adj[u].begin(), adj[u].end(),\
    \ parent[u]));\r\n        }\r\n        \r\n        siz[u] = 1;\r\n        for\
    \ (auto &v : adj[u]) {\r\n            parent[v] = u;\r\n            dep[v] = dep[u]\
    \ + 1;\r\n            dfs1(v);\r\n            siz[u] += siz[v];\r\n          \
    \  if (siz[v] > siz[adj[u][0]]) {\r\n                std::swap(v, adj[u][0]);\r\
    \n            }\r\n        }\r\n    }\r\n    void dfs2(int u) {\r\n        in[u]\
    \ = cur++;\r\n        seq[in[u]] = u;\r\n        for (auto v : adj[u]) {\r\n \
    \           top[v] = v == adj[u][0] ? top[u] : v;\r\n            dfs2(v);\r\n\
    \        }\r\n        out[u] = cur;\r\n    }\r\n    int lca(int u, int v) {\r\n\
    \        while (top[u] != top[v]) {\r\n            if (dep[top[u]] > dep[top[v]])\
    \ {\r\n                u = parent[top[u]];\r\n            } else {\r\n       \
    \         v = parent[top[v]];\r\n            }\r\n        }\r\n        return\
    \ dep[u] < dep[v] ? u : v;\r\n    }\r\n    \r\n    int dist(int u, int v) {\r\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\r\n    }\r\n    \r\n   \
    \ int jump(int u, int k) {\r\n        if (dep[u] < k) {\r\n            return\
    \ -1;\r\n        }\r\n        \r\n        int d = dep[u] - k;\r\n        \r\n\
    \        while (dep[top[u]] > d) {\r\n            u = parent[top[u]];\r\n    \
    \    }\r\n        \r\n        return seq[in[u] - dep[u] + d];\r\n    }\r\n   \
    \ \r\n    bool isAncester(int u, int v) {\r\n        return in[u] <= in[v] &&\
    \ in[v] < out[u];\r\n    }\r\n    \r\n    int rootedParent(int u, int v) {\r\n\
    \        std::swap(u, v);\r\n        if (u == v) {\r\n            return u;\r\n\
    \        }\r\n        if (!isAncester(u, v)) {\r\n            return parent[u];\r\
    \n        }\r\n        auto it = std::upper_bound(adj[u].begin(), adj[u].end(),\
    \ v, [&](int x, int y) {\r\n            return in[x] < in[y];\r\n        }) -\
    \ 1;\r\n        return *it;\r\n    }\r\n    \r\n    int rootedSize(int u, int\
    \ v) {\r\n        if (u == v) {\r\n            return n;\r\n        }\r\n    \
    \    if (!isAncester(v, u)) {\r\n            return siz[v];\r\n        }\r\n \
    \       return n - siz[rootedParent(u, v)];\r\n    }\r\n    \r\n    int rootedLca(int\
    \ a, int b, int c) {\r\n        return lca(a, b) ^ lca(b, c) ^ lca(c, a);\r\n\
    \    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/08-HLD.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/08-HLD.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/08-HLD.hpp
- /library/src/jiangly/graph/08-HLD.hpp.html
title: src/jiangly/graph/08-HLD.hpp
---
