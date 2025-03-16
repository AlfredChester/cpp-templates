---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc161/submissions/46031530
  bundledCode: "#line 1 \"src/jiangly/graph/05-Two-Sat.hpp\"\n/**   TwoSat\uFF082-Sat\uFF09\
    \r\n *    2023-09-29: https://atcoder.jp/contests/arc161/submissions/46031530\r\
    \n**/\r\nstruct TwoSat {\r\n    int n;\r\n    std::vector<std::vector<int>> e;\r\
    \n    std::vector<bool> ans;\r\n    TwoSat(int n) : n(n), e(2 * n), ans(n) {}\r\
    \n    void addClause(int u, bool f, int v, bool g) {\r\n        e[2 * u + !f].push_back(2\
    \ * v + g);\r\n        e[2 * v + !g].push_back(2 * u + f);\r\n    }\r\n    bool\
    \ satisfiable() {\r\n        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2\
    \ * n, -1);\r\n        std::vector<int> stk;\r\n        int now = 0, cnt = 0;\r\
    \n        std::function<void(int)> tarjan = [&](int u) {\r\n            stk.push_back(u);\r\
    \n            dfn[u] = low[u] = now++;\r\n            for (auto v : e[u]) {\r\n\
    \                if (dfn[v] == -1) {\r\n                    tarjan(v);\r\n   \
    \                 low[u] = std::min(low[u], low[v]);\r\n                } else\
    \ if (id[v] == -1) {\r\n                    low[u] = std::min(low[u], dfn[v]);\r\
    \n                }\r\n            }\r\n            if (dfn[u] == low[u]) {\r\n\
    \                int v;\r\n                do {\r\n                    v = stk.back();\r\
    \n                    stk.pop_back();\r\n                    id[v] = cnt;\r\n\
    \                } while (v != u);\r\n                ++cnt;\r\n            }\r\
    \n        };\r\n        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);\r\
    \n        for (int i = 0; i < n; ++i) {\r\n            if (id[2 * i] == id[2 *\
    \ i + 1]) return false;\r\n            ans[i] = id[2 * i] > id[2 * i + 1];\r\n\
    \        }\r\n        return true;\r\n    }\r\n    std::vector<bool> answer()\
    \ { return ans; }\r\n};\n"
  code: "/**   TwoSat\uFF082-Sat\uFF09\r\n *    2023-09-29: https://atcoder.jp/contests/arc161/submissions/46031530\r\
    \n**/\r\nstruct TwoSat {\r\n    int n;\r\n    std::vector<std::vector<int>> e;\r\
    \n    std::vector<bool> ans;\r\n    TwoSat(int n) : n(n), e(2 * n), ans(n) {}\r\
    \n    void addClause(int u, bool f, int v, bool g) {\r\n        e[2 * u + !f].push_back(2\
    \ * v + g);\r\n        e[2 * v + !g].push_back(2 * u + f);\r\n    }\r\n    bool\
    \ satisfiable() {\r\n        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2\
    \ * n, -1);\r\n        std::vector<int> stk;\r\n        int now = 0, cnt = 0;\r\
    \n        std::function<void(int)> tarjan = [&](int u) {\r\n            stk.push_back(u);\r\
    \n            dfn[u] = low[u] = now++;\r\n            for (auto v : e[u]) {\r\n\
    \                if (dfn[v] == -1) {\r\n                    tarjan(v);\r\n   \
    \                 low[u] = std::min(low[u], low[v]);\r\n                } else\
    \ if (id[v] == -1) {\r\n                    low[u] = std::min(low[u], dfn[v]);\r\
    \n                }\r\n            }\r\n            if (dfn[u] == low[u]) {\r\n\
    \                int v;\r\n                do {\r\n                    v = stk.back();\r\
    \n                    stk.pop_back();\r\n                    id[v] = cnt;\r\n\
    \                } while (v != u);\r\n                ++cnt;\r\n            }\r\
    \n        };\r\n        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);\r\
    \n        for (int i = 0; i < n; ++i) {\r\n            if (id[2 * i] == id[2 *\
    \ i + 1]) return false;\r\n            ans[i] = id[2 * i] > id[2 * i + 1];\r\n\
    \        }\r\n        return true;\r\n    }\r\n    std::vector<bool> answer()\
    \ { return ans; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/05-Two-Sat.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/05-Two-Sat.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/05-Two-Sat.hpp
- /library/src/jiangly/graph/05-Two-Sat.hpp.html
title: src/jiangly/graph/05-Two-Sat.hpp
---
