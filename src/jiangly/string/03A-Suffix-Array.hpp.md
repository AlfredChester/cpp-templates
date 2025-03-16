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
    - https://atcoder.jp/contests/discovery2016-qual/submissions/39727257
    - https://qoj.ac/submission/164483
    - https://qoj.ac/submission/384415
  bundledCode: "#line 1 \"src/jiangly/string/03A-Suffix-Array.hpp\"\n/**   \u540E\u7F00\
    \u6570\u7EC4\uFF08SuffixArray \u65E7\u7248\uFF09\r\n *    2023-03-14: https://atcoder.jp/contests/discovery2016-qual/submissions/39727257\r\
    \n *    2023-09-05: https://qoj.ac/submission/164483\r\n *    2024-04-09: https://qoj.ac/submission/384415\
    \ \u3010\u6A21\u677F\u3011\r\n**/\r\nstruct SuffixArray {\r\n    int n;\r\n  \
    \  std::vector<int> sa, rk, lc;\r\n    SuffixArray(const std::string &s) {\r\n\
    \        n = s.length();\r\n        sa.resize(n);\r\n        lc.resize(n - 1);\r\
    \n        rk.resize(n);\r\n        std::iota(sa.begin(), sa.end(), 0);\r\n   \
    \     std::sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});\r\
    \n        rk[sa[0]] = 0;\r\n        for (int i = 1; i < n; ++i)\r\n          \
    \  rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);\r\n        int k =\
    \ 1;\r\n        std::vector<int> tmp, cnt(n);\r\n        tmp.reserve(n);\r\n \
    \       while (rk[sa[n - 1]] < n - 1) {\r\n            tmp.clear();\r\n      \
    \      for (int i = 0; i < k; ++i)\r\n                tmp.push_back(n - k + i);\r\
    \n            for (auto i : sa)\r\n                if (i >= k)\r\n           \
    \         tmp.push_back(i - k);\r\n            std::fill(cnt.begin(), cnt.end(),\
    \ 0);\r\n            for (int i = 0; i < n; ++i)\r\n                ++cnt[rk[i]];\r\
    \n            for (int i = 1; i < n; ++i)\r\n                cnt[i] += cnt[i -\
    \ 1];\r\n            for (int i = n - 1; i >= 0; --i)\r\n                sa[--cnt[rk[tmp[i]]]]\
    \ = tmp[i];\r\n            std::swap(rk, tmp);\r\n            rk[sa[0]] = 0;\r\
    \n            for (int i = 1; i < n; ++i)\r\n                rk[sa[i]] = rk[sa[i\
    \ - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1]\
    \ + k] < tmp[sa[i] + k]);\r\n            k *= 2;\r\n        }\r\n        for (int\
    \ i = 0, j = 0; i < n; ++i) {\r\n            if (rk[i] == 0) {\r\n           \
    \     j = 0;\r\n            } else {\r\n                for (j -= j > 0; i + j\
    \ < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )\r\n    \
    \                ++j;\r\n                lc[rk[i] - 1] = j;\r\n            }\r\
    \n        }\r\n    }\r\n};\r\n\r\n"
  code: "/**   \u540E\u7F00\u6570\u7EC4\uFF08SuffixArray \u65E7\u7248\uFF09\r\n *\
    \    2023-03-14: https://atcoder.jp/contests/discovery2016-qual/submissions/39727257\r\
    \n *    2023-09-05: https://qoj.ac/submission/164483\r\n *    2024-04-09: https://qoj.ac/submission/384415\
    \ \u3010\u6A21\u677F\u3011\r\n**/\r\nstruct SuffixArray {\r\n    int n;\r\n  \
    \  std::vector<int> sa, rk, lc;\r\n    SuffixArray(const std::string &s) {\r\n\
    \        n = s.length();\r\n        sa.resize(n);\r\n        lc.resize(n - 1);\r\
    \n        rk.resize(n);\r\n        std::iota(sa.begin(), sa.end(), 0);\r\n   \
    \     std::sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});\r\
    \n        rk[sa[0]] = 0;\r\n        for (int i = 1; i < n; ++i)\r\n          \
    \  rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);\r\n        int k =\
    \ 1;\r\n        std::vector<int> tmp, cnt(n);\r\n        tmp.reserve(n);\r\n \
    \       while (rk[sa[n - 1]] < n - 1) {\r\n            tmp.clear();\r\n      \
    \      for (int i = 0; i < k; ++i)\r\n                tmp.push_back(n - k + i);\r\
    \n            for (auto i : sa)\r\n                if (i >= k)\r\n           \
    \         tmp.push_back(i - k);\r\n            std::fill(cnt.begin(), cnt.end(),\
    \ 0);\r\n            for (int i = 0; i < n; ++i)\r\n                ++cnt[rk[i]];\r\
    \n            for (int i = 1; i < n; ++i)\r\n                cnt[i] += cnt[i -\
    \ 1];\r\n            for (int i = n - 1; i >= 0; --i)\r\n                sa[--cnt[rk[tmp[i]]]]\
    \ = tmp[i];\r\n            std::swap(rk, tmp);\r\n            rk[sa[0]] = 0;\r\
    \n            for (int i = 1; i < n; ++i)\r\n                rk[sa[i]] = rk[sa[i\
    \ - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1]\
    \ + k] < tmp[sa[i] + k]);\r\n            k *= 2;\r\n        }\r\n        for (int\
    \ i = 0, j = 0; i < n; ++i) {\r\n            if (rk[i] == 0) {\r\n           \
    \     j = 0;\r\n            } else {\r\n                for (j -= j > 0; i + j\
    \ < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )\r\n    \
    \                ++j;\r\n                lc[rk[i] - 1] = j;\r\n            }\r\
    \n        }\r\n    }\r\n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/string/03A-Suffix-Array.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/string/03A-Suffix-Array.hpp
layout: document
redirect_from:
- /library/src/jiangly/string/03A-Suffix-Array.hpp
- /library/src/jiangly/string/03A-Suffix-Array.hpp.html
title: src/jiangly/string/03A-Suffix-Array.hpp
---
