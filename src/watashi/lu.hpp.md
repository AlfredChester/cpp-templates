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
  bundledCode: "#line 1 \"src/watashi/lu.hpp\"\nconst int MAXN = 128;\nconst double\
    \ EPS = 1e-10;\n\nvoid LU(int n, double a[MAXN][MAXN], int r[MAXN], int c[MAXN])\
    \ {\n    for (int i = 0; i < n; ++i) {\n        r[i] = c[i] = i;\n    }\n    for\
    \ (int k = 0; k < n; ++k) {\n        int ii = k, jj = k;\n        for (int i =\
    \ k; i < n; ++i) {\n            for (int j = k; j < n; ++j) {\n              \
    \  if (fabs(a[i][j]) > fabs(a[ii][jj])) {\n                    ii = i;\n     \
    \               jj = j;\n                }\n            }\n        }\n       \
    \ swap(r[k], r[ii]);\n        swap(c[k], c[jj]);\n        for (int i = 0; i <\
    \ n; ++i) {\n            swap(a[i][k], a[i][jj]);\n        }\n        for (int\
    \ j = 0; j < n; ++j) {\n            swap(a[k][j], a[ii][j]);\n        }\n    \
    \    if (fabs(a[k][k]) < EPS) {\n            continue;\n        }\n        for\
    \ (int i = k + 1; i < n; ++i) {\n            a[i][k] = a[i][k] / a[k][k];\n  \
    \          for (int j = k + 1; j < n; ++j) {\n                a[i][j] -= a[i][k]\
    \ * a[k][j];\n            }\n        }\n    }\n}\n\nvoid solve(int n, double a[MAXN][MAXN],\
    \ int r[MAXN], int c[MAXN], double b[MAXN]) {\n    static double x[MAXN];\n  \
    \  for (int i = 0; i < n; ++i) {\n        x[i] = b[r[i]];\n    }\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int j = 0; j < i; ++j) {\n            x[i]\
    \ -= a[i][j] * x[j];\n        }\n    }\n    for (int i = n - 1; i >= 0; --i) {\n\
    \        for (int j = n - 1; j > i; --j) {\n            x[i] -= a[i][j] * x[j];\n\
    \        }\n        if (fabs(a[i][i]) >= EPS) {\n            x[i] /= a[i][i];\n\
    \        } // else assert(fabs(x[i]) < EPS);\n    }\n    for (int i = 0; i < n;\
    \ ++i) {\n        b[c[i]] = x[i];\n    }\n}\n\n// LU(n - 1, a, r, c);\n// solve(n\
    \ - 1, a, r, c, b);\n"
  code: "const int MAXN = 128;\nconst double EPS = 1e-10;\n\nvoid LU(int n, double\
    \ a[MAXN][MAXN], int r[MAXN], int c[MAXN]) {\n    for (int i = 0; i < n; ++i)\
    \ {\n        r[i] = c[i] = i;\n    }\n    for (int k = 0; k < n; ++k) {\n    \
    \    int ii = k, jj = k;\n        for (int i = k; i < n; ++i) {\n            for\
    \ (int j = k; j < n; ++j) {\n                if (fabs(a[i][j]) > fabs(a[ii][jj]))\
    \ {\n                    ii = i;\n                    jj = j;\n              \
    \  }\n            }\n        }\n        swap(r[k], r[ii]);\n        swap(c[k],\
    \ c[jj]);\n        for (int i = 0; i < n; ++i) {\n            swap(a[i][k], a[i][jj]);\n\
    \        }\n        for (int j = 0; j < n; ++j) {\n            swap(a[k][j], a[ii][j]);\n\
    \        }\n        if (fabs(a[k][k]) < EPS) {\n            continue;\n      \
    \  }\n        for (int i = k + 1; i < n; ++i) {\n            a[i][k] = a[i][k]\
    \ / a[k][k];\n            for (int j = k + 1; j < n; ++j) {\n                a[i][j]\
    \ -= a[i][k] * a[k][j];\n            }\n        }\n    }\n}\n\nvoid solve(int\
    \ n, double a[MAXN][MAXN], int r[MAXN], int c[MAXN], double b[MAXN]) {\n    static\
    \ double x[MAXN];\n    for (int i = 0; i < n; ++i) {\n        x[i] = b[r[i]];\n\
    \    }\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < i; ++j)\
    \ {\n            x[i] -= a[i][j] * x[j];\n        }\n    }\n    for (int i = n\
    \ - 1; i >= 0; --i) {\n        for (int j = n - 1; j > i; --j) {\n           \
    \ x[i] -= a[i][j] * x[j];\n        }\n        if (fabs(a[i][i]) >= EPS) {\n  \
    \          x[i] /= a[i][i];\n        } // else assert(fabs(x[i]) < EPS);\n   \
    \ }\n    for (int i = 0; i < n; ++i) {\n        b[c[i]] = x[i];\n    }\n}\n\n\
    // LU(n - 1, a, r, c);\n// solve(n - 1, a, r, c, b);\n"
  dependsOn: []
  isVerificationFile: false
  path: src/watashi/lu.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/watashi/lu.hpp
layout: document
redirect_from:
- /library/src/watashi/lu.hpp
- /library/src/watashi/lu.hpp.html
title: src/watashi/lu.hpp
---
