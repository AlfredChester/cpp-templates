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
  bundledCode: "#line 1 \"src/watashi/lca.hpp\"\n#include <algorithm>\n#include <cstdio>\n\
    #include <vector>\n\nusing namespace std;\n\nconst int MAXM = 16;\nconst int MAXN\
    \ = 1 << MAXM;\n\n// LCA\nstruct LCA {\n    vector<int> e[MAXN];\n    int d[MAXN],\
    \ p[MAXN][MAXM];\n\n    void dfs_(int v, int f) {\n        p[v][0] = f;\n    \
    \    for (int i = 1; i < MAXM; ++i) {\n            p[v][i] = p[p[v][i - 1]][i\
    \ - 1];\n        }\n        for (int i = 0; i < (int)e[v].size(); ++i) {\n   \
    \         int w = e[v][i];\n            if (w != f) {\n                d[w] =\
    \ d[v] + 1;\n                dfs_(w, v);\n            }\n        }\n    }\n\n\
    \    int up_(int v, int m) {\n        for (int i = 0; i < MAXM; ++i) {\n     \
    \       if (m & (1 << i)) {\n                v = p[v][i];\n            }\n   \
    \     }\n        return v;\n    }\n\n    int lca(int a, int b) {\n        if (d[a]\
    \ > d[b]) {\n            swap(a, b);\n        }\n        b = up_(b, d[b] - d[a]);\n\
    \        if (a == b) {\n            return a;\n        } else {\n            for\
    \ (int i = MAXM - 1; i >= 0; --i) {\n                if (p[a][i] != p[b][i]) {\n\
    \                    a = p[a][i];\n                    b = p[b][i];\n        \
    \        }\n            }\n            return p[a][0];\n        }\n    }\n\n \
    \   void init(int n) {\n        for (int i = 0; i < n; ++i) {\n            e[i].clear();\n\
    \        }\n    }\n\n    void add(int a, int b) {\n        e[a].push_back(b);\n\
    \        e[b].push_back(a);\n    }\n\n    void build() {\n        d[0] = 0;\n\
    \        dfs_(0, 0);\n    }\n} lca;\n"
  code: "#include <algorithm>\n#include <cstdio>\n#include <vector>\n\nusing namespace\
    \ std;\n\nconst int MAXM = 16;\nconst int MAXN = 1 << MAXM;\n\n// LCA\nstruct\
    \ LCA {\n    vector<int> e[MAXN];\n    int d[MAXN], p[MAXN][MAXM];\n\n    void\
    \ dfs_(int v, int f) {\n        p[v][0] = f;\n        for (int i = 1; i < MAXM;\
    \ ++i) {\n            p[v][i] = p[p[v][i - 1]][i - 1];\n        }\n        for\
    \ (int i = 0; i < (int)e[v].size(); ++i) {\n            int w = e[v][i];\n   \
    \         if (w != f) {\n                d[w] = d[v] + 1;\n                dfs_(w,\
    \ v);\n            }\n        }\n    }\n\n    int up_(int v, int m) {\n      \
    \  for (int i = 0; i < MAXM; ++i) {\n            if (m & (1 << i)) {\n       \
    \         v = p[v][i];\n            }\n        }\n        return v;\n    }\n\n\
    \    int lca(int a, int b) {\n        if (d[a] > d[b]) {\n            swap(a,\
    \ b);\n        }\n        b = up_(b, d[b] - d[a]);\n        if (a == b) {\n  \
    \          return a;\n        } else {\n            for (int i = MAXM - 1; i >=\
    \ 0; --i) {\n                if (p[a][i] != p[b][i]) {\n                    a\
    \ = p[a][i];\n                    b = p[b][i];\n                }\n          \
    \  }\n            return p[a][0];\n        }\n    }\n\n    void init(int n) {\n\
    \        for (int i = 0; i < n; ++i) {\n            e[i].clear();\n        }\n\
    \    }\n\n    void add(int a, int b) {\n        e[a].push_back(b);\n        e[b].push_back(a);\n\
    \    }\n\n    void build() {\n        d[0] = 0;\n        dfs_(0, 0);\n    }\n\
    } lca;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/lca.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/lca.hpp
layout: document
redirect_from:
- /library/src/watashi/lca.hpp
- /library/src/watashi/lca.hpp.html
title: src/watashi/lca.hpp
---
