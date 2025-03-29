---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/pbds-balance-tree.hpp
    title: src/alfred/data_structure/pbds-balance-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-pbds.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line 1 \"\
    src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\ninline void optimizeIO(void)\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL), std::cout.tie(NULL);\n\
    }\n#line 1 \"src/alfred/data_structure/pbds-balance-tree.hpp\"\n\n\n\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\n//\
    \ TreeTag can also be __gnu_pbds::splay_tree_tag\ntemplate <class T, class Cmp\
    \ = std::less_equal<int>, class TreeTag = __gnu_pbds::rb_tree_tag>\nusing BalanceTree\
    \ = __gnu_pbds::tree<T, __gnu_pbds::null_type, Cmp, TreeTag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \n\n#line 6 \"verify/verify-yosupo-ds/yosupo-pbds.test.cpp\"\n\nstd::string T;\n\
    int n, q, opt, x;\nBalanceTree<int, std::less<int>> tr;\n\nint main(int argc,\
    \ char const *argv[]) {\n    optimizeIO();\n    std::cin >> n >> q >> T;\n   \
    \ for (int i = 0; i < n; i++) {\n        if (T[i] == '1') tr.insert(i);\n    }\n\
    \n    while (q--) {\n        std::cin >> opt >> x;\n        if (opt == 0) {\n\
    \            tr.insert(x);\n        } else if (opt == 1) {\n            if (tr.find(x)\
    \ != tr.end()) {\n                tr.erase(x);\n            }\n        } else\
    \ if (opt == 2) {\n            std::cout << (tr.find(x) != tr.end()) << '\\n';\n\
    \        } else if (opt == 3) {\n            auto it = tr.lower_bound(x);\n  \
    \          std::cout << (it == tr.end() ? -1 : *it) << '\\n';\n        } else\
    \ {\n            auto it = tr.upper_bound(x);\n            std::cout << (it ==\
    \ tr.begin() ? -1 : *(--it)) << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/pbds-balance-tree.hpp\"\
    \n#include <iostream>\n\nstd::string T;\nint n, q, opt, x;\nBalanceTree<int, std::less<int>>\
    \ tr;\n\nint main(int argc, char const *argv[]) {\n    optimizeIO();\n    std::cin\
    \ >> n >> q >> T;\n    for (int i = 0; i < n; i++) {\n        if (T[i] == '1')\
    \ tr.insert(i);\n    }\n\n    while (q--) {\n        std::cin >> opt >> x;\n \
    \       if (opt == 0) {\n            tr.insert(x);\n        } else if (opt ==\
    \ 1) {\n            if (tr.find(x) != tr.end()) {\n                tr.erase(x);\n\
    \            }\n        } else if (opt == 2) {\n            std::cout << (tr.find(x)\
    \ != tr.end()) << '\\n';\n        } else if (opt == 3) {\n            auto it\
    \ = tr.lower_bound(x);\n            std::cout << (it == tr.end() ? -1 : *it) <<\
    \ '\\n';\n        } else {\n            auto it = tr.upper_bound(x);\n       \
    \     std::cout << (it == tr.begin() ? -1 : *(--it)) << '\\n';\n        }\n  \
    \  }\n\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/pbds-balance-tree.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-pbds.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 20:36:59+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-pbds.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-pbds.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-pbds.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-pbds.test.cpp
---
