---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
    title: verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/data_structure/priority-set.hpp\"\n\n\n\n#include\
    \ <bits/stdc++.h>\n\ntemplate <class T, class Comp = std::less<T>>\nclass PrioritySet\
    \ { // warning: all erase operations must be legal.\nprivate:\n    std::priority_queue<T,\
    \ std::vector<T>, Comp> data;\n    std::priority_queue<T, std::vector<T>, Comp>\
    \ erased;\n\npublic:\n    PrioritySet(void) : data(), erased() {};\n    PrioritySet(std::vector<T>\
    \ &init) {\n        for (auto &v : init) insert(v);\n    }\n    inline void insert(const\
    \ T x) { data.push(x); }\n    inline void erase(const T x) { erased.push(x); }\n\
    \    inline const T &top(void) noexcept {\n        // assert(data.size() >= erased.size());\n\
    \        while (!erased.empty() && data.top() == erased.top()) {\n           \
    \ data.pop(), erased.pop();\n        }\n        return data.top();\n    }\n  \
    \  inline size_t size(void) {\n        return data.size() - erased.size();\n \
    \   }\n};\n\n\n"
  code: "#ifndef AFDS_PRIORITY_SET\n#define AFDS_PRIORITY_SET\n\n#include <bits/stdc++.h>\n\
    \ntemplate <class T, class Comp = std::less<T>>\nclass PrioritySet { // warning:\
    \ all erase operations must be legal.\nprivate:\n    std::priority_queue<T, std::vector<T>,\
    \ Comp> data;\n    std::priority_queue<T, std::vector<T>, Comp> erased;\n\npublic:\n\
    \    PrioritySet(void) : data(), erased() {};\n    PrioritySet(std::vector<T>\
    \ &init) {\n        for (auto &v : init) insert(v);\n    }\n    inline void insert(const\
    \ T x) { data.push(x); }\n    inline void erase(const T x) { erased.push(x); }\n\
    \    inline const T &top(void) noexcept {\n        // assert(data.size() >= erased.size());\n\
    \        while (!erased.empty() && data.top() == erased.top()) {\n           \
    \ data.pop(), erased.pop();\n        }\n        return data.top();\n    }\n  \
    \  inline size_t size(void) {\n        return data.size() - erased.size();\n \
    \   }\n};\n\n#endif // AFDS_PRIORITY_SET"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/priority-set.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
documentation_of: src/alfred/data_structure/priority-set.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/priority-set.hpp
- /library/src/alfred/data_structure/priority-set.hpp.html
title: src/alfred/data_structure/priority-set.hpp
---
