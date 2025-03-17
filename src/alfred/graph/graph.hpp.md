---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/graph/graph.hpp\"\n\n\n\n#include <vector>\n\n\
    struct NT {}; // null_type\ntemplate <class W = NT>\nclass Graph {\nprivate:\n\
    \    struct Edge {\n        int to;\n        W w;\n    };\n    std::vector<std::vector<Edge>>\
    \ G; // (to, E)\n\npublic:\n    Graph(void) {}\n    Graph(int n) : G(n + 1) {}\n\
    \    inline void clear(void) { G.clear(); }\n    inline void resize(int n) { G.resize(n\
    \ + 1); }\n    std::vector<Edge> &operator[](int x) { return G[x]; }\n    inline\
    \ void add_directed(int u, int v, W w = W{}) {\n        G[u].push_back({v, w});\n\
    \    }\n    inline void add_undirected(int u, int v, W w = W{}) {\n        G[u].push_back({v,\
    \ w});\n        G[v].push_back({u, w});\n    }\n    std::vector<W> dijkstra(int\
    \ s) { // by default the shortest path.\n        using Node = std::pair<W, int>;\n\
    \        std::vector<W> dis(G.size(), std::numeric_limits<W>::max());\n      \
    \  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> heap;\n  \
    \      heap.push({W{}, s});\n        while (!heap.empty()) {\n            auto\
    \ t = heap.top();\n            heap.pop();\n            if (dis[t.second] != t.first)\
    \ {\n                continue;\n            }\n            for (auto &edge : G[t.second])\
    \ {\n                if (dis[edge.to] > t.first + edge.w) {\n                \
    \    dis[edge.to] = t.first + edge.w;\n                    heap.push({dis[edge.to],\
    \ edge.to});\n                }\n            }\n        }\n        return dis;\n\
    \    }\n};\n\n\n"
  code: "#ifndef ALGR_GRAPH\n#define ALGR_GRAPH\n\n#include <vector>\n\nstruct NT\
    \ {}; // null_type\ntemplate <class W = NT>\nclass Graph {\nprivate:\n    struct\
    \ Edge {\n        int to;\n        W w;\n    };\n    std::vector<std::vector<Edge>>\
    \ G; // (to, E)\n\npublic:\n    Graph(void) {}\n    Graph(int n) : G(n + 1) {}\n\
    \    inline void clear(void) { G.clear(); }\n    inline void resize(int n) { G.resize(n\
    \ + 1); }\n    std::vector<Edge> &operator[](int x) { return G[x]; }\n    inline\
    \ void add_directed(int u, int v, W w = W{}) {\n        G[u].push_back({v, w});\n\
    \    }\n    inline void add_undirected(int u, int v, W w = W{}) {\n        G[u].push_back({v,\
    \ w});\n        G[v].push_back({u, w});\n    }\n    std::vector<W> dijkstra(int\
    \ s) { // by default the shortest path.\n        using Node = std::pair<W, int>;\n\
    \        std::vector<W> dis(G.size(), std::numeric_limits<W>::max());\n      \
    \  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> heap;\n  \
    \      heap.push({W{}, s});\n        while (!heap.empty()) {\n            auto\
    \ t = heap.top();\n            heap.pop();\n            if (dis[t.second] != t.first)\
    \ {\n                continue;\n            }\n            for (auto &edge : G[t.second])\
    \ {\n                if (dis[edge.to] > t.first + edge.w) {\n                \
    \    dis[edge.to] = t.first + edge.w;\n                    heap.push({dis[edge.to],\
    \ edge.to});\n                }\n            }\n        }\n        return dis;\n\
    \    }\n};\n\n#endif // ALGR_GRAPH"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/graph/graph.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/graph/graph.hpp
layout: document
redirect_from:
- /library/src/alfred/graph/graph.hpp
- /library/src/alfred/graph/graph.hpp.html
title: src/alfred/graph/graph.hpp
---
