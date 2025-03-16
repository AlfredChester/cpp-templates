---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Local Debug Printer
    links: []
  bundledCode: "#line 1 \"src/alfred/config/debug.h\"\n/**\n * @file        debug.h\n\
    \ * @author      Dr.Alfred (abonlinejudge@163.com)\n * @brief       Local Debug\
    \ Printer\n * @version     1.0\n * @date        2023-12-30\n *\n * @copyright\
    \   Copyright (c) 2019-now <Rhodes Island Inc.>\n *\n */\n\n#include <bits/stdc++.h>\n\
    \nusing std::cerr;\nusing std::pair;\nusing std::string;\n\nconst long long dbg_inf\
    \ = 9e18 + 19260817;\n\nvoid __print(int x) { cerr << x; }\nvoid __print(long\
    \ x) { cerr << x; }\nvoid __print(long long x) {\n    if (x != dbg_inf) {\n  \
    \      cerr << x;\n    } else {\n        cerr << \"inf\";\n    }\n}\nvoid __print(unsigned\
    \ x) { cerr << x; }\nvoid __print(unsigned long x) { cerr << x; }\nvoid __print(unsigned\
    \ long long x) { cerr << x; }\nvoid __print(float x) { cerr << x; }\nvoid __print(double\
    \ x) { cerr << x; }\nvoid __print(long double x) { cerr << x; }\nvoid __print(char\
    \ x) { cerr << '\\'' << x << '\\''; }\nvoid __print(const char *x) { cerr << '\\\
    \"' << x << '\\\"'; }\nvoid __print(const string &x) { cerr << '\\\"' << x <<\
    \ '\\\"'; }\nvoid __print(bool x) { cerr << (x ? \"true\" : \"false\"); }\nvoid\
    \ __print(__int128_t x) {\n    if (x < 0) cerr << '-', x = -x;\n    if (x > 9)\
    \ __print(x / 10);\n    cerr << char((x % 10) ^ 48);\n}\nvoid dbgEndl(void) {\
    \ cerr << '\\n'; }\n\ntemplate <typename T, typename V>\nvoid __print(const pair<T,\
    \ V> &x) {\n    cerr << '{', __print(x.first), cerr << \", \", __print(x.second),\
    \ cerr << '}';\n}\ntemplate <typename T>\nvoid __print(const T &x) {\n    int\
    \ f = 0;\n    cerr << '{';\n    for (auto i : x) cerr << (f++ ? \", \" : \"\"\
    ), __print(i);\n    cerr << \"}\";\n}\nvoid _print() { cerr << \"]\\n\"; }\ntemplate\
    \ <typename T, typename... V>\nvoid _print(T t, V... v) {\n    __print(t);\n \
    \   if (sizeof...(v)) cerr << \", \";\n    _print(v...);\n}\n// To customize a\
    \ struct/class to print, just define the __print function.\n\n#if defined(DEBUG)\
    \ && !defined(NO_DBG_COLOR)\n#define dbg(x...)                               \
    \                              \\\n    cerr << \"\\e[91m\" << __func__ << \":\"\
    \ << __LINE__ << \" [\" << #x << \"] = [\"; \\\n    _print(x);               \
    \                                                 \\\n    cerr << \"\\e[39m\"\
    ;\n\n#define short_dbg(x...) \\\n    cerr << \"\\e[91m[[\"; \\\n    _print(x);\
    \          \\\n    cerr << \"\\e[39m\";\n#elif defined(DEBUG)\n#define dbg(x...)\
    \                                                 \\\n    cerr << __func__ <<\
    \ \":\" << __LINE__ << \" [\" << #x << \"] = [\"; \\\n    _print(x);\n#define\
    \ short_dbg(x...) \\\n    cerr << \"[\";        \\\n    _print(x);\n#else\n#define\
    \ dbg(x...)\n#endif // !DEBUG\n"
  code: "/**\n * @file        debug.h\n * @author      Dr.Alfred (abonlinejudge@163.com)\n\
    \ * @brief       Local Debug Printer\n * @version     1.0\n * @date        2023-12-30\n\
    \ *\n * @copyright   Copyright (c) 2019-now <Rhodes Island Inc.>\n *\n */\n\n\
    #include <bits/stdc++.h>\n\nusing std::cerr;\nusing std::pair;\nusing std::string;\n\
    \nconst long long dbg_inf = 9e18 + 19260817;\n\nvoid __print(int x) { cerr <<\
    \ x; }\nvoid __print(long x) { cerr << x; }\nvoid __print(long long x) {\n   \
    \ if (x != dbg_inf) {\n        cerr << x;\n    } else {\n        cerr << \"inf\"\
    ;\n    }\n}\nvoid __print(unsigned x) { cerr << x; }\nvoid __print(unsigned long\
    \ x) { cerr << x; }\nvoid __print(unsigned long long x) { cerr << x; }\nvoid __print(float\
    \ x) { cerr << x; }\nvoid __print(double x) { cerr << x; }\nvoid __print(long\
    \ double x) { cerr << x; }\nvoid __print(char x) { cerr << '\\'' << x << '\\'';\
    \ }\nvoid __print(const char *x) { cerr << '\\\"' << x << '\\\"'; }\nvoid __print(const\
    \ string &x) { cerr << '\\\"' << x << '\\\"'; }\nvoid __print(bool x) { cerr <<\
    \ (x ? \"true\" : \"false\"); }\nvoid __print(__int128_t x) {\n    if (x < 0)\
    \ cerr << '-', x = -x;\n    if (x > 9) __print(x / 10);\n    cerr << char((x %\
    \ 10) ^ 48);\n}\nvoid dbgEndl(void) { cerr << '\\n'; }\n\ntemplate <typename T,\
    \ typename V>\nvoid __print(const pair<T, V> &x) {\n    cerr << '{', __print(x.first),\
    \ cerr << \", \", __print(x.second), cerr << '}';\n}\ntemplate <typename T>\n\
    void __print(const T &x) {\n    int f = 0;\n    cerr << '{';\n    for (auto i\
    \ : x) cerr << (f++ ? \", \" : \"\"), __print(i);\n    cerr << \"}\";\n}\nvoid\
    \ _print() { cerr << \"]\\n\"; }\ntemplate <typename T, typename... V>\nvoid _print(T\
    \ t, V... v) {\n    __print(t);\n    if (sizeof...(v)) cerr << \", \";\n    _print(v...);\n\
    }\n// To customize a struct/class to print, just define the __print function.\n\
    \n#if defined(DEBUG) && !defined(NO_DBG_COLOR)\n#define dbg(x...)            \
    \                                                 \\\n    cerr << \"\\e[91m\"\
    \ << __func__ << \":\" << __LINE__ << \" [\" << #x << \"] = [\"; \\\n    _print(x);\
    \                                                                \\\n    cerr\
    \ << \"\\e[39m\";\n\n#define short_dbg(x...) \\\n    cerr << \"\\e[91m[[\"; \\\
    \n    _print(x);          \\\n    cerr << \"\\e[39m\";\n#elif defined(DEBUG)\n\
    #define dbg(x...)                                                 \\\n    cerr\
    \ << __func__ << \":\" << __LINE__ << \" [\" << #x << \"] = [\"; \\\n    _print(x);\n\
    #define short_dbg(x...) \\\n    cerr << \"[\";        \\\n    _print(x);\n#else\n\
    #define dbg(x...)\n#endif // !DEBUG\n"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/config/debug.h
  requiredBy: []
  timestamp: '2025-02-17 23:55:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/config/debug.h
layout: document
redirect_from:
- /library/src/alfred/config/debug.h
- /library/src/alfred/config/debug.h.html
title: Local Debug Printer
---
