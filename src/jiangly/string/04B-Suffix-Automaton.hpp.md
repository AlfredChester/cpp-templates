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
    - https://cf.dianhsu.com/gym/104353/submission/207318083
    - https://qoj.ac/submission/188106
    - https://qoj.ac/submission/384423
    - https://qoj.ac/submission/384429
  bundledCode: "#line 1 \"src/jiangly/string/04B-Suffix-Automaton.hpp\"\n/**   \u540E\
    \u7F00\u81EA\u52A8\u673A\uFF08SAM \u65B0\u7248\uFF09\r\n *    2023-05-27: https://cf.dianhsu.com/gym/104353/submission/207318083\r\
    \n *    2023-09-25: https://qoj.ac/submission/188106\r\n *    2024-04-09: https://qoj.ac/submission/384423\
    \ \u3010\u6A21\u677F\u3011\r\n *    2024-04-09: https://qoj.ac/submission/384429\
    \ \u3010\u6A21\u677F\u3011\r\n**/\r\nstruct SAM {\r\n    static constexpr int\
    \ ALPHABET_SIZE = 26;\r\n    struct Node {\r\n        int len;\r\n        int\
    \ link;\r\n        std::array<int, ALPHABET_SIZE> next;\r\n        Node() : len{},\
    \ link{}, next{} {}\r\n    };\r\n    std::vector<Node> t;\r\n    SAM() {\r\n \
    \       init();\r\n    }\r\n    void init() {\r\n        t.assign(2, Node());\r\
    \n        t[0].next.fill(1);\r\n        t[0].len = -1;\r\n    }\r\n    int newNode()\
    \ {\r\n        t.emplace_back();\r\n        return t.size() - 1;\r\n    }\r\n\
    \    int extend(int p, int c) {\r\n        if (t[p].next[c]) {\r\n           \
    \ int q = t[p].next[c];\r\n            if (t[q].len == t[p].len + 1) {\r\n   \
    \             return q;\r\n            }\r\n            int r = newNode();\r\n\
    \            t[r].len = t[p].len + 1;\r\n            t[r].link = t[q].link;\r\n\
    \            t[r].next = t[q].next;\r\n            t[q].link = r;\r\n        \
    \    while (t[p].next[c] == q) {\r\n                t[p].next[c] = r;\r\n    \
    \            p = t[p].link;\r\n            }\r\n            return r;\r\n    \
    \    }\r\n        int cur = newNode();\r\n        t[cur].len = t[p].len + 1;\r\
    \n        while (!t[p].next[c]) {\r\n            t[p].next[c] = cur;\r\n     \
    \       p = t[p].link;\r\n        }\r\n        t[cur].link = extend(p, c);\r\n\
    \        return cur;\r\n    }\r\n    int extend(int p, char c, char offset = 'a')\
    \ {\r\n        return extend(p, c - offset);\r\n    }\r\n    \r\n    int next(int\
    \ p, int x) {\r\n        return t[p].next[x];\r\n    }\r\n    \r\n    int next(int\
    \ p, char c, char offset = 'a') {\r\n        return next(p, c - 'a');\r\n    }\r\
    \n    \r\n    int link(int p) {\r\n        return t[p].link;\r\n    }\r\n    \r\
    \n    int len(int p) {\r\n        return t[p].len;\r\n    }\r\n    \r\n    int\
    \ size() {\r\n        return t.size();\r\n    }\r\n};\r\n\r\n"
  code: "/**   \u540E\u7F00\u81EA\u52A8\u673A\uFF08SAM \u65B0\u7248\uFF09\r\n *  \
    \  2023-05-27: https://cf.dianhsu.com/gym/104353/submission/207318083\r\n *  \
    \  2023-09-25: https://qoj.ac/submission/188106\r\n *    2024-04-09: https://qoj.ac/submission/384423\
    \ \u3010\u6A21\u677F\u3011\r\n *    2024-04-09: https://qoj.ac/submission/384429\
    \ \u3010\u6A21\u677F\u3011\r\n**/\r\nstruct SAM {\r\n    static constexpr int\
    \ ALPHABET_SIZE = 26;\r\n    struct Node {\r\n        int len;\r\n        int\
    \ link;\r\n        std::array<int, ALPHABET_SIZE> next;\r\n        Node() : len{},\
    \ link{}, next{} {}\r\n    };\r\n    std::vector<Node> t;\r\n    SAM() {\r\n \
    \       init();\r\n    }\r\n    void init() {\r\n        t.assign(2, Node());\r\
    \n        t[0].next.fill(1);\r\n        t[0].len = -1;\r\n    }\r\n    int newNode()\
    \ {\r\n        t.emplace_back();\r\n        return t.size() - 1;\r\n    }\r\n\
    \    int extend(int p, int c) {\r\n        if (t[p].next[c]) {\r\n           \
    \ int q = t[p].next[c];\r\n            if (t[q].len == t[p].len + 1) {\r\n   \
    \             return q;\r\n            }\r\n            int r = newNode();\r\n\
    \            t[r].len = t[p].len + 1;\r\n            t[r].link = t[q].link;\r\n\
    \            t[r].next = t[q].next;\r\n            t[q].link = r;\r\n        \
    \    while (t[p].next[c] == q) {\r\n                t[p].next[c] = r;\r\n    \
    \            p = t[p].link;\r\n            }\r\n            return r;\r\n    \
    \    }\r\n        int cur = newNode();\r\n        t[cur].len = t[p].len + 1;\r\
    \n        while (!t[p].next[c]) {\r\n            t[p].next[c] = cur;\r\n     \
    \       p = t[p].link;\r\n        }\r\n        t[cur].link = extend(p, c);\r\n\
    \        return cur;\r\n    }\r\n    int extend(int p, char c, char offset = 'a')\
    \ {\r\n        return extend(p, c - offset);\r\n    }\r\n    \r\n    int next(int\
    \ p, int x) {\r\n        return t[p].next[x];\r\n    }\r\n    \r\n    int next(int\
    \ p, char c, char offset = 'a') {\r\n        return next(p, c - 'a');\r\n    }\r\
    \n    \r\n    int link(int p) {\r\n        return t[p].link;\r\n    }\r\n    \r\
    \n    int len(int p) {\r\n        return t[p].len;\r\n    }\r\n    \r\n    int\
    \ size() {\r\n        return t.size();\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/04B-Suffix-Automaton.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/04B-Suffix-Automaton.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/04B-Suffix-Automaton.hpp
- /library/src/jiangly/string/04B-Suffix-Automaton.hpp.html
title: src/jiangly/string/04B-Suffix-Automaton.hpp
---
