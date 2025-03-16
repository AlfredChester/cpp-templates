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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62237107&returnHomeType=1&uid=329687984
    - https://qoj.ac/submission/384435
  bundledCode: "#line 1 \"src/jiangly/string/05-Palindrome-Automaton.hpp\"\n/**  \
    \ \u56DE\u6587\u81EA\u52A8\u673A\uFF08PAM\uFF09\r\n *    2023-05-19: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62237107&returnHomeType=1&uid=329687984\r\
    \n *    2024-04-09: https://qoj.ac/submission/384435 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstruct PAM {\r\n    static constexpr int ALPHABET_SIZE = 26;\r\n    struct\
    \ Node {\r\n        int len;\r\n        int link;\r\n        int cnt;\r\n    \
    \    std::array<int, ALPHABET_SIZE> next;\r\n        Node() : len{}, link{}, cnt{},\
    \ next{} {}\r\n    };\r\n    std::vector<Node> t;\r\n    int suff;\r\n    std::string\
    \ s;\r\n    PAM() {\r\n        init();\r\n    }\r\n    void init() {\r\n     \
    \   t.assign(2, Node());\r\n        t[0].len = -1;\r\n        suff = 1;\r\n  \
    \      s.clear();\r\n    }\r\n    int newNode() {\r\n        t.emplace_back();\r\
    \n        return t.size() - 1;\r\n    }\r\n    bool add(char c) {\r\n        int\
    \ pos = s.size();\r\n        s += c;\r\n        int let = c - 'a';\r\n       \
    \ int cur = suff, curlen = 0;\r\n        while (true) {\r\n            curlen\
    \ = t[cur].len;\r\n            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen]\
    \ == s[pos]) {\r\n                break;\r\n            }\r\n            cur =\
    \ t[cur].link;\r\n        }\r\n        if (t[cur].next[let]) {\r\n           \
    \ suff = t[cur].next[let];\r\n            return false;\r\n        }\r\n     \
    \   int num = newNode();\r\n        suff = num;\r\n        t[num].len = t[cur].len\
    \ + 2;\r\n        t[cur].next[let] = num;\r\n        if (t[num].len == 1) {\r\n\
    \            t[num].link = 1;\r\n            t[num].cnt = 1;\r\n            return\
    \ true;\r\n        }\r\n        while (true) {\r\n            cur = t[cur].link;\r\
    \n            curlen = t[cur].len;\r\n            if (pos - 1 - curlen >= 0 &&\
    \ s[pos - 1 - curlen] == s[pos]) {\r\n                t[num].link = t[cur].next[let];\r\
    \n                break;\r\n            }\r\n        }\r\n        t[num].cnt =\
    \ 1 + t[t[num].link].cnt;\r\n        return true;\r\n    }\r\n    int next(int\
    \ p, int x) {\r\n        return t[p].next[x];\r\n    }\r\n    int link(int p)\
    \ {\r\n        return t[p].link;\r\n    }\r\n    int len(int p) {\r\n        return\
    \ t[p].len;\r\n    }\r\n    int size() {\r\n        return t.size();\r\n    }\r\
    \n};\n"
  code: "/**   \u56DE\u6587\u81EA\u52A8\u673A\uFF08PAM\uFF09\r\n *    2023-05-19:\
    \ https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62237107&returnHomeType=1&uid=329687984\r\
    \n *    2024-04-09: https://qoj.ac/submission/384435 \u3010\u6A21\u677F\u3011\r\
    \n**/\r\nstruct PAM {\r\n    static constexpr int ALPHABET_SIZE = 26;\r\n    struct\
    \ Node {\r\n        int len;\r\n        int link;\r\n        int cnt;\r\n    \
    \    std::array<int, ALPHABET_SIZE> next;\r\n        Node() : len{}, link{}, cnt{},\
    \ next{} {}\r\n    };\r\n    std::vector<Node> t;\r\n    int suff;\r\n    std::string\
    \ s;\r\n    PAM() {\r\n        init();\r\n    }\r\n    void init() {\r\n     \
    \   t.assign(2, Node());\r\n        t[0].len = -1;\r\n        suff = 1;\r\n  \
    \      s.clear();\r\n    }\r\n    int newNode() {\r\n        t.emplace_back();\r\
    \n        return t.size() - 1;\r\n    }\r\n    bool add(char c) {\r\n        int\
    \ pos = s.size();\r\n        s += c;\r\n        int let = c - 'a';\r\n       \
    \ int cur = suff, curlen = 0;\r\n        while (true) {\r\n            curlen\
    \ = t[cur].len;\r\n            if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen]\
    \ == s[pos]) {\r\n                break;\r\n            }\r\n            cur =\
    \ t[cur].link;\r\n        }\r\n        if (t[cur].next[let]) {\r\n           \
    \ suff = t[cur].next[let];\r\n            return false;\r\n        }\r\n     \
    \   int num = newNode();\r\n        suff = num;\r\n        t[num].len = t[cur].len\
    \ + 2;\r\n        t[cur].next[let] = num;\r\n        if (t[num].len == 1) {\r\n\
    \            t[num].link = 1;\r\n            t[num].cnt = 1;\r\n            return\
    \ true;\r\n        }\r\n        while (true) {\r\n            cur = t[cur].link;\r\
    \n            curlen = t[cur].len;\r\n            if (pos - 1 - curlen >= 0 &&\
    \ s[pos - 1 - curlen] == s[pos]) {\r\n                t[num].link = t[cur].next[let];\r\
    \n                break;\r\n            }\r\n        }\r\n        t[num].cnt =\
    \ 1 + t[t[num].link].cnt;\r\n        return true;\r\n    }\r\n    int next(int\
    \ p, int x) {\r\n        return t[p].next[x];\r\n    }\r\n    int link(int p)\
    \ {\r\n        return t[p].link;\r\n    }\r\n    int len(int p) {\r\n        return\
    \ t[p].len;\r\n    }\r\n    int size() {\r\n        return t.size();\r\n    }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/05-Palindrome-Automaton.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/05-Palindrome-Automaton.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/05-Palindrome-Automaton.hpp
- /library/src/jiangly/string/05-Palindrome-Automaton.hpp.html
title: src/jiangly/string/05-Palindrome-Automaton.hpp
---
