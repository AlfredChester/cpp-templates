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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432
    - https://codeforces.com/contest/1982/submission/267353839
  bundledCode: "#line 1 \"src/jiangly/ds/03C-Segment-Tree.hpp\"\n/**   \u7EBF\u6BB5\
    \u6811\uFF08SegmentTree+Info \u521D\u59CB\u8D4B\u503C+\u5355\u70B9\u4FEE\u6539\
    +\u67E5\u627E\u524D\u9A71\u540E\u7EE7\uFF09\r\n *    2023-07-17: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432\r\
    \n *    2024-06-25: https://codeforces.com/contest/1982/submission/267353839\r\
    \n**/\r\ntemplate<class Info>\r\nstruct SegmentTree {\r\n    int n;\r\n    std::vector<Info>\
    \ info;\r\n    SegmentTree() : n(0) {}\r\n    SegmentTree(int n_, Info v_ = Info())\
    \ {\r\n        init(n_, v_);\r\n    }\r\n    template<class T>\r\n    SegmentTree(std::vector<T>\
    \ init_) {\r\n        init(init_);\r\n    }\r\n    void init(int n_, Info v_ =\
    \ Info()) {\r\n        init(std::vector(n_, v_));\r\n    }\r\n    template<class\
    \ T>\r\n    void init(std::vector<T> init_) {\r\n        n = init_.size();\r\n\
    \        info.assign(4 << std::__lg(n), Info());\r\n        std::function<void(int,\
    \ int, int)> build = [&](int p, int l, int r) {\r\n            if (r - l == 1)\
    \ {\r\n                info[p] = init_[l];\r\n                return;\r\n    \
    \        }\r\n            int m = (l + r) / 2;\r\n            build(2 * p, l,\
    \ m);\r\n            build(2 * p + 1, m, r);\r\n            pull(p);\r\n     \
    \   };\r\n        build(1, 0, n);\r\n    }\r\n    void pull(int p) {\r\n     \
    \   info[p] = info[2 * p] + info[2 * p + 1];\r\n    }\r\n    void modify(int p,\
    \ int l, int r, int x, const Info &v) {\r\n        if (r - l == 1) {\r\n     \
    \       info[p] = v;\r\n            return;\r\n        }\r\n        int m = (l\
    \ + r) / 2;\r\n        if (x < m) {\r\n            modify(2 * p, l, m, x, v);\r\
    \n        } else {\r\n            modify(2 * p + 1, m, r, x, v);\r\n        }\r\
    \n        pull(p);\r\n    }\r\n    void modify(int p, const Info &v) {\r\n   \
    \     modify(1, 0, n, p, v);\r\n    }\r\n    Info rangeQuery(int p, int l, int\
    \ r, int x, int y) {\r\n        if (l >= y || r <= x) {\r\n            return\
    \ Info();\r\n        }\r\n        if (l >= x && r <= y) {\r\n            return\
    \ info[p];\r\n        }\r\n        int m = (l + r) / 2;\r\n        return rangeQuery(2\
    \ * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);\r\n    }\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(1, 0, n, l, r);\r\n    }\r\n    template<class\
    \ F>\r\n    int findFirst(int p, int l, int r, int x, int y, F &&pred) {\r\n \
    \       if (l >= y || r <= x) {\r\n            return -1;\r\n        }\r\n   \
    \     if (l >= x && r <= y && !pred(info[p])) {\r\n            return -1;\r\n\
    \        }\r\n        if (r - l == 1) {\r\n            return l;\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        int res = findFirst(2 * p, l, m, x,\
    \ y, pred);\r\n        if (res == -1) {\r\n            res = findFirst(2 * p +\
    \ 1, m, r, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n    template<class\
    \ F>\r\n    int findFirst(int l, int r, F &&pred) {\r\n        return findFirst(1,\
    \ 0, n, l, r, pred);\r\n    }\r\n    template<class F>\r\n    int findLast(int\
    \ p, int l, int r, int x, int y, F &&pred) {\r\n        if (l >= y || r <= x)\
    \ {\r\n            return -1;\r\n        }\r\n        if (l >= x && r <= y &&\
    \ !pred(info[p])) {\r\n            return -1;\r\n        }\r\n        if (r -\
    \ l == 1) {\r\n            return l;\r\n        }\r\n        int m = (l + r) /\
    \ 2;\r\n        int res = findLast(2 * p + 1, m, r, x, y, pred);\r\n        if\
    \ (res == -1) {\r\n            res = findLast(2 * p, l, m, x, y, pred);\r\n  \
    \      }\r\n        return res;\r\n    }\r\n    template<class F>\r\n    int findLast(int\
    \ l, int r, F &&pred) {\r\n        return findLast(1, 0, n, l, r, pred);\r\n \
    \   }\r\n};\n"
  code: "/**   \u7EBF\u6BB5\u6811\uFF08SegmentTree+Info \u521D\u59CB\u8D4B\u503C+\u5355\
    \u70B9\u4FEE\u6539+\u67E5\u627E\u524D\u9A71\u540E\u7EE7\uFF09\r\n *    2023-07-17:\
    \ https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432\r\n\
    \ *    2024-06-25: https://codeforces.com/contest/1982/submission/267353839\r\n\
    **/\r\ntemplate<class Info>\r\nstruct SegmentTree {\r\n    int n;\r\n    std::vector<Info>\
    \ info;\r\n    SegmentTree() : n(0) {}\r\n    SegmentTree(int n_, Info v_ = Info())\
    \ {\r\n        init(n_, v_);\r\n    }\r\n    template<class T>\r\n    SegmentTree(std::vector<T>\
    \ init_) {\r\n        init(init_);\r\n    }\r\n    void init(int n_, Info v_ =\
    \ Info()) {\r\n        init(std::vector(n_, v_));\r\n    }\r\n    template<class\
    \ T>\r\n    void init(std::vector<T> init_) {\r\n        n = init_.size();\r\n\
    \        info.assign(4 << std::__lg(n), Info());\r\n        std::function<void(int,\
    \ int, int)> build = [&](int p, int l, int r) {\r\n            if (r - l == 1)\
    \ {\r\n                info[p] = init_[l];\r\n                return;\r\n    \
    \        }\r\n            int m = (l + r) / 2;\r\n            build(2 * p, l,\
    \ m);\r\n            build(2 * p + 1, m, r);\r\n            pull(p);\r\n     \
    \   };\r\n        build(1, 0, n);\r\n    }\r\n    void pull(int p) {\r\n     \
    \   info[p] = info[2 * p] + info[2 * p + 1];\r\n    }\r\n    void modify(int p,\
    \ int l, int r, int x, const Info &v) {\r\n        if (r - l == 1) {\r\n     \
    \       info[p] = v;\r\n            return;\r\n        }\r\n        int m = (l\
    \ + r) / 2;\r\n        if (x < m) {\r\n            modify(2 * p, l, m, x, v);\r\
    \n        } else {\r\n            modify(2 * p + 1, m, r, x, v);\r\n        }\r\
    \n        pull(p);\r\n    }\r\n    void modify(int p, const Info &v) {\r\n   \
    \     modify(1, 0, n, p, v);\r\n    }\r\n    Info rangeQuery(int p, int l, int\
    \ r, int x, int y) {\r\n        if (l >= y || r <= x) {\r\n            return\
    \ Info();\r\n        }\r\n        if (l >= x && r <= y) {\r\n            return\
    \ info[p];\r\n        }\r\n        int m = (l + r) / 2;\r\n        return rangeQuery(2\
    \ * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);\r\n    }\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(1, 0, n, l, r);\r\n    }\r\n    template<class\
    \ F>\r\n    int findFirst(int p, int l, int r, int x, int y, F &&pred) {\r\n \
    \       if (l >= y || r <= x) {\r\n            return -1;\r\n        }\r\n   \
    \     if (l >= x && r <= y && !pred(info[p])) {\r\n            return -1;\r\n\
    \        }\r\n        if (r - l == 1) {\r\n            return l;\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        int res = findFirst(2 * p, l, m, x,\
    \ y, pred);\r\n        if (res == -1) {\r\n            res = findFirst(2 * p +\
    \ 1, m, r, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n    template<class\
    \ F>\r\n    int findFirst(int l, int r, F &&pred) {\r\n        return findFirst(1,\
    \ 0, n, l, r, pred);\r\n    }\r\n    template<class F>\r\n    int findLast(int\
    \ p, int l, int r, int x, int y, F &&pred) {\r\n        if (l >= y || r <= x)\
    \ {\r\n            return -1;\r\n        }\r\n        if (l >= x && r <= y &&\
    \ !pred(info[p])) {\r\n            return -1;\r\n        }\r\n        if (r -\
    \ l == 1) {\r\n            return l;\r\n        }\r\n        int m = (l + r) /\
    \ 2;\r\n        int res = findLast(2 * p + 1, m, r, x, y, pred);\r\n        if\
    \ (res == -1) {\r\n            res = findLast(2 * p, l, m, x, y, pred);\r\n  \
    \      }\r\n        return res;\r\n    }\r\n    template<class F>\r\n    int findLast(int\
    \ l, int r, F &&pred) {\r\n        return findLast(1, 0, n, l, r, pred);\r\n \
    \   }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/03C-Segment-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/03C-Segment-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/03C-Segment-Tree.hpp
- /library/src/jiangly/ds/03C-Segment-Tree.hpp.html
title: src/jiangly/ds/03C-Segment-Tree.hpp
---
