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
  bundledCode: "#line 1 \"src/alfred/data_structure/chtholly.hpp\"\n\n\n\n#include\
    \ <set>\n\nstruct ChthollyTree {\n    using i64 = long long;\n    struct Node\
    \ {\n        mutable i64 l, r, v;\n        inline bool operator<(const Node &x)\
    \ const { return l < x.l; }\n    };\n    std::set<Node> tr;\n    using iterator\
    \ = std::set<Node>::iterator;\n    ChthollyTree(void) = default;\n    ChthollyTree(int\
    \ rng, int val) { init(rng, val); }\n    inline void init(i64 rng, i64 val) noexcept\
    \ {\n        tr.insert({1, rng, val}), tr.insert({rng + 1, rng + 1, 0});\n   \
    \ }\n    inline iterator begin(void) const noexcept { return tr.begin(); }\n \
    \   inline iterator end(void) const noexcept { return tr.end(); }\n    inline\
    \ iterator split(i64 pos) {\n        auto it = tr.lower_bound({pos, 0, 0});\n\
    \        if (it != tr.end() && it->l == pos) return it;\n        i64 l = (--it)->l,\
    \ r = it->r, v = it->v;\n        tr.erase(it), tr.insert({l, pos - 1, v});\n \
    \       return tr.insert({pos, r, v}).first;\n    }\n    inline void assign(i64\
    \ l, i64 r, i64 v) {\n        auto R = split(r + 1), L = split(l);\n        tr.erase(L,\
    \ R), tr.insert({l, r, v});\n    }\n    template <class _Functor> // func(iterator)\n\
    \    inline void modify(i64 l, i64 r, _Functor func) {\n        auto R = split(r\
    \ + 1), L = split(l);\n        for (auto it = L; it != R; it++) func(it);\n  \
    \  }\n    template <class _Functor> // func(i64 &, iterator)\n    inline i64 query(i64\
    \ l, i64 r, _Functor func) {\n        i64 ans = 0;\n        auto R = split(r +\
    \ 1);\n        for (auto it = split(l); it != R; it++) func(ans, it);\n      \
    \  return ans;\n    }\n};\n\n\n"
  code: "#ifndef AFDS_CHTHOLLY\n#define AFDS_CHTHOLLY\n\n#include <set>\n\nstruct\
    \ ChthollyTree {\n    using i64 = long long;\n    struct Node {\n        mutable\
    \ i64 l, r, v;\n        inline bool operator<(const Node &x) const { return l\
    \ < x.l; }\n    };\n    std::set<Node> tr;\n    using iterator = std::set<Node>::iterator;\n\
    \    ChthollyTree(void) = default;\n    ChthollyTree(int rng, int val) { init(rng,\
    \ val); }\n    inline void init(i64 rng, i64 val) noexcept {\n        tr.insert({1,\
    \ rng, val}), tr.insert({rng + 1, rng + 1, 0});\n    }\n    inline iterator begin(void)\
    \ const noexcept { return tr.begin(); }\n    inline iterator end(void) const noexcept\
    \ { return tr.end(); }\n    inline iterator split(i64 pos) {\n        auto it\
    \ = tr.lower_bound({pos, 0, 0});\n        if (it != tr.end() && it->l == pos)\
    \ return it;\n        i64 l = (--it)->l, r = it->r, v = it->v;\n        tr.erase(it),\
    \ tr.insert({l, pos - 1, v});\n        return tr.insert({pos, r, v}).first;\n\
    \    }\n    inline void assign(i64 l, i64 r, i64 v) {\n        auto R = split(r\
    \ + 1), L = split(l);\n        tr.erase(L, R), tr.insert({l, r, v});\n    }\n\
    \    template <class _Functor> // func(iterator)\n    inline void modify(i64 l,\
    \ i64 r, _Functor func) {\n        auto R = split(r + 1), L = split(l);\n    \
    \    for (auto it = L; it != R; it++) func(it);\n    }\n    template <class _Functor>\
    \ // func(i64 &, iterator)\n    inline i64 query(i64 l, i64 r, _Functor func)\
    \ {\n        i64 ans = 0;\n        auto R = split(r + 1);\n        for (auto it\
    \ = split(l); it != R; it++) func(ans, it);\n        return ans;\n    }\n};\n\n\
    #endif // AFDS_CHTHOLLY"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/chtholly.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:57:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/chtholly.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/chtholly.hpp
- /library/src/alfred/data_structure/chtholly.hpp.html
title: src/alfred/data_structure/chtholly.hpp
---
