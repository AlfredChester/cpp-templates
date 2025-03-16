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
    - https://qoj.ac/submission/179994
    - https://qoj.ac/submission/222042
  bundledCode: "#line 1 \"src/jiangly/others/04B-Binary-Search.hpp\"\n/**   \u4E8C\
    \u5206\u7B97\u6CD5\uFF08\u5B9E\u6570\u57DF\uFF09\r\n *    2023-10-21: https://qoj.ac/submission/222042\r\
    \n**/\r\nauto check = [&](double t) {\r\n    // write\r\n};\r\n\r\ndouble lo =\
    \ 0;\r\ndouble hi = 1E12;\r\nwhile (hi - lo > std::max(1.0, lo) * eps) {\r\n \
    \   double x = (lo + hi) / 2;\r\n    if (check(x)) {\r\n        hi = x;\r\n  \
    \  } else {\r\n        lo = x;\r\n    }\r\n}\r\n\r\nstd::cout << lo << \"\\n\"\
    ;\r\n\r\n/**   \u4E8C\u5206\u7B97\u6CD5\uFF08\u5B9E\u6570\u57DF\uFF09\r\n *  \
    \  2023-09-15: https://qoj.ac/submission/179994\r\n**/\r\nusing i64 = long long;\r\
    \nusing real = long double;\r\n\r\nconstexpr real eps = 1E-7;\r\n\r\nauto get\
    \ = [&](const auto &f) {\r\n    real lo = -1E4, hi = 1E4;\r\n    while (hi - lo\
    \ > 3 * eps) {\r\n        real x1 = (lo + hi - eps) / 2;\r\n        real x2 =\
    \ (lo + hi + eps) / 2;\r\n        if (f(x1) > f(x2)) {\r\n            lo = x1;\r\
    \n        } else {\r\n            hi = x2;\r\n        }\r\n    }\r\n    return\
    \ f((lo + hi) / 2);\r\n};\r\n\r\nstd::cout << get([&](real px) {\r\n    return\
    \ get([&](real py) {\r\n        // write\r\n    });\r\n}) << \"\\n\";\n"
  code: "/**   \u4E8C\u5206\u7B97\u6CD5\uFF08\u5B9E\u6570\u57DF\uFF09\r\n *    2023-10-21:\
    \ https://qoj.ac/submission/222042\r\n**/\r\nauto check = [&](double t) {\r\n\
    \    // write\r\n};\r\n\r\ndouble lo = 0;\r\ndouble hi = 1E12;\r\nwhile (hi -\
    \ lo > std::max(1.0, lo) * eps) {\r\n    double x = (lo + hi) / 2;\r\n    if (check(x))\
    \ {\r\n        hi = x;\r\n    } else {\r\n        lo = x;\r\n    }\r\n}\r\n\r\n\
    std::cout << lo << \"\\n\";\r\n\r\n/**   \u4E8C\u5206\u7B97\u6CD5\uFF08\u5B9E\u6570\
    \u57DF\uFF09\r\n *    2023-09-15: https://qoj.ac/submission/179994\r\n**/\r\n\
    using i64 = long long;\r\nusing real = long double;\r\n\r\nconstexpr real eps\
    \ = 1E-7;\r\n\r\nauto get = [&](const auto &f) {\r\n    real lo = -1E4, hi = 1E4;\r\
    \n    while (hi - lo > 3 * eps) {\r\n        real x1 = (lo + hi - eps) / 2;\r\n\
    \        real x2 = (lo + hi + eps) / 2;\r\n        if (f(x1) > f(x2)) {\r\n  \
    \          lo = x1;\r\n        } else {\r\n            hi = x2;\r\n        }\r\
    \n    }\r\n    return f((lo + hi) / 2);\r\n};\r\n\r\nstd::cout << get([&](real\
    \ px) {\r\n    return get([&](real py) {\r\n        // write\r\n    });\r\n})\
    \ << \"\\n\";"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/others/04B-Binary-Search.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/others/04B-Binary-Search.hpp
layout: document
redirect_from:
- /library/src/jiangly/others/04B-Binary-Search.hpp
- /library/src/jiangly/others/04B-Binary-Search.hpp.html
title: src/jiangly/others/04B-Binary-Search.hpp
---
