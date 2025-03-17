---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/alfred/math/prime.hpp
    title: src/alfred/math/prime.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/math/speed-of-light-power.hpp\"\n\n\n\n#line\
    \ 2 \"src/alfred/math/prime.hpp\"\n\n#ifndef AFMT_PRIME\n#define AFMT_PRIME\n\n\
    // O(sqrt(x)) to judge if x is a prime.\n// It will be re-written in Miller-rabin\
    \ sometime.\nconstexpr bool is_prime(long long x) {\n    if (x < 2) return false;\n\
    \    for (long long i = 2; i * i <= x; i++) {\n        if (x % i == 0) return\
    \ false;\n    }\n    return true;\n}\n\n#endif // AFMT_PRIME\n#line 5 \"src/alfred/math/speed-of-light-power.hpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <int base, int mod>\nstruct SOLPower {\
    \ // Speed Of Light Power. O(sqrt(n)) ~ O(1)\n    // p1 stores base^0  ~ base^sq\n\
    \    // ps stores base^sq ~ base^(sq^2)\n    std::vector<int> p1, ps;\n    static\
    \ const bool P = is_prime(mod);\n    static const int sq = std::sqrt(mod);\n \
    \   SOLPower(void) {\n        p1.push_back(1), ps.push_back(1);\n        for (int\
    \ i = 1; i <= sq; i++) {\n            p1.push_back(1ll * p1.back() * base % mod);\n\
    \        }\n        ps.push_back(p1.back());\n        for (int i = 2 * sq; i <=\
    \ mod; i += sq) {\n            ps.push_back(1ll * ps.back() * ps[1] % mod);\n\
    \        }\n    }\n    inline int power(long long index) {\n        if (P && index\
    \ >= mod) index %= mod;\n        return 1ll * ps[index / sq] * p1[index % sq]\
    \ % mod;\n    }\n};\n\n\n"
  code: "#ifndef AFMT_SPEED_OF_LIGHT_POWER\n#define AFMT_SPEED_OF_LIGHT_POWER\n\n\
    #include \"prime.hpp\"\n#include <bits/stdc++.h>\n\ntemplate <int base, int mod>\n\
    struct SOLPower { // Speed Of Light Power. O(sqrt(n)) ~ O(1)\n    // p1 stores\
    \ base^0  ~ base^sq\n    // ps stores base^sq ~ base^(sq^2)\n    std::vector<int>\
    \ p1, ps;\n    static const bool P = is_prime(mod);\n    static const int sq =\
    \ std::sqrt(mod);\n    SOLPower(void) {\n        p1.push_back(1), ps.push_back(1);\n\
    \        for (int i = 1; i <= sq; i++) {\n            p1.push_back(1ll * p1.back()\
    \ * base % mod);\n        }\n        ps.push_back(p1.back());\n        for (int\
    \ i = 2 * sq; i <= mod; i += sq) {\n            ps.push_back(1ll * ps.back() *\
    \ ps[1] % mod);\n        }\n    }\n    inline int power(long long index) {\n \
    \       if (P && index >= mod) index %= mod;\n        return 1ll * ps[index /\
    \ sq] * p1[index % sq] % mod;\n    }\n};\n\n#endif // AFMT_SPEED_OF_LIGHT_POWER\n"
  dependsOn:
  - src/alfred/math/prime.hpp
  isVerificationFile: false
  path: src/alfred/math/speed-of-light-power.hpp
  requiredBy: []
  timestamp: '2025-03-17 21:42:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/math/speed-of-light-power.hpp
layout: document
redirect_from:
- /library/src/alfred/math/speed-of-light-power.hpp
- /library/src/alfred/math/speed-of-light-power.hpp.html
title: src/alfred/math/speed-of-light-power.hpp
---
