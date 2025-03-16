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
    - https://atcoder.jp/contests/arc155/submissions/38664055
  bundledCode: "#line 1 \"src/jiangly/math/12A-Poly.hpp\"\n/**   \u591A\u9879\u5F0F\
    \u76F8\u5173\uFF08Poly, with. Z\uFF09\r\n *    2023-02-06: https://atcoder.jp/contests/arc155/submissions/38664055\r\
    \n**/\r\nstd::vector<int> rev;\r\nstd::vector<Z> roots{0, 1};\r\nvoid dft(std::vector<Z>\
    \ &a) {\r\n    int n = a.size();\r\n    \r\n    if (int(rev.size()) != n) {\r\n\
    \        int k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for\
    \ (int i = 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1)\
    \ << k;\r\n        }\r\n    }\r\n    \r\n    for (int i = 0; i < n; i++) {\r\n\
    \        if (rev[i] < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n    \
    \    }\r\n    }\r\n    if (int(roots.size()) < n) {\r\n        int k = __builtin_ctz(roots.size());\r\
    \n        roots.resize(n);\r\n        while ((1 << k) < n) {\r\n            Z\
    \ e = power(Z(3), (P - 1) >> (k + 1));\r\n            for (int i = 1 << (k - 1);\
    \ i < (1 << k); i++) {\r\n                roots[2 * i] = roots[i];\r\n       \
    \         roots[2 * i + 1] = roots[i] * e;\r\n            }\r\n            k++;\r\
    \n        }\r\n    }\r\n    for (int k = 1; k < n; k *= 2) {\r\n        for (int\
    \ i = 0; i < n; i += 2 * k) {\r\n            for (int j = 0; j < k; j++) {\r\n\
    \                Z u = a[i + j];\r\n                Z v = a[i + j + k] * roots[k\
    \ + j];\r\n                a[i + j] = u + v;\r\n                a[i + j + k] =\
    \ u - v;\r\n            }\r\n        }\r\n    }\r\n}\r\nvoid idft(std::vector<Z>\
    \ &a) {\r\n    int n = a.size();\r\n    std::reverse(a.begin() + 1, a.end());\r\
    \n    dft(a);\r\n    Z inv = (1 - P) / n;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        a[i] *= inv;\r\n    }\r\n}\r\nstruct Poly {\r\n    std::vector<Z> a;\r\
    \n    Poly() {}\r\n    explicit Poly(int size, std::function<Z(int)> f = [](int)\
    \ { return 0; }) : a(size) {\r\n        for (int i = 0; i < size; i++) {\r\n \
    \           a[i] = f(i);\r\n        }\r\n    }\r\n    Poly(const std::vector<Z>\
    \ &a) : a(a) {}\r\n    Poly(const std::initializer_list<Z> &a) : a(a) {}\r\n \
    \   int size() const {\r\n        return a.size();\r\n    }\r\n    void resize(int\
    \ n) {\r\n        a.resize(n);\r\n    }\r\n    Z operator[](int idx) const {\r\
    \n        if (idx < size()) {\r\n            return a[idx];\r\n        } else\
    \ {\r\n            return 0;\r\n        }\r\n    }\r\n    Z &operator[](int idx)\
    \ {\r\n        return a[idx];\r\n    }\r\n    Poly mulxk(int k) const {\r\n  \
    \      auto b = a;\r\n        b.insert(b.begin(), k, 0);\r\n        return Poly(b);\r\
    \n    }\r\n    Poly modxk(int k) const {\r\n        k = std::min(k, size());\r\
    \n        return Poly(std::vector<Z>(a.begin(), a.begin() + k));\r\n    }\r\n\
    \    Poly divxk(int k) const {\r\n        if (size() <= k) {\r\n            return\
    \ Poly();\r\n        }\r\n        return Poly(std::vector<Z>(a.begin() + k, a.end()));\r\
    \n    }\r\n    friend Poly operator+(const Poly &a, const Poly &b) {\r\n     \
    \   std::vector<Z> res(std::max(a.size(), b.size()));\r\n        for (int i =\
    \ 0; i < int(res.size()); i++) {\r\n            res[i] = a[i] + b[i];\r\n    \
    \    }\r\n        return Poly(res);\r\n    }\r\n    friend Poly operator-(const\
    \ Poly &a, const Poly &b) {\r\n        std::vector<Z> res(std::max(a.size(), b.size()));\r\
    \n        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] =\
    \ a[i] - b[i];\r\n        }\r\n        return Poly(res);\r\n    }\r\n    friend\
    \ Poly operator-(const Poly &a) {\r\n        std::vector<Z> res(a.size());\r\n\
    \        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] = -a[i];\r\
    \n        }\r\n        return Poly(res);\r\n    }\r\n    friend Poly operator*(Poly\
    \ a, Poly b) {\r\n        if (a.size() == 0 || b.size() == 0) {\r\n          \
    \  return Poly();\r\n        }\r\n        if (a.size() < b.size()) {\r\n     \
    \       std::swap(a, b);\r\n        }\r\n        if (b.size() < 128) {\r\n   \
    \         Poly c(a.size() + b.size() - 1);\r\n            for (int i = 0; i <\
    \ a.size(); i++) {\r\n                for (int j = 0; j < b.size(); j++) {\r\n\
    \                    c[i + j] += a[i] * b[j];\r\n                }\r\n       \
    \     }\r\n            return c;\r\n        }\r\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\r\n        while (sz < tot) {\r\n            sz *= 2;\r\n  \
    \      }\r\n        a.a.resize(sz);\r\n        b.a.resize(sz);\r\n        dft(a.a);\r\
    \n        dft(b.a);\r\n        for (int i = 0; i < sz; ++i) {\r\n            a.a[i]\
    \ = a[i] * b[i];\r\n        }\r\n        idft(a.a);\r\n        a.resize(tot);\r\
    \n        return a;\r\n    }\r\n    friend Poly operator*(Z a, Poly b) {\r\n \
    \       for (int i = 0; i < int(b.size()); i++) {\r\n            b[i] *= a;\r\n\
    \        }\r\n        return b;\r\n    }\r\n    friend Poly operator*(Poly a,\
    \ Z b) {\r\n        for (int i = 0; i < int(a.size()); i++) {\r\n            a[i]\
    \ *= b;\r\n        }\r\n        return a;\r\n    }\r\n    Poly &operator+=(Poly\
    \ b) {\r\n        return (*this) = (*this) + b;\r\n    }\r\n    Poly &operator-=(Poly\
    \ b) {\r\n        return (*this) = (*this) - b;\r\n    }\r\n    Poly &operator*=(Poly\
    \ b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n    Poly &operator*=(Z\
    \ b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n    Poly deriv() const\
    \ {\r\n        if (a.empty()) {\r\n            return Poly();\r\n        }\r\n\
    \        std::vector<Z> res(size() - 1);\r\n        for (int i = 0; i < size()\
    \ - 1; ++i) {\r\n            res[i] = (i + 1) * a[i + 1];\r\n        }\r\n   \
    \     return Poly(res);\r\n    }\r\n    Poly integr() const {\r\n        std::vector<Z>\
    \ res(size() + 1);\r\n        for (int i = 0; i < size(); ++i) {\r\n         \
    \   res[i + 1] = a[i] / (i + 1);\r\n        }\r\n        return Poly(res);\r\n\
    \    }\r\n    Poly inv(int m) const {\r\n        Poly x{a[0].inv()};\r\n     \
    \   int k = 1;\r\n        while (k < m) {\r\n            k *= 2;\r\n         \
    \   x = (x * (Poly{2} - modxk(k) * x)).modxk(k);\r\n        }\r\n        return\
    \ x.modxk(m);\r\n    }\r\n    Poly log(int m) const {\r\n        return (deriv()\
    \ * inv(m)).integr().modxk(m);\r\n    }\r\n    Poly exp(int m) const {\r\n   \
    \     Poly x{1};\r\n        int k = 1;\r\n        while (k < m) {\r\n        \
    \    k *= 2;\r\n            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);\r\
    \n        }\r\n        return x.modxk(m);\r\n    }\r\n    Poly pow(int k, int\
    \ m) const {\r\n        int i = 0;\r\n        while (i < size() && a[i].val()\
    \ == 0) {\r\n            i++;\r\n        }\r\n        if (i == size() || 1LL *\
    \ i * k >= m) {\r\n            return Poly(std::vector<Z>(m));\r\n        }\r\n\
    \        Z v = a[i];\r\n        auto f = divxk(i) * v.inv();\r\n        return\
    \ (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);\r\n    }\r\
    \n    Poly sqrt(int m) const {\r\n        Poly x{1};\r\n        int k = 1;\r\n\
    \        while (k < m) {\r\n            k *= 2;\r\n            x = (x + (modxk(k)\
    \ * x.inv(k)).modxk(k)) * ((P + 1) / 2);\r\n        }\r\n        return x.modxk(m);\r\
    \n    }\r\n    Poly mulT(Poly b) const {\r\n        if (b.size() == 0) {\r\n \
    \           return Poly();\r\n        }\r\n        int n = b.size();\r\n     \
    \   std::reverse(b.a.begin(), b.a.end());\r\n        return ((*this) * b).divxk(n\
    \ - 1);\r\n    }\r\n    std::vector<Z> eval(std::vector<Z> x) const {\r\n    \
    \    if (size() == 0) {\r\n            return std::vector<Z>(x.size(), 0);\r\n\
    \        }\r\n        const int n = std::max(int(x.size()), size());\r\n     \
    \   std::vector<Poly> q(4 * n);\r\n        std::vector<Z> ans(x.size());\r\n \
    \       x.resize(n);\r\n        std::function<void(int, int, int)> build = [&](int\
    \ p, int l, int r) {\r\n            if (r - l == 1) {\r\n                q[p]\
    \ = Poly{1, -x[l]};\r\n            } else {\r\n                int m = (l + r)\
    \ / 2;\r\n                build(2 * p, l, m);\r\n                build(2 * p +\
    \ 1, m, r);\r\n                q[p] = q[2 * p] * q[2 * p + 1];\r\n           \
    \ }\r\n        };\r\n        build(1, 0, n);\r\n        std::function<void(int,\
    \ int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {\r\
    \n            if (r - l == 1) {\r\n                if (l < int(ans.size())) {\r\
    \n                    ans[l] = num[0];\r\n                }\r\n            } else\
    \ {\r\n                int m = (l + r) / 2;\r\n                work(2 * p, l,\
    \ m, num.mulT(q[2 * p + 1]).modxk(m - l));\r\n                work(2 * p + 1,\
    \ m, r, num.mulT(q[2 * p]).modxk(r - m));\r\n            }\r\n        };\r\n \
    \       work(1, 0, n, mulT(q[1].inv(n)));\r\n        return ans;\r\n    }\r\n\
    };\n"
  code: "/**   \u591A\u9879\u5F0F\u76F8\u5173\uFF08Poly, with. Z\uFF09\r\n *    2023-02-06:\
    \ https://atcoder.jp/contests/arc155/submissions/38664055\r\n**/\r\nstd::vector<int>\
    \ rev;\r\nstd::vector<Z> roots{0, 1};\r\nvoid dft(std::vector<Z> &a) {\r\n   \
    \ int n = a.size();\r\n    \r\n    if (int(rev.size()) != n) {\r\n        int\
    \ k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\r\n\
    \        }\r\n    }\r\n    \r\n    for (int i = 0; i < n; i++) {\r\n        if\
    \ (rev[i] < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n        }\r\n \
    \   }\r\n    if (int(roots.size()) < n) {\r\n        int k = __builtin_ctz(roots.size());\r\
    \n        roots.resize(n);\r\n        while ((1 << k) < n) {\r\n            Z\
    \ e = power(Z(3), (P - 1) >> (k + 1));\r\n            for (int i = 1 << (k - 1);\
    \ i < (1 << k); i++) {\r\n                roots[2 * i] = roots[i];\r\n       \
    \         roots[2 * i + 1] = roots[i] * e;\r\n            }\r\n            k++;\r\
    \n        }\r\n    }\r\n    for (int k = 1; k < n; k *= 2) {\r\n        for (int\
    \ i = 0; i < n; i += 2 * k) {\r\n            for (int j = 0; j < k; j++) {\r\n\
    \                Z u = a[i + j];\r\n                Z v = a[i + j + k] * roots[k\
    \ + j];\r\n                a[i + j] = u + v;\r\n                a[i + j + k] =\
    \ u - v;\r\n            }\r\n        }\r\n    }\r\n}\r\nvoid idft(std::vector<Z>\
    \ &a) {\r\n    int n = a.size();\r\n    std::reverse(a.begin() + 1, a.end());\r\
    \n    dft(a);\r\n    Z inv = (1 - P) / n;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        a[i] *= inv;\r\n    }\r\n}\r\nstruct Poly {\r\n    std::vector<Z> a;\r\
    \n    Poly() {}\r\n    explicit Poly(int size, std::function<Z(int)> f = [](int)\
    \ { return 0; }) : a(size) {\r\n        for (int i = 0; i < size; i++) {\r\n \
    \           a[i] = f(i);\r\n        }\r\n    }\r\n    Poly(const std::vector<Z>\
    \ &a) : a(a) {}\r\n    Poly(const std::initializer_list<Z> &a) : a(a) {}\r\n \
    \   int size() const {\r\n        return a.size();\r\n    }\r\n    void resize(int\
    \ n) {\r\n        a.resize(n);\r\n    }\r\n    Z operator[](int idx) const {\r\
    \n        if (idx < size()) {\r\n            return a[idx];\r\n        } else\
    \ {\r\n            return 0;\r\n        }\r\n    }\r\n    Z &operator[](int idx)\
    \ {\r\n        return a[idx];\r\n    }\r\n    Poly mulxk(int k) const {\r\n  \
    \      auto b = a;\r\n        b.insert(b.begin(), k, 0);\r\n        return Poly(b);\r\
    \n    }\r\n    Poly modxk(int k) const {\r\n        k = std::min(k, size());\r\
    \n        return Poly(std::vector<Z>(a.begin(), a.begin() + k));\r\n    }\r\n\
    \    Poly divxk(int k) const {\r\n        if (size() <= k) {\r\n            return\
    \ Poly();\r\n        }\r\n        return Poly(std::vector<Z>(a.begin() + k, a.end()));\r\
    \n    }\r\n    friend Poly operator+(const Poly &a, const Poly &b) {\r\n     \
    \   std::vector<Z> res(std::max(a.size(), b.size()));\r\n        for (int i =\
    \ 0; i < int(res.size()); i++) {\r\n            res[i] = a[i] + b[i];\r\n    \
    \    }\r\n        return Poly(res);\r\n    }\r\n    friend Poly operator-(const\
    \ Poly &a, const Poly &b) {\r\n        std::vector<Z> res(std::max(a.size(), b.size()));\r\
    \n        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] =\
    \ a[i] - b[i];\r\n        }\r\n        return Poly(res);\r\n    }\r\n    friend\
    \ Poly operator-(const Poly &a) {\r\n        std::vector<Z> res(a.size());\r\n\
    \        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] = -a[i];\r\
    \n        }\r\n        return Poly(res);\r\n    }\r\n    friend Poly operator*(Poly\
    \ a, Poly b) {\r\n        if (a.size() == 0 || b.size() == 0) {\r\n          \
    \  return Poly();\r\n        }\r\n        if (a.size() < b.size()) {\r\n     \
    \       std::swap(a, b);\r\n        }\r\n        if (b.size() < 128) {\r\n   \
    \         Poly c(a.size() + b.size() - 1);\r\n            for (int i = 0; i <\
    \ a.size(); i++) {\r\n                for (int j = 0; j < b.size(); j++) {\r\n\
    \                    c[i + j] += a[i] * b[j];\r\n                }\r\n       \
    \     }\r\n            return c;\r\n        }\r\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\r\n        while (sz < tot) {\r\n            sz *= 2;\r\n  \
    \      }\r\n        a.a.resize(sz);\r\n        b.a.resize(sz);\r\n        dft(a.a);\r\
    \n        dft(b.a);\r\n        for (int i = 0; i < sz; ++i) {\r\n            a.a[i]\
    \ = a[i] * b[i];\r\n        }\r\n        idft(a.a);\r\n        a.resize(tot);\r\
    \n        return a;\r\n    }\r\n    friend Poly operator*(Z a, Poly b) {\r\n \
    \       for (int i = 0; i < int(b.size()); i++) {\r\n            b[i] *= a;\r\n\
    \        }\r\n        return b;\r\n    }\r\n    friend Poly operator*(Poly a,\
    \ Z b) {\r\n        for (int i = 0; i < int(a.size()); i++) {\r\n            a[i]\
    \ *= b;\r\n        }\r\n        return a;\r\n    }\r\n    Poly &operator+=(Poly\
    \ b) {\r\n        return (*this) = (*this) + b;\r\n    }\r\n    Poly &operator-=(Poly\
    \ b) {\r\n        return (*this) = (*this) - b;\r\n    }\r\n    Poly &operator*=(Poly\
    \ b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n    Poly &operator*=(Z\
    \ b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n    Poly deriv() const\
    \ {\r\n        if (a.empty()) {\r\n            return Poly();\r\n        }\r\n\
    \        std::vector<Z> res(size() - 1);\r\n        for (int i = 0; i < size()\
    \ - 1; ++i) {\r\n            res[i] = (i + 1) * a[i + 1];\r\n        }\r\n   \
    \     return Poly(res);\r\n    }\r\n    Poly integr() const {\r\n        std::vector<Z>\
    \ res(size() + 1);\r\n        for (int i = 0; i < size(); ++i) {\r\n         \
    \   res[i + 1] = a[i] / (i + 1);\r\n        }\r\n        return Poly(res);\r\n\
    \    }\r\n    Poly inv(int m) const {\r\n        Poly x{a[0].inv()};\r\n     \
    \   int k = 1;\r\n        while (k < m) {\r\n            k *= 2;\r\n         \
    \   x = (x * (Poly{2} - modxk(k) * x)).modxk(k);\r\n        }\r\n        return\
    \ x.modxk(m);\r\n    }\r\n    Poly log(int m) const {\r\n        return (deriv()\
    \ * inv(m)).integr().modxk(m);\r\n    }\r\n    Poly exp(int m) const {\r\n   \
    \     Poly x{1};\r\n        int k = 1;\r\n        while (k < m) {\r\n        \
    \    k *= 2;\r\n            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);\r\
    \n        }\r\n        return x.modxk(m);\r\n    }\r\n    Poly pow(int k, int\
    \ m) const {\r\n        int i = 0;\r\n        while (i < size() && a[i].val()\
    \ == 0) {\r\n            i++;\r\n        }\r\n        if (i == size() || 1LL *\
    \ i * k >= m) {\r\n            return Poly(std::vector<Z>(m));\r\n        }\r\n\
    \        Z v = a[i];\r\n        auto f = divxk(i) * v.inv();\r\n        return\
    \ (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);\r\n    }\r\
    \n    Poly sqrt(int m) const {\r\n        Poly x{1};\r\n        int k = 1;\r\n\
    \        while (k < m) {\r\n            k *= 2;\r\n            x = (x + (modxk(k)\
    \ * x.inv(k)).modxk(k)) * ((P + 1) / 2);\r\n        }\r\n        return x.modxk(m);\r\
    \n    }\r\n    Poly mulT(Poly b) const {\r\n        if (b.size() == 0) {\r\n \
    \           return Poly();\r\n        }\r\n        int n = b.size();\r\n     \
    \   std::reverse(b.a.begin(), b.a.end());\r\n        return ((*this) * b).divxk(n\
    \ - 1);\r\n    }\r\n    std::vector<Z> eval(std::vector<Z> x) const {\r\n    \
    \    if (size() == 0) {\r\n            return std::vector<Z>(x.size(), 0);\r\n\
    \        }\r\n        const int n = std::max(int(x.size()), size());\r\n     \
    \   std::vector<Poly> q(4 * n);\r\n        std::vector<Z> ans(x.size());\r\n \
    \       x.resize(n);\r\n        std::function<void(int, int, int)> build = [&](int\
    \ p, int l, int r) {\r\n            if (r - l == 1) {\r\n                q[p]\
    \ = Poly{1, -x[l]};\r\n            } else {\r\n                int m = (l + r)\
    \ / 2;\r\n                build(2 * p, l, m);\r\n                build(2 * p +\
    \ 1, m, r);\r\n                q[p] = q[2 * p] * q[2 * p + 1];\r\n           \
    \ }\r\n        };\r\n        build(1, 0, n);\r\n        std::function<void(int,\
    \ int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {\r\
    \n            if (r - l == 1) {\r\n                if (l < int(ans.size())) {\r\
    \n                    ans[l] = num[0];\r\n                }\r\n            } else\
    \ {\r\n                int m = (l + r) / 2;\r\n                work(2 * p, l,\
    \ m, num.mulT(q[2 * p + 1]).modxk(m - l));\r\n                work(2 * p + 1,\
    \ m, r, num.mulT(q[2 * p]).modxk(r - m));\r\n            }\r\n        };\r\n \
    \       work(1, 0, n, mulT(q[1].inv(n)));\r\n        return ans;\r\n    }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/12A-Poly.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/12A-Poly.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/12A-Poly.hpp
- /library/src/jiangly/math/12A-Poly.hpp.html
title: src/jiangly/math/12A-Poly.hpp
---
