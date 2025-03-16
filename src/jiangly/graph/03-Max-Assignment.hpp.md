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
    - https://atcoder.jp/contests/abc247/submissions/30867023
    - https://qoj.ac/submission/184824
  bundledCode: "#line 1 \"src/jiangly/graph/03-Max-Assignment.hpp\"\n/**   \u4E8C\u5206\
    \u56FE\u6700\u5927\u6743\u5339\u914D\uFF08MaxAssignment \u57FA\u4E8EKM\uFF09\r\
    \n *    2022-04-10: https://atcoder.jp/contests/abc247/submissions/30867023\r\n\
    \ *    2023-09-21: https://qoj.ac/submission/184824\r\n**/\r\nconstexpr int inf\
    \ = 1E7;\r\ntemplate<class T>\r\nstruct MaxAssignment {\r\n    public:\r\n   \
    \     T solve(int nx, int ny, std::vector<std::vector<T>> a) {\r\n           \
    \ assert(0 <= nx && nx <= ny);\r\n            assert(int(a.size()) == nx);\r\n\
    \            for (int i = 0; i < nx; ++i) {\r\n                assert(int(a[i].size())\
    \ == ny);\r\n                for (auto x : a[i])\r\n                    assert(x\
    \ >= 0);\r\n            }\r\n            \r\n            auto update = [&](int\
    \ x) {\r\n                for (int y = 0; y < ny; ++y) {\r\n                 \
    \   if (lx[x] + ly[y] - a[x][y] < slack[y]) {\r\n                        slack[y]\
    \ = lx[x] + ly[y] - a[x][y];\r\n                        slackx[y] = x;\r\n   \
    \                 }\r\n                }\r\n            };\r\n            \r\n\
    \            costs.resize(nx + 1);\r\n            costs[0] = 0;\r\n          \
    \  lx.assign(nx, std::numeric_limits<T>::max());\r\n            ly.assign(ny,\
    \ 0);\r\n            xy.assign(nx, -1);\r\n            yx.assign(ny, -1);\r\n\
    \            slackx.resize(ny);\r\n            for (int cur = 0; cur < nx; ++cur)\
    \ {\r\n                std::queue<int> que;\r\n                visx.assign(nx,\
    \ false);\r\n                visy.assign(ny, false);\r\n                slack.assign(ny,\
    \ std::numeric_limits<T>::max());\r\n                p.assign(nx, -1);\r\n   \
    \             \r\n                for (int x = 0; x < nx; ++x) {\r\n         \
    \           if (xy[x] == -1) {\r\n                        que.push(x);\r\n   \
    \                     visx[x] = true;\r\n                        update(x);\r\n\
    \                    }\r\n                }\r\n                \r\n          \
    \      int ex, ey;\r\n                bool found = false;\r\n                while\
    \ (!found) {\r\n                    while (!que.empty() && !found) {\r\n     \
    \                   auto x = que.front();\r\n                        que.pop();\r\
    \n                        for (int y = 0; y < ny; ++y) {\r\n                 \
    \           if (a[x][y] == lx[x] + ly[y] && !visy[y]) {\r\n                  \
    \              if (yx[y] == -1) {\r\n                                    ex =\
    \ x;\r\n                                    ey = y;\r\n                      \
    \              found = true;\r\n                                    break;\r\n\
    \                                }\r\n                                que.push(yx[y]);\r\
    \n                                p[yx[y]] = x;\r\n                          \
    \      visy[y] = visx[yx[y]] = true;\r\n                                update(yx[y]);\r\
    \n                            }\r\n                        }\r\n             \
    \       }\r\n                    if (found)\r\n                        break;\r\
    \n                    \r\n                    T delta = std::numeric_limits<T>::max();\r\
    \n                    for (int y = 0; y < ny; ++y)\r\n                       \
    \ if (!visy[y])\r\n                            delta = std::min(delta, slack[y]);\r\
    \n                    for (int x = 0; x < nx; ++x)\r\n                       \
    \ if (visx[x])\r\n                            lx[x] -= delta;\r\n            \
    \        for (int y = 0; y < ny; ++y) {\r\n                        if (visy[y])\
    \ {\r\n                            ly[y] += delta;\r\n                       \
    \ } else {\r\n                            slack[y] -= delta;\r\n             \
    \           }\r\n                    }\r\n                    for (int y = 0;\
    \ y < ny; ++y) {\r\n                        if (!visy[y] && slack[y] == 0) {\r\
    \n                            if (yx[y] == -1) {\r\n                         \
    \       ex = slackx[y];\r\n                                ey = y;\r\n       \
    \                         found = true;\r\n                                break;\r\
    \n                            }\r\n                            que.push(yx[y]);\r\
    \n                            p[yx[y]] = slackx[y];\r\n                      \
    \      visy[y] = visx[yx[y]] = true;\r\n                            update(yx[y]);\r\
    \n                        }\r\n                    }\r\n                }\r\n\
    \                \r\n                costs[cur + 1] = costs[cur];\r\n        \
    \        for (int x = ex, y = ey, ty; x != -1; x = p[x], y = ty) {\r\n       \
    \             costs[cur + 1] += a[x][y];\r\n                    if (xy[x] != -1)\r\
    \n                        costs[cur + 1] -= a[x][xy[x]];\r\n                 \
    \   ty = xy[x];\r\n                    xy[x] = y;\r\n                    yx[y]\
    \ = x;\r\n                }\r\n            }\r\n            return costs[nx];\r\
    \n        }\r\n        std::vector<int> assignment() {\r\n            return xy;\r\
    \n        }\r\n        std::pair<std::vector<T>, std::vector<T>> labels() {\r\n\
    \            return std::make_pair(lx, ly);\r\n        }\r\n        std::vector<T>\
    \ weights() {\r\n            return costs;\r\n        }\r\n    private:\r\n  \
    \      std::vector<T> lx, ly, slack, costs;\r\n        std::vector<int> xy, yx,\
    \ p, slackx;\r\n        std::vector<bool> visx, visy;\r\n};\n"
  code: "/**   \u4E8C\u5206\u56FE\u6700\u5927\u6743\u5339\u914D\uFF08MaxAssignment\
    \ \u57FA\u4E8EKM\uFF09\r\n *    2022-04-10: https://atcoder.jp/contests/abc247/submissions/30867023\r\
    \n *    2023-09-21: https://qoj.ac/submission/184824\r\n**/\r\nconstexpr int inf\
    \ = 1E7;\r\ntemplate<class T>\r\nstruct MaxAssignment {\r\n    public:\r\n   \
    \     T solve(int nx, int ny, std::vector<std::vector<T>> a) {\r\n           \
    \ assert(0 <= nx && nx <= ny);\r\n            assert(int(a.size()) == nx);\r\n\
    \            for (int i = 0; i < nx; ++i) {\r\n                assert(int(a[i].size())\
    \ == ny);\r\n                for (auto x : a[i])\r\n                    assert(x\
    \ >= 0);\r\n            }\r\n            \r\n            auto update = [&](int\
    \ x) {\r\n                for (int y = 0; y < ny; ++y) {\r\n                 \
    \   if (lx[x] + ly[y] - a[x][y] < slack[y]) {\r\n                        slack[y]\
    \ = lx[x] + ly[y] - a[x][y];\r\n                        slackx[y] = x;\r\n   \
    \                 }\r\n                }\r\n            };\r\n            \r\n\
    \            costs.resize(nx + 1);\r\n            costs[0] = 0;\r\n          \
    \  lx.assign(nx, std::numeric_limits<T>::max());\r\n            ly.assign(ny,\
    \ 0);\r\n            xy.assign(nx, -1);\r\n            yx.assign(ny, -1);\r\n\
    \            slackx.resize(ny);\r\n            for (int cur = 0; cur < nx; ++cur)\
    \ {\r\n                std::queue<int> que;\r\n                visx.assign(nx,\
    \ false);\r\n                visy.assign(ny, false);\r\n                slack.assign(ny,\
    \ std::numeric_limits<T>::max());\r\n                p.assign(nx, -1);\r\n   \
    \             \r\n                for (int x = 0; x < nx; ++x) {\r\n         \
    \           if (xy[x] == -1) {\r\n                        que.push(x);\r\n   \
    \                     visx[x] = true;\r\n                        update(x);\r\n\
    \                    }\r\n                }\r\n                \r\n          \
    \      int ex, ey;\r\n                bool found = false;\r\n                while\
    \ (!found) {\r\n                    while (!que.empty() && !found) {\r\n     \
    \                   auto x = que.front();\r\n                        que.pop();\r\
    \n                        for (int y = 0; y < ny; ++y) {\r\n                 \
    \           if (a[x][y] == lx[x] + ly[y] && !visy[y]) {\r\n                  \
    \              if (yx[y] == -1) {\r\n                                    ex =\
    \ x;\r\n                                    ey = y;\r\n                      \
    \              found = true;\r\n                                    break;\r\n\
    \                                }\r\n                                que.push(yx[y]);\r\
    \n                                p[yx[y]] = x;\r\n                          \
    \      visy[y] = visx[yx[y]] = true;\r\n                                update(yx[y]);\r\
    \n                            }\r\n                        }\r\n             \
    \       }\r\n                    if (found)\r\n                        break;\r\
    \n                    \r\n                    T delta = std::numeric_limits<T>::max();\r\
    \n                    for (int y = 0; y < ny; ++y)\r\n                       \
    \ if (!visy[y])\r\n                            delta = std::min(delta, slack[y]);\r\
    \n                    for (int x = 0; x < nx; ++x)\r\n                       \
    \ if (visx[x])\r\n                            lx[x] -= delta;\r\n            \
    \        for (int y = 0; y < ny; ++y) {\r\n                        if (visy[y])\
    \ {\r\n                            ly[y] += delta;\r\n                       \
    \ } else {\r\n                            slack[y] -= delta;\r\n             \
    \           }\r\n                    }\r\n                    for (int y = 0;\
    \ y < ny; ++y) {\r\n                        if (!visy[y] && slack[y] == 0) {\r\
    \n                            if (yx[y] == -1) {\r\n                         \
    \       ex = slackx[y];\r\n                                ey = y;\r\n       \
    \                         found = true;\r\n                                break;\r\
    \n                            }\r\n                            que.push(yx[y]);\r\
    \n                            p[yx[y]] = slackx[y];\r\n                      \
    \      visy[y] = visx[yx[y]] = true;\r\n                            update(yx[y]);\r\
    \n                        }\r\n                    }\r\n                }\r\n\
    \                \r\n                costs[cur + 1] = costs[cur];\r\n        \
    \        for (int x = ex, y = ey, ty; x != -1; x = p[x], y = ty) {\r\n       \
    \             costs[cur + 1] += a[x][y];\r\n                    if (xy[x] != -1)\r\
    \n                        costs[cur + 1] -= a[x][xy[x]];\r\n                 \
    \   ty = xy[x];\r\n                    xy[x] = y;\r\n                    yx[y]\
    \ = x;\r\n                }\r\n            }\r\n            return costs[nx];\r\
    \n        }\r\n        std::vector<int> assignment() {\r\n            return xy;\r\
    \n        }\r\n        std::pair<std::vector<T>, std::vector<T>> labels() {\r\n\
    \            return std::make_pair(lx, ly);\r\n        }\r\n        std::vector<T>\
    \ weights() {\r\n            return costs;\r\n        }\r\n    private:\r\n  \
    \      std::vector<T> lx, ly, slack, costs;\r\n        std::vector<int> xy, yx,\
    \ p, slackx;\r\n        std::vector<bool> visx, visy;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/graph/03-Max-Assignment.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/graph/03-Max-Assignment.hpp
layout: document
redirect_from:
- /library/src/jiangly/graph/03-Max-Assignment.hpp
- /library/src/jiangly/graph/03-Max-Assignment.hpp.html
title: src/jiangly/graph/03-Max-Assignment.hpp
---
