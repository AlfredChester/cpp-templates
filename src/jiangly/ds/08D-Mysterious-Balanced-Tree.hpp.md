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
  bundledCode: "#line 1 \"src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp\"\nstruct\
    \ Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n    int cnt =\
    \ 0;\r\n    int cntnew = 0;\r\n};\r\n\r\nNode *add(int l, int r, int x, int isnew)\
    \ {\r\n    Node *t = new Node;\r\n    t->cnt = 1;\r\n    t->cntnew = isnew;\r\n\
    \    if (r - l == 1) {\r\n        return t;\r\n    }\r\n    int m = (l + r) /\
    \ 2;\r\n    if (x < m) {\r\n        t->l = add(l, m, x, isnew);\r\n    } else\
    \ {\r\n        t->r = add(m, r, x, isnew);\r\n    }\r\n    return t;\r\n}\r\n\r\
    \nstruct Info {\r\n    Node *t = nullptr;\r\n    int psum = 0;\r\n    bool rev\
    \ = false;\r\n};\r\n\r\nvoid pull(Node *t) {\r\n    t->cnt = (t->l ? t->l->cnt\
    \ : 0) + (t->r ? t->r->cnt : 0);\r\n    t->cntnew = (t->l ? t->l->cntnew : 0)\
    \ + (t->r ? t->r->cntnew : 0);\r\n}\r\n\r\nstd::pair<Node *, Node *> split(Node\
    \ *t, int l, int r, int x, bool rev) {\r\n    if (!t) {\r\n        return {t,\
    \ t};\r\n    }\r\n    if (x == 0) {\r\n        return {nullptr, t};\r\n    }\r\
    \n    if (x == t->cnt) {\r\n        return {t, nullptr};\r\n    }\r\n    if (r\
    \ - l == 1) {\r\n        Node *t2 = new Node;\r\n        t2->cnt = t->cnt - x;\r\
    \n        t->cnt = x;\r\n        return {t, t2};\r\n    }\r\n    Node *t2 = new\
    \ Node;\r\n    int m = (l + r) / 2;\r\n    if (!rev) {\r\n        if (t->l &&\
    \ x <= t->l->cnt) {\r\n            std::tie(t->l, t2->l) = split(t->l, l, m, x,\
    \ rev);\r\n            t2->r = t->r;\r\n            t->r = nullptr;\r\n      \
    \  } else {\r\n            std::tie(t->r, t2->r) = split(t->r, m, r, x - (t->l\
    \ ? t->l->cnt : 0), rev);\r\n        }\r\n    } else {\r\n        if (t->r &&\
    \ x <= t->r->cnt) {\r\n            std::tie(t->r, t2->r) = split(t->r, m, r, x,\
    \ rev);\r\n            t2->l = t->l;\r\n            t->l = nullptr;\r\n      \
    \  } else {\r\n            std::tie(t->l, t2->l) = split(t->l, l, m, x - (t->r\
    \ ? t->r->cnt : 0), rev);\r\n        }\r\n    }\r\n    pull(t);\r\n    pull(t2);\r\
    \n    return {t, t2};\r\n}\r\n\r\nNode *merge(Node *t1, Node *t2, int l, int r)\
    \ {\r\n    if (!t1) {\r\n        return t2;\r\n    }\r\n    if (!t2) {\r\n   \
    \     return t1;\r\n    }\r\n    if (r - l == 1) {\r\n        t1->cnt += t2->cnt;\r\
    \n        t1->cntnew += t2->cntnew;\r\n        delete t2;\r\n        return t1;\r\
    \n    }\r\n    int m = (l + r) / 2;\r\n    t1->l = merge(t1->l, t2->l, l, m);\r\
    \n    t1->r = merge(t1->r, t2->r, m, r);\r\n    delete t2;\r\n    pull(t1);\r\n\
    \    return t1;\r\n}\r\n\r\n"
  code: "struct Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n   \
    \ int cnt = 0;\r\n    int cntnew = 0;\r\n};\r\n\r\nNode *add(int l, int r, int\
    \ x, int isnew) {\r\n    Node *t = new Node;\r\n    t->cnt = 1;\r\n    t->cntnew\
    \ = isnew;\r\n    if (r - l == 1) {\r\n        return t;\r\n    }\r\n    int m\
    \ = (l + r) / 2;\r\n    if (x < m) {\r\n        t->l = add(l, m, x, isnew);\r\n\
    \    } else {\r\n        t->r = add(m, r, x, isnew);\r\n    }\r\n    return t;\r\
    \n}\r\n\r\nstruct Info {\r\n    Node *t = nullptr;\r\n    int psum = 0;\r\n  \
    \  bool rev = false;\r\n};\r\n\r\nvoid pull(Node *t) {\r\n    t->cnt = (t->l ?\
    \ t->l->cnt : 0) + (t->r ? t->r->cnt : 0);\r\n    t->cntnew = (t->l ? t->l->cntnew\
    \ : 0) + (t->r ? t->r->cntnew : 0);\r\n}\r\n\r\nstd::pair<Node *, Node *> split(Node\
    \ *t, int l, int r, int x, bool rev) {\r\n    if (!t) {\r\n        return {t,\
    \ t};\r\n    }\r\n    if (x == 0) {\r\n        return {nullptr, t};\r\n    }\r\
    \n    if (x == t->cnt) {\r\n        return {t, nullptr};\r\n    }\r\n    if (r\
    \ - l == 1) {\r\n        Node *t2 = new Node;\r\n        t2->cnt = t->cnt - x;\r\
    \n        t->cnt = x;\r\n        return {t, t2};\r\n    }\r\n    Node *t2 = new\
    \ Node;\r\n    int m = (l + r) / 2;\r\n    if (!rev) {\r\n        if (t->l &&\
    \ x <= t->l->cnt) {\r\n            std::tie(t->l, t2->l) = split(t->l, l, m, x,\
    \ rev);\r\n            t2->r = t->r;\r\n            t->r = nullptr;\r\n      \
    \  } else {\r\n            std::tie(t->r, t2->r) = split(t->r, m, r, x - (t->l\
    \ ? t->l->cnt : 0), rev);\r\n        }\r\n    } else {\r\n        if (t->r &&\
    \ x <= t->r->cnt) {\r\n            std::tie(t->r, t2->r) = split(t->r, m, r, x,\
    \ rev);\r\n            t2->l = t->l;\r\n            t->l = nullptr;\r\n      \
    \  } else {\r\n            std::tie(t->l, t2->l) = split(t->l, l, m, x - (t->r\
    \ ? t->r->cnt : 0), rev);\r\n        }\r\n    }\r\n    pull(t);\r\n    pull(t2);\r\
    \n    return {t, t2};\r\n}\r\n\r\nNode *merge(Node *t1, Node *t2, int l, int r)\
    \ {\r\n    if (!t1) {\r\n        return t2;\r\n    }\r\n    if (!t2) {\r\n   \
    \     return t1;\r\n    }\r\n    if (r - l == 1) {\r\n        t1->cnt += t2->cnt;\r\
    \n        t1->cntnew += t2->cntnew;\r\n        delete t2;\r\n        return t1;\r\
    \n    }\r\n    int m = (l + r) / 2;\r\n    t1->l = merge(t1->l, t2->l, l, m);\r\
    \n    t1->r = merge(t1->r, t2->r, m, r);\r\n    delete t2;\r\n    pull(t1);\r\n\
    \    return t1;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp
- /library/src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp.html
title: src/jiangly/ds/08D-Mysterious-Balanced-Tree.hpp
---
