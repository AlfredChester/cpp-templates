---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aizu-string/aizu-hashed-string.test.cpp
    title: verify/verify-aizu-string/aizu-hashed-string.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/string/hashed-string.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <int mod, int seed>\nstruct SingleHash {\n    int\
    \ n;\n    std::vector<int> pow, h;\n    SingleHash(void) = default;\n    SingleHash(std::string\
    \ &s) { init(s); }\n    inline void init(std::string &s) {\n        n = s.size(),\
    \ h.assign(n + 2, 0), pow.assign(n + 2, 1);\n        for (int i = 1; i <= n; i++)\
    \ {\n            pow[i] = 1ll * pow[i - 1] * seed % mod;\n            h[i] = (1ll\
    \ * h[i - 1] * seed + s[i - 1]) % mod;\n        }\n    }\n    inline int get_hash(int\
    \ l, int r) {\n        return (h[r + 1] - 1ll * h[l] * pow[r - l + 1] % mod +\
    \ mod) % mod;\n    }\n    inline bool check_same(int l1, int r1, int l2, int r2)\
    \ {\n        return get_hash(l1, r1) == get_hash(l2, r2);\n    }\n};\nstruct HashedString\
    \ {\n    SingleHash<998244353, 477> H1;\n    SingleHash<1000000007, 233> H2;\n\
    \    HashedString(void) = default;\n    HashedString(std::string s) : H1(s), H2(s)\
    \ {}\n    inline void init(std::string s) {\n        H1.init(s), H2.init(s);\n\
    \    }\n    std::pair<int, int> get_hash(int l, int r) { // not recommended.\n\
    \        return {H1.get_hash(l, r), H2.get_hash(l, r)};\n    }\n    // caution:\
    \ index begins with zero.\n    // If index beginning with one is wanted, use s\
    \ = ' ' + s\n    inline bool check_same(int l1, int r1, int l2, int r2) {\n  \
    \      return H1.check_same(l1, r1, l2, r2) && H2.check_same(l1, r1, l2, r2);\n\
    \    }\n    inline bool check_period(int l, int r, int p) {\n        return check_same(l,\
    \ r - p, l + p, r);\n    }\n};\n\nstruct PalindromeCheck {\n    int n;\n    HashedString\
    \ H1, H2;\n    PalindromeCheck(void) = default;\n    PalindromeCheck(std::string\
    \ s) : n(s.size()), H1(s) {\n        std::reverse(s.begin(), s.end()), H2.init(s);\n\
    \    }\n    inline void init(std::string s) {\n        n = s.size(), H1.init(s);\n\
    \        std::reverse(s.begin(), s.end()), H2.init(s);\n    }\n    inline bool\
    \ check(int l, int r) {\n        return H1.get_hash(l, r) == H2.get_hash(n - 1\
    \ - r, n - 1 - l);\n    }\n};\n\n\n"
  code: "#ifndef AFSTR_HASHED_STRING\n#define AFSTR_HASHED_STRING\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <int mod, int seed>\nstruct SingleHash {\n    int\
    \ n;\n    std::vector<int> pow, h;\n    SingleHash(void) = default;\n    SingleHash(std::string\
    \ &s) { init(s); }\n    inline void init(std::string &s) {\n        n = s.size(),\
    \ h.assign(n + 2, 0), pow.assign(n + 2, 1);\n        for (int i = 1; i <= n; i++)\
    \ {\n            pow[i] = 1ll * pow[i - 1] * seed % mod;\n            h[i] = (1ll\
    \ * h[i - 1] * seed + s[i - 1]) % mod;\n        }\n    }\n    inline int get_hash(int\
    \ l, int r) {\n        return (h[r + 1] - 1ll * h[l] * pow[r - l + 1] % mod +\
    \ mod) % mod;\n    }\n    inline bool check_same(int l1, int r1, int l2, int r2)\
    \ {\n        return get_hash(l1, r1) == get_hash(l2, r2);\n    }\n};\nstruct HashedString\
    \ {\n    SingleHash<998244353, 477> H1;\n    SingleHash<1000000007, 233> H2;\n\
    \    HashedString(void) = default;\n    HashedString(std::string s) : H1(s), H2(s)\
    \ {}\n    inline void init(std::string s) {\n        H1.init(s), H2.init(s);\n\
    \    }\n    std::pair<int, int> get_hash(int l, int r) { // not recommended.\n\
    \        return {H1.get_hash(l, r), H2.get_hash(l, r)};\n    }\n    // caution:\
    \ index begins with zero.\n    // If index beginning with one is wanted, use s\
    \ = ' ' + s\n    inline bool check_same(int l1, int r1, int l2, int r2) {\n  \
    \      return H1.check_same(l1, r1, l2, r2) && H2.check_same(l1, r1, l2, r2);\n\
    \    }\n    inline bool check_period(int l, int r, int p) {\n        return check_same(l,\
    \ r - p, l + p, r);\n    }\n};\n\nstruct PalindromeCheck {\n    int n;\n    HashedString\
    \ H1, H2;\n    PalindromeCheck(void) = default;\n    PalindromeCheck(std::string\
    \ s) : n(s.size()), H1(s) {\n        std::reverse(s.begin(), s.end()), H2.init(s);\n\
    \    }\n    inline void init(std::string s) {\n        n = s.size(), H1.init(s);\n\
    \        std::reverse(s.begin(), s.end()), H2.init(s);\n    }\n    inline bool\
    \ check(int l, int r) {\n        return H1.get_hash(l, r) == H2.get_hash(n - 1\
    \ - r, n - 1 - l);\n    }\n};\n\n#endif // AFSTR_HASHED_STRING\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/string/hashed-string.hpp
  requiredBy: []
  timestamp: '2025-03-22 21:54:53+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aizu-string/aizu-hashed-string.test.cpp
documentation_of: src/alfred/string/hashed-string.hpp
layout: document
redirect_from:
- /library/src/alfred/string/hashed-string.hpp
- /library/src/alfred/string/hashed-string.hpp.html
title: src/alfred/string/hashed-string.hpp
---
