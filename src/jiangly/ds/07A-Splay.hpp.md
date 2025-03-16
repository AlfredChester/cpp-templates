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
  bundledCode: "#line 1 \"src/jiangly/ds/07A-Splay.hpp\"\nstruct Node {\r\n    Node\
    \ *l = nullptr;\r\n    Node *r = nullptr;\r\n    int cnt = 0;\r\n    i64 sum =\
    \ 0;\r\n};\r\n\r\nNode *add(Node *t, int l, int r, int p, int v) {\r\n    Node\
    \ *x = new Node;\r\n    if (t) {\r\n        *x = *t;\r\n    }\r\n    x->cnt +=\
    \ 1;\r\n    x->sum += v;\r\n    if (r - l == 1) {\r\n        return x;\r\n   \
    \ }\r\n    int m = (l + r) / 2;\r\n    if (p < m) {\r\n        x->l = add(x->l,\
    \ l, m, p, v);\r\n    } else {\r\n        x->r = add(x->r, m, r, p, v);\r\n  \
    \  }\r\n    return x;\r\n}\r\n\r\nint find(Node *tl, Node *tr, int l, int r, int\
    \ x) {\r\n    if (r <= x) {\r\n        return -1;\r\n    }\r\n    if (l >= x)\
    \ {\r\n        int cnt = (tr ? tr->cnt : 0) - (tl ? tl->cnt : 0);\r\n        if\
    \ (cnt == 0) {\r\n            return -1;\r\n        }\r\n        if (r - l ==\
    \ 1) {\r\n            return l;\r\n        }\r\n    }\r\n    int m = (l + r) /\
    \ 2;\r\n    int res = find(tl ? tl->l : tl, tr ? tr->l : tr, l, m, x);\r\n   \
    \ if (res == -1) {\r\n        res = find(tl ? tl->r : tl, tr ? tr->r : tr, m,\
    \ r, x);\r\n    }\r\n    return res;\r\n}\r\n\r\nstd::pair<int, i64> get(Node\
    \ *t, int l, int r, int x, int y) {\r\n    if (l >= y || r <= x || !t) {\r\n \
    \       return {0, 0LL};\r\n    }\r\n    if (l >= x && r <= y) {\r\n        return\
    \ {t->cnt, t->sum};\r\n    }\r\n    int m = (l + r) / 2;\r\n    auto [cl, sl]\
    \ = get(t->l, l, m, x, y);\r\n    auto [cr, sr] = get(t->r, m, r, x, y);\r\n \
    \   return {cl + cr, sl + sr};\r\n}\r\n\r\nstruct Tree {\r\n    int add = 0;\r\
    \n    int val = 0;\r\n    int id = 0;\r\n    Tree *ch[2] = {};\r\n    Tree *p\
    \ = nullptr;\r\n};\r\n\r\nint pos(Tree *t) {\r\n    return t->p->ch[1] == t;\r\
    \n}\r\n\r\nvoid add(Tree *t, int v) {\r\n    t->val += v;\r\n    t->add += v;\r\
    \n}\r\n\r\nvoid push(Tree *t) {\r\n    if (t->ch[0]) {\r\n        add(t->ch[0],\
    \ t->add);\r\n    }\r\n    if (t->ch[1]) {\r\n        add(t->ch[1], t->add);\r\
    \n    }\r\n    t->add = 0;\r\n}\r\n\r\nvoid rotate(Tree *t) {\r\n    Tree *q =\
    \ t->p;\r\n    int x = !pos(t);\r\n    q->ch[!x] = t->ch[x];\r\n    if (t->ch[x])\
    \ t->ch[x]->p = q;\r\n    t->p = q->p;\r\n    if (q->p) q->p->ch[pos(q)] = t;\r\
    \n    t->ch[x] = q;\r\n    q->p = t;\r\n}\r\n\r\nvoid splay(Tree *t) {\r\n   \
    \ std::vector<Tree *> s;\r\n    for (Tree *i = t; i->p; i = i->p) s.push_back(i->p);\r\
    \n    while (!s.empty()) {\r\n        push(s.back());\r\n        s.pop_back();\r\
    \n    }\r\n    push(t);\r\n    while (t->p) {\r\n        if (t->p->p) {\r\n  \
    \          if (pos(t) == pos(t->p)) rotate(t->p);\r\n            else rotate(t);\r\
    \n        }\r\n        rotate(t);\r\n    }\r\n}\r\n\r\nvoid insert(Tree *&t, Tree\
    \ *x, Tree *p = nullptr) {\r\n    if (!t) {\r\n        t = x;\r\n        x->p\
    \ = p;\r\n        return;\r\n    }\r\n    \r\n    push(t);\r\n    if (x->val <\
    \ t->val) {\r\n        insert(t->ch[0], x, t);\r\n    } else {\r\n        insert(t->ch[1],\
    \ x, t);\r\n    }\r\n}\r\n\r\nvoid dfs(Tree *t) {\r\n    if (!t) {\r\n       \
    \ return;\r\n    }\r\n    push(t);\r\n    dfs(t->ch[0]);\r\n    std::cerr << t->val\
    \ << \" \";\r\n    dfs(t->ch[1]);\r\n}\r\n\r\nstd::pair<Tree *, Tree *> split(Tree\
    \ *t, int x) {\r\n    if (!t) {\r\n        return {t, t};\r\n    }\r\n    Tree\
    \ *v = nullptr;\r\n    Tree *j = t;\r\n    for (Tree *i = t; i; ) {\r\n      \
    \  push(i);\r\n        j = i;\r\n        if (i->val >= x) {\r\n            v =\
    \ i;\r\n            i = i->ch[0];\r\n        } else {\r\n            i = i->ch[1];\r\
    \n        }\r\n    }\r\n    \r\n    splay(j);\r\n    if (!v) {\r\n        return\
    \ {j, nullptr};\r\n    }\r\n    \r\n    splay(v);\r\n    \r\n    Tree *u = v->ch[0];\r\
    \n    if (u) {\r\n        v->ch[0] = u->p = nullptr;\r\n    }\r\n    // std::cerr\
    \ << \"split \" << x << \"\\n\";\r\n    // dfs(u);\r\n    // std::cerr << \"\\\
    n\";\r\n    // dfs(v);\r\n    // std::cerr << \"\\n\";\r\n    return {u, v};\r\
    \n}\r\n\r\nTree *merge(Tree *l, Tree *r) {\r\n    if (!l) {\r\n        return\
    \ r;\r\n    }\r\n    if (!r) {\r\n        return l;\r\n    }\r\n    Tree *i =\
    \ l;\r\n    while (i->ch[1]) {\r\n        i = i->ch[1];\r\n    }\r\n    splay(i);\r\
    \n    i->ch[1] = r;\r\n    r->p = i;\r\n    return i;\r\n}\r\n\r\n"
  code: "struct Node {\r\n    Node *l = nullptr;\r\n    Node *r = nullptr;\r\n   \
    \ int cnt = 0;\r\n    i64 sum = 0;\r\n};\r\n\r\nNode *add(Node *t, int l, int\
    \ r, int p, int v) {\r\n    Node *x = new Node;\r\n    if (t) {\r\n        *x\
    \ = *t;\r\n    }\r\n    x->cnt += 1;\r\n    x->sum += v;\r\n    if (r - l == 1)\
    \ {\r\n        return x;\r\n    }\r\n    int m = (l + r) / 2;\r\n    if (p < m)\
    \ {\r\n        x->l = add(x->l, l, m, p, v);\r\n    } else {\r\n        x->r =\
    \ add(x->r, m, r, p, v);\r\n    }\r\n    return x;\r\n}\r\n\r\nint find(Node *tl,\
    \ Node *tr, int l, int r, int x) {\r\n    if (r <= x) {\r\n        return -1;\r\
    \n    }\r\n    if (l >= x) {\r\n        int cnt = (tr ? tr->cnt : 0) - (tl ? tl->cnt\
    \ : 0);\r\n        if (cnt == 0) {\r\n            return -1;\r\n        }\r\n\
    \        if (r - l == 1) {\r\n            return l;\r\n        }\r\n    }\r\n\
    \    int m = (l + r) / 2;\r\n    int res = find(tl ? tl->l : tl, tr ? tr->l :\
    \ tr, l, m, x);\r\n    if (res == -1) {\r\n        res = find(tl ? tl->r : tl,\
    \ tr ? tr->r : tr, m, r, x);\r\n    }\r\n    return res;\r\n}\r\n\r\nstd::pair<int,\
    \ i64> get(Node *t, int l, int r, int x, int y) {\r\n    if (l >= y || r <= x\
    \ || !t) {\r\n        return {0, 0LL};\r\n    }\r\n    if (l >= x && r <= y) {\r\
    \n        return {t->cnt, t->sum};\r\n    }\r\n    int m = (l + r) / 2;\r\n  \
    \  auto [cl, sl] = get(t->l, l, m, x, y);\r\n    auto [cr, sr] = get(t->r, m,\
    \ r, x, y);\r\n    return {cl + cr, sl + sr};\r\n}\r\n\r\nstruct Tree {\r\n  \
    \  int add = 0;\r\n    int val = 0;\r\n    int id = 0;\r\n    Tree *ch[2] = {};\r\
    \n    Tree *p = nullptr;\r\n};\r\n\r\nint pos(Tree *t) {\r\n    return t->p->ch[1]\
    \ == t;\r\n}\r\n\r\nvoid add(Tree *t, int v) {\r\n    t->val += v;\r\n    t->add\
    \ += v;\r\n}\r\n\r\nvoid push(Tree *t) {\r\n    if (t->ch[0]) {\r\n        add(t->ch[0],\
    \ t->add);\r\n    }\r\n    if (t->ch[1]) {\r\n        add(t->ch[1], t->add);\r\
    \n    }\r\n    t->add = 0;\r\n}\r\n\r\nvoid rotate(Tree *t) {\r\n    Tree *q =\
    \ t->p;\r\n    int x = !pos(t);\r\n    q->ch[!x] = t->ch[x];\r\n    if (t->ch[x])\
    \ t->ch[x]->p = q;\r\n    t->p = q->p;\r\n    if (q->p) q->p->ch[pos(q)] = t;\r\
    \n    t->ch[x] = q;\r\n    q->p = t;\r\n}\r\n\r\nvoid splay(Tree *t) {\r\n   \
    \ std::vector<Tree *> s;\r\n    for (Tree *i = t; i->p; i = i->p) s.push_back(i->p);\r\
    \n    while (!s.empty()) {\r\n        push(s.back());\r\n        s.pop_back();\r\
    \n    }\r\n    push(t);\r\n    while (t->p) {\r\n        if (t->p->p) {\r\n  \
    \          if (pos(t) == pos(t->p)) rotate(t->p);\r\n            else rotate(t);\r\
    \n        }\r\n        rotate(t);\r\n    }\r\n}\r\n\r\nvoid insert(Tree *&t, Tree\
    \ *x, Tree *p = nullptr) {\r\n    if (!t) {\r\n        t = x;\r\n        x->p\
    \ = p;\r\n        return;\r\n    }\r\n    \r\n    push(t);\r\n    if (x->val <\
    \ t->val) {\r\n        insert(t->ch[0], x, t);\r\n    } else {\r\n        insert(t->ch[1],\
    \ x, t);\r\n    }\r\n}\r\n\r\nvoid dfs(Tree *t) {\r\n    if (!t) {\r\n       \
    \ return;\r\n    }\r\n    push(t);\r\n    dfs(t->ch[0]);\r\n    std::cerr << t->val\
    \ << \" \";\r\n    dfs(t->ch[1]);\r\n}\r\n\r\nstd::pair<Tree *, Tree *> split(Tree\
    \ *t, int x) {\r\n    if (!t) {\r\n        return {t, t};\r\n    }\r\n    Tree\
    \ *v = nullptr;\r\n    Tree *j = t;\r\n    for (Tree *i = t; i; ) {\r\n      \
    \  push(i);\r\n        j = i;\r\n        if (i->val >= x) {\r\n            v =\
    \ i;\r\n            i = i->ch[0];\r\n        } else {\r\n            i = i->ch[1];\r\
    \n        }\r\n    }\r\n    \r\n    splay(j);\r\n    if (!v) {\r\n        return\
    \ {j, nullptr};\r\n    }\r\n    \r\n    splay(v);\r\n    \r\n    Tree *u = v->ch[0];\r\
    \n    if (u) {\r\n        v->ch[0] = u->p = nullptr;\r\n    }\r\n    // std::cerr\
    \ << \"split \" << x << \"\\n\";\r\n    // dfs(u);\r\n    // std::cerr << \"\\\
    n\";\r\n    // dfs(v);\r\n    // std::cerr << \"\\n\";\r\n    return {u, v};\r\
    \n}\r\n\r\nTree *merge(Tree *l, Tree *r) {\r\n    if (!l) {\r\n        return\
    \ r;\r\n    }\r\n    if (!r) {\r\n        return l;\r\n    }\r\n    Tree *i =\
    \ l;\r\n    while (i->ch[1]) {\r\n        i = i->ch[1];\r\n    }\r\n    splay(i);\r\
    \n    i->ch[1] = r;\r\n    r->p = i;\r\n    return i;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/07A-Splay.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/07A-Splay.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/07A-Splay.hpp
- /library/src/jiangly/ds/07A-Splay.hpp.html
title: src/jiangly/ds/07A-Splay.hpp
---
