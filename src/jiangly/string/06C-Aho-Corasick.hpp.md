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
  bundledCode: "#line 1 \"src/jiangly/string/06C-Aho-Corasick.hpp\"\nstruct AhoCorasick\
    \ {\r\n    static constexpr int ALPHABET = 26;\r\n    struct Node {\r\n      \
    \  int len;\r\n        int link;\r\n        std::array<int, ALPHABET> next;\r\n\
    \        Node() : len{0}, link{0}, next{} {}\r\n    };\r\n    \r\n    std::vector<Node>\
    \ t;\r\n    \r\n    AhoCorasick() {\r\n        init();\r\n    }\r\n    \r\n  \
    \  void init() {\r\n        t.assign(2, Node());\r\n        t[0].next.fill(1);\r\
    \n        t[0].len = -1;\r\n    }\r\n    \r\n    int newNode() {\r\n        t.emplace_back();\r\
    \n        return t.size() - 1;\r\n    }\r\n    \r\n    int add(const std::string\
    \ &a) {\r\n        int p = 1;\r\n        for (auto c : a) {\r\n            int\
    \ x = c - 'a';\r\n            if (t[p].next[x] == 0) {\r\n                t[p].next[x]\
    \ = newNode();\r\n                t[t[p].next[x]].len = t[p].len + 1;\r\n    \
    \        }\r\n            p = t[p].next[x];\r\n        }\r\n        return p;\r\
    \n    }\r\n    \r\n    void work() {\r\n        std::queue<int> q;\r\n       \
    \ q.push(1);\r\n        \r\n        while (!q.empty()) {\r\n            int x\
    \ = q.front();\r\n            q.pop();\r\n            \r\n            for (int\
    \ i = 0; i < ALPHABET; i++) {\r\n                if (t[x].next[i] == 0) {\r\n\
    \                    t[x].next[i] = t[t[x].link].next[i];\r\n                }\
    \ else {\r\n                    t[t[x].next[i]].link = t[t[x].link].next[i];\r\
    \n                    q.push(t[x].next[i]);\r\n                }\r\n         \
    \   }\r\n        }\r\n    }\r\n    \r\n    int next(int p, int x) {\r\n      \
    \  return t[p].next[x];\r\n    }\r\n    \r\n    int link(int p) {\r\n        return\
    \ t[p].link;\r\n    }\r\n    \r\n    int len(int p) {\r\n        return t[p].len;\r\
    \n    }\r\n    \r\n    int size() {\r\n        return t.size();\r\n    }\r\n};\r\
    \n"
  code: "struct AhoCorasick {\r\n    static constexpr int ALPHABET = 26;\r\n    struct\
    \ Node {\r\n        int len;\r\n        int link;\r\n        std::array<int, ALPHABET>\
    \ next;\r\n        Node() : len{0}, link{0}, next{} {}\r\n    };\r\n    \r\n \
    \   std::vector<Node> t;\r\n    \r\n    AhoCorasick() {\r\n        init();\r\n\
    \    }\r\n    \r\n    void init() {\r\n        t.assign(2, Node());\r\n      \
    \  t[0].next.fill(1);\r\n        t[0].len = -1;\r\n    }\r\n    \r\n    int newNode()\
    \ {\r\n        t.emplace_back();\r\n        return t.size() - 1;\r\n    }\r\n\
    \    \r\n    int add(const std::string &a) {\r\n        int p = 1;\r\n       \
    \ for (auto c : a) {\r\n            int x = c - 'a';\r\n            if (t[p].next[x]\
    \ == 0) {\r\n                t[p].next[x] = newNode();\r\n                t[t[p].next[x]].len\
    \ = t[p].len + 1;\r\n            }\r\n            p = t[p].next[x];\r\n      \
    \  }\r\n        return p;\r\n    }\r\n    \r\n    void work() {\r\n        std::queue<int>\
    \ q;\r\n        q.push(1);\r\n        \r\n        while (!q.empty()) {\r\n   \
    \         int x = q.front();\r\n            q.pop();\r\n            \r\n     \
    \       for (int i = 0; i < ALPHABET; i++) {\r\n                if (t[x].next[i]\
    \ == 0) {\r\n                    t[x].next[i] = t[t[x].link].next[i];\r\n    \
    \            } else {\r\n                    t[t[x].next[i]].link = t[t[x].link].next[i];\r\
    \n                    q.push(t[x].next[i]);\r\n                }\r\n         \
    \   }\r\n        }\r\n    }\r\n    \r\n    int next(int p, int x) {\r\n      \
    \  return t[p].next[x];\r\n    }\r\n    \r\n    int link(int p) {\r\n        return\
    \ t[p].link;\r\n    }\r\n    \r\n    int len(int p) {\r\n        return t[p].len;\r\
    \n    }\r\n    \r\n    int size() {\r\n        return t.size();\r\n    }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/06C-Aho-Corasick.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/06C-Aho-Corasick.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/06C-Aho-Corasick.hpp
- /library/src/jiangly/string/06C-Aho-Corasick.hpp.html
title: src/jiangly/string/06C-Aho-Corasick.hpp
---
