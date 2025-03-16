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
  bundledCode: "#line 1 \"src/watashi/bit.hpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<typename T = int>\nstruct BIT {\n  vector<T> a;\n\n  void init(int\
    \ n) {\n    vector<T>(n + 1).swap(a);\n  }\n\n  void add(int i, T v) {\n    for\
    \ (int j = i + 1; j < (int)a.size(); j = (j | (j - 1)) + 1) {\n      a[j] += v;\n\
    \    }\n  }\n\n  // [0, i)\n  T sum(int i) const {\n    T ret = T();\n    for\
    \ (int j = i; j > 0; j = j & (j - 1)) {\n      ret += a[j];\n    }\n    return\
    \ ret;\n  }\n\n  T get(int i) const {\n    return sum(i + 1) - sum(i);\n  }\n\n\
    \  void set(int i, T v) {\n    add(i, v - get(i));\n  }\n};\n\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<typename T = int>\n\
    struct BIT {\n  vector<T> a;\n\n  void init(int n) {\n    vector<T>(n + 1).swap(a);\n\
    \  }\n\n  void add(int i, T v) {\n    for (int j = i + 1; j < (int)a.size(); j\
    \ = (j | (j - 1)) + 1) {\n      a[j] += v;\n    }\n  }\n\n  // [0, i)\n  T sum(int\
    \ i) const {\n    T ret = T();\n    for (int j = i; j > 0; j = j & (j - 1)) {\n\
    \      ret += a[j];\n    }\n    return ret;\n  }\n\n  T get(int i) const {\n \
    \   return sum(i + 1) - sum(i);\n  }\n\n  void set(int i, T v) {\n    add(i, v\
    \ - get(i));\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/bit.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/bit.hpp
layout: document
redirect_from:
- /library/src/watashi/bit.hpp
- /library/src/watashi/bit.hpp.html
title: src/watashi/bit.hpp
---
