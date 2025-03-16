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
  bundledCode: "#line 1 \"src/watashi/bimatch.hpp\"\n// maximum matchings in bipartite\
    \ graphs\n// maximum cardinality bipartite matching\n// O(|V||E|), generally fast\n\
    \n#include <algorithm>\n#include <string>\n#include <vector>\n\nusing namespace\
    \ std;\n\nstruct Hungarian {\n    int nx, ny;\n    vector<int> mx, my;\n    vector<vector<int>>\
    \ e;\n\n    void init(int nx, int ny) {\n        this->nx = nx;\n        this->ny\
    \ = ny;\n        mx.resize(nx);\n        my.resize(ny);\n        e.clear();\n\
    \        e.resize(nx);\n        mark.resize(nx);\n    }\n\n    void add(int a,\
    \ int b) {\n        e[a].push_back(b);\n    }\n\n    // vector<bool> is evil!!!\n\
    \    basic_string<bool> mark;\n\n    bool augment(int i) {\n        if (!mark[i])\
    \ {\n            mark[i] = true;\n            for (vector<int>::const_iterator\
    \ j = e[i].begin(); j != e[i].end(); ++j) {\n                if (my[*j] == -1\
    \ || augment(my[*j])) {\n                    mx[i] = *j;\n                   \
    \ my[*j] = i;\n                    return true;\n                }\n         \
    \   }\n        }\n        return false;\n    }\n\n    int gao() {\n        int\
    \ ret = 0;\n        fill(mx.begin(), mx.end(), -1);\n        fill(my.begin(),\
    \ my.end(), -1);\n        for (int i = 0; i < nx; ++i) {\n            fill(mark.begin(),\
    \ mark.end(), false);\n            if (augment(i)) {\n                ++ret;\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "// maximum matchings in bipartite graphs\n// maximum cardinality bipartite\
    \ matching\n// O(|V||E|), generally fast\n\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n\nusing namespace std;\n\nstruct Hungarian {\n    int nx, ny;\n\
    \    vector<int> mx, my;\n    vector<vector<int>> e;\n\n    void init(int nx,\
    \ int ny) {\n        this->nx = nx;\n        this->ny = ny;\n        mx.resize(nx);\n\
    \        my.resize(ny);\n        e.clear();\n        e.resize(nx);\n        mark.resize(nx);\n\
    \    }\n\n    void add(int a, int b) {\n        e[a].push_back(b);\n    }\n\n\
    \    // vector<bool> is evil!!!\n    basic_string<bool> mark;\n\n    bool augment(int\
    \ i) {\n        if (!mark[i]) {\n            mark[i] = true;\n            for\
    \ (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {\n   \
    \             if (my[*j] == -1 || augment(my[*j])) {\n                    mx[i]\
    \ = *j;\n                    my[*j] = i;\n                    return true;\n \
    \               }\n            }\n        }\n        return false;\n    }\n\n\
    \    int gao() {\n        int ret = 0;\n        fill(mx.begin(), mx.end(), -1);\n\
    \        fill(my.begin(), my.end(), -1);\n        for (int i = 0; i < nx; ++i)\
    \ {\n            fill(mark.begin(), mark.end(), false);\n            if (augment(i))\
    \ {\n                ++ret;\n            }\n        }\n        return ret;\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/bimatch.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/bimatch.hpp
layout: document
redirect_from:
- /library/src/watashi/bimatch.hpp
- /library/src/watashi/bimatch.hpp.html
title: src/watashi/bimatch.hpp
---
