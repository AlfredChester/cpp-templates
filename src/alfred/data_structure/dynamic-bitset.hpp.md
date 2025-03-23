---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-bitset.test.cpp
    title: verify/verify-yosupo-ds/yosupo-bitset.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/data_structure/dynamic-bitset.hpp\"\n\n\n\n#include\
    \ <limits>\n#include <numeric>\n#include <vector>\n\n// TODO: Implement resize\
    \ and bitwise operators. Figure out how to mod.\n\nclass DynamicBitset {\nprivate:\n\
    \    using Word_t = unsigned long long;\n    constexpr static int bw = sizeof(Word_t)\
    \ * 8;\n    constexpr static Word_t WORD_MAX = std::numeric_limits<Word_t>::max();\n\
    \    size_t n, cnt;\n    std::vector<Word_t> bits;\n\n    inline int calc_len(void)\
    \ {\n        return (std::max<size_t>(n, bw) + bw - 1) / bw;\n    }\n\npublic:\n\
    \    DynamicBitset(size_t N) : n(N), bits(calc_len()) {}\n    inline int size(void)\
    \ { return n; }\n    inline int count(void) { return cnt; }\n    inline int test(size_t\
    \ i) { return (bits[i / bw] >> (i % bw)) & 1; }\n    inline void set(size_t i,\
    \ bool val = true) {\n        if (test(i) == val) return;\n        bits[i / bw]\
    \ ^= (1ULL << (i % bw));\n        val ? cnt++ : cnt--;\n    }\n    inline void\
    \ flip(size_t i) {\n        bits[i / bw] ^= (1ULL << (i % bw));\n        test(i)\
    \ ? cnt-- : cnt++;\n    }\n    inline void reset(void) {\n        std::fill(bits.begin(),\
    \ bits.end(), 0);\n        cnt = 0;\n    }\n    inline void clear(void) {\n  \
    \      bits.clear(), cnt = n = 0;\n    }\n    // find the previous val before\
    \ i. returns -1 if not found.\n    inline int pre(size_t i, bool contain = false,\
    \ bool val = true) {\n        Word_t cur = bits[i / bw];\n        for (int j =\
    \ (int)(i % bw) - (!contain); j >= 0; j--) {\n            if ((cur >> j & 1) ==\
    \ val) {\n                return i - (i % bw - j);\n            }\n        }\n\
    \        for (int j = i / bw - 1; j >= 0; j--) {\n            if (bits[j] == (val\
    \ ? 0 : WORD_MAX)) continue;\n            for (int k = bw - 1; k >= 0; k--) {\n\
    \                if ((bits[j] >> k & 1) == val) {\n                    return\
    \ j * bw + k;\n                }\n            }\n        }\n        return -1;\n\
    \    }\n    inline int suf(size_t i, bool contain = false, bool val = true) {\n\
    \        Word_t cur = bits[i / bw];\n        for (int j = i % bw + (!contain);\
    \ j < bw; j++) {\n            if ((cur >> j & 1) == val) {\n                return\
    \ i + (j - i % bw);\n            }\n        }\n        const int len = calc_len();\n\
    \        for (int j = i / bw + 1; j < len; j++) {\n            if (bits[j] ==\
    \ (val ? 0 : WORD_MAX)) continue;\n            for (int k = 0; k < bw; k++) {\n\
    \                if ((bits[j] >> k & 1) == val) {\n                    return\
    \ j * bw + k;\n                }\n            }\n        }\n        return -1;\n\
    \    }\n};\n\n\n"
  code: "#ifndef AFDS_DYNAMIC_BITSET\n#define AFDS_DYNAMIC_BITSET\n\n#include <limits>\n\
    #include <numeric>\n#include <vector>\n\n// TODO: Implement resize and bitwise\
    \ operators. Figure out how to mod.\n\nclass DynamicBitset {\nprivate:\n    using\
    \ Word_t = unsigned long long;\n    constexpr static int bw = sizeof(Word_t) *\
    \ 8;\n    constexpr static Word_t WORD_MAX = std::numeric_limits<Word_t>::max();\n\
    \    size_t n, cnt;\n    std::vector<Word_t> bits;\n\n    inline int calc_len(void)\
    \ {\n        return (std::max<size_t>(n, bw) + bw - 1) / bw;\n    }\n\npublic:\n\
    \    DynamicBitset(size_t N) : n(N), bits(calc_len()) {}\n    inline int size(void)\
    \ { return n; }\n    inline int count(void) { return cnt; }\n    inline int test(size_t\
    \ i) { return (bits[i / bw] >> (i % bw)) & 1; }\n    inline void set(size_t i,\
    \ bool val = true) {\n        if (test(i) == val) return;\n        bits[i / bw]\
    \ ^= (1ULL << (i % bw));\n        val ? cnt++ : cnt--;\n    }\n    inline void\
    \ flip(size_t i) {\n        bits[i / bw] ^= (1ULL << (i % bw));\n        test(i)\
    \ ? cnt-- : cnt++;\n    }\n    inline void reset(void) {\n        std::fill(bits.begin(),\
    \ bits.end(), 0);\n        cnt = 0;\n    }\n    inline void clear(void) {\n  \
    \      bits.clear(), cnt = n = 0;\n    }\n    // find the previous val before\
    \ i. returns -1 if not found.\n    inline int pre(size_t i, bool contain = false,\
    \ bool val = true) {\n        Word_t cur = bits[i / bw];\n        for (int j =\
    \ (int)(i % bw) - (!contain); j >= 0; j--) {\n            if ((cur >> j & 1) ==\
    \ val) {\n                return i - (i % bw - j);\n            }\n        }\n\
    \        for (int j = i / bw - 1; j >= 0; j--) {\n            if (bits[j] == (val\
    \ ? 0 : WORD_MAX)) continue;\n            for (int k = bw - 1; k >= 0; k--) {\n\
    \                if ((bits[j] >> k & 1) == val) {\n                    return\
    \ j * bw + k;\n                }\n            }\n        }\n        return -1;\n\
    \    }\n    inline int suf(size_t i, bool contain = false, bool val = true) {\n\
    \        Word_t cur = bits[i / bw];\n        for (int j = i % bw + (!contain);\
    \ j < bw; j++) {\n            if ((cur >> j & 1) == val) {\n                return\
    \ i + (j - i % bw);\n            }\n        }\n        const int len = calc_len();\n\
    \        for (int j = i / bw + 1; j < len; j++) {\n            if (bits[j] ==\
    \ (val ? 0 : WORD_MAX)) continue;\n            for (int k = 0; k < bw; k++) {\n\
    \                if ((bits[j] >> k & 1) == val) {\n                    return\
    \ j * bw + k;\n                }\n            }\n        }\n        return -1;\n\
    \    }\n};\n\n#endif // AFDS_DYNAMIC_BITSET\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/dynamic-bitset.hpp
  requiredBy: []
  timestamp: '2025-03-23 22:31:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-bitset.test.cpp
documentation_of: src/alfred/data_structure/dynamic-bitset.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/dynamic-bitset.hpp
- /library/src/alfred/data_structure/dynamic-bitset.hpp.html
title: src/alfred/data_structure/dynamic-bitset.hpp
---
