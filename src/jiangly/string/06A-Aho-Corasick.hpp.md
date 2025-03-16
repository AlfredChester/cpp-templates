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
  bundledCode: "#line 1 \"src/jiangly/string/06A-Aho-Corasick.hpp\"\nconstexpr int\
    \ N = 3e5 + 30, A = 26;\r\n\r\nstruct Node {\r\n    int fail;\r\n    int sum;\r\
    \n    int next[A];\r\n    Node() : fail(-1), sum(0) {\r\n        std::memset(next,\
    \ -1, sizeof(next));\r\n    }\r\n} node[N];\r\n\r\nint cnt = 0;\r\nint bin[N];\r\
    \nint nBin = 0;\r\n\r\nint newNode() {\r\n    int p = nBin > 0 ? bin[--nBin] :\
    \ cnt++;\r\n    node[p] = Node();\r\n    return p;\r\n}\r\n\r\nstruct AC {\r\n\
    \    std::vector<int> x;\r\n    AC(AC &&a) : x(std::move(a.x)) {}\r\n    AC(std::vector<std::string>\
    \ s, std::vector<int> w) {\r\n        x = {newNode(), newNode()};\r\n        std::fill(node[x[0]].next,\
    \ node[x[0]].next + A, x[1]);\r\n        node[x[1]].fail = x[0];\r\n        \r\
    \n        for (int i = 0; i < int(s.size()); i++) {\r\n            int p = x[1];\r\
    \n            for (int j = 0; j < int(s[i].length()); j++) {\r\n             \
    \   int c = s[i][j] - 'a';\r\n                if (node[p].next[c] == -1) {\r\n\
    \                    int u = newNode();\r\n                    x.push_back(u);\r\
    \n                    node[p].next[c] = u;\r\n                }\r\n          \
    \      p = node[p].next[c];\r\n            }\r\n            node[p].sum += w[i];\r\
    \n        }\r\n        \r\n        std::queue<int> que;\r\n        que.push(x[1]);\r\
    \n        while (!que.empty()) {\r\n            int u = que.front();\r\n     \
    \       que.pop();\r\n            node[u].sum += node[node[u].fail].sum;\r\n \
    \           for (int c = 0; c < A; c++) {\r\n                if (node[u].next[c]\
    \ == -1) {\r\n                    node[u].next[c] = node[node[u].fail].next[c];\r\
    \n                } else {\r\n                    node[node[u].next[c]].fail =\
    \ node[node[u].fail].next[c];\r\n                    que.push(node[u].next[c]);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n    ~AC() {\r\n\
    \        for (auto p : x) {\r\n            bin[nBin++] = p;\r\n        }\r\n \
    \   }\r\n    i64 query(const std::string &s) const {\r\n        i64 ans = 0;\r\
    \n        int p = x[1];\r\n        for (int i = 0; i < int(s.length()); i++) \
    \ {\r\n            int c = s[i] - 'a';\r\n            p = node[p].next[c];\r\n\
    \            ans += node[p].sum;\r\n        }\r\n        return ans;\r\n    }\r\
    \n};\r\n\r\n"
  code: "constexpr int N = 3e5 + 30, A = 26;\r\n\r\nstruct Node {\r\n    int fail;\r\
    \n    int sum;\r\n    int next[A];\r\n    Node() : fail(-1), sum(0) {\r\n    \
    \    std::memset(next, -1, sizeof(next));\r\n    }\r\n} node[N];\r\n\r\nint cnt\
    \ = 0;\r\nint bin[N];\r\nint nBin = 0;\r\n\r\nint newNode() {\r\n    int p = nBin\
    \ > 0 ? bin[--nBin] : cnt++;\r\n    node[p] = Node();\r\n    return p;\r\n}\r\n\
    \r\nstruct AC {\r\n    std::vector<int> x;\r\n    AC(AC &&a) : x(std::move(a.x))\
    \ {}\r\n    AC(std::vector<std::string> s, std::vector<int> w) {\r\n        x\
    \ = {newNode(), newNode()};\r\n        std::fill(node[x[0]].next, node[x[0]].next\
    \ + A, x[1]);\r\n        node[x[1]].fail = x[0];\r\n        \r\n        for (int\
    \ i = 0; i < int(s.size()); i++) {\r\n            int p = x[1];\r\n          \
    \  for (int j = 0; j < int(s[i].length()); j++) {\r\n                int c = s[i][j]\
    \ - 'a';\r\n                if (node[p].next[c] == -1) {\r\n                 \
    \   int u = newNode();\r\n                    x.push_back(u);\r\n            \
    \        node[p].next[c] = u;\r\n                }\r\n                p = node[p].next[c];\r\
    \n            }\r\n            node[p].sum += w[i];\r\n        }\r\n        \r\
    \n        std::queue<int> que;\r\n        que.push(x[1]);\r\n        while (!que.empty())\
    \ {\r\n            int u = que.front();\r\n            que.pop();\r\n        \
    \    node[u].sum += node[node[u].fail].sum;\r\n            for (int c = 0; c <\
    \ A; c++) {\r\n                if (node[u].next[c] == -1) {\r\n              \
    \      node[u].next[c] = node[node[u].fail].next[c];\r\n                } else\
    \ {\r\n                    node[node[u].next[c]].fail = node[node[u].fail].next[c];\r\
    \n                    que.push(node[u].next[c]);\r\n                }\r\n    \
    \        }\r\n        }\r\n    }\r\n    ~AC() {\r\n        for (auto p : x) {\r\
    \n            bin[nBin++] = p;\r\n        }\r\n    }\r\n    i64 query(const std::string\
    \ &s) const {\r\n        i64 ans = 0;\r\n        int p = x[1];\r\n        for\
    \ (int i = 0; i < int(s.length()); i++)  {\r\n            int c = s[i] - 'a';\r\
    \n            p = node[p].next[c];\r\n            ans += node[p].sum;\r\n    \
    \    }\r\n        return ans;\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/06A-Aho-Corasick.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/06A-Aho-Corasick.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/06A-Aho-Corasick.hpp
- /library/src/jiangly/string/06A-Aho-Corasick.hpp.html
title: src/jiangly/string/06A-Aho-Corasick.hpp
---
