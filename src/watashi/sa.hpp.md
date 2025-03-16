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
  bundledCode: "#line 1 \"src/watashi/sa.hpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\n\nstruct SuffixArray {\n    vector<int>\
    \ sa, rank, height;\n\n    template <typename T>\n    void init(int n, const T\
    \ a[]) {\n        sa.resize(n);\n        rank.resize(n);\n\n        vector<pair<T,\
    \ int>> assoc(n);\n        for (int i = 0; i < n; ++i) {\n            assoc[i]\
    \ = make_pair(a[i], i);\n        }\n        sort(assoc.begin(), assoc.end());\n\
    \        for (int i = 0; i < n; ++i) {\n            sa[i] = assoc[i].second;\n\
    \            if (i == 0 || assoc[i].first != assoc[i - 1].first) {\n         \
    \       rank[sa[i]] = i;\n            } else {\n                rank[sa[i]] =\
    \ rank[sa[i - 1]];\n            }\n        }\n\n        vector<int> tmp(n), cnt(n);\n\
    \        vector<pair<int, int>> suffix(n);\n        for (int m = 1; m < n; m <<=\
    \ 1) {\n            // snd\n            for (int i = 0; i < m; ++i) {\n      \
    \          tmp[i] = n - m + i;\n            }\n            for (int i = 0, j =\
    \ m; i < n; ++i) {\n                if (sa[i] >= m) {\n                    tmp[j++]\
    \ = sa[i] - m;\n                }\n            }\n            // fst\n       \
    \     fill(cnt.begin(), cnt.end(), 0);\n            for (int i = 0; i < n; ++i)\
    \ {\n                ++cnt[rank[i]];\n            }\n            partial_sum(cnt.begin(),\
    \ cnt.end(), cnt.begin());\n            for (int i = n - 1; i >= 0; --i) {\n \
    \               sa[--cnt[rank[tmp[i]]]] = tmp[i];\n            }\n           \
    \ //\n            for (int i = 0; i < n; ++i) {\n                suffix[i] = make_pair(rank[i],\
    \ i + m < n ? rank[i + m] : numeric_limits<int>::min());\n            }\n    \
    \        for (int i = 0; i < n; ++i) {\n                if (i == 0 || suffix[sa[i]]\
    \ != suffix[sa[i - 1]]) {\n                    rank[sa[i]] = i;\n            \
    \    } else {\n                    rank[sa[i]] = rank[sa[i - 1]];\n          \
    \      }\n            }\n        }\n\n        height.resize(n);\n        for (int\
    \ i = 0, z = 0; i < n; ++i) {\n            if (rank[i] == 0) {\n             \
    \   height[0] = z = 0;\n            } else {\n                int x = i, y = sa[rank[i]\
    \ - 1];\n                z = max(0, z - 1);\n                while (x + z < n\
    \ && y + z < n && a[x + z] == a[y + z]) {\n                    ++z;\n        \
    \        }\n                height[rank[i]] = z;\n            }\n        }\n \
    \   }\n};\n"
  code: "#include <algorithm>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\n\nstruct SuffixArray {\n    vector<int> sa, rank, height;\n\n    template\
    \ <typename T>\n    void init(int n, const T a[]) {\n        sa.resize(n);\n \
    \       rank.resize(n);\n\n        vector<pair<T, int>> assoc(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            assoc[i] = make_pair(a[i], i);\n    \
    \    }\n        sort(assoc.begin(), assoc.end());\n        for (int i = 0; i <\
    \ n; ++i) {\n            sa[i] = assoc[i].second;\n            if (i == 0 || assoc[i].first\
    \ != assoc[i - 1].first) {\n                rank[sa[i]] = i;\n            } else\
    \ {\n                rank[sa[i]] = rank[sa[i - 1]];\n            }\n        }\n\
    \n        vector<int> tmp(n), cnt(n);\n        vector<pair<int, int>> suffix(n);\n\
    \        for (int m = 1; m < n; m <<= 1) {\n            // snd\n            for\
    \ (int i = 0; i < m; ++i) {\n                tmp[i] = n - m + i;\n           \
    \ }\n            for (int i = 0, j = m; i < n; ++i) {\n                if (sa[i]\
    \ >= m) {\n                    tmp[j++] = sa[i] - m;\n                }\n    \
    \        }\n            // fst\n            fill(cnt.begin(), cnt.end(), 0);\n\
    \            for (int i = 0; i < n; ++i) {\n                ++cnt[rank[i]];\n\
    \            }\n            partial_sum(cnt.begin(), cnt.end(), cnt.begin());\n\
    \            for (int i = n - 1; i >= 0; --i) {\n                sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n            }\n            //\n            for (int i = 0; i < n;\
    \ ++i) {\n                suffix[i] = make_pair(rank[i], i + m < n ? rank[i +\
    \ m] : numeric_limits<int>::min());\n            }\n            for (int i = 0;\
    \ i < n; ++i) {\n                if (i == 0 || suffix[sa[i]] != suffix[sa[i -\
    \ 1]]) {\n                    rank[sa[i]] = i;\n                } else {\n   \
    \                 rank[sa[i]] = rank[sa[i - 1]];\n                }\n        \
    \    }\n        }\n\n        height.resize(n);\n        for (int i = 0, z = 0;\
    \ i < n; ++i) {\n            if (rank[i] == 0) {\n                height[0] =\
    \ z = 0;\n            } else {\n                int x = i, y = sa[rank[i] - 1];\n\
    \                z = max(0, z - 1);\n                while (x + z < n && y + z\
    \ < n && a[x + z] == a[y + z]) {\n                    ++z;\n                }\n\
    \                height[rank[i]] = z;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/sa.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/sa.hpp
layout: document
redirect_from:
- /library/src/watashi/sa.hpp
- /library/src/watashi/sa.hpp.html
title: src/watashi/sa.hpp
---
