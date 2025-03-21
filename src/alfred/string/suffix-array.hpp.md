---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/sparse-table.hpp
    title: src/alfred/data_structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aizu-string/aizu-suffix-array.test.cpp
    title: verify/verify-aizu-string/aizu-suffix-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/string/suffix-array.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <string>\n#include <vector>\n\n#line 1 \"src/alfred/data_structure/sparse-table.hpp\"\
    \n\n\n\n#include <limits>\n#include <numeric>\n#line 7 \"src/alfred/data_structure/sparse-table.hpp\"\
    \n\ntemplate <class T>\nstruct MaxInfo {\n    T val;\n    MaxInfo(void) { val\
    \ = std::numeric_limits<T>::min(); }\n    template <class InitT>\n    MaxInfo(InitT\
    \ x) { val = x; }\n    MaxInfo operator+(MaxInfo &x) {\n        return {std::max(val,\
    \ x.val)};\n    }\n};\ntemplate <class T>\nstruct MinInfo {\n    T val;\n    MinInfo(void)\
    \ { val = std::numeric_limits<T>::max(); }\n    template <class InitT>\n    MinInfo(InitT\
    \ x) { val = x; }\n    MinInfo operator+(MinInfo &x) {\n        return {std::min(val,\
    \ x.val)};\n    }\n};\ntemplate <class T>\nstruct GcdInfo {\n    T val;\n    GcdInfo(void)\
    \ { val = T(); }\n    template <class InitT>\n    GcdInfo(InitT x) { val = x;\
    \ }\n    GcdInfo operator+(GcdInfo &x) {\n#if __cplusplus >= 201703L\n       \
    \ return {std::gcd(x.val, val)};\n#else\n        return {__gcd(x.val, val)};\n\
    #endif\n    }\n};\ntemplate <class T>\nclass SparseTable {\nprivate:\n    int\
    \ n;\n    std::vector<std::vector<T>> ST;\n\npublic:\n    SparseTable(void) {}\n\
    \    SparseTable(int N) : n(N), ST(N, std::vector<T>(std::__lg(N) + 1)) {}\n \
    \   template <class InitT>\n    SparseTable(std::vector<InitT> &_init) : SparseTable(_init.size())\
    \ { init(_init, true); }\n    template <class InitT>\n    inline void init(std::vector<InitT>\
    \ &_init, bool internal = false) {\n        if (!internal) {\n            n =\
    \ _init.size();\n            ST.assign(n, std::vector<T>(std::__lg(n) + 1));\n\
    \        }\n        for (int i = 0; i < n; i++) ST[i][0] = T(_init[i]);\n    \
    \    for (int i = 1; (1 << i) <= n; i++) {\n            for (int j = 0; j + (1\
    \ << i) - 1 < n; j++) {\n                ST[j][i] = ST[j][i - 1] + ST[j + (1 <<\
    \ (i - 1))][i - 1];\n            }\n        }\n    }\n    inline T query(int l,\
    \ int r) { // 0 based\n        if (l > r) return T();\n        int w = std::__lg(r\
    \ - l + 1);\n        return ST[l][w] + ST[r - (1 << w) + 1][w];\n    }\n    inline\
    \ T disjoint_query(int l, int r) {\n        T ans = T();\n        for (int i =\
    \ l; i <= r; i += (1 << std::__lg(r - i + 1))) {\n            ans = ans + ST[i][std::__lg(r\
    \ - i + 1)];\n        }\n        return ans;\n    }\n};\n\n\n#line 9 \"src/alfred/string/suffix-array.hpp\"\
    \n\nclass SuffixArray {\nprivate:\n    int n;\n    std::string s; // internal\
    \ is 1-index, access is 0-indexed.\n    SparseTable<MinInfo<int>> ST;\n    std::vector<int>\
    \ sa, rnk, old, h;\n\npublic:\n    SuffixArray(std::string S) : n(S.size()), s(S)\
    \ {\n        const int m = n + 1;\n        s.insert(s.begin(), ' '), sa.assign(m,\
    \ 0);\n        rnk.assign(m, 0), old.assign(m, 0), h.assign(m, 0);\n        for\
    \ (int i = 1; i <= n; i++) sa[i] = i, rnk[i] = s[i];\n\n        for (int w = 1;\
    \ w < n; w *= 2) {\n            std::copy(rnk.begin(), rnk.end(), old.begin());\n\
    \            auto cmp = [&](int x, int y) {\n                if (old[x] != old[y])\
    \ return old[x] < old[y];\n                if (y + w > n) return false;\n    \
    \            if (x + w > n) return true;\n                return old[x + w] <\
    \ old[y + w];\n            };\n            std::sort(std::next(sa.begin()), sa.end(),\
    \ cmp);\n            for (int i = 1; i <= n; i++) {\n                rnk[sa[i]]\
    \ = rnk[sa[i - 1]] + cmp(sa[i - 1], sa[i]);\n            }\n            if (rnk[sa[n]]\
    \ == n) break;\n        }\n\n        for (int i = 1, k = 0; i <= n; i++) {\n \
    \           if (rnk[i] == 0) continue;\n            if (k != 0) k--;\n       \
    \     while (std::max(i, sa[rnk[i] - 1]) <= n - k &&\n                   s[i +\
    \ k] == s[sa[rnk[i] - 1] + k]) {\n                k++;\n            }\n      \
    \      h[rnk[i]] = k;\n        }\n        ST.init(h);\n    }\n    const std::vector<int>\
    \ get_h(void) { return h; }\n    const std::vector<int> get_sa(void) { return\
    \ sa; }\n    const std::vector<int> get_rnk(void) { return rnk; }\n    inline\
    \ int lcp(int i, int j) { // 0-indexed !\n        i = rnk[i + 1], j = rnk[j +\
    \ 1];\n        if (i > j) std::swap(i, j);\n        return i == j ? n - i : ST.query(i\
    \ + 1, j).val;\n    }\n};\n\n\n"
  code: "#ifndef AFSTR_SUFFIX_ARRAY\n#define AFSTR_SUFFIX_ARRAY\n\n#include <algorithm>\n\
    #include <string>\n#include <vector>\n\n#include \"../data_structure/sparse-table.hpp\"\
    \n\nclass SuffixArray {\nprivate:\n    int n;\n    std::string s; // internal\
    \ is 1-index, access is 0-indexed.\n    SparseTable<MinInfo<int>> ST;\n    std::vector<int>\
    \ sa, rnk, old, h;\n\npublic:\n    SuffixArray(std::string S) : n(S.size()), s(S)\
    \ {\n        const int m = n + 1;\n        s.insert(s.begin(), ' '), sa.assign(m,\
    \ 0);\n        rnk.assign(m, 0), old.assign(m, 0), h.assign(m, 0);\n        for\
    \ (int i = 1; i <= n; i++) sa[i] = i, rnk[i] = s[i];\n\n        for (int w = 1;\
    \ w < n; w *= 2) {\n            std::copy(rnk.begin(), rnk.end(), old.begin());\n\
    \            auto cmp = [&](int x, int y) {\n                if (old[x] != old[y])\
    \ return old[x] < old[y];\n                if (y + w > n) return false;\n    \
    \            if (x + w > n) return true;\n                return old[x + w] <\
    \ old[y + w];\n            };\n            std::sort(std::next(sa.begin()), sa.end(),\
    \ cmp);\n            for (int i = 1; i <= n; i++) {\n                rnk[sa[i]]\
    \ = rnk[sa[i - 1]] + cmp(sa[i - 1], sa[i]);\n            }\n            if (rnk[sa[n]]\
    \ == n) break;\n        }\n\n        for (int i = 1, k = 0; i <= n; i++) {\n \
    \           if (rnk[i] == 0) continue;\n            if (k != 0) k--;\n       \
    \     while (std::max(i, sa[rnk[i] - 1]) <= n - k &&\n                   s[i +\
    \ k] == s[sa[rnk[i] - 1] + k]) {\n                k++;\n            }\n      \
    \      h[rnk[i]] = k;\n        }\n        ST.init(h);\n    }\n    const std::vector<int>\
    \ get_h(void) { return h; }\n    const std::vector<int> get_sa(void) { return\
    \ sa; }\n    const std::vector<int> get_rnk(void) { return rnk; }\n    inline\
    \ int lcp(int i, int j) { // 0-indexed !\n        i = rnk[i + 1], j = rnk[j +\
    \ 1];\n        if (i > j) std::swap(i, j);\n        return i == j ? n - i : ST.query(i\
    \ + 1, j).val;\n    }\n};\n\n#endif\n"
  dependsOn:
  - src/alfred/data_structure/sparse-table.hpp
  isVerificationFile: false
  path: src/alfred/string/suffix-array.hpp
  requiredBy: []
  timestamp: '2025-03-21 23:00:50+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aizu-string/aizu-suffix-array.test.cpp
documentation_of: src/alfred/string/suffix-array.hpp
layout: document
redirect_from:
- /library/src/alfred/string/suffix-array.hpp
- /library/src/alfred/string/suffix-array.hpp.html
title: src/alfred/string/suffix-array.hpp
---
