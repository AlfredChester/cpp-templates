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
  bundledCode: "#line 1 \"src/jiangly/string/04A-Suffix-Automaton.hpp\"\nstruct SuffixAutomaton\
    \ {\r\n    static constexpr int ALPHABET_SIZE = 26, N = 5e5;\r\n    struct Node\
    \ {\r\n        int len;\r\n        int link;\r\n        int next[ALPHABET_SIZE];\r\
    \n        Node() : len(0), link(0), next{} {}\r\n    } t[2 * N];\r\n    int cntNodes;\r\
    \n    SuffixAutomaton() {\r\n        cntNodes = 1;\r\n        std::fill(t[0].next,\
    \ t[0].next + ALPHABET_SIZE, 1);\r\n        t[0].len = -1;\r\n    }\r\n    int\
    \ extend(int p, int c) {\r\n        if (t[p].next[c]) {\r\n            int q =\
    \ t[p].next[c];\r\n            if (t[q].len == t[p].len + 1)\r\n             \
    \   return q;\r\n            int r = ++cntNodes;\r\n            t[r].len = t[p].len\
    \ + 1;\r\n            t[r].link = t[q].link;\r\n            std::copy(t[q].next,\
    \ t[q].next + ALPHABET_SIZE, t[r].next);\r\n            t[q].link = r;\r\n   \
    \         while (t[p].next[c] == q) {\r\n                t[p].next[c] = r;\r\n\
    \                p = t[p].link;\r\n            }\r\n            return r;\r\n\
    \        }\r\n        int cur = ++cntNodes;\r\n        t[cur].len = t[p].len +\
    \ 1;\r\n        while (!t[p].next[c]) {\r\n            t[p].next[c] = cur;\r\n\
    \            p = t[p].link;\r\n        }\r\n        t[cur].link = extend(p, c);\r\
    \n        return cur;\r\n    }\r\n};\n"
  code: "struct SuffixAutomaton {\r\n    static constexpr int ALPHABET_SIZE = 26,\
    \ N = 5e5;\r\n    struct Node {\r\n        int len;\r\n        int link;\r\n \
    \       int next[ALPHABET_SIZE];\r\n        Node() : len(0), link(0), next{} {}\r\
    \n    } t[2 * N];\r\n    int cntNodes;\r\n    SuffixAutomaton() {\r\n        cntNodes\
    \ = 1;\r\n        std::fill(t[0].next, t[0].next + ALPHABET_SIZE, 1);\r\n    \
    \    t[0].len = -1;\r\n    }\r\n    int extend(int p, int c) {\r\n        if (t[p].next[c])\
    \ {\r\n            int q = t[p].next[c];\r\n            if (t[q].len == t[p].len\
    \ + 1)\r\n                return q;\r\n            int r = ++cntNodes;\r\n   \
    \         t[r].len = t[p].len + 1;\r\n            t[r].link = t[q].link;\r\n \
    \           std::copy(t[q].next, t[q].next + ALPHABET_SIZE, t[r].next);\r\n  \
    \          t[q].link = r;\r\n            while (t[p].next[c] == q) {\r\n     \
    \           t[p].next[c] = r;\r\n                p = t[p].link;\r\n          \
    \  }\r\n            return r;\r\n        }\r\n        int cur = ++cntNodes;\r\n\
    \        t[cur].len = t[p].len + 1;\r\n        while (!t[p].next[c]) {\r\n   \
    \         t[p].next[c] = cur;\r\n            p = t[p].link;\r\n        }\r\n \
    \       t[cur].link = extend(p, c);\r\n        return cur;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/04A-Suffix-Automaton.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/04A-Suffix-Automaton.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/04A-Suffix-Automaton.hpp
- /library/src/jiangly/string/04A-Suffix-Automaton.hpp.html
title: src/jiangly/string/04A-Suffix-Automaton.hpp
---
