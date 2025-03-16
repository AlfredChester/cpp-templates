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
    - https://codeforces.com/contest/1615/submission/140509278
  bundledCode: "#line 1 \"src/jiangly/graph/04-Graph-Match.hpp\"\n/**   \u4E00\u822C\
    \u56FE\u6700\u5927\u5339\u914D\uFF08Graph \u5E26\u82B1\u6811\u7B97\u6CD5\uFF09\
    \u3010\u4E45\u8FDC\u3011\r\n *    2021-12-24: https://codeforces.com/contest/1615/submission/140509278\r\
    \n**/\r\nstruct Graph {\r\n    int n;\r\n    std::vector<std::vector<int>> e;\r\
    \n    Graph(int n) : n(n), e(n) {}\r\n    void addEdge(int u, int v) {\r\n   \
    \     e[u].push_back(v);\r\n        e[v].push_back(u);\r\n    }\r\n    std::vector<int>\
    \ findMatching() {\r\n        std::vector<int> match(n, -1), vis(n), link(n),\
    \ f(n), dep(n);\r\n        \r\n        // disjoint set union\r\n        auto find\
    \ = [&](int u) {\r\n            while (f[u] != u)\r\n                u = f[u]\
    \ = f[f[u]];\r\n            return u;\r\n        };\r\n        \r\n        auto\
    \ lca = [&](int u, int v) {\r\n            u = find(u);\r\n            v = find(v);\r\
    \n            while (u != v) {\r\n                if (dep[u] < dep[v])\r\n   \
    \                 std::swap(u, v);\r\n                u = find(link[match[u]]);\r\
    \n            }\r\n            return u;\r\n        };\r\n        \r\n       \
    \ std::queue<int> que;\r\n        auto blossom = [&](int u, int v, int p) {\r\n\
    \            while (find(u) != p) {\r\n                link[u] = v;\r\n      \
    \          v = match[u];\r\n                if (vis[v] == 0) {\r\n           \
    \         vis[v] = 1;\r\n                    que.push(v);\r\n                }\r\
    \n                f[u] = f[v] = p;\r\n                u = link[v];\r\n       \
    \     }\r\n        };\r\n        \r\n        // find an augmenting path starting\
    \ from u and augment (if exist)\r\n        auto augment = [&](int u) {\r\n   \
    \         \r\n            while (!que.empty())\r\n                que.pop();\r\
    \n            \r\n            std::iota(f.begin(), f.end(), 0);\r\n          \
    \  \r\n            // vis = 0 corresponds to inner vertices, vis = 1 corresponds\
    \ to outer vertices\r\n            std::fill(vis.begin(), vis.end(), -1);\r\n\
    \            \r\n            que.push(u);\r\n            vis[u] = 1;\r\n     \
    \       dep[u] = 0;\r\n            \r\n            while (!que.empty()){\r\n \
    \               int u = que.front();\r\n                que.pop();\r\n       \
    \         for (auto v : e[u]) {\r\n                    if (vis[v] == -1) {\r\n\
    \                        \r\n                        vis[v] = 0;\r\n         \
    \               link[v] = u;\r\n                        dep[v] = dep[u] + 1;\r\
    \n                        \r\n                        // found an augmenting path\r\
    \n                        if (match[v] == -1) {\r\n                          \
    \  for (int x = v, y = u, temp; y != -1; x = temp, y = x == -1 ? -1 : link[x])\
    \ {\r\n                                temp = match[y];\r\n                  \
    \              match[x] = y;\r\n                                match[y] = x;\r\
    \n                            }\r\n                            return;\r\n   \
    \                     }\r\n                        \r\n                      \
    \  vis[match[v]] = 1;\r\n                        dep[match[v]] = dep[u] + 2;\r\
    \n                        que.push(match[v]);\r\n                        \r\n\
    \                    } else if (vis[v] == 1 && find(v) != find(u)) {\r\n     \
    \                   // found a blossom\r\n                        int p = lca(u,\
    \ v);\r\n                        blossom(u, v, p);\r\n                       \
    \ blossom(v, u, p);\r\n                    }\r\n                }\r\n        \
    \    }\r\n            \r\n        };\r\n        \r\n        // find a maximal\
    \ matching greedily (decrease constant)\r\n        auto greedy = [&]() {\r\n \
    \           \r\n            for (int u = 0; u < n; ++u) {\r\n                if\
    \ (match[u] != -1)\r\n                    continue;\r\n                for (auto\
    \ v : e[u]) {\r\n                    if (match[v] == -1) {\r\n               \
    \         match[u] = v;\r\n                        match[v] = u;\r\n         \
    \               break;\r\n                    }\r\n                }\r\n     \
    \       }\r\n        };\r\n        \r\n        greedy();\r\n        \r\n     \
    \   for (int u = 0; u < n; ++u)\r\n            if (match[u] == -1)\r\n       \
    \         augment(u);\r\n        \r\n        return match;\r\n    }\r\n};\n"
  code: "/**   \u4E00\u822C\u56FE\u6700\u5927\u5339\u914D\uFF08Graph \u5E26\u82B1\u6811\
    \u7B97\u6CD5\uFF09\u3010\u4E45\u8FDC\u3011\r\n *    2021-12-24: https://codeforces.com/contest/1615/submission/140509278\r\
    \n**/\r\nstruct Graph {\r\n    int n;\r\n    std::vector<std::vector<int>> e;\r\
    \n    Graph(int n) : n(n), e(n) {}\r\n    void addEdge(int u, int v) {\r\n   \
    \     e[u].push_back(v);\r\n        e[v].push_back(u);\r\n    }\r\n    std::vector<int>\
    \ findMatching() {\r\n        std::vector<int> match(n, -1), vis(n), link(n),\
    \ f(n), dep(n);\r\n        \r\n        // disjoint set union\r\n        auto find\
    \ = [&](int u) {\r\n            while (f[u] != u)\r\n                u = f[u]\
    \ = f[f[u]];\r\n            return u;\r\n        };\r\n        \r\n        auto\
    \ lca = [&](int u, int v) {\r\n            u = find(u);\r\n            v = find(v);\r\
    \n            while (u != v) {\r\n                if (dep[u] < dep[v])\r\n   \
    \                 std::swap(u, v);\r\n                u = find(link[match[u]]);\r\
    \n            }\r\n            return u;\r\n        };\r\n        \r\n       \
    \ std::queue<int> que;\r\n        auto blossom = [&](int u, int v, int p) {\r\n\
    \            while (find(u) != p) {\r\n                link[u] = v;\r\n      \
    \          v = match[u];\r\n                if (vis[v] == 0) {\r\n           \
    \         vis[v] = 1;\r\n                    que.push(v);\r\n                }\r\
    \n                f[u] = f[v] = p;\r\n                u = link[v];\r\n       \
    \     }\r\n        };\r\n        \r\n        // find an augmenting path starting\
    \ from u and augment (if exist)\r\n        auto augment = [&](int u) {\r\n   \
    \         \r\n            while (!que.empty())\r\n                que.pop();\r\
    \n            \r\n            std::iota(f.begin(), f.end(), 0);\r\n          \
    \  \r\n            // vis = 0 corresponds to inner vertices, vis = 1 corresponds\
    \ to outer vertices\r\n            std::fill(vis.begin(), vis.end(), -1);\r\n\
    \            \r\n            que.push(u);\r\n            vis[u] = 1;\r\n     \
    \       dep[u] = 0;\r\n            \r\n            while (!que.empty()){\r\n \
    \               int u = que.front();\r\n                que.pop();\r\n       \
    \         for (auto v : e[u]) {\r\n                    if (vis[v] == -1) {\r\n\
    \                        \r\n                        vis[v] = 0;\r\n         \
    \               link[v] = u;\r\n                        dep[v] = dep[u] + 1;\r\
    \n                        \r\n                        // found an augmenting path\r\
    \n                        if (match[v] == -1) {\r\n                          \
    \  for (int x = v, y = u, temp; y != -1; x = temp, y = x == -1 ? -1 : link[x])\
    \ {\r\n                                temp = match[y];\r\n                  \
    \              match[x] = y;\r\n                                match[y] = x;\r\
    \n                            }\r\n                            return;\r\n   \
    \                     }\r\n                        \r\n                      \
    \  vis[match[v]] = 1;\r\n                        dep[match[v]] = dep[u] + 2;\r\
    \n                        que.push(match[v]);\r\n                        \r\n\
    \                    } else if (vis[v] == 1 && find(v) != find(u)) {\r\n     \
    \                   // found a blossom\r\n                        int p = lca(u,\
    \ v);\r\n                        blossom(u, v, p);\r\n                       \
    \ blossom(v, u, p);\r\n                    }\r\n                }\r\n        \
    \    }\r\n            \r\n        };\r\n        \r\n        // find a maximal\
    \ matching greedily (decrease constant)\r\n        auto greedy = [&]() {\r\n \
    \           \r\n            for (int u = 0; u < n; ++u) {\r\n                if\
    \ (match[u] != -1)\r\n                    continue;\r\n                for (auto\
    \ v : e[u]) {\r\n                    if (match[v] == -1) {\r\n               \
    \         match[u] = v;\r\n                        match[v] = u;\r\n         \
    \               break;\r\n                    }\r\n                }\r\n     \
    \       }\r\n        };\r\n        \r\n        greedy();\r\n        \r\n     \
    \   for (int u = 0; u < n; ++u)\r\n            if (match[u] == -1)\r\n       \
    \         augment(u);\r\n        \r\n        return match;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/04-Graph-Match.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/04-Graph-Match.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/04-Graph-Match.hpp
- /library/src/jiangly/graph/04-Graph-Match.hpp.html
title: src/jiangly/graph/04-Graph-Match.hpp
---
