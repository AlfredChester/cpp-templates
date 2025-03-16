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
  bundledCode: "#line 1 \"src/watashi/scc.hpp\"\n#include <algorithm>\n#include <stack>\n\
    #include <vector>\n\nusing namespace std;\n\nstruct SCCTarjan {\n    int n;\n\
    \    vector<vector<int>> e;\n\n    vector<int> id;\n    vector<vector<int>> scc;\n\
    \n    void init(int n) {\n        this->n = n;\n        vector<vector<int>>(n).swap(e);\n\
    \        id.resize(n);\n        dfn.resize(n);\n        low.resize(n);\n    }\n\
    \n    void add(int a, int b) {\n        e[a].push_back(b);\n    }\n\n    vector<int>\
    \ dfn, low;\n    int timestamp;\n    stack<int> s;\n\n    void dfs(int v) {\n\
    \        dfn[v] = timestamp++;\n        low[v] = dfn[v];\n        s.push(v);\n\
    \        for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w)\
    \ {\n            if (dfn[*w] == -1) {\n                dfs(*w);\n            \
    \    low[v] = min(low[v], low[*w]);\n            } else if (dfn[*w] != -2) {\n\
    \                low[v] = min(low[v], dfn[*w]);\n            }\n        }\n\n\
    \        if (low[v] == dfn[v]) {\n            vector<int> t;\n            do {\n\
    \                int w = s.top();\n                s.pop();\n                id[w]\
    \ = (int)scc.size();\n                t.push_back(w);\n                dfn[w]\
    \ = -2;\n            } while (t.back() != v);\n            scc.push_back(t);\n\
    \        }\n    }\n\n    int gao() {\n        scc.clear();\n        stack<int>().swap(s);\n\
    \        timestamp = 0;\n\n        fill(dfn.begin(), dfn.end(), -1);\n       \
    \ for (int i = 0; i < n; ++i) {\n            if (dfn[i] == -1) {\n           \
    \     dfs(i);\n            }\n        }\n        return (int)scc.size();\n   \
    \ }\n};\n"
  code: "#include <algorithm>\n#include <stack>\n#include <vector>\n\nusing namespace\
    \ std;\n\nstruct SCCTarjan {\n    int n;\n    vector<vector<int>> e;\n\n    vector<int>\
    \ id;\n    vector<vector<int>> scc;\n\n    void init(int n) {\n        this->n\
    \ = n;\n        vector<vector<int>>(n).swap(e);\n        id.resize(n);\n     \
    \   dfn.resize(n);\n        low.resize(n);\n    }\n\n    void add(int a, int b)\
    \ {\n        e[a].push_back(b);\n    }\n\n    vector<int> dfn, low;\n    int timestamp;\n\
    \    stack<int> s;\n\n    void dfs(int v) {\n        dfn[v] = timestamp++;\n \
    \       low[v] = dfn[v];\n        s.push(v);\n        for (vector<int>::const_iterator\
    \ w = e[v].begin(); w != e[v].end(); ++w) {\n            if (dfn[*w] == -1) {\n\
    \                dfs(*w);\n                low[v] = min(low[v], low[*w]);\n  \
    \          } else if (dfn[*w] != -2) {\n                low[v] = min(low[v], dfn[*w]);\n\
    \            }\n        }\n\n        if (low[v] == dfn[v]) {\n            vector<int>\
    \ t;\n            do {\n                int w = s.top();\n                s.pop();\n\
    \                id[w] = (int)scc.size();\n                t.push_back(w);\n \
    \               dfn[w] = -2;\n            } while (t.back() != v);\n         \
    \   scc.push_back(t);\n        }\n    }\n\n    int gao() {\n        scc.clear();\n\
    \        stack<int>().swap(s);\n        timestamp = 0;\n\n        fill(dfn.begin(),\
    \ dfn.end(), -1);\n        for (int i = 0; i < n; ++i) {\n            if (dfn[i]\
    \ == -1) {\n                dfs(i);\n            }\n        }\n        return\
    \ (int)scc.size();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/scc.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/scc.hpp
layout: document
redirect_from:
- /library/src/watashi/scc.hpp
- /library/src/watashi/scc.hpp.html
title: src/watashi/scc.hpp
---
