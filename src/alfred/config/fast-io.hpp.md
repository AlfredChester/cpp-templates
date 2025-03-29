---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aizu-graph/aizu-lca.test.cpp
    title: verify/verify-aizu-graph/aizu-lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/alfred/config/fast-io.hpp\"\n#include <iostream>\n\n\
    class FastIO {\nprivate:\n    int siz = 100000;\n    char *buf, *p1, *p2;\n\n\
    public:\n    inline char nc(void) {\n        return p1 == p2 && (p2 = (p1 = buf)\
    \ + fread(buf, 1, siz, stdin), p1 == p2) ? EOF : *p1++;\n    }\n    inline void\
    \ pc(char c) { putchar(c); }\n    FastIO(void) { buf = (char *)malloc(siz); }\n\
    \    FastIO(int n) : siz(n) { buf = (char *)malloc(siz); } // n characters.\n\
    \    ~FastIO(void) { free(buf); }\n    inline void resize(int n) {\n        siz\
    \ = n;\n        buf = (char *)realloc(buf, siz);\n    }\n} __buf;\n\ninline void\
    \ reset_size(int siz) {\n    __buf.resize(siz);\n}\n\ntemplate <class T>\ninline\
    \ void fast_read(T &x) {\n    x = 0;\n    static char c = __buf.nc();\n    while\
    \ (c < '0' || c > '9') c = __buf.nc();\n    while (c >= '0' && c <= '9') {\n \
    \       x = (x << 1) + (x << 3) + (c ^ 48), c = __buf.nc();\n    }\n}\ntemplate\
    \ <class T>\ninline void write(T x) {\n    if (x < 0) putchar('-'), x = -x;\n\
    \    if (x > 9) write(x / 10);\n    putchar((x % 10) ^ 48);\n}\ntemplate <class\
    \ T>\ninline void writeln(T x) {\n    write(x), puts(\"\");\n}\ntemplate <typename\
    \ T, typename... V>\ninline void writeln(T x, V... v) {\n    write(x), putchar('\
    \ '), writeln(v...);\n}\ntemplate <typename T, typename... V>\ninline void fast_read(T\
    \ &t, V &...v) {\n    fast_read(t), fast_read(v...);\n}\n"
  code: "#include <iostream>\n\nclass FastIO {\nprivate:\n    int siz = 100000;\n\
    \    char *buf, *p1, *p2;\n\npublic:\n    inline char nc(void) {\n        return\
    \ p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, siz, stdin), p1 == p2) ? EOF :\
    \ *p1++;\n    }\n    inline void pc(char c) { putchar(c); }\n    FastIO(void)\
    \ { buf = (char *)malloc(siz); }\n    FastIO(int n) : siz(n) { buf = (char *)malloc(siz);\
    \ } // n characters.\n    ~FastIO(void) { free(buf); }\n    inline void resize(int\
    \ n) {\n        siz = n;\n        buf = (char *)realloc(buf, siz);\n    }\n} __buf;\n\
    \ninline void reset_size(int siz) {\n    __buf.resize(siz);\n}\n\ntemplate <class\
    \ T>\ninline void fast_read(T &x) {\n    x = 0;\n    static char c = __buf.nc();\n\
    \    while (c < '0' || c > '9') c = __buf.nc();\n    while (c >= '0' && c <= '9')\
    \ {\n        x = (x << 1) + (x << 3) + (c ^ 48), c = __buf.nc();\n    }\n}\ntemplate\
    \ <class T>\ninline void write(T x) {\n    if (x < 0) putchar('-'), x = -x;\n\
    \    if (x > 9) write(x / 10);\n    putchar((x % 10) ^ 48);\n}\ntemplate <class\
    \ T>\ninline void writeln(T x) {\n    write(x), puts(\"\");\n}\ntemplate <typename\
    \ T, typename... V>\ninline void writeln(T x, V... v) {\n    write(x), putchar('\
    \ '), writeln(v...);\n}\ntemplate <typename T, typename... V>\ninline void fast_read(T\
    \ &t, V &...v) {\n    fast_read(t), fast_read(v...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/config/fast-io.hpp
  requiredBy: []
  timestamp: '2025-03-29 12:01:17+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aizu-graph/aizu-lca.test.cpp
documentation_of: src/alfred/config/fast-io.hpp
layout: document
redirect_from:
- /library/src/alfred/config/fast-io.hpp
- /library/src/alfred/config/fast-io.hpp.html
title: src/alfred/config/fast-io.hpp
---
