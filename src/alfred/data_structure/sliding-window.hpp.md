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
  bundledCode: "#line 1 \"src/alfred/data_structure/sliding-window.hpp\"\n\n\n\n#include\
    \ <compare>\n#include <queue>\n#include <vector>\n\ntemplate <class T, class Compare\
    \ = std::less<T>> // by default, we find minimum.\nstd::vector<T> sliding_window(\n\
    \    std::vector<T> A, size_t k, Compare comp = Compare()\n) {\n    std::vector<T>\
    \ res;\n    std::deque<size_t> Q;\n    for (size_t i = 0; i < A.size(); i++) {\n\
    \        if (!Q.empty() && Q[0] + k == i) {\n            Q.pop_front();\n    \
    \    }\n        while (!Q.empty() && comp(A[i], A[Q.back()])) {\n            Q.pop_back();\n\
    \        }\n        Q.push_back(i);\n        if (i + 1 >= k) { // warning: assert\
    \ k >= 1\n            res.push_back(A[Q[0]]);\n        }\n    }\n    return res;\n\
    }\ntemplate <class T, class Compare = std::less<T>> // by default, we find minimum.\n\
    std::vector<std::vector<T>> grid_sliding_window(\n    std::vector<std::vector<T>>\
    \ &A,\n    size_t x, size_t y, Compare comp = Compare()\n) {\n    const size_t\
    \ n = A.size(), m = A[0].size();\n    std::vector<std::vector<T>> cols(m - y +\
    \ 1);\n    std::vector<std::vector<T>> ans(n - x + 1, std::vector<T>(m - y + 1));\n\
    \    for (size_t i = 0; i < n; i++) {\n        std::vector<T> res = sliding_window(A[i],\
    \ y, comp);\n        for (size_t j = 0; j <= m - y; j++) {\n            cols[j].push_back(res[j]);\n\
    \        }\n    }\n    for (size_t j = 0; j <= m - y; j++) {\n        std::vector<T>\
    \ res = sliding_window(cols[j], x, comp);\n        for (size_t i = 0; i <= n -\
    \ x; i++) {\n            ans[i][j] = res[i];\n        }\n    }\n    return ans;\n\
    }\n\n\n"
  code: "#ifndef AFDS_SLIDING_WINDOW\n#define AFDS_SLIDING_WINDOW\n\n#include <compare>\n\
    #include <queue>\n#include <vector>\n\ntemplate <class T, class Compare = std::less<T>>\
    \ // by default, we find minimum.\nstd::vector<T> sliding_window(\n    std::vector<T>\
    \ A, size_t k, Compare comp = Compare()\n) {\n    std::vector<T> res;\n    std::deque<size_t>\
    \ Q;\n    for (size_t i = 0; i < A.size(); i++) {\n        if (!Q.empty() && Q[0]\
    \ + k == i) {\n            Q.pop_front();\n        }\n        while (!Q.empty()\
    \ && comp(A[i], A[Q.back()])) {\n            Q.pop_back();\n        }\n      \
    \  Q.push_back(i);\n        if (i + 1 >= k) { // warning: assert k >= 1\n    \
    \        res.push_back(A[Q[0]]);\n        }\n    }\n    return res;\n}\ntemplate\
    \ <class T, class Compare = std::less<T>> // by default, we find minimum.\nstd::vector<std::vector<T>>\
    \ grid_sliding_window(\n    std::vector<std::vector<T>> &A,\n    size_t x, size_t\
    \ y, Compare comp = Compare()\n) {\n    const size_t n = A.size(), m = A[0].size();\n\
    \    std::vector<std::vector<T>> cols(m - y + 1);\n    std::vector<std::vector<T>>\
    \ ans(n - x + 1, std::vector<T>(m - y + 1));\n    for (size_t i = 0; i < n; i++)\
    \ {\n        std::vector<T> res = sliding_window(A[i], y, comp);\n        for\
    \ (size_t j = 0; j <= m - y; j++) {\n            cols[j].push_back(res[j]);\n\
    \        }\n    }\n    for (size_t j = 0; j <= m - y; j++) {\n        std::vector<T>\
    \ res = sliding_window(cols[j], x, comp);\n        for (size_t i = 0; i <= n -\
    \ x; i++) {\n            ans[i][j] = res[i];\n        }\n    }\n    return ans;\n\
    }\n\n#endif // AFDS_SLIDING_WINDOW\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/sliding-window.hpp
  requiredBy: []
  timestamp: '2025-03-22 09:26:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/sliding-window.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/sliding-window.hpp
- /library/src/alfred/data_structure/sliding-window.hpp.html
title: src/alfred/data_structure/sliding-window.hpp
---
