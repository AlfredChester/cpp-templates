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
    - https://cf.dianhsu.com/gym/104417/submission/223800089
  bundledCode: "#line 1 \"src/jiangly/ds/03B-Segment-Tree.hpp\"\n/**   \u7EBF\u6BB5\
    \u6811\uFF08SegmentTree \u533A\u95F4\u4E58+\u5355\u70B9\u52A0\uFF09\r\n *    2023-10-18:\
    \ https://cf.dianhsu.com/gym/104417/submission/223800089\r\n**/\r\nstruct SegmentTree\
    \ {\r\n    int n;\r\n    std::vector<int> tag, sum;\r\n    SegmentTree(int n_)\
    \ : n(n_), tag(4 * n, 1), sum(4 * n) {}\r\n\r\n    void pull(int p) {\r\n    \
    \    sum[p] = (sum[2 * p] + sum[2 * p + 1]) % P;\r\n    }\r\n\r\n    void mul(int\
    \ p, int v) {\r\n        tag[p] = 1LL * tag[p] * v % P;\r\n        sum[p] = 1LL\
    \ * sum[p] * v % P;\r\n    }\r\n\r\n    void push(int p) {\r\n        mul(2 *\
    \ p, tag[p]);\r\n        mul(2 * p + 1, tag[p]);\r\n        tag[p] = 1;\r\n  \
    \  }\r\n    \r\n    int query(int p, int l, int r, int x, int y) {\r\n       \
    \ if (l >= y || r <= x) {\r\n            return 0;\r\n        }\r\n        if\
    \ (l >= x && r <= y) {\r\n            return sum[p];\r\n        }\r\n        int\
    \ m = (l + r) / 2;\r\n        push(p);\r\n        return (query(2 * p, l, m, x,\
    \ y) + query(2 * p + 1, m, r, x, y)) % P;\r\n    }\r\n    \r\n    int query(int\
    \ x, int y) {\r\n        return query(1, 0, n, x, y);\r\n    }\r\n    \r\n   \
    \ void rangeMul(int p, int l, int r, int x, int y, int v) {\r\n        if (l >=\
    \ y || r <= x) {\r\n            return;\r\n        }\r\n        if (l >= x &&\
    \ r <= y) {\r\n            return mul(p, v);\r\n        }\r\n        int m = (l\
    \ + r) / 2;\r\n        push(p);\r\n        rangeMul(2 * p, l, m, x, y, v);\r\n\
    \        rangeMul(2 * p + 1, m, r, x, y, v);\r\n        pull(p);\r\n    }\r\n\
    \    \r\n    void rangeMul(int x, int y, int v) {\r\n        rangeMul(1, 0, n,\
    \ x, y, v);\r\n    }\r\n    \r\n    void add(int p, int l, int r, int x, int v)\
    \ {\r\n        if (r - l == 1) {\r\n            sum[p] = (sum[p] + v) % P;\r\n\
    \            return;\r\n        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\
    \n        if (x < m) {\r\n            add(2 * p, l, m, x, v);\r\n        } else\
    \ {\r\n            add(2 * p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\
    \n    }\r\n    \r\n    void add(int x, int v) {\r\n        add(1, 0, n, x, v);\r\
    \n    }\r\n};\n"
  code: "/**   \u7EBF\u6BB5\u6811\uFF08SegmentTree \u533A\u95F4\u4E58+\u5355\u70B9\
    \u52A0\uFF09\r\n *    2023-10-18: https://cf.dianhsu.com/gym/104417/submission/223800089\r\
    \n**/\r\nstruct SegmentTree {\r\n    int n;\r\n    std::vector<int> tag, sum;\r\
    \n    SegmentTree(int n_) : n(n_), tag(4 * n, 1), sum(4 * n) {}\r\n\r\n    void\
    \ pull(int p) {\r\n        sum[p] = (sum[2 * p] + sum[2 * p + 1]) % P;\r\n   \
    \ }\r\n\r\n    void mul(int p, int v) {\r\n        tag[p] = 1LL * tag[p] * v %\
    \ P;\r\n        sum[p] = 1LL * sum[p] * v % P;\r\n    }\r\n\r\n    void push(int\
    \ p) {\r\n        mul(2 * p, tag[p]);\r\n        mul(2 * p + 1, tag[p]);\r\n \
    \       tag[p] = 1;\r\n    }\r\n    \r\n    int query(int p, int l, int r, int\
    \ x, int y) {\r\n        if (l >= y || r <= x) {\r\n            return 0;\r\n\
    \        }\r\n        if (l >= x && r <= y) {\r\n            return sum[p];\r\n\
    \        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        return\
    \ (query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y)) % P;\r\n    }\r\n\
    \    \r\n    int query(int x, int y) {\r\n        return query(1, 0, n, x, y);\r\
    \n    }\r\n    \r\n    void rangeMul(int p, int l, int r, int x, int y, int v)\
    \ {\r\n        if (l >= y || r <= x) {\r\n            return;\r\n        }\r\n\
    \        if (l >= x && r <= y) {\r\n            return mul(p, v);\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        rangeMul(2 * p,\
    \ l, m, x, y, v);\r\n        rangeMul(2 * p + 1, m, r, x, y, v);\r\n        pull(p);\r\
    \n    }\r\n    \r\n    void rangeMul(int x, int y, int v) {\r\n        rangeMul(1,\
    \ 0, n, x, y, v);\r\n    }\r\n    \r\n    void add(int p, int l, int r, int x,\
    \ int v) {\r\n        if (r - l == 1) {\r\n            sum[p] = (sum[p] + v) %\
    \ P;\r\n            return;\r\n        }\r\n        int m = (l + r) / 2;\r\n \
    \       push(p);\r\n        if (x < m) {\r\n            add(2 * p, l, m, x, v);\r\
    \n        } else {\r\n            add(2 * p + 1, m, r, x, v);\r\n        }\r\n\
    \        pull(p);\r\n    }\r\n    \r\n    void add(int x, int v) {\r\n       \
    \ add(1, 0, n, x, v);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/03B-Segment-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/03B-Segment-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/03B-Segment-Tree.hpp
- /library/src/jiangly/ds/03B-Segment-Tree.hpp.html
title: src/jiangly/ds/03B-Segment-Tree.hpp
---
