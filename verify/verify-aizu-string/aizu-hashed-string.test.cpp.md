---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/string/hashed-string.hpp
    title: src/alfred/string/hashed-string.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0528
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0528
  bundledCode: "#line 1 \"verify/verify-aizu-string/aizu-hashed-string.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0528\"\
    \n\n#line 1 \"src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\n\
    inline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL),\
    \ std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/string/hashed-string.hpp\"\n\n\
    \n\n#line 5 \"src/alfred/string/hashed-string.hpp\"\n\ntemplate <int mod, int\
    \ seed>\nstruct SingleHash {\n    int n;\n    std::vector<int> pow, h;\n    SingleHash(void)\
    \ = default;\n    SingleHash(std::string &s) { init(s); }\n    inline void init(std::string\
    \ &s) {\n        n = s.size(), h.assign(n + 2, 0), pow.assign(n + 2, 1);\n   \
    \     for (int i = 1; i <= n; i++) {\n            pow[i] = 1ll * pow[i - 1] *\
    \ seed % mod;\n            h[i] = (1ll * h[i - 1] * seed + s[i - 1]) % mod;\n\
    \        }\n    }\n    inline int get_hash(int l, int r) {\n        return (h[r\
    \ + 1] - 1ll * h[l] * pow[r - l + 1] % mod + mod) % mod;\n    }\n    inline bool\
    \ check_same(int l1, int r1, int l2, int r2) {\n        return get_hash(l1, r1)\
    \ == get_hash(l2, r2);\n    }\n};\nstruct HashedString {\n    SingleHash<998244353,\
    \ 477> H1;\n    SingleHash<1000000007, 233> H2;\n    HashedString(void) = default;\n\
    \    HashedString(std::string s) : H1(s), H2(s) {}\n    inline void init(std::string\
    \ s) {\n        H1.init(s), H2.init(s);\n    }\n    std::pair<int, int> get_hash(int\
    \ l, int r) { // not recommended.\n        return {H1.get_hash(l, r), H2.get_hash(l,\
    \ r)};\n    }\n    // caution: index begins with zero.\n    // If index beginning\
    \ with one is wanted, use s = ' ' + s\n    inline bool check_same(int l1, int\
    \ r1, int l2, int r2) {\n        return H1.check_same(l1, r1, l2, r2) && H2.check_same(l1,\
    \ r1, l2, r2);\n    }\n    inline bool check_period(int l, int r, int p) {\n \
    \       return check_same(l, r - p, l + p, r);\n    }\n};\n\n\n#line 6 \"verify/verify-aizu-string/aizu-hashed-string.test.cpp\"\
    \n\nstd::string S, T;\n\ninline void solve(void) {\n    HashedString H(S + T);\n\
    \    int ans = 0, L, R, mid;\n    int n = S.size(), m = T.size();\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n            if\
    \ (S[i] != T[j]) continue;\n            L = 0, R = std::min(n - i, m - j) - 1;\n\
    \            if (R + 1 < ans) continue;\n            while (L < R) {\n       \
    \         mid = (L + R + 1) >> 1;\n                if (H.check_same(i, i + mid,\
    \ j + n, j + n + mid)) {\n                    L = mid;\n                } else\
    \ {\n                    R = mid - 1;\n                }\n            }\n    \
    \        ans = std::max(ans, L + 1);\n        }\n    }\n    std::cout << ans <<\
    \ '\\n';\n}\n\nint main(int argc, char const *argv[]) {\n    optimizeIO();\n \
    \   while (std::cin >> S >> T) {\n        solve();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0528\"\
    \n\n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/string/hashed-string.hpp\"\
    \n#include <iostream>\n\nstd::string S, T;\n\ninline void solve(void) {\n    HashedString\
    \ H(S + T);\n    int ans = 0, L, R, mid;\n    int n = S.size(), m = T.size();\n\
    \    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n  \
    \          if (S[i] != T[j]) continue;\n            L = 0, R = std::min(n - i,\
    \ m - j) - 1;\n            if (R + 1 < ans) continue;\n            while (L <\
    \ R) {\n                mid = (L + R + 1) >> 1;\n                if (H.check_same(i,\
    \ i + mid, j + n, j + n + mid)) {\n                    L = mid;\n            \
    \    } else {\n                    R = mid - 1;\n                }\n         \
    \   }\n            ans = std::max(ans, L + 1);\n        }\n    }\n    std::cout\
    \ << ans << '\\n';\n}\n\nint main(int argc, char const *argv[]) {\n    optimizeIO();\n\
    \    while (std::cin >> S >> T) {\n        solve();\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/string/hashed-string.hpp
  isVerificationFile: true
  path: verify/verify-aizu-string/aizu-hashed-string.test.cpp
  requiredBy: []
  timestamp: '2025-03-21 21:25:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aizu-string/aizu-hashed-string.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aizu-string/aizu-hashed-string.test.cpp
- /verify/verify/verify-aizu-string/aizu-hashed-string.test.cpp.html
title: verify/verify-aizu-string/aizu-hashed-string.test.cpp
---
