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
    - https://codeforces.com/contest/1672/submission/154766851
  bundledCode: "#line 1 \"src/jiangly/ds/03D-Segment-Tree.hpp\"\n/**   \u7EBF\u6BB5\
    \u6811\uFF08SegmentTree+Info+Merge \u521D\u59CB\u8D4B\u503C+\u5355\u70B9\u4FEE\
    \u6539+\u533A\u95F4\u5408\u5E76\uFF09\r\n *    2022-04-23: https://codeforces.com/contest/1672/submission/154766851\r\
    \n**/\r\ntemplate<class Info,\r\n    class Merge = std::plus<Info>>\r\nstruct\
    \ SegmentTree {\r\n    const int n;\r\n    const Merge merge;\r\n    std::vector<Info>\
    \ info;\r\n    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n))\
    \ {}\r\n    SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {\r\
    \n        std::function<void(int, int, int)> build = [&](int p, int l, int r)\
    \ {\r\n            if (r - l == 1) {\r\n                info[p] = init[l];\r\n\
    \                return;\r\n            }\r\n            int m = (l + r) / 2;\r\
    \n            build(2 * p, l, m);\r\n            build(2 * p + 1, m, r);\r\n \
    \           pull(p);\r\n        };\r\n        build(1, 0, n);\r\n    }\r\n   \
    \ void pull(int p) {\r\n        info[p] = merge(info[2 * p], info[2 * p + 1]);\r\
    \n    }\r\n    void modify(int p, int l, int r, int x, const Info &v) {\r\n  \
    \      if (r - l == 1) {\r\n            info[p] = v;\r\n            return;\r\n\
    \        }\r\n        int m = (l + r) / 2;\r\n        if (x < m) {\r\n       \
    \     modify(2 * p, l, m, x, v);\r\n        } else {\r\n            modify(2 *\
    \ p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\n    }\r\n    void modify(int\
    \ p, const Info &v) {\r\n        modify(1, 0, n, p, v);\r\n    }\r\n    Info rangeQuery(int\
    \ p, int l, int r, int x, int y) {\r\n        if (l >= y || r <= x) {\r\n    \
    \        return Info();\r\n        }\r\n        if (l >= x && r <= y) {\r\n  \
    \          return info[p];\r\n        }\r\n        int m = (l + r) / 2;\r\n  \
    \      return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r,\
    \ x, y));\r\n    }\r\n    Info rangeQuery(int l, int r) {\r\n        return rangeQuery(1,\
    \ 0, n, l, r);\r\n    }\r\n};\n"
  code: "/**   \u7EBF\u6BB5\u6811\uFF08SegmentTree+Info+Merge \u521D\u59CB\u8D4B\u503C\
    +\u5355\u70B9\u4FEE\u6539+\u533A\u95F4\u5408\u5E76\uFF09\r\n *    2022-04-23:\
    \ https://codeforces.com/contest/1672/submission/154766851\r\n**/\r\ntemplate<class\
    \ Info,\r\n    class Merge = std::plus<Info>>\r\nstruct SegmentTree {\r\n    const\
    \ int n;\r\n    const Merge merge;\r\n    std::vector<Info> info;\r\n    SegmentTree(int\
    \ n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}\r\n    SegmentTree(std::vector<Info>\
    \ init) : SegmentTree(init.size()) {\r\n        std::function<void(int, int, int)>\
    \ build = [&](int p, int l, int r) {\r\n            if (r - l == 1) {\r\n    \
    \            info[p] = init[l];\r\n                return;\r\n            }\r\n\
    \            int m = (l + r) / 2;\r\n            build(2 * p, l, m);\r\n     \
    \       build(2 * p + 1, m, r);\r\n            pull(p);\r\n        };\r\n    \
    \    build(1, 0, n);\r\n    }\r\n    void pull(int p) {\r\n        info[p] = merge(info[2\
    \ * p], info[2 * p + 1]);\r\n    }\r\n    void modify(int p, int l, int r, int\
    \ x, const Info &v) {\r\n        if (r - l == 1) {\r\n            info[p] = v;\r\
    \n            return;\r\n        }\r\n        int m = (l + r) / 2;\r\n       \
    \ if (x < m) {\r\n            modify(2 * p, l, m, x, v);\r\n        } else {\r\
    \n            modify(2 * p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\
    \n    }\r\n    void modify(int p, const Info &v) {\r\n        modify(1, 0, n,\
    \ p, v);\r\n    }\r\n    Info rangeQuery(int p, int l, int r, int x, int y) {\r\
    \n        if (l >= y || r <= x) {\r\n            return Info();\r\n        }\r\
    \n        if (l >= x && r <= y) {\r\n            return info[p];\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        return merge(rangeQuery(2 * p, l, m,\
    \ x, y), rangeQuery(2 * p + 1, m, r, x, y));\r\n    }\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(1, 0, n, l, r);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/03D-Segment-Tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/03D-Segment-Tree.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/03D-Segment-Tree.hpp
- /library/src/jiangly/ds/03D-Segment-Tree.hpp.html
title: src/jiangly/ds/03D-Segment-Tree.hpp
---
