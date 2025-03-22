---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/alfred/config/io-sync-off.hpp
    title: src/alfred/config/io-sync-off.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/data_structure/weighted-dsu.hpp
    title: src/alfred/data_structure/weighted-dsu.hpp
  - icon: ':heavy_check_mark:'
    path: src/alfred/math/mod-int.hpp
    title: src/alfred/math/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\n\
    \n#line 1 \"src/alfred/config/io-sync-off.hpp\"\n#include <bits/stdc++.h>\n\n\
    inline void optimizeIO(void) {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(NULL),\
    \ std::cout.tie(NULL);\n}\n#line 1 \"src/alfred/data_structure/weighted-dsu.hpp\"\
    \n\n\n\n#line 6 \"src/alfred/data_structure/weighted-dsu.hpp\"\n\ntemplate <class\
    \ T>\nstruct WeightedDSU {\n    std::vector<int> fa;\n    std::vector<T> w;\n\
    \    WeightedDSU(int n) : fa(n + 1), w(n + 1) {\n        std::iota(fa.begin(),\
    \ fa.end(), 0);\n    }\n    inline int find(int x) {\n        if (fa[x] == x)\
    \ return x;\n        int f = fa[x], f2 = find(f);\n        return w[x] += w[f],\
    \ fa[x] = f2;\n    }\n    inline bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n    // Given info: a[x] + v = a[y]\n    // Returns true\
    \ if this operation has no conflict, false otherwise.\n    inline bool merge(int\
    \ x, int y, T v) {\n        int fx = find(x), fy = find(y);\n        if (fx ==\
    \ fy) {\n            return w[x] + v == w[y];\n        }\n        w[fy] = w[x]\
    \ + v - w[y], fa[fy] = fx;\n        return true;\n    }\n    inline T distance(int\
    \ x, int y) {\n        return find(x), find(y), w[y] - w[x];\n    }\n};\n\n\n\
    #line 1 \"src/alfred/math/mod-int.hpp\"\n\n\n#ifndef AFMT_MOD_INT\n#define AFMT_MOD_INT\n\
    \n#include <iostream>\n\ntemplate <int mod>\ninline int down(int x) { return x\
    \ >= mod ? x - mod : x; }\ntemplate <int mod>\nstruct ModInt {\n    int x;\n \
    \   ModInt(void) = default;\n    ModInt(int x) : x(x) {}\n    ModInt(long long\
    \ x) : x(x % mod) {}\n    friend std::istream &operator>>(std::istream &in, ModInt\
    \ &a) { return in >> a.x; }\n    friend std::ostream &operator<<(std::ostream\
    \ &out, ModInt a) { return out << a.x; }\n    friend ModInt operator+(ModInt a,\
    \ ModInt b) { return down<mod>(a.x + b.x); }\n    friend ModInt operator-(ModInt\
    \ a, ModInt b) { return down<mod>(a.x - b.x + mod); }\n    friend ModInt operator*(ModInt\
    \ a, ModInt b) { return (long long)a.x * b.x % mod; }\n    friend ModInt operator/(ModInt\
    \ a, ModInt b) { return a * ~b; }\n    friend ModInt operator^(ModInt a, long\
    \ long b) {\n        ModInt ans = 1;\n        for (; b > 0; b >>= 1, a *= a)\n\
    \            if (b & 1) ans *= a;\n        return ans;\n    }\n    friend ModInt\
    \ operator~(ModInt a) { return a ^ (mod - 2); }\n    friend ModInt operator-(ModInt\
    \ a) { return down<mod>(mod - a.x); }\n    friend ModInt &operator+=(ModInt &a,\
    \ ModInt b) { return a = a + b; }\n    friend ModInt &operator-=(ModInt &a, ModInt\
    \ b) { return a = a - b; }\n    friend ModInt &operator*=(ModInt &a, ModInt b)\
    \ { return a = a * b; }\n    friend ModInt &operator/=(ModInt &a, ModInt b) {\
    \ return a = a / b; }\n    friend ModInt &operator^=(ModInt &a, long long b) {\
    \ return a = a ^ b; }\n    friend ModInt &operator++(ModInt &a) { return a +=\
    \ 1; }\n    friend ModInt operator++(ModInt &a, int) {\n        ModInt x = a;\n\
    \        a += 1;\n        return x;\n    }\n    friend ModInt &operator--(ModInt\
    \ &a) { return a -= 1; }\n    friend ModInt operator--(ModInt &a, int) {\n   \
    \     ModInt x = a;\n        a -= 1;\n        return x;\n    }\n    friend bool\
    \ operator==(ModInt a, ModInt b) { return a.x == b.x; }\n    friend bool operator!=(ModInt\
    \ a, ModInt b) { return !(a == b); }\n};\ntemplate <int mod>\ninline void __print(ModInt<mod>\
    \ x) {\n    std::cerr << x;\n}\n\nusing m998 = ModInt<998244353>;\nusing m107\
    \ = ModInt<1000000007>;\n\n#endif // AFMT_MOD_INT\n#line 7 \"verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp\"\
    \n\nint n, q, opt, u, v, x;\nusing mint = ModInt<998244353>;\n\nint main(int argc,\
    \ char const *argv[]) {\n    optimizeIO(), std::cin >> n >> q;\n\n    WeightedDSU<mint>\
    \ dsu(n);\n\n    while (q--) {\n        std::cin >> opt >> u >> v;\n        if\
    \ (opt == 0) {\n            std::cin >> x;\n            std::cout << dsu.merge(u,\
    \ v, x) << '\\n';\n        } else if (!dsu.same(u, v)) {\n            std::cout\
    \ << \"-1\\n\";\n        } else {\n            std::cout << dsu.distance(u, v)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../../src/alfred/config/io-sync-off.hpp\"\n#include \"../../src/alfred/data_structure/weighted-dsu.hpp\"\
    \n#include \"../../src/alfred/math/mod-int.hpp\"\n#include <iostream>\n\nint n,\
    \ q, opt, u, v, x;\nusing mint = ModInt<998244353>;\n\nint main(int argc, char\
    \ const *argv[]) {\n    optimizeIO(), std::cin >> n >> q;\n\n    WeightedDSU<mint>\
    \ dsu(n);\n\n    while (q--) {\n        std::cin >> opt >> u >> v;\n        if\
    \ (opt == 0) {\n            std::cin >> x;\n            std::cout << dsu.merge(u,\
    \ v, x) << '\\n';\n        } else if (!dsu.same(u, v)) {\n            std::cout\
    \ << \"-1\\n\";\n        } else {\n            std::cout << dsu.distance(u, v)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - src/alfred/config/io-sync-off.hpp
  - src/alfred/data_structure/weighted-dsu.hpp
  - src/alfred/math/mod-int.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
  requiredBy: []
  timestamp: '2025-03-22 17:56:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-weighted-dsu.test.cpp
---
