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
  bundledCode: "#line 1 \"src/watashi/chain-decomp.hpp\"\n#include <cstdio>\n#include\
    \ <vector>\n#include <algorithm>\n\nusing namespace std;\n\nconst int MAXM = 16;\n\
    const int MAXN = 1 << MAXM;\n\n// Heavy-Light Decomposition\nstruct TreeDecomposition\
    \ {\n  vector<int> e[MAXN], c[MAXN];\n  int s[MAXN];    // subtree size\n  int\
    \ p[MAXN];    // parent id\n  int r[MAXN];    // chain root id\n  int t[MAXN];\
    \    // timestamp, index used in segtree\n  int ts;\n\n  void dfs_(int v, int\
    \ f) {\n    p[v] = f;\n    s[v] = 1;\n    for (int i = 0; i < (int)e[v].size();\
    \ ++i) {\n      int w = e[v][i];\n      if (w != f) {\n        dfs_(w, v);\n \
    \       s[v] += s[w];\n      }\n    }\n  }\n\n  void decomp_(int v, int f, int\
    \ k) {\n    t[v] = ts++;\n    c[k].push_back(v);\n    r[v] = k;\n\n    int x =\
    \ 0, y = -1;\n    for (int i = 0; i < (int)e[v].size(); ++i) {\n      int w =\
    \ e[v][i];\n      if (w != f) {\n        if (s[w] > x) {\n          x = s[w];\n\
    \          y = w;\n        }\n      }\n    }\n    if (y != -1) {\n      decomp_(y,\
    \ v, k);\n    }\n\n    for (int i = 0; i < (int)e[v].size(); ++i) {\n      int\
    \ w = e[v][i];\n      if (w != f && w != y) {\n        decomp_(w, v, w);\n   \
    \   }\n    }\n  }\n\n  void init(int n) {\n    for (int i = 0; i < n; ++i) {\n\
    \      e[i].clear();\n    }\n  }\n\n  void add(int a, int b) {\n    e[a].push_back(b);\n\
    \    e[b].push_back(a);\n  }\n\n  void build() {  // !!\n    ts = 0;\n    dfs_(0,\
    \ 0);\n    decomp_(0, 0, 0);\n  }\n} hld;\n\n"
  code: "#include <cstdio>\n#include <vector>\n#include <algorithm>\n\nusing namespace\
    \ std;\n\nconst int MAXM = 16;\nconst int MAXN = 1 << MAXM;\n\n// Heavy-Light\
    \ Decomposition\nstruct TreeDecomposition {\n  vector<int> e[MAXN], c[MAXN];\n\
    \  int s[MAXN];    // subtree size\n  int p[MAXN];    // parent id\n  int r[MAXN];\
    \    // chain root id\n  int t[MAXN];    // timestamp, index used in segtree\n\
    \  int ts;\n\n  void dfs_(int v, int f) {\n    p[v] = f;\n    s[v] = 1;\n    for\
    \ (int i = 0; i < (int)e[v].size(); ++i) {\n      int w = e[v][i];\n      if (w\
    \ != f) {\n        dfs_(w, v);\n        s[v] += s[w];\n      }\n    }\n  }\n\n\
    \  void decomp_(int v, int f, int k) {\n    t[v] = ts++;\n    c[k].push_back(v);\n\
    \    r[v] = k;\n\n    int x = 0, y = -1;\n    for (int i = 0; i < (int)e[v].size();\
    \ ++i) {\n      int w = e[v][i];\n      if (w != f) {\n        if (s[w] > x) {\n\
    \          x = s[w];\n          y = w;\n        }\n      }\n    }\n    if (y !=\
    \ -1) {\n      decomp_(y, v, k);\n    }\n\n    for (int i = 0; i < (int)e[v].size();\
    \ ++i) {\n      int w = e[v][i];\n      if (w != f && w != y) {\n        decomp_(w,\
    \ v, w);\n      }\n    }\n  }\n\n  void init(int n) {\n    for (int i = 0; i <\
    \ n; ++i) {\n      e[i].clear();\n    }\n  }\n\n  void add(int a, int b) {\n \
    \   e[a].push_back(b);\n    e[b].push_back(a);\n  }\n\n  void build() {  // !!\n\
    \    ts = 0;\n    dfs_(0, 0);\n    decomp_(0, 0, 0);\n  }\n} hld;\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/chain-decomp.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/chain-decomp.hpp
layout: document
redirect_from:
- /library/src/watashi/chain-decomp.hpp
- /library/src/watashi/chain-decomp.hpp.html
title: src/watashi/chain-decomp.hpp
---
