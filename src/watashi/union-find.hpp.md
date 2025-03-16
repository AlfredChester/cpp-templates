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
  bundledCode: "#line 1 \"src/watashi/union-find.hpp\"\n#include <vector>\n\nusing\
    \ namespace std;\n\nstruct DisjointSet {\n    vector<int> p;\n\n    void init(int\
    \ n) {\n        p.resize(n);\n        for (int i = 0; i < n; ++i) {\n        \
    \    p[i] = i;\n        }\n    }\n\n    int getp(int i) {\n        return i ==\
    \ p[i] ? i : (p[i] = getp(p[i]));\n    }\n\n    bool setp(int i, int j) {\n  \
    \      i = getp(i);\n        j = getp(j);\n        p[i] = j;\n        return i\
    \ != j;\n    }\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\nstruct DisjointSet {\n    vector<int>\
    \ p;\n\n    void init(int n) {\n        p.resize(n);\n        for (int i = 0;\
    \ i < n; ++i) {\n            p[i] = i;\n        }\n    }\n\n    int getp(int i)\
    \ {\n        return i == p[i] ? i : (p[i] = getp(p[i]));\n    }\n\n    bool setp(int\
    \ i, int j) {\n        i = getp(i);\n        j = getp(j);\n        p[i] = j;\n\
    \        return i != j;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/union-find.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/union-find.hpp
layout: document
redirect_from:
- /library/src/watashi/union-find.hpp
- /library/src/watashi/union-find.hpp.html
title: src/watashi/union-find.hpp
---
