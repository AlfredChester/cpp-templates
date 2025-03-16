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
  bundledCode: "#line 1 \"src/watashi/flow.hpp\"\n#include <algorithm>\n#include <cstdio>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <int MAXN, typename T = int, typename S = T>\nstruct MinCostMaxFlow\
    \ {\n    struct NegativeCostCircuitExistsException {\n    };\n\n    struct Edge\
    \ {\n        int v;\n        T c;\n        S w;\n        int b;\n        Edge(int\
    \ v, T c, S w, int b) : v(v), c(c), w(w), b(b) {}\n    };\n\n    int n, source,\
    \ sink;\n    vector<Edge> e[MAXN];\n\n    void init(int n, int source, int sink)\
    \ {\n        this->n = n;\n        this->source = source;\n        this->sink\
    \ = sink;\n        for (int i = 0; i < n; ++i) {\n            e[i].clear();\n\
    \        }\n    }\n\n    void addEdge(int a, int b, T c, S w) {\n        e[a].push_back(Edge(b,\
    \ c, w, e[b].size()));\n        e[b].push_back(Edge(a, 0, -w, e[a].size() - 1));\
    \ // TODO\n    }\n\n    bool mark[MAXN];\n    T maxc[MAXN];\n    S minw[MAXN];\n\
    \    int dist[MAXN];\n    Edge *prev[MAXN];\n\n    bool _spfa() {\n        queue<int>\
    \ q;\n        fill(mark, mark + n, false);\n        fill(maxc, maxc + n, 0);\n\
    \        fill(minw, minw + n, numeric_limits<S>::max());\n        fill(dist, dist\
    \ + n, 0);\n        fill(prev, prev + n, (Edge *)NULL);\n        mark[source]\
    \ = true;\n        maxc[source] = numeric_limits<S>::max();\n        minw[source]\
    \ = 0;\n\n        q.push(source);\n        while (!q.empty()) {\n            int\
    \ cur = q.front();\n            mark[cur] = false;\n            q.pop();\n   \
    \         for (typename vector<Edge>::iterator it = e[cur].begin(); it != e[cur].end();\
    \ ++it) {\n                T c = min(maxc[cur], it->c);\n                if (c\
    \ == 0) {\n                    continue;\n                }\n\n              \
    \  int v = it->v;\n                S w = minw[cur] + it->w;\n                if\
    \ (minw[v] > w || (minw[v] == w && maxc[v] < c)) { // TODO\n                 \
    \   maxc[v] = c;\n                    minw[v] = w;\n                    dist[v]\
    \ = dist[cur] + 1;\n                    if (dist[v] >= n) {\n                \
    \        return false;\n                    }\n                    prev[v] = &*it;\n\
    \                    if (!mark[v]) {\n                        mark[v] = true;\n\
    \                        q.push(v);\n                    }\n                }\n\
    \            }\n        }\n        return true;\n    }\n\n    pair<T, S> gao()\
    \ {\n        T sumc = 0;\n        S sumw = 0;\n        while (true) {\n      \
    \      if (!_spfa()) {\n                throw NegativeCostCircuitExistsException();\n\
    \            } else if (maxc[sink] == 0) {\n                break;\n         \
    \   } else {\n                T c = maxc[sink];\n                sumc += c;\n\
    \                sumw += c * minw[sink];\n\n                int cur = sink;\n\
    \                while (cur != source) {\n                    Edge *e1 = prev[cur];\n\
    \                    e1->c -= c;\n                    Edge *e2 = &e[e1->v][e1->b];\n\
    \                    e2->c += c;\n                    cur = e2->v;\n         \
    \       }\n            }\n        }\n        return make_pair(sumc, sumw);\n \
    \   }\n};\n"
  code: "#include <algorithm>\n#include <cstdio>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate <int MAXN, typename T =\
    \ int, typename S = T>\nstruct MinCostMaxFlow {\n    struct NegativeCostCircuitExistsException\
    \ {\n    };\n\n    struct Edge {\n        int v;\n        T c;\n        S w;\n\
    \        int b;\n        Edge(int v, T c, S w, int b) : v(v), c(c), w(w), b(b)\
    \ {}\n    };\n\n    int n, source, sink;\n    vector<Edge> e[MAXN];\n\n    void\
    \ init(int n, int source, int sink) {\n        this->n = n;\n        this->source\
    \ = source;\n        this->sink = sink;\n        for (int i = 0; i < n; ++i) {\n\
    \            e[i].clear();\n        }\n    }\n\n    void addEdge(int a, int b,\
    \ T c, S w) {\n        e[a].push_back(Edge(b, c, w, e[b].size()));\n        e[b].push_back(Edge(a,\
    \ 0, -w, e[a].size() - 1)); // TODO\n    }\n\n    bool mark[MAXN];\n    T maxc[MAXN];\n\
    \    S minw[MAXN];\n    int dist[MAXN];\n    Edge *prev[MAXN];\n\n    bool _spfa()\
    \ {\n        queue<int> q;\n        fill(mark, mark + n, false);\n        fill(maxc,\
    \ maxc + n, 0);\n        fill(minw, minw + n, numeric_limits<S>::max());\n   \
    \     fill(dist, dist + n, 0);\n        fill(prev, prev + n, (Edge *)NULL);\n\
    \        mark[source] = true;\n        maxc[source] = numeric_limits<S>::max();\n\
    \        minw[source] = 0;\n\n        q.push(source);\n        while (!q.empty())\
    \ {\n            int cur = q.front();\n            mark[cur] = false;\n      \
    \      q.pop();\n            for (typename vector<Edge>::iterator it = e[cur].begin();\
    \ it != e[cur].end(); ++it) {\n                T c = min(maxc[cur], it->c);\n\
    \                if (c == 0) {\n                    continue;\n              \
    \  }\n\n                int v = it->v;\n                S w = minw[cur] + it->w;\n\
    \                if (minw[v] > w || (minw[v] == w && maxc[v] < c)) { // TODO\n\
    \                    maxc[v] = c;\n                    minw[v] = w;\n        \
    \            dist[v] = dist[cur] + 1;\n                    if (dist[v] >= n) {\n\
    \                        return false;\n                    }\n              \
    \      prev[v] = &*it;\n                    if (!mark[v]) {\n                \
    \        mark[v] = true;\n                        q.push(v);\n               \
    \     }\n                }\n            }\n        }\n        return true;\n \
    \   }\n\n    pair<T, S> gao() {\n        T sumc = 0;\n        S sumw = 0;\n  \
    \      while (true) {\n            if (!_spfa()) {\n                throw NegativeCostCircuitExistsException();\n\
    \            } else if (maxc[sink] == 0) {\n                break;\n         \
    \   } else {\n                T c = maxc[sink];\n                sumc += c;\n\
    \                sumw += c * minw[sink];\n\n                int cur = sink;\n\
    \                while (cur != source) {\n                    Edge *e1 = prev[cur];\n\
    \                    e1->c -= c;\n                    Edge *e2 = &e[e1->v][e1->b];\n\
    \                    e2->c += c;\n                    cur = e2->v;\n         \
    \       }\n            }\n        }\n        return make_pair(sumc, sumw);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/flow.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/flow.hpp
layout: document
redirect_from:
- /library/src/watashi/flow.hpp
- /library/src/watashi/flow.hpp.html
title: src/watashi/flow.hpp
---
