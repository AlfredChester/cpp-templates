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
  bundledCode: "#line 1 \"src/watashi/bcc.hpp\"\n#include <algorithm>\n#include <stack>\n\
    #include <utility>\n#include <vector>\n\nusing namespace std;\n\n// TODO: cannot\
    \ handle duplicate edges\nstruct Tarjan {\n    int n;\n    vector<vector<int>>\
    \ e;\n\n    vector<int> cut;\n    vector<pair<int, int>> bridge;\n    vector<vector<pair<int,\
    \ int>>> bcc;\n\n    void init(int n) {\n        this->n = n;\n        e.clear();\n\
    \        e.resize(n);\n        dfn.resize(n);\n        low.resize(n);\n    }\n\
    \n    void add(int a, int b) {\n        // assert(find(e[a].begin(), e[a].end(),\
    \ b) == e[a].end());\n        e[a].push_back(b);\n        e[b].push_back(a);\n\
    \    }\n\n    vector<int> dfn, low;\n    int timestamp;\n    stack<pair<int, int>>\
    \ s;\n\n    void dfs(int v, int p) {\n        int part = p == -1 ? 0 : 1;\n  \
    \      dfn[v] = low[v] = timestamp++;\n        for (vector<int>::const_iterator\
    \ w = e[v].begin(); w != e[v].end(); ++w) {\n            pair<int, int> f = make_pair(min(v,\
    \ *w), max(v, *w));\n            if (dfn[*w] == -1) {\n                s.push(f);\n\
    \                dfs(*w, v);\n                low[v] = min(low[v], low[*w]);\n\
    \                if (dfn[v] <= low[*w]) {\n                    // articulation\
    \ point\n                    if (++part == 2) {\n                        cut.push_back(v);\n\
    \                    }\n                    // articulation edge\n           \
    \         if (dfn[v] < low[*w]) {\n                        bridge.push_back(f);\n\
    \                    }\n                    // biconnected component (2-vertex-connected)\n\
    \                    vector<pair<int, int>> t;\n                    do {\n   \
    \                     t.push_back(s.top());\n                        s.pop();\n\
    \                    } while (t.back() != f);\n                    bcc.push_back(t);\n\
    \                }\n            } else if (*w != p && dfn[*w] < dfn[v]) {\n  \
    \              s.push(f);\n                low[v] = min(low[v], dfn[*w]);\n  \
    \          }\n        }\n    }\n\n    void gao() {\n        cut.clear();\n   \
    \     bridge.clear();\n        bcc.clear();\n\n        timestamp = 0;\n      \
    \  stack<pair<int, int>>().swap(s);\n        fill(dfn.begin(), dfn.end(), -1);\n\
    \n        for (int i = 0; i < n; ++i) {\n            if (dfn[i] == -1) {\n   \
    \             dfs(i, -1);\n            }\n        }\n    }\n};\n\nstruct BridgeBlockTree\
    \ {\n    Tarjan<MAXN> bcc;\n    DisjointSet<MAXN> ds;\n    vector<int> e[MAXN];\n\
    \n    void init(int n) {\n        bcc.init(n);\n        ds.init(n);\n    }\n\n\
    \    void add(int a, int b) {\n        bcc.add(a, b);\n    }\n\n    void gao()\
    \ {\n        bcc.gao();\n        for (const auto &i : bcc.bcc) {\n           \
    \ if (i.size() > 1) {\n                for (const auto &j : i) {\n           \
    \         ds.setp(j.first, j.second);\n                }\n            }\n    \
    \    }\n        for (const auto &i : bcc.bridge) {\n            int a = ds.getp(i.first);\n\
    \            int b = ds.getp(i.second);\n            e[a].push_back(b);\n    \
    \        e[b].push_back(a);\n        }\n    }\n\n    int id(int v) {\n       \
    \ return ds.getp(v);\n    }\n};\n"
  code: "#include <algorithm>\n#include <stack>\n#include <utility>\n#include <vector>\n\
    \nusing namespace std;\n\n// TODO: cannot handle duplicate edges\nstruct Tarjan\
    \ {\n    int n;\n    vector<vector<int>> e;\n\n    vector<int> cut;\n    vector<pair<int,\
    \ int>> bridge;\n    vector<vector<pair<int, int>>> bcc;\n\n    void init(int\
    \ n) {\n        this->n = n;\n        e.clear();\n        e.resize(n);\n     \
    \   dfn.resize(n);\n        low.resize(n);\n    }\n\n    void add(int a, int b)\
    \ {\n        // assert(find(e[a].begin(), e[a].end(), b) == e[a].end());\n   \
    \     e[a].push_back(b);\n        e[b].push_back(a);\n    }\n\n    vector<int>\
    \ dfn, low;\n    int timestamp;\n    stack<pair<int, int>> s;\n\n    void dfs(int\
    \ v, int p) {\n        int part = p == -1 ? 0 : 1;\n        dfn[v] = low[v] =\
    \ timestamp++;\n        for (vector<int>::const_iterator w = e[v].begin(); w !=\
    \ e[v].end(); ++w) {\n            pair<int, int> f = make_pair(min(v, *w), max(v,\
    \ *w));\n            if (dfn[*w] == -1) {\n                s.push(f);\n      \
    \          dfs(*w, v);\n                low[v] = min(low[v], low[*w]);\n     \
    \           if (dfn[v] <= low[*w]) {\n                    // articulation point\n\
    \                    if (++part == 2) {\n                        cut.push_back(v);\n\
    \                    }\n                    // articulation edge\n           \
    \         if (dfn[v] < low[*w]) {\n                        bridge.push_back(f);\n\
    \                    }\n                    // biconnected component (2-vertex-connected)\n\
    \                    vector<pair<int, int>> t;\n                    do {\n   \
    \                     t.push_back(s.top());\n                        s.pop();\n\
    \                    } while (t.back() != f);\n                    bcc.push_back(t);\n\
    \                }\n            } else if (*w != p && dfn[*w] < dfn[v]) {\n  \
    \              s.push(f);\n                low[v] = min(low[v], dfn[*w]);\n  \
    \          }\n        }\n    }\n\n    void gao() {\n        cut.clear();\n   \
    \     bridge.clear();\n        bcc.clear();\n\n        timestamp = 0;\n      \
    \  stack<pair<int, int>>().swap(s);\n        fill(dfn.begin(), dfn.end(), -1);\n\
    \n        for (int i = 0; i < n; ++i) {\n            if (dfn[i] == -1) {\n   \
    \             dfs(i, -1);\n            }\n        }\n    }\n};\n\nstruct BridgeBlockTree\
    \ {\n    Tarjan<MAXN> bcc;\n    DisjointSet<MAXN> ds;\n    vector<int> e[MAXN];\n\
    \n    void init(int n) {\n        bcc.init(n);\n        ds.init(n);\n    }\n\n\
    \    void add(int a, int b) {\n        bcc.add(a, b);\n    }\n\n    void gao()\
    \ {\n        bcc.gao();\n        for (const auto &i : bcc.bcc) {\n           \
    \ if (i.size() > 1) {\n                for (const auto &j : i) {\n           \
    \         ds.setp(j.first, j.second);\n                }\n            }\n    \
    \    }\n        for (const auto &i : bcc.bridge) {\n            int a = ds.getp(i.first);\n\
    \            int b = ds.getp(i.second);\n            e[a].push_back(b);\n    \
    \        e[b].push_back(a);\n        }\n    }\n\n    int id(int v) {\n       \
    \ return ds.getp(v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/bcc.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/bcc.hpp
layout: document
redirect_from:
- /library/src/watashi/bcc.hpp
- /library/src/watashi/bcc.hpp.html
title: src/watashi/bcc.hpp
---
