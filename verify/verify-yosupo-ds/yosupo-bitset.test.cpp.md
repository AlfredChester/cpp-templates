---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/dynamic-bitset.hpp
    title: src/alfred/data_structure/dynamic-bitset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-bitset.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line 1 \"\
    src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\ninline void optimizeIO(void)\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL), std::cout.tie(NULL);\n\
    }\n#line 1 \"src/alfred/data_structure/dynamic-bitset.hpp\"\n\n\n\n#line 7 \"\
    src/alfred/data_structure/dynamic-bitset.hpp\"\n\n// TODO: Implement resize and\
    \ bitwise operators. Figure out how to mod.\n\nclass DynamicBitset {\nprivate:\n\
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
    \    }\n};\n\n\n#line 6 \"verify/verify-yosupo-ds/yosupo-bitset.test.cpp\"\n\n\
    std::string T;\nint n, q, opt, x;\n\nint main(int argc, char const *argv[]) {\n\
    \    optimizeIO();\n    std::cin >> n >> q >> T;\n\n    DynamicBitset bit(n);\n\
    \n    for (int i = 0; i < n; i++) {\n        if (T[i] == '1') bit.set(i);\n  \
    \  }\n\n    while (q--) {\n        std::cin >> opt >> x;\n        if (opt == 0)\
    \ {\n            bit.set(x);\n        } else if (opt == 1) {\n            bit.set(x,\
    \ false);\n        } else if (opt == 2) {\n            std::cout << bit.test(x)\
    \ << '\\n';\n        } else if (opt == 3) {\n            std::cout << bit.suf(x,\
    \ true) << '\\n';\n        } else {\n            std::cout << bit.pre(x, true)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/dynamic-bitset.hpp\"\
    \n#include <iostream>\n\nstd::string T;\nint n, q, opt, x;\n\nint main(int argc,\
    \ char const *argv[]) {\n    optimizeIO();\n    std::cin >> n >> q >> T;\n\n \
    \   DynamicBitset bit(n);\n\n    for (int i = 0; i < n; i++) {\n        if (T[i]\
    \ == '1') bit.set(i);\n    }\n\n    while (q--) {\n        std::cin >> opt >>\
    \ x;\n        if (opt == 0) {\n            bit.set(x);\n        } else if (opt\
    \ == 1) {\n            bit.set(x, false);\n        } else if (opt == 2) {\n  \
    \          std::cout << bit.test(x) << '\\n';\n        } else if (opt == 3) {\n\
    \            std::cout << bit.suf(x, true) << '\\n';\n        } else {\n     \
    \       std::cout << bit.pre(x, true) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/dynamic-bitset.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-bitset.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 22:31:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-bitset.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-bitset.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-bitset.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-bitset.test.cpp
---
