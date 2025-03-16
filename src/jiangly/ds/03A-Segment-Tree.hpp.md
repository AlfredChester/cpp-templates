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
    - https://qoj.ac/submission/178310
  bundledCode: "#line 1 \"src/jiangly/ds/03A-Segment-Tree.hpp\"\n/**   \u7EBF\u6BB5\
    \u6811\uFF08SegmentTree+Info \u533A\u95F4\u52A0+\u5355\u70B9\u4FEE\u6539\uFF09\
    \r\n *    2023-09-13: https://qoj.ac/submission/178310\r\n**/\r\nstruct SegmentTree\
    \ {\r\n    int n;\r\n    std::vector<int> tag;\r\n    std::vector<Info> info;\r\
    \n    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}\r\n\r\n    void\
    \ pull(int p) {\r\n        info[p] = info[2 * p] + info[2 * p + 1];\r\n    }\r\
    \n\r\n    void add(int p, int v) {\r\n        tag[p] += v;\r\n        info[p].max\
    \ += v;\r\n    }\r\n\r\n    void push(int p) {\r\n        add(2 * p, tag[p]);\r\
    \n        add(2 * p + 1, tag[p]);\r\n        tag[p] = 0;\r\n    }\r\n    \r\n\
    \    Info query(int p, int l, int r, int x, int y) {\r\n        if (l >= y ||\
    \ r <= x) {\r\n            return {};\r\n        }\r\n        if (l >= x && r\
    \ <= y) {\r\n            return info[p];\r\n        }\r\n        int m = (l +\
    \ r) / 2;\r\n        push(p);\r\n        return query(2 * p, l, m, x, y) + query(2\
    \ * p + 1, m, r, x, y);\r\n    }\r\n    \r\n    Info query(int x, int y) {\r\n\
    \        return query(1, 0, n, x, y);\r\n    }\r\n    \r\n    void rangeAdd(int\
    \ p, int l, int r, int x, int y, int v) {\r\n        if (l >= y || r <= x) {\r\
    \n            return;\r\n        }\r\n        if (l >= x && r <= y) {\r\n    \
    \        return add(p, v);\r\n        }\r\n        int m = (l + r) / 2;\r\n  \
    \      push(p);\r\n        rangeAdd(2 * p, l, m, x, y, v);\r\n        rangeAdd(2\
    \ * p + 1, m, r, x, y, v);\r\n        pull(p);\r\n    }\r\n    \r\n    void rangeAdd(int\
    \ x, int y, int v) {\r\n        rangeAdd(1, 0, n, x, y, v);\r\n    }\r\n    \r\
    \n    void modify(int p, int l, int r, int x, const Info &v) {\r\n        if (r\
    \ - l == 1) {\r\n            info[p] = v;\r\n            return;\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        if (x < m) {\r\n\
    \            modify(2 * p, l, m, x, v);\r\n        } else {\r\n            modify(2\
    \ * p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\n    }\r\n    \r\n\
    \    void modify(int x, const Info &v) {\r\n        modify(1, 0, n, x, v);\r\n\
    \    }\r\n};\n"
  code: "/**   \u7EBF\u6BB5\u6811\uFF08SegmentTree+Info \u533A\u95F4\u52A0+\u5355\u70B9\
    \u4FEE\u6539\uFF09\r\n *    2023-09-13: https://qoj.ac/submission/178310\r\n**/\r\
    \nstruct SegmentTree {\r\n    int n;\r\n    std::vector<int> tag;\r\n    std::vector<Info>\
    \ info;\r\n    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}\r\n\r\n\
    \    void pull(int p) {\r\n        info[p] = info[2 * p] + info[2 * p + 1];\r\n\
    \    }\r\n\r\n    void add(int p, int v) {\r\n        tag[p] += v;\r\n       \
    \ info[p].max += v;\r\n    }\r\n\r\n    void push(int p) {\r\n        add(2 *\
    \ p, tag[p]);\r\n        add(2 * p + 1, tag[p]);\r\n        tag[p] = 0;\r\n  \
    \  }\r\n    \r\n    Info query(int p, int l, int r, int x, int y) {\r\n      \
    \  if (l >= y || r <= x) {\r\n            return {};\r\n        }\r\n        if\
    \ (l >= x && r <= y) {\r\n            return info[p];\r\n        }\r\n       \
    \ int m = (l + r) / 2;\r\n        push(p);\r\n        return query(2 * p, l, m,\
    \ x, y) + query(2 * p + 1, m, r, x, y);\r\n    }\r\n    \r\n    Info query(int\
    \ x, int y) {\r\n        return query(1, 0, n, x, y);\r\n    }\r\n    \r\n   \
    \ void rangeAdd(int p, int l, int r, int x, int y, int v) {\r\n        if (l >=\
    \ y || r <= x) {\r\n            return;\r\n        }\r\n        if (l >= x &&\
    \ r <= y) {\r\n            return add(p, v);\r\n        }\r\n        int m = (l\
    \ + r) / 2;\r\n        push(p);\r\n        rangeAdd(2 * p, l, m, x, y, v);\r\n\
    \        rangeAdd(2 * p + 1, m, r, x, y, v);\r\n        pull(p);\r\n    }\r\n\
    \    \r\n    void rangeAdd(int x, int y, int v) {\r\n        rangeAdd(1, 0, n,\
    \ x, y, v);\r\n    }\r\n    \r\n    void modify(int p, int l, int r, int x, const\
    \ Info &v) {\r\n        if (r - l == 1) {\r\n            info[p] = v;\r\n    \
    \        return;\r\n        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\
    \n        if (x < m) {\r\n            modify(2 * p, l, m, x, v);\r\n        }\
    \ else {\r\n            modify(2 * p + 1, m, r, x, v);\r\n        }\r\n      \
    \  pull(p);\r\n    }\r\n    \r\n    void modify(int x, const Info &v) {\r\n  \
    \      modify(1, 0, n, x, v);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/03A-Segment-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/03A-Segment-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/03A-Segment-Tree.hpp
- /library/src/jiangly/ds/03A-Segment-Tree.hpp.html
title: src/jiangly/ds/03A-Segment-Tree.hpp
---
