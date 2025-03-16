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
  bundledCode: "#line 1 \"src/watashi/ac-automata.hpp\"\n#include <algorithm>\n#include\
    \ <queue>\n\nusing namespace std;\n\nstruct AhoCorasick {\n    static const int\
    \ NONE = 0;\n    static const int MAXN = 1024;\n    static const int CHARSET =\
    \ 26;\n\n    int end;\n    int tag[MAXN];\n    int fail[MAXN];\n    int trie[MAXN][CHARSET];\n\
    \n    void init() {\n        tag[0] = NONE;\n        fill(trie[0], trie[0] + CHARSET,\
    \ -1);\n        end = 1;\n    }\n\n    int add(int m, const int *s) {\n      \
    \  int p = 0;\n        for (int i = 0; i < m; ++i) {\n            if (trie[p][*s]\
    \ == -1) {\n                tag[end] = NONE;\n                fill(trie[end],\
    \ trie[end] + CHARSET, -1);\n                trie[p][*s] = end++;\n          \
    \  }\n            p = trie[p][*s];\n            ++s;\n        }\n        return\
    \ p;\n    }\n\n    void build(void) { // !!\n        queue<int> bfs;\n       \
    \ fail[0] = 0;\n        for (int i = 0; i < CHARSET; ++i) {\n            if (trie[0][i]\
    \ != -1) {\n                fail[trie[0][i]] = 0;\n                bfs.push(trie[0][i]);\n\
    \            } else {\n                trie[0][i] = 0;\n            }\n      \
    \  }\n        while (!bfs.empty()) {\n            int p = bfs.front();\n     \
    \       tag[p] |= tag[fail[p]];\n            bfs.pop();\n            for (int\
    \ i = 0; i < CHARSET; ++i) {\n                if (trie[p][i] != -1) {\n      \
    \              fail[trie[p][i]] = trie[fail[p]][i];\n                    bfs.push(trie[p][i]);\n\
    \                } else {\n                    trie[p][i] = trie[fail[p]][i];\n\
    \                }\n            }\n        }\n    }\n} ac;\n"
  code: "#include <algorithm>\n#include <queue>\n\nusing namespace std;\n\nstruct\
    \ AhoCorasick {\n    static const int NONE = 0;\n    static const int MAXN = 1024;\n\
    \    static const int CHARSET = 26;\n\n    int end;\n    int tag[MAXN];\n    int\
    \ fail[MAXN];\n    int trie[MAXN][CHARSET];\n\n    void init() {\n        tag[0]\
    \ = NONE;\n        fill(trie[0], trie[0] + CHARSET, -1);\n        end = 1;\n \
    \   }\n\n    int add(int m, const int *s) {\n        int p = 0;\n        for (int\
    \ i = 0; i < m; ++i) {\n            if (trie[p][*s] == -1) {\n               \
    \ tag[end] = NONE;\n                fill(trie[end], trie[end] + CHARSET, -1);\n\
    \                trie[p][*s] = end++;\n            }\n            p = trie[p][*s];\n\
    \            ++s;\n        }\n        return p;\n    }\n\n    void build(void)\
    \ { // !!\n        queue<int> bfs;\n        fail[0] = 0;\n        for (int i =\
    \ 0; i < CHARSET; ++i) {\n            if (trie[0][i] != -1) {\n              \
    \  fail[trie[0][i]] = 0;\n                bfs.push(trie[0][i]);\n            }\
    \ else {\n                trie[0][i] = 0;\n            }\n        }\n        while\
    \ (!bfs.empty()) {\n            int p = bfs.front();\n            tag[p] |= tag[fail[p]];\n\
    \            bfs.pop();\n            for (int i = 0; i < CHARSET; ++i) {\n   \
    \             if (trie[p][i] != -1) {\n                    fail[trie[p][i]] =\
    \ trie[fail[p]][i];\n                    bfs.push(trie[p][i]);\n             \
    \   } else {\n                    trie[p][i] = trie[fail[p]][i];\n           \
    \     }\n            }\n        }\n    }\n} ac;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/ac-automata.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/ac-automata.hpp
layout: document
redirect_from:
- /library/src/watashi/ac-automata.hpp
- /library/src/watashi/ac-automata.hpp.html
title: src/watashi/ac-automata.hpp
---
