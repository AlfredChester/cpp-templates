---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/priority-set.hpp
    title: src/alfred/data_structure/priority-set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-priority-set.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 1 \"src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\n\
    inline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL),\
    \ std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/data_structure/priority-set.hpp\"\
    \n\n\n\n#line 6 \"src/alfred/data_structure/priority-set.hpp\"\n\ntemplate <class\
    \ T, class Comp = std::less<T>>\nclass PrioritySet { // warning: all erase operations\
    \ must be legal.\nprivate:\n    std::priority_queue<T, std::vector<T>, Comp> data;\n\
    \    std::priority_queue<T, std::vector<T>, Comp> erased;\n\npublic:\n    PrioritySet(void)\
    \ : data(), erased() {};\n    PrioritySet(std::vector<T> &init) {\n        for\
    \ (auto &v : init) insert(v);\n    }\n    inline void insert(const T x) { data.push(x);\
    \ }\n    inline void erase(const T x) { erased.push(x); }\n    inline const T\
    \ &top(void) noexcept {\n        // assert(data.size() >= erased.size());\n  \
    \      while (!erased.empty() && data.top() == erased.top()) {\n            data.pop(),\
    \ erased.pop();\n        }\n        return data.top();\n    }\n    inline size_t\
    \ size(void) {\n        return data.size() - erased.size();\n    }\n};\n\n\n#line\
    \ 6 \"verify/verify-yosupo-ds/yosupo-priority-set.test.cpp\"\n\nint main(int argc,\
    \ char const *argv[]) {\n    int n, q, opt, x;\n    optimizeIO(), std::cin >>\
    \ n >> q;\n    PrioritySet<int, std::less<int>> P1;\n    PrioritySet<int, std::greater<int>>\
    \ P2;\n    for (int i = 0; i < n; i++) {\n        std::cin >> x;\n        P1.insert(x);\n\
    \        P2.insert(x);\n    }\n    while (q--) {\n        std::cin >> opt;\n \
    \       if (opt == 0) {\n            std::cin >> x;\n            P1.insert(x);\n\
    \            P2.insert(x);\n        } else if (opt == 1) {\n            x = P2.top();\n\
    \            std::cout << x << '\\n';\n            P1.erase(x), P2.erase(x);\n\
    \        } else {\n            x = P1.top();\n            std::cout << x << '\\\
    n';\n            P1.erase(x), P2.erase(x);\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/priority-set.hpp\"\
    \n#include <iostream>\n\nint main(int argc, char const *argv[]) {\n    int n,\
    \ q, opt, x;\n    optimizeIO(), std::cin >> n >> q;\n    PrioritySet<int, std::less<int>>\
    \ P1;\n    PrioritySet<int, std::greater<int>> P2;\n    for (int i = 0; i < n;\
    \ i++) {\n        std::cin >> x;\n        P1.insert(x);\n        P2.insert(x);\n\
    \    }\n    while (q--) {\n        std::cin >> opt;\n        if (opt == 0) {\n\
    \            std::cin >> x;\n            P1.insert(x);\n            P2.insert(x);\n\
    \        } else if (opt == 1) {\n            x = P2.top();\n            std::cout\
    \ << x << '\\n';\n            P1.erase(x), P2.erase(x);\n        } else {\n  \
    \          x = P1.top();\n            std::cout << x << '\\n';\n            P1.erase(x),\
    \ P2.erase(x);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/priority-set.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-priority-set.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-priority-set.test.cpp
---
