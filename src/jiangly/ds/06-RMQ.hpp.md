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
    - https://atcoder.jp/contests/joi2022ho/submissions/39351739
    - https://qoj.ac/submission/163598
  bundledCode: "#line 1 \"src/jiangly/ds/06-RMQ.hpp\"\n/**   \u72B6\u538BRMQ\uFF08\
    RMQ\uFF09\r\n *    2023-03-02: https://atcoder.jp/contests/joi2022ho/submissions/39351739\r\
    \n *    2023-09-04: https://qoj.ac/submission/163598\r\n**/\r\ntemplate<class\
    \ T,\r\n    class Cmp = std::less<T>>\r\nstruct RMQ {\r\n    const Cmp cmp = Cmp();\r\
    \n    static constexpr unsigned B = 64;\r\n    using u64 = unsigned long long;\r\
    \n    int n;\r\n    std::vector<std::vector<T>> a;\r\n    std::vector<T> pre,\
    \ suf, ini;\r\n    std::vector<u64> stk;\r\n    RMQ() {}\r\n    RMQ(const std::vector<T>\
    \ &v) {\r\n        init(v);\r\n    }\r\n    void init(const std::vector<T> &v)\
    \ {\r\n        n = v.size();\r\n        pre = suf = ini = v;\r\n        stk.resize(n);\r\
    \n        if (!n) {\r\n            return;\r\n        }\r\n        const int M\
    \ = (n - 1) / B + 1;\r\n        const int lg = std::__lg(M);\r\n        a.assign(lg\
    \ + 1, std::vector<T>(M));\r\n        for (int i = 0; i < M; i++) {\r\n      \
    \      a[0][i] = v[i * B];\r\n            for (int j = 1; j < B && i * B + j <\
    \ n; j++) {\r\n                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);\r\
    \n            }\r\n        }\r\n        for (int i = 1; i < n; i++) {\r\n    \
    \        if (i % B) {\r\n                pre[i] = std::min(pre[i], pre[i - 1],\
    \ cmp);\r\n            }\r\n        }\r\n        for (int i = n - 2; i >= 0; i--)\
    \ {\r\n            if (i % B != B - 1) {\r\n                suf[i] = std::min(suf[i],\
    \ suf[i + 1], cmp);\r\n            }\r\n        }\r\n        for (int j = 0; j\
    \ < lg; j++) {\r\n            for (int i = 0; i + (2 << j) <= M; i++) {\r\n  \
    \              a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);\r\n \
    \           }\r\n        }\r\n        for (int i = 0; i < M; i++) {\r\n      \
    \      const int l = i * B;\r\n            const int r = std::min(1U * n, l +\
    \ B);\r\n            u64 s = 0;\r\n            for (int j = l; j < r; j++) {\r\
    \n                while (s && cmp(v[j], v[std::__lg(s) + l])) {\r\n          \
    \          s ^= 1ULL << std::__lg(s);\r\n                }\r\n               \
    \ s |= 1ULL << (j - l);\r\n                stk[j] = s;\r\n            }\r\n  \
    \      }\r\n    } \r\n    T operator()(int l, int r) {\r\n        if (l / B !=\
    \ (r - 1) / B) {\r\n            T ans = std::min(suf[l], pre[r - 1], cmp);\r\n\
    \            l = l / B + 1;\r\n            r = r / B;\r\n            if (l < r)\
    \ {\r\n                int k = std::__lg(r - l);\r\n                ans = std::min({ans,\
    \ a[k][l], a[k][r - (1 << k)]}, cmp);\r\n            }\r\n            return ans;\r\
    \n        } else {\r\n            int x = B * (l / B);\r\n            return ini[__builtin_ctzll(stk[r\
    \ - 1] >> (l - x)) + l];\r\n        }\r\n    }\r\n};\r\n\r\n"
  code: "/**   \u72B6\u538BRMQ\uFF08RMQ\uFF09\r\n *    2023-03-02: https://atcoder.jp/contests/joi2022ho/submissions/39351739\r\
    \n *    2023-09-04: https://qoj.ac/submission/163598\r\n**/\r\ntemplate<class\
    \ T,\r\n    class Cmp = std::less<T>>\r\nstruct RMQ {\r\n    const Cmp cmp = Cmp();\r\
    \n    static constexpr unsigned B = 64;\r\n    using u64 = unsigned long long;\r\
    \n    int n;\r\n    std::vector<std::vector<T>> a;\r\n    std::vector<T> pre,\
    \ suf, ini;\r\n    std::vector<u64> stk;\r\n    RMQ() {}\r\n    RMQ(const std::vector<T>\
    \ &v) {\r\n        init(v);\r\n    }\r\n    void init(const std::vector<T> &v)\
    \ {\r\n        n = v.size();\r\n        pre = suf = ini = v;\r\n        stk.resize(n);\r\
    \n        if (!n) {\r\n            return;\r\n        }\r\n        const int M\
    \ = (n - 1) / B + 1;\r\n        const int lg = std::__lg(M);\r\n        a.assign(lg\
    \ + 1, std::vector<T>(M));\r\n        for (int i = 0; i < M; i++) {\r\n      \
    \      a[0][i] = v[i * B];\r\n            for (int j = 1; j < B && i * B + j <\
    \ n; j++) {\r\n                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);\r\
    \n            }\r\n        }\r\n        for (int i = 1; i < n; i++) {\r\n    \
    \        if (i % B) {\r\n                pre[i] = std::min(pre[i], pre[i - 1],\
    \ cmp);\r\n            }\r\n        }\r\n        for (int i = n - 2; i >= 0; i--)\
    \ {\r\n            if (i % B != B - 1) {\r\n                suf[i] = std::min(suf[i],\
    \ suf[i + 1], cmp);\r\n            }\r\n        }\r\n        for (int j = 0; j\
    \ < lg; j++) {\r\n            for (int i = 0; i + (2 << j) <= M; i++) {\r\n  \
    \              a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);\r\n \
    \           }\r\n        }\r\n        for (int i = 0; i < M; i++) {\r\n      \
    \      const int l = i * B;\r\n            const int r = std::min(1U * n, l +\
    \ B);\r\n            u64 s = 0;\r\n            for (int j = l; j < r; j++) {\r\
    \n                while (s && cmp(v[j], v[std::__lg(s) + l])) {\r\n          \
    \          s ^= 1ULL << std::__lg(s);\r\n                }\r\n               \
    \ s |= 1ULL << (j - l);\r\n                stk[j] = s;\r\n            }\r\n  \
    \      }\r\n    } \r\n    T operator()(int l, int r) {\r\n        if (l / B !=\
    \ (r - 1) / B) {\r\n            T ans = std::min(suf[l], pre[r - 1], cmp);\r\n\
    \            l = l / B + 1;\r\n            r = r / B;\r\n            if (l < r)\
    \ {\r\n                int k = std::__lg(r - l);\r\n                ans = std::min({ans,\
    \ a[k][l], a[k][r - (1 << k)]}, cmp);\r\n            }\r\n            return ans;\r\
    \n        } else {\r\n            int x = B * (l / B);\r\n            return ini[__builtin_ctzll(stk[r\
    \ - 1] >> (l - x)) + l];\r\n        }\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/06-RMQ.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/06-RMQ.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/06-RMQ.hpp
- /library/src/jiangly/ds/06-RMQ.hpp.html
title: src/jiangly/ds/06-RMQ.hpp
---
