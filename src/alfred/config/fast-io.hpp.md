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
  bundledCode: "#line 1 \"src/alfred/config/fast-io.hpp\"\n#include <bits/stdc++.h>\n\
    \nnamespace fastIO {\n    char c, f, e = 0;\n    namespace usr {\n        template\
    \ <class _Tp>\n        inline int read(_Tp &x) {\n            x = f = 0, c = getchar();\n\
    \            while (!isdigit(c) && !e) f = c == '-', e |= c == EOF, c = getchar();\n\
    \            while (isdigit(c) && !e) x = (x << 1) + (x << 3) + (c ^ 48), c =\
    \ getchar();\n            return (e |= c == EOF) ? 0 : ((f ? x = -x : 0), 1);\n\
    \        }\n        template <class _Tp>\n        inline void write(_Tp x) {\n\
    \            if (x < 0) putchar('-'), x = -x;\n            if (x > 9) write(x\
    \ / 10);\n            putchar((x % 10) ^ 48);\n        }\n        template <typename\
    \ T, typename... V>\n        inline void read(T &t, V &...v) { read(t), read(v...);\
    \ }\n        template <typename T, typename... V>\n        inline void write(T\
    \ t, V... v) {\n            write(t), putchar(' '), write(v...);\n        }\n\
    \    }\n}\nusing namespace fastIO::usr;\n"
  code: "#include <bits/stdc++.h>\n\nnamespace fastIO {\n    char c, f, e = 0;\n \
    \   namespace usr {\n        template <class _Tp>\n        inline int read(_Tp\
    \ &x) {\n            x = f = 0, c = getchar();\n            while (!isdigit(c)\
    \ && !e) f = c == '-', e |= c == EOF, c = getchar();\n            while (isdigit(c)\
    \ && !e) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();\n            return\
    \ (e |= c == EOF) ? 0 : ((f ? x = -x : 0), 1);\n        }\n        template <class\
    \ _Tp>\n        inline void write(_Tp x) {\n            if (x < 0) putchar('-'),\
    \ x = -x;\n            if (x > 9) write(x / 10);\n            putchar((x % 10)\
    \ ^ 48);\n        }\n        template <typename T, typename... V>\n        inline\
    \ void read(T &t, V &...v) { read(t), read(v...); }\n        template <typename\
    \ T, typename... V>\n        inline void write(T t, V... v) {\n            write(t),\
    \ putchar(' '), write(v...);\n        }\n    }\n}\nusing namespace fastIO::usr;"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/config/fast-io.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/config/fast-io.hpp
layout: document
redirect_from:
- /library/src/alfred/config/fast-io.hpp
- /library/src/alfred/config/fast-io.hpp.html
title: src/alfred/config/fast-io.hpp
---
