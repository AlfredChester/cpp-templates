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
    - https://cf.dianhsu.com/gym/105229/submission/267199687?version=1.5
  bundledCode: "#line 1 \"src/jiangly/ds/07C-Splay.hpp\"\nstruct Matrix : std::array<std::array<i64,\
    \ 4>, 4> {\r\n    Matrix(i64 v = 0) {\r\n        for (int i = 0; i < 4; i++) {\r\
    \n            for (int j = 0; j < 4; j++) {\r\n                (*this)[i][j] =\
    \ (i == j ? v : inf);\r\n            }\r\n        }\r\n    }\r\n};\r\n\r\nMatrix\
    \ operator*(const Matrix &a, const Matrix &b) {\r\n    Matrix c(inf);\r\n    for\
    \ (int i = 0; i < 3; i++) {\r\n        for (int j = 0; j < 3; j++) {\r\n     \
    \       for (int k = 0; k < 4; k++) {\r\n                c[i][k] = std::min(c[i][k],\
    \ a[i][j] + b[j][k]);\r\n            }\r\n        }\r\n        c[i][3] = std::min(c[i][3],\
    \ a[i][3]);\r\n    }\r\n    c[3][3] = 0;\r\n    return c;\r\n}\r\n\r\nstruct Node\
    \ {\r\n    Node *ch[2], *p;\r\n    i64 sumg = 0;\r\n    i64 sumh = 0;\r\n    i64\
    \ sumb = 0;\r\n    i64 g = 0;\r\n    i64 h = 0;\r\n    i64 b = 0;\r\n    Matrix\
    \ mat;\r\n    Matrix prd;\r\n    std::array<i64, 4> ans{};\r\n    Node() : ch{nullptr,\
    \ nullptr}, p(nullptr) {}\r\n\r\n    void update() {\r\n        mat = Matrix(inf);\r\
    \n        mat[0][0] = b + h - g + sumg;\r\n        mat[1][1] = mat[1][2] = mat[1][3]\
    \ = h + sumh;\r\n        mat[2][0] = mat[2][1] = mat[2][2] = mat[2][3] = b + h\
    \ + sumb;\r\n        mat[3][3] = 0;\r\n    }\r\n};\r\nvoid push(Node *t) {\r\n\
    }\r\nvoid pull(Node *t) {\r\n    t->prd = (t->ch[0] ? t->ch[0]->prd : Matrix())\
    \ * t->mat * (t->ch[1] ? t->ch[1]->prd : Matrix());\r\n}\r\nbool isroot(Node *t)\
    \ {\r\n    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t);\r\
    \n}\r\nint pos(Node *t) {\r\n    return t->p->ch[1] == t;\r\n}\r\nvoid pushAll(Node\
    \ *t) {\r\n    if (!isroot(t)) {\r\n        pushAll(t->p);\r\n    }\r\n    push(t);\r\
    \n}\r\nvoid rotate(Node *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\
    \n    q->ch[!x] = t->ch[x];\r\n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\
    \n    }\r\n    t->p = q->p;\r\n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)]\
    \ = t;\r\n    }\r\n    t->ch[x] = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\n\
    void splay(Node *t) {\r\n    pushAll(t);\r\n    while (!isroot(t)) {\r\n     \
    \   if (!isroot(t->p)) {\r\n            if (pos(t) == pos(t->p)) {\r\n       \
    \         rotate(t->p);\r\n            } else {\r\n                rotate(t);\r\
    \n            }\r\n        }\r\n        rotate(t);\r\n    }\r\n    pull(t);\r\n\
    }\r\n\r\nstd::array<i64, 4> get(Node *t) {\r\n    std::array<i64, 4> ans;\r\n\
    \    ans.fill(inf);\r\n    ans[3] = 0;\r\n    for (int i = 0; i < 3; i++) {\r\n\
    \        for (int j = 0; j < 4; j++) {\r\n            ans[i] = std::min(ans[i],\
    \ t->prd[i][j]);\r\n        }\r\n    }\r\n    return ans;\r\n}\r\n\r\nvoid access(Node\
    \ *t) {\r\n    std::array<i64, 4> old{};\r\n    for (Node *i = t, *q = nullptr;\
    \ i; q = i, i = i->p) {\r\n        splay(i);\r\n        if (i->ch[1]) {\r\n  \
    \          auto res = get(i->ch[1]);\r\n            i->sumg += res[0];\r\n   \
    \         i->sumh += std::min({res[1], res[2], res[3]});\r\n            i->sumb\
    \ += std::min({res[0], res[1], res[2], res[3]});\r\n        }\r\n        i->ch[1]\
    \ = q;\r\n        i->sumg -= old[0];\r\n        i->sumh -= std::min({old[1], old[2],\
    \ old[3]});\r\n        i->sumb -= std::min({old[0], old[1], old[2], old[3]});\r\
    \n        old = get(i);\r\n        i->update();\r\n        pull(i);\r\n    }\r\
    \n    splay(t);\r\n}\r\n```\r\n\r\n```cpp\r\n    /**   Splay\r\n     *    2024-06-24:\
    \ https://cf.dianhsu.com/gym/105229/submission/267199687?version=1.5\r\n     **/\r\
    \n    constexpr int D = 27;\r\nstruct Info {\r\n    int up[D][2]{};\r\n    int\
    \ down[D][2]{};\r\n    int t = 0;\r\n    i64 ans = 0;\r\n};\r\n\r\nInfo operator+(const\
    \ Info &a, const Info &b) {\r\n    Info c;\r\n    c.t = a.t ^ b.t;\r\n    c.ans\
    \ = a.ans + b.ans;\r\n    for (int i = 0; i < D; i++) {\r\n        for (int j\
    \ = 0; j < 2; j++) {\r\n            c.ans += (1LL << i) * a.down[i][j] * b.up[i][j\
    \ ^ 1];\r\n            c.up[i][j] += a.up[i][j] + b.up[i][j ^ (a.t >> i & 1)];\r\
    \n            c.down[i][j] += b.down[i][j] + a.down[i][j ^ (b.t >> i & 1)];\r\n\
    \        }\r\n    }\r\n    return c;\r\n}\r\nstruct Node {\r\n    Node *ch[2],\
    \ *p;\r\n    Info val;\r\n    Info tot;\r\n    int cnt[D][2];\r\n    i64 pair[D][2];\r\
    \n    i64 sum;\r\n    Node() : ch{nullptr, nullptr}, p(nullptr), cnt{}, pair{},\
    \ sum{} {}\r\n};\r\nvoid pull(Node *t) {\r\n    t->tot = (t->ch[0] ? t->ch[0]->tot\
    \ : Info{}) + t->val + (t->ch[1] ? t->ch[1]->tot : Info{});\r\n}\r\nbool isroot(Node\
    \ *t) {\r\n    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t);\r\
    \n}\r\nint pos(Node *t) {\r\n    return t->p->ch[1] == t;\r\n}\r\nvoid rotate(Node\
    \ *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\n    q->ch[!x] = t->ch[x];\r\
    \n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\n    }\r\n    t->p = q->p;\r\
    \n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)] = t;\r\n    }\r\n    t->ch[x]\
    \ = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\nvoid update(Node *t) {\r\n   \
    \ t->val.ans = t->val.t + t->sum;\r\n    for (int i = 0; i < D; i++) {\r\n   \
    \     t->val.ans += (1LL << i) * t->pair[i][t->val.t >> i & 1];\r\n        for\
    \ (int j = 0; j < 2; j++) {\r\n            t->val.up[i][j] = t->cnt[i][j ^ (t->val.t\
    \ >> i & 1)];\r\n            t->val.down[i][j] = t->cnt[i][j ^ (t->val.t >> i\
    \ & 1)];\r\n        }\r\n        t->val.up[i][t->val.t >> i & 1]++;\r\n      \
    \  t->val.down[i][t->val.t >> i & 1]++;\r\n    }\r\n    pull(t);\r\n}\r\nvoid\
    \ splay(Node *t) {\r\n    while (!isroot(t)) {\r\n        if (!isroot(t->p)) {\r\
    \n            if (pos(t) == pos(t->p)) {\r\n                rotate(t->p);\r\n\
    \            } else {\r\n                rotate(t);\r\n            }\r\n     \
    \   }\r\n        rotate(t);\r\n    }\r\n    pull(t);\r\n}\r\nvoid add(Node *t,\
    \ Info s) {\r\n    for (int i = 0; i < D; i++) {\r\n        for (int x = 0; x\
    \ < 2; x++) {\r\n            t->pair[i][x] += s.up[i][1 ^ x];\r\n            for\
    \ (int j = 0; j < 2; j++) {\r\n                t->pair[i][x] += t->cnt[i][j] *\
    \ s.up[i][j ^ 1 ^ x];\r\n            }\r\n        }\r\n        for (int j = 0;\
    \ j < 2; j++) {\r\n            t->cnt[i][j] += s.up[i][j];\r\n        }\r\n  \
    \  }\r\n    t->sum += s.ans;\r\n}\r\nvoid del(Node *t, Info s) {\r\n    t->sum\
    \ -= s.ans;\r\n    for (int i = 0; i < D; i++) {\r\n        for (int j = 0; j\
    \ < 2; j++) {\r\n            t->cnt[i][j] -= s.up[i][j];\r\n        }\r\n    \
    \    for (int x = 0; x < 2; x++) {\r\n            for (int j = 0; j < 2; j++)\
    \ {\r\n                t->pair[i][x] -= t->cnt[i][j] * s.up[i][j ^ 1 ^ x];\r\n\
    \            }\r\n            t->pair[i][x] -= s.up[i][1 ^ x];\r\n        }\r\n\
    \    }\r\n}\r\nvoid access(Node *t, int v) {\r\n    Info lst;\r\n    for (Node\
    \ *i = t, *q = nullptr; i; q = i, i = i->p) {\r\n        splay(i);\r\n       \
    \ if (i->ch[1]) {\r\n            add(i, i->ch[1]->tot);\r\n        }\r\n     \
    \   i->ch[1] = q;\r\n        if (q) {\r\n            del(i, lst);\r\n        }\
    \ else {\r\n            i->val.t = v;\r\n        }\r\n        lst = i->tot;\r\n\
    \        update(i);\r\n    }\r\n    splay(t);\r\n}\n"
  code: "struct Matrix : std::array<std::array<i64, 4>, 4> {\r\n    Matrix(i64 v =\
    \ 0) {\r\n        for (int i = 0; i < 4; i++) {\r\n            for (int j = 0;\
    \ j < 4; j++) {\r\n                (*this)[i][j] = (i == j ? v : inf);\r\n   \
    \         }\r\n        }\r\n    }\r\n};\r\n\r\nMatrix operator*(const Matrix &a,\
    \ const Matrix &b) {\r\n    Matrix c(inf);\r\n    for (int i = 0; i < 3; i++)\
    \ {\r\n        for (int j = 0; j < 3; j++) {\r\n            for (int k = 0; k\
    \ < 4; k++) {\r\n                c[i][k] = std::min(c[i][k], a[i][j] + b[j][k]);\r\
    \n            }\r\n        }\r\n        c[i][3] = std::min(c[i][3], a[i][3]);\r\
    \n    }\r\n    c[3][3] = 0;\r\n    return c;\r\n}\r\n\r\nstruct Node {\r\n   \
    \ Node *ch[2], *p;\r\n    i64 sumg = 0;\r\n    i64 sumh = 0;\r\n    i64 sumb =\
    \ 0;\r\n    i64 g = 0;\r\n    i64 h = 0;\r\n    i64 b = 0;\r\n    Matrix mat;\r\
    \n    Matrix prd;\r\n    std::array<i64, 4> ans{};\r\n    Node() : ch{nullptr,\
    \ nullptr}, p(nullptr) {}\r\n\r\n    void update() {\r\n        mat = Matrix(inf);\r\
    \n        mat[0][0] = b + h - g + sumg;\r\n        mat[1][1] = mat[1][2] = mat[1][3]\
    \ = h + sumh;\r\n        mat[2][0] = mat[2][1] = mat[2][2] = mat[2][3] = b + h\
    \ + sumb;\r\n        mat[3][3] = 0;\r\n    }\r\n};\r\nvoid push(Node *t) {\r\n\
    }\r\nvoid pull(Node *t) {\r\n    t->prd = (t->ch[0] ? t->ch[0]->prd : Matrix())\
    \ * t->mat * (t->ch[1] ? t->ch[1]->prd : Matrix());\r\n}\r\nbool isroot(Node *t)\
    \ {\r\n    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t);\r\
    \n}\r\nint pos(Node *t) {\r\n    return t->p->ch[1] == t;\r\n}\r\nvoid pushAll(Node\
    \ *t) {\r\n    if (!isroot(t)) {\r\n        pushAll(t->p);\r\n    }\r\n    push(t);\r\
    \n}\r\nvoid rotate(Node *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\
    \n    q->ch[!x] = t->ch[x];\r\n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\
    \n    }\r\n    t->p = q->p;\r\n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)]\
    \ = t;\r\n    }\r\n    t->ch[x] = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\n\
    void splay(Node *t) {\r\n    pushAll(t);\r\n    while (!isroot(t)) {\r\n     \
    \   if (!isroot(t->p)) {\r\n            if (pos(t) == pos(t->p)) {\r\n       \
    \         rotate(t->p);\r\n            } else {\r\n                rotate(t);\r\
    \n            }\r\n        }\r\n        rotate(t);\r\n    }\r\n    pull(t);\r\n\
    }\r\n\r\nstd::array<i64, 4> get(Node *t) {\r\n    std::array<i64, 4> ans;\r\n\
    \    ans.fill(inf);\r\n    ans[3] = 0;\r\n    for (int i = 0; i < 3; i++) {\r\n\
    \        for (int j = 0; j < 4; j++) {\r\n            ans[i] = std::min(ans[i],\
    \ t->prd[i][j]);\r\n        }\r\n    }\r\n    return ans;\r\n}\r\n\r\nvoid access(Node\
    \ *t) {\r\n    std::array<i64, 4> old{};\r\n    for (Node *i = t, *q = nullptr;\
    \ i; q = i, i = i->p) {\r\n        splay(i);\r\n        if (i->ch[1]) {\r\n  \
    \          auto res = get(i->ch[1]);\r\n            i->sumg += res[0];\r\n   \
    \         i->sumh += std::min({res[1], res[2], res[3]});\r\n            i->sumb\
    \ += std::min({res[0], res[1], res[2], res[3]});\r\n        }\r\n        i->ch[1]\
    \ = q;\r\n        i->sumg -= old[0];\r\n        i->sumh -= std::min({old[1], old[2],\
    \ old[3]});\r\n        i->sumb -= std::min({old[0], old[1], old[2], old[3]});\r\
    \n        old = get(i);\r\n        i->update();\r\n        pull(i);\r\n    }\r\
    \n    splay(t);\r\n}\r\n```\r\n\r\n```cpp\r\n    /**   Splay\r\n     *    2024-06-24:\
    \ https://cf.dianhsu.com/gym/105229/submission/267199687?version=1.5\r\n     **/\r\
    \n    constexpr int D = 27;\r\nstruct Info {\r\n    int up[D][2]{};\r\n    int\
    \ down[D][2]{};\r\n    int t = 0;\r\n    i64 ans = 0;\r\n};\r\n\r\nInfo operator+(const\
    \ Info &a, const Info &b) {\r\n    Info c;\r\n    c.t = a.t ^ b.t;\r\n    c.ans\
    \ = a.ans + b.ans;\r\n    for (int i = 0; i < D; i++) {\r\n        for (int j\
    \ = 0; j < 2; j++) {\r\n            c.ans += (1LL << i) * a.down[i][j] * b.up[i][j\
    \ ^ 1];\r\n            c.up[i][j] += a.up[i][j] + b.up[i][j ^ (a.t >> i & 1)];\r\
    \n            c.down[i][j] += b.down[i][j] + a.down[i][j ^ (b.t >> i & 1)];\r\n\
    \        }\r\n    }\r\n    return c;\r\n}\r\nstruct Node {\r\n    Node *ch[2],\
    \ *p;\r\n    Info val;\r\n    Info tot;\r\n    int cnt[D][2];\r\n    i64 pair[D][2];\r\
    \n    i64 sum;\r\n    Node() : ch{nullptr, nullptr}, p(nullptr), cnt{}, pair{},\
    \ sum{} {}\r\n};\r\nvoid pull(Node *t) {\r\n    t->tot = (t->ch[0] ? t->ch[0]->tot\
    \ : Info{}) + t->val + (t->ch[1] ? t->ch[1]->tot : Info{});\r\n}\r\nbool isroot(Node\
    \ *t) {\r\n    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t);\r\
    \n}\r\nint pos(Node *t) {\r\n    return t->p->ch[1] == t;\r\n}\r\nvoid rotate(Node\
    \ *t) {\r\n    Node *q = t->p;\r\n    int x = !pos(t);\r\n    q->ch[!x] = t->ch[x];\r\
    \n    if (t->ch[x]) {\r\n        t->ch[x]->p = q;\r\n    }\r\n    t->p = q->p;\r\
    \n    if (!isroot(q)) {\r\n        q->p->ch[pos(q)] = t;\r\n    }\r\n    t->ch[x]\
    \ = q;\r\n    q->p = t;\r\n    pull(q);\r\n}\r\nvoid update(Node *t) {\r\n   \
    \ t->val.ans = t->val.t + t->sum;\r\n    for (int i = 0; i < D; i++) {\r\n   \
    \     t->val.ans += (1LL << i) * t->pair[i][t->val.t >> i & 1];\r\n        for\
    \ (int j = 0; j < 2; j++) {\r\n            t->val.up[i][j] = t->cnt[i][j ^ (t->val.t\
    \ >> i & 1)];\r\n            t->val.down[i][j] = t->cnt[i][j ^ (t->val.t >> i\
    \ & 1)];\r\n        }\r\n        t->val.up[i][t->val.t >> i & 1]++;\r\n      \
    \  t->val.down[i][t->val.t >> i & 1]++;\r\n    }\r\n    pull(t);\r\n}\r\nvoid\
    \ splay(Node *t) {\r\n    while (!isroot(t)) {\r\n        if (!isroot(t->p)) {\r\
    \n            if (pos(t) == pos(t->p)) {\r\n                rotate(t->p);\r\n\
    \            } else {\r\n                rotate(t);\r\n            }\r\n     \
    \   }\r\n        rotate(t);\r\n    }\r\n    pull(t);\r\n}\r\nvoid add(Node *t,\
    \ Info s) {\r\n    for (int i = 0; i < D; i++) {\r\n        for (int x = 0; x\
    \ < 2; x++) {\r\n            t->pair[i][x] += s.up[i][1 ^ x];\r\n            for\
    \ (int j = 0; j < 2; j++) {\r\n                t->pair[i][x] += t->cnt[i][j] *\
    \ s.up[i][j ^ 1 ^ x];\r\n            }\r\n        }\r\n        for (int j = 0;\
    \ j < 2; j++) {\r\n            t->cnt[i][j] += s.up[i][j];\r\n        }\r\n  \
    \  }\r\n    t->sum += s.ans;\r\n}\r\nvoid del(Node *t, Info s) {\r\n    t->sum\
    \ -= s.ans;\r\n    for (int i = 0; i < D; i++) {\r\n        for (int j = 0; j\
    \ < 2; j++) {\r\n            t->cnt[i][j] -= s.up[i][j];\r\n        }\r\n    \
    \    for (int x = 0; x < 2; x++) {\r\n            for (int j = 0; j < 2; j++)\
    \ {\r\n                t->pair[i][x] -= t->cnt[i][j] * s.up[i][j ^ 1 ^ x];\r\n\
    \            }\r\n            t->pair[i][x] -= s.up[i][1 ^ x];\r\n        }\r\n\
    \    }\r\n}\r\nvoid access(Node *t, int v) {\r\n    Info lst;\r\n    for (Node\
    \ *i = t, *q = nullptr; i; q = i, i = i->p) {\r\n        splay(i);\r\n       \
    \ if (i->ch[1]) {\r\n            add(i, i->ch[1]->tot);\r\n        }\r\n     \
    \   i->ch[1] = q;\r\n        if (q) {\r\n            del(i, lst);\r\n        }\
    \ else {\r\n            i->val.t = v;\r\n        }\r\n        lst = i->tot;\r\n\
    \        update(i);\r\n    }\r\n    splay(t);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/07C-Splay.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/07C-Splay.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/07C-Splay.hpp
- /library/src/jiangly/ds/07C-Splay.hpp.html
title: src/jiangly/ds/07C-Splay.hpp
---
