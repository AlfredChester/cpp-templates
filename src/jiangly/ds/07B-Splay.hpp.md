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
  bundledCode: "#line 1 \"src/jiangly/ds/07B-Splay.hpp\"\nstruct Node {\r\n    Node\
    \ *ch[2], *p;\r\n    bool rev;\r\n    int siz = 1;\r\n    Node() : ch{nullptr,\
    \ nullptr}, p(nullptr), rev(false) {}\r\n};\r\nvoid reverse(Node *t) {\r\n   \
    \ if (t) {\r\n        std::swap(t->ch[0], t->ch[1]);\r\n        t->rev ^= 1;\r\
    \n    }\r\n}\r\nvoid push(Node *t) {\r\n    if (t->rev) {\r\n        reverse(t->ch[0]);\r\
    \n        reverse(t->ch[1]);\r\n        t->rev = false;\r\n    }\r\n}\r\nvoid\
    \ pull(Node *t) {\r\n    t->siz = (t->ch[0] ? t->ch[0]->siz : 0) + 1 + (t->ch[1]\
    \ ? t->ch[1]->siz : 0);\r\n}\r\nbool isroot(Node *t) {\r\n    return t->p == nullptr\
    \ || (t->p->ch[0] != t && t->p->ch[1] != t);\r\n}\r\nint pos(Node *t) {\r\n  \
    \  return t->p->ch[1] == t;\r\n}\r\nvoid pushAll(Node *t) {\r\n    if (!isroot(t))\
    \ {\r\n        pushAll(t->p);\r\n    }\r\n    push(t);\r\n}\r\nvoid rotate(Node\
    \ *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\n    q->ch[!x] = t->ch[x];\r\
    \n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\n    }\r\n    t->p = q->p;\r\
    \n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)] = t;\r\n    }\r\n    t->ch[x]\
    \ = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\nvoid splay(Node *t) {\r\n    pushAll(t);\r\
    \n    while (!isroot(t)) {\r\n        if (!isroot(t->p)) {\r\n            if (pos(t)\
    \ == pos(t->p)) {\r\n                rotate(t->p);\r\n            } else {\r\n\
    \                rotate(t);\r\n            }\r\n        }\r\n        rotate(t);\r\
    \n    }\r\n    pull(t);\r\n}\r\nvoid access(Node *t) {\r\n    for (Node *i = t,\
    \ *q = nullptr; i; q = i, i = i->p) {\r\n        splay(i);\r\n        i->ch[1]\
    \ = q;\r\n        pull(i);\r\n    }\r\n    splay(t);\r\n}\r\nvoid makeroot(Node\
    \ *t) {\r\n    access(t);\r\n    reverse(t);\r\n}\r\nvoid link(Node *x, Node *y)\
    \ {\r\n    makeroot(x);\r\n    x->p = y;\r\n}\r\nvoid split(Node *x, Node *y)\
    \ {\r\n    makeroot(x);\r\n    access(y);\r\n}\r\nvoid cut(Node *x, Node *y) {\r\
    \n    split(x, y);\r\n    x->p = y->ch[0] = nullptr;\r\n    pull(y);\r\n}\r\n\
    int dist(Node *x, Node *y) {\r\n    split(x, y);\r\n    return y->siz - 1;\r\n\
    }\n"
  code: "struct Node {\r\n    Node *ch[2], *p;\r\n    bool rev;\r\n    int siz = 1;\r\
    \n    Node() : ch{nullptr, nullptr}, p(nullptr), rev(false) {}\r\n};\r\nvoid reverse(Node\
    \ *t) {\r\n    if (t) {\r\n        std::swap(t->ch[0], t->ch[1]);\r\n        t->rev\
    \ ^= 1;\r\n    }\r\n}\r\nvoid push(Node *t) {\r\n    if (t->rev) {\r\n       \
    \ reverse(t->ch[0]);\r\n        reverse(t->ch[1]);\r\n        t->rev = false;\r\
    \n    }\r\n}\r\nvoid pull(Node *t) {\r\n    t->siz = (t->ch[0] ? t->ch[0]->siz\
    \ : 0) + 1 + (t->ch[1] ? t->ch[1]->siz : 0);\r\n}\r\nbool isroot(Node *t) {\r\n\
    \    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t);\r\n}\r\n\
    int pos(Node *t) {\r\n    return t->p->ch[1] == t;\r\n}\r\nvoid pushAll(Node *t)\
    \ {\r\n    if (!isroot(t)) {\r\n        pushAll(t->p);\r\n    }\r\n    push(t);\r\
    \n}\r\nvoid rotate(Node *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\
    \n    q->ch[!x] = t->ch[x];\r\n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\
    \n    }\r\n    t->p = q->p;\r\n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)]\
    \ = t;\r\n    }\r\n    t->ch[x] = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\n\
    void splay(Node *t) {\r\n    pushAll(t);\r\n    while (!isroot(t)) {\r\n     \
    \   if (!isroot(t->p)) {\r\n            if (pos(t) == pos(t->p)) {\r\n       \
    \         rotate(t->p);\r\n            } else {\r\n                rotate(t);\r\
    \n            }\r\n        }\r\n        rotate(t);\r\n    }\r\n    pull(t);\r\n\
    }\r\nvoid access(Node *t) {\r\n    for (Node *i = t, *q = nullptr; i; q = i, i\
    \ = i->p) {\r\n        splay(i);\r\n        i->ch[1] = q;\r\n        pull(i);\r\
    \n    }\r\n    splay(t);\r\n}\r\nvoid makeroot(Node *t) {\r\n    access(t);\r\n\
    \    reverse(t);\r\n}\r\nvoid link(Node *x, Node *y) {\r\n    makeroot(x);\r\n\
    \    x->p = y;\r\n}\r\nvoid split(Node *x, Node *y) {\r\n    makeroot(x);\r\n\
    \    access(y);\r\n}\r\nvoid cut(Node *x, Node *y) {\r\n    split(x, y);\r\n \
    \   x->p = y->ch[0] = nullptr;\r\n    pull(y);\r\n}\r\nint dist(Node *x, Node\
    \ *y) {\r\n    split(x, y);\r\n    return y->siz - 1;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/07B-Splay.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/07B-Splay.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/07B-Splay.hpp
- /library/src/jiangly/ds/07B-Splay.hpp.html
title: src/jiangly/ds/07B-Splay.hpp
---
