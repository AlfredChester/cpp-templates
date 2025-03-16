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
  bundledCode: "#line 1 \"src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp\"\nstruct\
    \ Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n    int sum =\
    \ 0;\r\n    int sumodd = 0;\r\n    \r\n    Node(Node *t) {\r\n        if (t) {\r\
    \n            *this = *t;\r\n        }\r\n    }\r\n};\r\n\r\nNode *add(Node *t,\
    \ int l, int r, int x, int v) {\r\n    t = new Node(t);\r\n    t->sum += v;\r\n\
    \    t->sumodd += (x % 2) * v;\r\n    if (r - l == 1) {\r\n        return t;\r\
    \n    }\r\n    int m = (l + r) / 2;\r\n    if (x < m) {\r\n        t->l = add(t->l,\
    \ l, m, x, v);\r\n    } else {\r\n        t->r = add(t->r, m, r, x, v);\r\n  \
    \  }\r\n    return t;\r\n}\r\n\r\nint query1(Node *t1, Node *t2, int l, int r,\
    \ int k) {\r\n    if (r - l == 1) {\r\n        return l;\r\n    }\r\n    int m\
    \ = (l + r) / 2;\r\n    int odd = (t1 && t1->r ? t1->r->sumodd : 0) - (t2 && t2->r\
    \ ? t2->r->sumodd : 0);\r\n    int cnt = (t1 && t1->r ? t1->r->sum : 0) - (t2\
    \ && t2->r ? t2->r->sum : 0);\r\n    if (odd > 0 || cnt > k) {\r\n        return\
    \ query1(t1 ? t1->r : t1, t2 ? t2->r : t2, m, r, k);\r\n    } else {\r\n     \
    \   return query1(t1 ? t1->l : t1, t2 ? t2->l : t2, l, m, k - cnt);\r\n    }\r\
    \n}\r\n\r\nstd::array<int, 3> query2(Node *t1, Node *t2, int l, int r, int k)\
    \ {\r\n    if (r - l == 1) {\r\n        int cnt = (t1 ? t1->sumodd : 0) - (t2\
    \ ? t2->sumodd : 0);\r\n        return {l, cnt, k};\r\n    }\r\n    int m = (l\
    \ + r) / 2;\r\n    int cnt = (t1 && t1->r ? t1->r->sumodd : 0) - (t2 && t2->r\
    \ ? t2->r->sumodd : 0);\r\n    if (cnt > k) {\r\n        return query2(t1 ? t1->r\
    \ : t1, t2 ? t2->r : t2, m, r, k);\r\n    } else {\r\n        return query2(t1\
    \ ? t1->l : t1, t2 ? t2->l : t2, l, m, k - cnt);\r\n    }\r\n}\r\n\r\n"
  code: "struct Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n   \
    \ int sum = 0;\r\n    int sumodd = 0;\r\n    \r\n    Node(Node *t) {\r\n     \
    \   if (t) {\r\n            *this = *t;\r\n        }\r\n    }\r\n};\r\n\r\nNode\
    \ *add(Node *t, int l, int r, int x, int v) {\r\n    t = new Node(t);\r\n    t->sum\
    \ += v;\r\n    t->sumodd += (x % 2) * v;\r\n    if (r - l == 1) {\r\n        return\
    \ t;\r\n    }\r\n    int m = (l + r) / 2;\r\n    if (x < m) {\r\n        t->l\
    \ = add(t->l, l, m, x, v);\r\n    } else {\r\n        t->r = add(t->r, m, r, x,\
    \ v);\r\n    }\r\n    return t;\r\n}\r\n\r\nint query1(Node *t1, Node *t2, int\
    \ l, int r, int k) {\r\n    if (r - l == 1) {\r\n        return l;\r\n    }\r\n\
    \    int m = (l + r) / 2;\r\n    int odd = (t1 && t1->r ? t1->r->sumodd : 0) -\
    \ (t2 && t2->r ? t2->r->sumodd : 0);\r\n    int cnt = (t1 && t1->r ? t1->r->sum\
    \ : 0) - (t2 && t2->r ? t2->r->sum : 0);\r\n    if (odd > 0 || cnt > k) {\r\n\
    \        return query1(t1 ? t1->r : t1, t2 ? t2->r : t2, m, r, k);\r\n    } else\
    \ {\r\n        return query1(t1 ? t1->l : t1, t2 ? t2->l : t2, l, m, k - cnt);\r\
    \n    }\r\n}\r\n\r\nstd::array<int, 3> query2(Node *t1, Node *t2, int l, int r,\
    \ int k) {\r\n    if (r - l == 1) {\r\n        int cnt = (t1 ? t1->sumodd : 0)\
    \ - (t2 ? t2->sumodd : 0);\r\n        return {l, cnt, k};\r\n    }\r\n    int\
    \ m = (l + r) / 2;\r\n    int cnt = (t1 && t1->r ? t1->r->sumodd : 0) - (t2 &&\
    \ t2->r ? t2->r->sumodd : 0);\r\n    if (cnt > k) {\r\n        return query2(t1\
    \ ? t1->r : t1, t2 ? t2->r : t2, m, r, k);\r\n    } else {\r\n        return query2(t1\
    \ ? t1->l : t1, t2 ? t2->l : t2, l, m, k - cnt);\r\n    }\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp
- /library/src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp.html
title: src/jiangly/ds/08A-Mysterious-Balanced-Tree.hpp
---
