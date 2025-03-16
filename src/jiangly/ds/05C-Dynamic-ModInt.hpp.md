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
    - https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70980889&returnHomeType=1&uid=329687984
  bundledCode: "#line 1 \"src/jiangly/ds/05C-Dynamic-ModInt.hpp\"\n/**   \u52A8\u6001\
    \u53D6\u6A21\u7C7B\uFF08ModIntBase\uFF09\n *    2024-08-14: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70980889&returnHomeType=1&uid=329687984\n\
    \ **/\n// TODO: Dynamic ModInt\n\ntemplate <typename T>\nconstexpr T power(T a,\
    \ u64 b) {\n    T res{1};\n    for (; b != 0; b /= 2, a *= a) {\n        if (b\
    \ % 2 == 1) {\n            res *= a;\n        }\n    }\n    return res;\n}\n\n\
    template <u32 P>\nconstexpr u32 mulMod(u32 a, u32 b) {\n    return 1ULL * a *\
    \ b % P;\n}\n\ntemplate <u64 P>\nconstexpr u64 mulMod(u64 a, u64 b) {\n    u64\
    \ res = a * b - u64(1.L * a * b / P - 0.5L) * P;\n    res %= P;\n    return res;\n\
    }\n\ntemplate <typename U, U P>\n    requires std::unsigned_integral<U>\nstruct\
    \ ModIntBase {\npublic:\n    constexpr ModIntBase() : x{0} {}\n\n    template\
    \ <typename T>\n        requires std::integral<T>\n    constexpr ModIntBase(T\
    \ x_) : x{norm(x_ % T{P})} {}\n\n    constexpr static U norm(U x) {\n        if\
    \ ((x >> (8 * sizeof(U) - 1) & 1) == 1) {\n            x += P;\n        }\n  \
    \      if (x >= P) {\n            x -= P;\n        }\n        return x;\n    }\n\
    \n    constexpr U val() const {\n        return x;\n    }\n\n    constexpr ModIntBase\
    \ operator-() const {\n        ModIntBase res;\n        res.x = norm(P - x);\n\
    \        return res;\n    }\n\n    constexpr ModIntBase inv() const {\n      \
    \  return power(*this, P - 2);\n    }\n\n    constexpr ModIntBase &operator*=(const\
    \ ModIntBase &rhs) & {\n        x = mulMod<P>(x, rhs.val());\n        return *this;\n\
    \    }\n\n    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {\n  \
    \      x = norm(x + rhs.x);\n        return *this;\n    }\n\n    constexpr ModIntBase\
    \ &operator-=(const ModIntBase &rhs) & {\n        x = norm(x - rhs.x);\n     \
    \   return *this;\n    }\n\n    constexpr ModIntBase &operator/=(const ModIntBase\
    \ &rhs) & {\n        return *this *= rhs.inv();\n    }\n\n    friend constexpr\
    \ ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {\n        lhs *=\
    \ rhs;\n        return lhs;\n    }\n\n    friend constexpr ModIntBase operator+(ModIntBase\
    \ lhs, const ModIntBase &rhs) {\n        lhs += rhs;\n        return lhs;\n  \
    \  }\n\n    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase\
    \ &rhs) {\n        lhs -= rhs;\n        return lhs;\n    }\n\n    friend constexpr\
    \ ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {\n        lhs /=\
    \ rhs;\n        return lhs;\n    }\n\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const ModIntBase &a) {\n        return os << a.val();\n    }\n\n    friend\
    \ constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {\n        return\
    \ lhs.val() == rhs.val();\n    }\n\n    friend constexpr bool operator!=(ModIntBase\
    \ lhs, ModIntBase rhs) {\n        return lhs.val() != rhs.val();\n    }\n\n  \
    \  friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {\n       \
    \ return lhs.val() < rhs.val();\n    }\n\nprivate:\n    U x;\n};\n\ntemplate <u32\
    \ P>\nusing ModInt = ModIntBase<u32, P>;\n\ntemplate <u64 P>\nusing ModInt64 =\
    \ ModIntBase<u64, P>;\n\nconstexpr u32 P = 998244353;\nusing Z = ModInt<P>;\n"
  code: "/**   \u52A8\u6001\u53D6\u6A21\u7C7B\uFF08ModIntBase\uFF09\n *    2024-08-14:\
    \ https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70980889&returnHomeType=1&uid=329687984\n\
    \ **/\n// TODO: Dynamic ModInt\n\ntemplate <typename T>\nconstexpr T power(T a,\
    \ u64 b) {\n    T res{1};\n    for (; b != 0; b /= 2, a *= a) {\n        if (b\
    \ % 2 == 1) {\n            res *= a;\n        }\n    }\n    return res;\n}\n\n\
    template <u32 P>\nconstexpr u32 mulMod(u32 a, u32 b) {\n    return 1ULL * a *\
    \ b % P;\n}\n\ntemplate <u64 P>\nconstexpr u64 mulMod(u64 a, u64 b) {\n    u64\
    \ res = a * b - u64(1.L * a * b / P - 0.5L) * P;\n    res %= P;\n    return res;\n\
    }\n\ntemplate <typename U, U P>\n    requires std::unsigned_integral<U>\nstruct\
    \ ModIntBase {\npublic:\n    constexpr ModIntBase() : x{0} {}\n\n    template\
    \ <typename T>\n        requires std::integral<T>\n    constexpr ModIntBase(T\
    \ x_) : x{norm(x_ % T{P})} {}\n\n    constexpr static U norm(U x) {\n        if\
    \ ((x >> (8 * sizeof(U) - 1) & 1) == 1) {\n            x += P;\n        }\n  \
    \      if (x >= P) {\n            x -= P;\n        }\n        return x;\n    }\n\
    \n    constexpr U val() const {\n        return x;\n    }\n\n    constexpr ModIntBase\
    \ operator-() const {\n        ModIntBase res;\n        res.x = norm(P - x);\n\
    \        return res;\n    }\n\n    constexpr ModIntBase inv() const {\n      \
    \  return power(*this, P - 2);\n    }\n\n    constexpr ModIntBase &operator*=(const\
    \ ModIntBase &rhs) & {\n        x = mulMod<P>(x, rhs.val());\n        return *this;\n\
    \    }\n\n    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {\n  \
    \      x = norm(x + rhs.x);\n        return *this;\n    }\n\n    constexpr ModIntBase\
    \ &operator-=(const ModIntBase &rhs) & {\n        x = norm(x - rhs.x);\n     \
    \   return *this;\n    }\n\n    constexpr ModIntBase &operator/=(const ModIntBase\
    \ &rhs) & {\n        return *this *= rhs.inv();\n    }\n\n    friend constexpr\
    \ ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {\n        lhs *=\
    \ rhs;\n        return lhs;\n    }\n\n    friend constexpr ModIntBase operator+(ModIntBase\
    \ lhs, const ModIntBase &rhs) {\n        lhs += rhs;\n        return lhs;\n  \
    \  }\n\n    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase\
    \ &rhs) {\n        lhs -= rhs;\n        return lhs;\n    }\n\n    friend constexpr\
    \ ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {\n        lhs /=\
    \ rhs;\n        return lhs;\n    }\n\n    friend constexpr std::ostream &operator<<(std::ostream\
    \ &os, const ModIntBase &a) {\n        return os << a.val();\n    }\n\n    friend\
    \ constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {\n        return\
    \ lhs.val() == rhs.val();\n    }\n\n    friend constexpr bool operator!=(ModIntBase\
    \ lhs, ModIntBase rhs) {\n        return lhs.val() != rhs.val();\n    }\n\n  \
    \  friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {\n       \
    \ return lhs.val() < rhs.val();\n    }\n\nprivate:\n    U x;\n};\n\ntemplate <u32\
    \ P>\nusing ModInt = ModIntBase<u32, P>;\n\ntemplate <u64 P>\nusing ModInt64 =\
    \ ModIntBase<u64, P>;\n\nconstexpr u32 P = 998244353;\nusing Z = ModInt<P>;"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/ds/05C-Dynamic-ModInt.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/ds/05C-Dynamic-ModInt.hpp
layout: document
redirect_from:
- /library/src/jiangly/ds/05C-Dynamic-ModInt.hpp
- /library/src/jiangly/ds/05C-Dynamic-ModInt.hpp.html
title: src/jiangly/ds/05C-Dynamic-ModInt.hpp
---
