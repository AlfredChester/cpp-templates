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
    - https://atcoder.jp/contests/joi2023yo2/submissions/39363123
    - https://codeforces.com/contest/1804/submission/197106837
    - https://qoj.ac/submission/249505
  bundledCode: "#line 1 \"src/jiangly/ds/04-Lazy-Segt.hpp\"\n/**   \u61D2\u6807\u8BB0\
    \u7EBF\u6BB5\u6811\uFF08LazySegmentTree\uFF09\r\n *    2023-03-03: https://atcoder.jp/contests/joi2023yo2/submissions/39363123\r\
    \n *    2023-03-12: https://codeforces.com/contest/1804/submission/197106837\r\
    \n *    2023-07-17: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432\r\
    \n *    2023-11-12: https://qoj.ac/submission/249505\r\n**/\r\ntemplate<class\
    \ Info, class Tag>\r\nstruct LazySegmentTree {\r\n    int n;\r\n    std::vector<Info>\
    \ info;\r\n    std::vector<Tag> tag;\r\n    LazySegmentTree() : n(0) {}\r\n  \
    \  LazySegmentTree(int n_, Info v_ = Info()) {\r\n        init(n_, v_);\r\n  \
    \  }\r\n    template<class T>\r\n    LazySegmentTree(std::vector<T> init_) {\r\
    \n        init(init_);\r\n    }\r\n    void init(int n_, Info v_ = Info()) {\r\
    \n        init(std::vector(n_, v_));\r\n    }\r\n    template<class T>\r\n   \
    \ void init(std::vector<T> init_) {\r\n        n = init_.size();\r\n        info.assign(4\
    \ << std::__lg(n), Info());\r\n        tag.assign(4 << std::__lg(n), Tag());\r\
    \n        std::function<void(int, int, int)> build = [&](int p, int l, int r)\
    \ {\r\n            if (r - l == 1) {\r\n                info[p] = init_[l];\r\n\
    \                return;\r\n            }\r\n            int m = (l + r) / 2;\r\
    \n            build(2 * p, l, m);\r\n            build(2 * p + 1, m, r);\r\n \
    \           pull(p);\r\n        };\r\n        build(1, 0, n);\r\n    }\r\n   \
    \ void pull(int p) {\r\n        info[p] = info[2 * p] + info[2 * p + 1];\r\n \
    \   }\r\n    void apply(int p, const Tag &v) {\r\n        info[p].apply(v);\r\n\
    \        tag[p].apply(v);\r\n    }\r\n    void push(int p) {\r\n        apply(2\
    \ * p, tag[p]);\r\n        apply(2 * p + 1, tag[p]);\r\n        tag[p] = Tag();\r\
    \n    }\r\n    void modify(int p, int l, int r, int x, const Info &v) {\r\n  \
    \      if (r - l == 1) {\r\n            info[p] = v;\r\n            return;\r\n\
    \        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        if (x\
    \ < m) {\r\n            modify(2 * p, l, m, x, v);\r\n        } else {\r\n   \
    \         modify(2 * p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\n\
    \    }\r\n    void modify(int p, const Info &v) {\r\n        modify(1, 0, n, p,\
    \ v);\r\n    }\r\n    Info rangeQuery(int p, int l, int r, int x, int y) {\r\n\
    \        if (l >= y || r <= x) {\r\n            return Info();\r\n        }\r\n\
    \        if (l >= x && r <= y) {\r\n            return info[p];\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        return rangeQuery(2\
    \ * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);\r\n    }\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(1, 0, n, l, r);\r\n    }\r\n    void\
    \ rangeApply(int p, int l, int r, int x, int y, const Tag &v) {\r\n        if\
    \ (l >= y || r <= x) {\r\n            return;\r\n        }\r\n        if (l >=\
    \ x && r <= y) {\r\n            apply(p, v);\r\n            return;\r\n      \
    \  }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        rangeApply(2\
    \ * p, l, m, x, y, v);\r\n        rangeApply(2 * p + 1, m, r, x, y, v);\r\n  \
    \      pull(p);\r\n    }\r\n    void rangeApply(int l, int r, const Tag &v) {\r\
    \n        return rangeApply(1, 0, n, l, r, v);\r\n    }\r\n    void half(int p,\
    \ int l, int r) {\r\n        if (info[p].act == 0) {\r\n            return;\r\n\
    \        }\r\n        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {\r\n\
    \            apply(p, {-(info[p].min + 1) / 2});\r\n            return;\r\n  \
    \      }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        half(2\
    \ * p, l, m);\r\n        half(2 * p + 1, m, r);\r\n        pull(p);\r\n    }\r\
    \n    void half() {\r\n        half(1, 0, n);\r\n    }\r\n    \r\n    template<class\
    \ F>\r\n    int findFirst(int p, int l, int r, int x, int y, F pred) {\r\n   \
    \     if (l >= y || r <= x || !pred(info[p])) {\r\n            return -1;\r\n\
    \        }\r\n        if (r - l == 1) {\r\n            return l;\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        int res = findFirst(2\
    \ * p, l, m, x, y, pred);\r\n        if (res == -1) {\r\n            res = findFirst(2\
    \ * p + 1, m, r, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n\
    \    template<class F>\r\n    int findFirst(int l, int r, F pred) {\r\n      \
    \  return findFirst(1, 0, n, l, r, pred);\r\n    }\r\n    template<class F>\r\n\
    \    int findLast(int p, int l, int r, int x, int y, F pred) {\r\n        if (l\
    \ >= y || r <= x || !pred(info[p])) {\r\n            return -1;\r\n        }\r\
    \n        if (r - l == 1) {\r\n            return l;\r\n        }\r\n        int\
    \ m = (l + r) / 2;\r\n        push(p);\r\n        int res = findLast(2 * p + 1,\
    \ m, r, x, y, pred);\r\n        if (res == -1) {\r\n            res = findLast(2\
    \ * p, l, m, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n   \
    \ template<class F>\r\n    int findLast(int l, int r, F pred) {\r\n        return\
    \ findLast(1, 0, n, l, r, pred);\r\n    }\r\n    \r\n    void maintainL(int p,\
    \ int l, int r, int pre) {\r\n        if (info[p].difl > 0 && info[p].maxlowl\
    \ < pre) {\r\n            return;\r\n        }\r\n        if (r - l == 1) {\r\n\
    \            info[p].max = info[p].maxlowl;\r\n            info[p].maxl = info[p].maxr\
    \ = l;\r\n            info[p].maxlowl = info[p].maxlowr = -inf;\r\n          \
    \  return;\r\n        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n\
    \        maintainL(2 * p, l, m, pre);\r\n        pre = std::max(pre, info[2 *\
    \ p].max);\r\n        maintainL(2 * p + 1, m, r, pre);\r\n        pull(p);\r\n\
    \    }\r\n    void maintainL() {\r\n        maintainL(1, 0, n, -1);\r\n    }\r\
    \n    void maintainR(int p, int l, int r, int suf) {\r\n        if (info[p].difr\
    \ > 0 && info[p].maxlowr < suf) {\r\n            return;\r\n        }\r\n    \
    \    if (r - l == 1) {\r\n            info[p].max = info[p].maxlowl;\r\n     \
    \       info[p].maxl = info[p].maxr = l;\r\n            info[p].maxlowl = info[p].maxlowr\
    \ = -inf;\r\n            return;\r\n        }\r\n        int m = (l + r) / 2;\r\
    \n        push(p);\r\n        maintainR(2 * p + 1, m, r, suf);\r\n        suf\
    \ = std::max(suf, info[2 * p + 1].max);\r\n        maintainR(2 * p, l, m, suf);\r\
    \n        pull(p);\r\n    }\r\n    void maintainR() {\r\n        maintainR(1,\
    \ 0, n, -1);\r\n    }\r\n};\r\n\r\nstruct Tag {\r\n    int x = 0;\r\n    void\
    \ apply(const Tag &t) & {\r\n        x = std::max(x, t.x);\r\n    }\r\n};\r\n\r\
    \nstruct Info {\r\n    int x = 0;\r\n    void apply(const Tag &t) & {\r\n    \
    \    x = std::max(x, t.x);\r\n    }\r\n};\r\n\r\nInfo operator+(const Info &a,\
    \ const Info &b) {\r\n    return {std::max(a.x, b.x)};\r\n}\n"
  code: "/**   \u61D2\u6807\u8BB0\u7EBF\u6BB5\u6811\uFF08LazySegmentTree\uFF09\r\n\
    \ *    2023-03-03: https://atcoder.jp/contests/joi2023yo2/submissions/39363123\r\
    \n *    2023-03-12: https://codeforces.com/contest/1804/submission/197106837\r\
    \n *    2023-07-17: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432\r\
    \n *    2023-11-12: https://qoj.ac/submission/249505\r\n**/\r\ntemplate<class\
    \ Info, class Tag>\r\nstruct LazySegmentTree {\r\n    int n;\r\n    std::vector<Info>\
    \ info;\r\n    std::vector<Tag> tag;\r\n    LazySegmentTree() : n(0) {}\r\n  \
    \  LazySegmentTree(int n_, Info v_ = Info()) {\r\n        init(n_, v_);\r\n  \
    \  }\r\n    template<class T>\r\n    LazySegmentTree(std::vector<T> init_) {\r\
    \n        init(init_);\r\n    }\r\n    void init(int n_, Info v_ = Info()) {\r\
    \n        init(std::vector(n_, v_));\r\n    }\r\n    template<class T>\r\n   \
    \ void init(std::vector<T> init_) {\r\n        n = init_.size();\r\n        info.assign(4\
    \ << std::__lg(n), Info());\r\n        tag.assign(4 << std::__lg(n), Tag());\r\
    \n        std::function<void(int, int, int)> build = [&](int p, int l, int r)\
    \ {\r\n            if (r - l == 1) {\r\n                info[p] = init_[l];\r\n\
    \                return;\r\n            }\r\n            int m = (l + r) / 2;\r\
    \n            build(2 * p, l, m);\r\n            build(2 * p + 1, m, r);\r\n \
    \           pull(p);\r\n        };\r\n        build(1, 0, n);\r\n    }\r\n   \
    \ void pull(int p) {\r\n        info[p] = info[2 * p] + info[2 * p + 1];\r\n \
    \   }\r\n    void apply(int p, const Tag &v) {\r\n        info[p].apply(v);\r\n\
    \        tag[p].apply(v);\r\n    }\r\n    void push(int p) {\r\n        apply(2\
    \ * p, tag[p]);\r\n        apply(2 * p + 1, tag[p]);\r\n        tag[p] = Tag();\r\
    \n    }\r\n    void modify(int p, int l, int r, int x, const Info &v) {\r\n  \
    \      if (r - l == 1) {\r\n            info[p] = v;\r\n            return;\r\n\
    \        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        if (x\
    \ < m) {\r\n            modify(2 * p, l, m, x, v);\r\n        } else {\r\n   \
    \         modify(2 * p + 1, m, r, x, v);\r\n        }\r\n        pull(p);\r\n\
    \    }\r\n    void modify(int p, const Info &v) {\r\n        modify(1, 0, n, p,\
    \ v);\r\n    }\r\n    Info rangeQuery(int p, int l, int r, int x, int y) {\r\n\
    \        if (l >= y || r <= x) {\r\n            return Info();\r\n        }\r\n\
    \        if (l >= x && r <= y) {\r\n            return info[p];\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        return rangeQuery(2\
    \ * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);\r\n    }\r\n    Info rangeQuery(int\
    \ l, int r) {\r\n        return rangeQuery(1, 0, n, l, r);\r\n    }\r\n    void\
    \ rangeApply(int p, int l, int r, int x, int y, const Tag &v) {\r\n        if\
    \ (l >= y || r <= x) {\r\n            return;\r\n        }\r\n        if (l >=\
    \ x && r <= y) {\r\n            apply(p, v);\r\n            return;\r\n      \
    \  }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        rangeApply(2\
    \ * p, l, m, x, y, v);\r\n        rangeApply(2 * p + 1, m, r, x, y, v);\r\n  \
    \      pull(p);\r\n    }\r\n    void rangeApply(int l, int r, const Tag &v) {\r\
    \n        return rangeApply(1, 0, n, l, r, v);\r\n    }\r\n    void half(int p,\
    \ int l, int r) {\r\n        if (info[p].act == 0) {\r\n            return;\r\n\
    \        }\r\n        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {\r\n\
    \            apply(p, {-(info[p].min + 1) / 2});\r\n            return;\r\n  \
    \      }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n        half(2\
    \ * p, l, m);\r\n        half(2 * p + 1, m, r);\r\n        pull(p);\r\n    }\r\
    \n    void half() {\r\n        half(1, 0, n);\r\n    }\r\n    \r\n    template<class\
    \ F>\r\n    int findFirst(int p, int l, int r, int x, int y, F pred) {\r\n   \
    \     if (l >= y || r <= x || !pred(info[p])) {\r\n            return -1;\r\n\
    \        }\r\n        if (r - l == 1) {\r\n            return l;\r\n        }\r\
    \n        int m = (l + r) / 2;\r\n        push(p);\r\n        int res = findFirst(2\
    \ * p, l, m, x, y, pred);\r\n        if (res == -1) {\r\n            res = findFirst(2\
    \ * p + 1, m, r, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n\
    \    template<class F>\r\n    int findFirst(int l, int r, F pred) {\r\n      \
    \  return findFirst(1, 0, n, l, r, pred);\r\n    }\r\n    template<class F>\r\n\
    \    int findLast(int p, int l, int r, int x, int y, F pred) {\r\n        if (l\
    \ >= y || r <= x || !pred(info[p])) {\r\n            return -1;\r\n        }\r\
    \n        if (r - l == 1) {\r\n            return l;\r\n        }\r\n        int\
    \ m = (l + r) / 2;\r\n        push(p);\r\n        int res = findLast(2 * p + 1,\
    \ m, r, x, y, pred);\r\n        if (res == -1) {\r\n            res = findLast(2\
    \ * p, l, m, x, y, pred);\r\n        }\r\n        return res;\r\n    }\r\n   \
    \ template<class F>\r\n    int findLast(int l, int r, F pred) {\r\n        return\
    \ findLast(1, 0, n, l, r, pred);\r\n    }\r\n    \r\n    void maintainL(int p,\
    \ int l, int r, int pre) {\r\n        if (info[p].difl > 0 && info[p].maxlowl\
    \ < pre) {\r\n            return;\r\n        }\r\n        if (r - l == 1) {\r\n\
    \            info[p].max = info[p].maxlowl;\r\n            info[p].maxl = info[p].maxr\
    \ = l;\r\n            info[p].maxlowl = info[p].maxlowr = -inf;\r\n          \
    \  return;\r\n        }\r\n        int m = (l + r) / 2;\r\n        push(p);\r\n\
    \        maintainL(2 * p, l, m, pre);\r\n        pre = std::max(pre, info[2 *\
    \ p].max);\r\n        maintainL(2 * p + 1, m, r, pre);\r\n        pull(p);\r\n\
    \    }\r\n    void maintainL() {\r\n        maintainL(1, 0, n, -1);\r\n    }\r\
    \n    void maintainR(int p, int l, int r, int suf) {\r\n        if (info[p].difr\
    \ > 0 && info[p].maxlowr < suf) {\r\n            return;\r\n        }\r\n    \
    \    if (r - l == 1) {\r\n            info[p].max = info[p].maxlowl;\r\n     \
    \       info[p].maxl = info[p].maxr = l;\r\n            info[p].maxlowl = info[p].maxlowr\
    \ = -inf;\r\n            return;\r\n        }\r\n        int m = (l + r) / 2;\r\
    \n        push(p);\r\n        maintainR(2 * p + 1, m, r, suf);\r\n        suf\
    \ = std::max(suf, info[2 * p + 1].max);\r\n        maintainR(2 * p, l, m, suf);\r\
    \n        pull(p);\r\n    }\r\n    void maintainR() {\r\n        maintainR(1,\
    \ 0, n, -1);\r\n    }\r\n};\r\n\r\nstruct Tag {\r\n    int x = 0;\r\n    void\
    \ apply(const Tag &t) & {\r\n        x = std::max(x, t.x);\r\n    }\r\n};\r\n\r\
    \nstruct Info {\r\n    int x = 0;\r\n    void apply(const Tag &t) & {\r\n    \
    \    x = std::max(x, t.x);\r\n    }\r\n};\r\n\r\nInfo operator+(const Info &a,\
    \ const Info &b) {\r\n    return {std::max(a.x, b.x)};\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/04-Lazy-Segt.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/04-Lazy-Segt.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/04-Lazy-Segt.hpp
- /library/src/jiangly/ds/04-Lazy-Segt.hpp.html
title: src/jiangly/ds/04-Lazy-Segt.hpp
---
