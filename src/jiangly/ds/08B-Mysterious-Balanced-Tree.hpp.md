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
  bundledCode: "#line 1 \"src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp\"\nstruct\
    \ Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n    int cnt =\
    \ 0;\r\n};\r\n\r\nNode *add(Node *t, int l, int r, int x) {\r\n    if (t) {\r\n\
    \        t = new Node(*t);\r\n    } else {\r\n        t = new Node;\r\n    }\r\
    \n    t->cnt += 1;\r\n    if (r - l == 1) {\r\n        return t;\r\n    }\r\n\
    \    int m = (l + r) / 2;\r\n    if (x < m) {\r\n        t->l = add(t->l, l, m,\
    \ x);\r\n    } else {\r\n        t->r = add(t->r, m, r, x);\r\n    }\r\n    return\
    \ t;\r\n}\r\n\r\nint query(Node *t1, Node *t2, int l, int r, int x) {\r\n    int\
    \ cnt = (t2 ? t2->cnt : 0) - (t1 ? t1->cnt : 0);\r\n    if (cnt == 0 || l >= x)\
    \ {\r\n        return -1;\r\n    }\r\n    if (r - l == 1) {\r\n        return\
    \ l;\r\n    }\r\n    int m = (l + r) / 2;\r\n    int res = query(t1 ? t1->r :\
    \ t1, t2 ? t2->r : t2, m, r, x);\r\n    if (res == -1) {\r\n        res = query(t1\
    \ ? t1->l : t1, t2 ? t2->l : t2, l, m, x);\r\n    }\r\n    return res;\r\n}\r\n\
    \r\n"
  code: "struct Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n   \
    \ int cnt = 0;\r\n};\r\n\r\nNode *add(Node *t, int l, int r, int x) {\r\n    if\
    \ (t) {\r\n        t = new Node(*t);\r\n    } else {\r\n        t = new Node;\r\
    \n    }\r\n    t->cnt += 1;\r\n    if (r - l == 1) {\r\n        return t;\r\n\
    \    }\r\n    int m = (l + r) / 2;\r\n    if (x < m) {\r\n        t->l = add(t->l,\
    \ l, m, x);\r\n    } else {\r\n        t->r = add(t->r, m, r, x);\r\n    }\r\n\
    \    return t;\r\n}\r\n\r\nint query(Node *t1, Node *t2, int l, int r, int x)\
    \ {\r\n    int cnt = (t2 ? t2->cnt : 0) - (t1 ? t1->cnt : 0);\r\n    if (cnt ==\
    \ 0 || l >= x) {\r\n        return -1;\r\n    }\r\n    if (r - l == 1) {\r\n \
    \       return l;\r\n    }\r\n    int m = (l + r) / 2;\r\n    int res = query(t1\
    \ ? t1->r : t1, t2 ? t2->r : t2, m, r, x);\r\n    if (res == -1) {\r\n       \
    \ res = query(t1 ? t1->l : t1, t2 ? t2->l : t2, l, m, x);\r\n    }\r\n    return\
    \ res;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp
- /library/src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp.html
title: src/jiangly/ds/08B-Mysterious-Balanced-Tree.hpp
---
