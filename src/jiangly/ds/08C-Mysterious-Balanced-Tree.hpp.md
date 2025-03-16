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
  bundledCode: "#line 1 \"src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp\"\nstruct\
    \ Info {\r\n    int imp = 0;\r\n    int id = 0;\r\n};\r\n\r\nInfo operator+(Info\
    \ a, Info b) {\r\n    return {std::max(a.imp, b.imp), 0};\r\n}\r\n\r\nstruct Node\
    \ {\r\n    int w = rng();\r\n    Info info;\r\n    Info sum;\r\n    int siz =\
    \ 1;\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n};\r\n\r\nvoid pull(Node\
    \ *t) {\r\n    t->sum = t->info;\r\n    t->siz = 1;\r\n    if (t->l) {\r\n   \
    \     t->sum = t->l->sum + t->sum;\r\n        t->siz += t->l->siz;\r\n    }\r\n\
    \    if (t->r) {\r\n        t->sum = t->sum + t->r->sum;\r\n        t->siz +=\
    \ t->r->siz;\r\n    }\r\n}\r\n\r\nstd::pair<Node *, Node *> splitAt(Node *t, int\
    \ p) {\r\n    if (!t) {\r\n        return {t, t};\r\n    }\r\n    if (p <= (t->l\
    \ ? t->l->siz : 0)) {\r\n        auto [l, r] = splitAt(t->l, p);\r\n        t->l\
    \ = r;\r\n        pull(t);\r\n        return {l, t};\r\n    } else {\r\n     \
    \   auto [l, r] = splitAt(t->r, p - 1 - (t->l ? t->l->siz : 0));\r\n        t->r\
    \ = l;\r\n        pull(t);\r\n        return {t, r};\r\n    }\r\n}\r\n\r\nvoid\
    \ insertAt(Node *&t, int p, Node *x) {\r\n    if (!t) {\r\n        t = x;\r\n\
    \        return;\r\n    }\r\n    if (x->w < t->w) {\r\n        auto [l, r] = splitAt(t,\
    \ p);\r\n        t = x;\r\n        t->l = l;\r\n        t->r = r;\r\n        pull(t);\r\
    \n        return;\r\n    }\r\n    if (p <= (t->l ? t->l->siz : 0)) {\r\n     \
    \   insertAt(t->l, p, x);\r\n    } else {\r\n        insertAt(t->r, p - 1 - (t->l\
    \ ? t->l->siz : 0), x);\r\n    }\r\n    pull(t);\r\n}\r\n\r\nNode *merge(Node\
    \ *a, Node *b) {\r\n    if (!a) {\r\n        return b;\r\n    }\r\n    if (!b)\
    \ {\r\n        return a;\r\n    }\r\n    \r\n    if (a->w < b->w) {\r\n      \
    \  a->r = merge(a->r, b);\r\n        pull(a);\r\n        return a;\r\n    } else\
    \ {\r\n        b->l = merge(a, b->l);\r\n        pull(b);\r\n        return b;\r\
    \n    }\r\n}\r\n\r\nint query(Node *t, int v) {\r\n    if (!t) {\r\n        return\
    \ 0;\r\n    }\r\n    if (t->sum.imp < v) {\r\n        return t->siz;\r\n    }\r\
    \n    int res = query(t->r, v);\r\n    if (res != (t->r ? t->r->siz : 0)) {\r\n\
    \        return res;\r\n    }\r\n    if (t->info.imp > v) {\r\n        return\
    \ res;\r\n    }\r\n    return res + 1 + query(t->l, v);\r\n}\r\n\r\nvoid dfs(Node\
    \ *t) {\r\n    if (!t) {\r\n        return;\r\n    }\r\n    dfs(t->l);\r\n   \
    \ std::cout << t->info.id << \" \";\r\n    dfs(t->r);\r\n}\r\n\r\n"
  code: "struct Info {\r\n    int imp = 0;\r\n    int id = 0;\r\n};\r\n\r\nInfo operator+(Info\
    \ a, Info b) {\r\n    return {std::max(a.imp, b.imp), 0};\r\n}\r\n\r\nstruct Node\
    \ {\r\n    int w = rng();\r\n    Info info;\r\n    Info sum;\r\n    int siz =\
    \ 1;\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n};\r\n\r\nvoid pull(Node\
    \ *t) {\r\n    t->sum = t->info;\r\n    t->siz = 1;\r\n    if (t->l) {\r\n   \
    \     t->sum = t->l->sum + t->sum;\r\n        t->siz += t->l->siz;\r\n    }\r\n\
    \    if (t->r) {\r\n        t->sum = t->sum + t->r->sum;\r\n        t->siz +=\
    \ t->r->siz;\r\n    }\r\n}\r\n\r\nstd::pair<Node *, Node *> splitAt(Node *t, int\
    \ p) {\r\n    if (!t) {\r\n        return {t, t};\r\n    }\r\n    if (p <= (t->l\
    \ ? t->l->siz : 0)) {\r\n        auto [l, r] = splitAt(t->l, p);\r\n        t->l\
    \ = r;\r\n        pull(t);\r\n        return {l, t};\r\n    } else {\r\n     \
    \   auto [l, r] = splitAt(t->r, p - 1 - (t->l ? t->l->siz : 0));\r\n        t->r\
    \ = l;\r\n        pull(t);\r\n        return {t, r};\r\n    }\r\n}\r\n\r\nvoid\
    \ insertAt(Node *&t, int p, Node *x) {\r\n    if (!t) {\r\n        t = x;\r\n\
    \        return;\r\n    }\r\n    if (x->w < t->w) {\r\n        auto [l, r] = splitAt(t,\
    \ p);\r\n        t = x;\r\n        t->l = l;\r\n        t->r = r;\r\n        pull(t);\r\
    \n        return;\r\n    }\r\n    if (p <= (t->l ? t->l->siz : 0)) {\r\n     \
    \   insertAt(t->l, p, x);\r\n    } else {\r\n        insertAt(t->r, p - 1 - (t->l\
    \ ? t->l->siz : 0), x);\r\n    }\r\n    pull(t);\r\n}\r\n\r\nNode *merge(Node\
    \ *a, Node *b) {\r\n    if (!a) {\r\n        return b;\r\n    }\r\n    if (!b)\
    \ {\r\n        return a;\r\n    }\r\n    \r\n    if (a->w < b->w) {\r\n      \
    \  a->r = merge(a->r, b);\r\n        pull(a);\r\n        return a;\r\n    } else\
    \ {\r\n        b->l = merge(a, b->l);\r\n        pull(b);\r\n        return b;\r\
    \n    }\r\n}\r\n\r\nint query(Node *t, int v) {\r\n    if (!t) {\r\n        return\
    \ 0;\r\n    }\r\n    if (t->sum.imp < v) {\r\n        return t->siz;\r\n    }\r\
    \n    int res = query(t->r, v);\r\n    if (res != (t->r ? t->r->siz : 0)) {\r\n\
    \        return res;\r\n    }\r\n    if (t->info.imp > v) {\r\n        return\
    \ res;\r\n    }\r\n    return res + 1 + query(t->l, v);\r\n}\r\n\r\nvoid dfs(Node\
    \ *t) {\r\n    if (!t) {\r\n        return;\r\n    }\r\n    dfs(t->l);\r\n   \
    \ std::cout << t->info.id << \" \";\r\n    dfs(t->r);\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp
- /library/src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp.html
title: src/jiangly/ds/08C-Mysterious-Balanced-Tree.hpp
---
