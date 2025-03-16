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
    - https://atcoder.jp/contests/arc163/submissions/45737810
  bundledCode: "#line 1 \"src/jiangly/math/12B-Poly.hpp\"\n/**   \u591A\u9879\u5F0F\
    \u76F8\u5173\uFF08Poly, with. MInt & MLong\uFF09\r\n *    2023-09-20: https://atcoder.jp/contests/arc163/submissions/45737810\r\
    \n**/\r\nstd::vector<int> rev;\r\ntemplate<int P>\r\nstd::vector<MInt<P>> roots{0,\
    \ 1};\r\n\r\ntemplate<int P>\r\nconstexpr MInt<P> findPrimitiveRoot() {\r\n  \
    \  MInt<P> i = 2;\r\n    int k = __builtin_ctz(P - 1);\r\n    while (true) {\r\
    \n        if (power(i, (P - 1) / 2) != 1) {\r\n            break;\r\n        }\r\
    \n        i += 1;\r\n    }\r\n    return power(i, (P - 1) >> k);\r\n}\r\n\r\n\
    template<int P>\r\nconstexpr MInt<P> primitiveRoot = findPrimitiveRoot<P>();\r\
    \n\r\ntemplate<>\r\nconstexpr MInt<998244353> primitiveRoot<998244353> {31};\r\
    \n\r\ntemplate<int P>\r\nconstexpr void dft(std::vector<MInt<P>> &a) {\r\n   \
    \ int n = a.size();\r\n    \r\n    if (int(rev.size()) != n) {\r\n        int\
    \ k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\r\n\
    \        }\r\n    }\r\n    \r\n    for (int i = 0; i < n; i++) {\r\n        if\
    \ (rev[i] < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n        }\r\n \
    \   }\r\n    if (roots<P>.size() < n) {\r\n        int k = __builtin_ctz(roots<P>.size());\r\
    \n        roots<P>.resize(n);\r\n        while ((1 << k) < n) {\r\n          \
    \  auto e = power(primitiveRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));\r\n\
    \            for (int i = 1 << (k - 1); i < (1 << k); i++) {\r\n             \
    \   roots<P>[2 * i] = roots<P>[i];\r\n                roots<P>[2 * i + 1] = roots<P>[i]\
    \ * e;\r\n            }\r\n            k++;\r\n        }\r\n    }\r\n    for (int\
    \ k = 1; k < n; k *= 2) {\r\n        for (int i = 0; i < n; i += 2 * k) {\r\n\
    \            for (int j = 0; j < k; j++) {\r\n                MInt<P> u = a[i\
    \ + j];\r\n                MInt<P> v = a[i + j + k] * roots<P>[k + j];\r\n   \
    \             a[i + j] = u + v;\r\n                a[i + j + k] = u - v;\r\n \
    \           }\r\n        }\r\n    }\r\n}\r\n\r\ntemplate<int P>\r\nconstexpr void\
    \ idft(std::vector<MInt<P>> &a) {\r\n    int n = a.size();\r\n    std::reverse(a.begin()\
    \ + 1, a.end());\r\n    dft(a);\r\n    MInt<P> inv = (1 - P) / n;\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        a[i] *= inv;\r\n    }\r\n}\r\n\r\ntemplate<int\
    \ P = 998244353>\r\nstruct Poly : public std::vector<MInt<P>> {\r\n    using Value\
    \ = MInt<P>;\r\n    \r\n    Poly() : std::vector<Value>() {}\r\n    explicit constexpr\
    \ Poly(int n) : std::vector<Value>(n) {}\r\n    \r\n    explicit constexpr Poly(const\
    \ std::vector<Value> &a) : std::vector<Value>(a) {}\r\n    constexpr Poly(const\
    \ std::initializer_list<Value> &a) : std::vector<Value>(a) {}\r\n    \r\n    template<class\
    \ InputIt, class = std::_RequireInputIter<InputIt>>\r\n    explicit constexpr\
    \ Poly(InputIt first, InputIt last) : std::vector<Value>(first, last) {}\r\n \
    \   \r\n    template<class F>\r\n    explicit constexpr Poly(int n, F f) : std::vector<Value>(n)\
    \ {\r\n        for (int i = 0; i < n; i++) {\r\n            (*this)[i] = f(i);\r\
    \n        }\r\n    }\r\n    \r\n    constexpr Poly shift(int k) const {\r\n  \
    \      if (k >= 0) {\r\n            auto b = *this;\r\n            b.insert(b.begin(),\
    \ k, 0);\r\n            return b;\r\n        } else if (this->size() <= -k) {\r\
    \n            return Poly();\r\n        } else {\r\n            return Poly(this->begin()\
    \ + (-k), this->end());\r\n        }\r\n    }\r\n    constexpr Poly trunc(int\
    \ k) const {\r\n        Poly f = *this;\r\n        f.resize(k);\r\n        return\
    \ f;\r\n    }\r\n    constexpr friend Poly operator+(const Poly &a, const Poly\
    \ &b) {\r\n        Poly res(std::max(a.size(), b.size()));\r\n        for (int\
    \ i = 0; i < a.size(); i++) {\r\n            res[i] += a[i];\r\n        }\r\n\
    \        for (int i = 0; i < b.size(); i++) {\r\n            res[i] += b[i];\r\
    \n        }\r\n        return res;\r\n    }\r\n    constexpr friend Poly operator-(const\
    \ Poly &a, const Poly &b) {\r\n        Poly res(std::max(a.size(), b.size()));\r\
    \n        for (int i = 0; i < a.size(); i++) {\r\n            res[i] += a[i];\r\
    \n        }\r\n        for (int i = 0; i < b.size(); i++) {\r\n            res[i]\
    \ -= b[i];\r\n        }\r\n        return res;\r\n    }\r\n    constexpr friend\
    \ Poly operator-(const Poly &a) {\r\n        std::vector<Value> res(a.size());\r\
    \n        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] =\
    \ -a[i];\r\n        }\r\n        return Poly(res);\r\n    }\r\n    constexpr friend\
    \ Poly operator*(Poly a, Poly b) {\r\n        if (a.size() == 0 || b.size() ==\
    \ 0) {\r\n            return Poly();\r\n        }\r\n        if (a.size() < b.size())\
    \ {\r\n            std::swap(a, b);\r\n        }\r\n        int n = 1, tot = a.size()\
    \ + b.size() - 1;\r\n        while (n < tot) {\r\n            n *= 2;\r\n    \
    \    }\r\n        if (((P - 1) & (n - 1)) != 0 || b.size() < 128) {\r\n      \
    \      Poly c(a.size() + b.size() - 1);\r\n            for (int i = 0; i < a.size();\
    \ i++) {\r\n                for (int j = 0; j < b.size(); j++) {\r\n         \
    \           c[i + j] += a[i] * b[j];\r\n                }\r\n            }\r\n\
    \            return c;\r\n        }\r\n        a.resize(n);\r\n        b.resize(n);\r\
    \n        dft(a);\r\n        dft(b);\r\n        for (int i = 0; i < n; ++i) {\r\
    \n            a[i] *= b[i];\r\n        }\r\n        idft(a);\r\n        a.resize(tot);\r\
    \n        return a;\r\n    }\r\n    constexpr friend Poly operator*(Value a, Poly\
    \ b) {\r\n        for (int i = 0; i < int(b.size()); i++) {\r\n            b[i]\
    \ *= a;\r\n        }\r\n        return b;\r\n    }\r\n    constexpr friend Poly\
    \ operator*(Poly a, Value b) {\r\n        for (int i = 0; i < int(a.size()); i++)\
    \ {\r\n            a[i] *= b;\r\n        }\r\n        return a;\r\n    }\r\n \
    \   constexpr friend Poly operator/(Poly a, Value b) {\r\n        for (int i =\
    \ 0; i < int(a.size()); i++) {\r\n            a[i] /= b;\r\n        }\r\n    \
    \    return a;\r\n    }\r\n    constexpr Poly &operator+=(Poly b) {\r\n      \
    \  return (*this) = (*this) + b;\r\n    }\r\n    constexpr Poly &operator-=(Poly\
    \ b) {\r\n        return (*this) = (*this) - b;\r\n    }\r\n    constexpr Poly\
    \ &operator*=(Poly b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n\
    \    constexpr Poly &operator*=(Value b) {\r\n        return (*this) = (*this)\
    \ * b;\r\n    }\r\n    constexpr Poly &operator/=(Value b) {\r\n        return\
    \ (*this) = (*this) / b;\r\n    }\r\n    constexpr Poly deriv() const {\r\n  \
    \      if (this->empty()) {\r\n            return Poly();\r\n        }\r\n   \
    \     Poly res(this->size() - 1);\r\n        for (int i = 0; i < this->size()\
    \ - 1; ++i) {\r\n            res[i] = (i + 1) * (*this)[i + 1];\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr Poly integr() const {\r\n    \
    \    Poly res(this->size() + 1);\r\n        for (int i = 0; i < this->size();\
    \ ++i) {\r\n            res[i + 1] = (*this)[i] / (i + 1);\r\n        }\r\n  \
    \      return res;\r\n    }\r\n    constexpr Poly inv(int m) const {\r\n     \
    \   Poly x{(*this)[0].inv()};\r\n        int k = 1;\r\n        while (k < m) {\r\
    \n            k *= 2;\r\n            x = (x * (Poly{2} - trunc(k) * x)).trunc(k);\r\
    \n        }\r\n        return x.trunc(m);\r\n    }\r\n    constexpr Poly log(int\
    \ m) const {\r\n        return (deriv() * inv(m)).integr().trunc(m);\r\n    }\r\
    \n    constexpr Poly exp(int m) const {\r\n        Poly x{1};\r\n        int k\
    \ = 1;\r\n        while (k < m) {\r\n            k *= 2;\r\n            x = (x\
    \ * (Poly{1} - x.log(k) + trunc(k))).trunc(k);\r\n        }\r\n        return\
    \ x.trunc(m);\r\n    }\r\n    constexpr Poly pow(int k, int m) const {\r\n   \
    \     int i = 0;\r\n        while (i < this->size() && (*this)[i] == 0) {\r\n\
    \            i++;\r\n        }\r\n        if (i == this->size() || 1LL * i * k\
    \ >= m) {\r\n            return Poly(m);\r\n        }\r\n        Value v = (*this)[i];\r\
    \n        auto f = shift(-i) * v.inv();\r\n        return (f.log(m - i * k) *\
    \ k).exp(m - i * k).shift(i * k) * power(v, k);\r\n    }\r\n    constexpr Poly\
    \ sqrt(int m) const {\r\n        Poly x{1};\r\n        int k = 1;\r\n        while\
    \ (k < m) {\r\n            k *= 2;\r\n            x = (x + (trunc(k) * x.inv(k)).trunc(k))\
    \ * CInv<2, P>;\r\n        }\r\n        return x.trunc(m);\r\n    }\r\n    constexpr\
    \ Poly mulT(Poly b) const {\r\n        if (b.size() == 0) {\r\n            return\
    \ Poly();\r\n        }\r\n        int n = b.size();\r\n        std::reverse(b.begin(),\
    \ b.end());\r\n        return ((*this) * b).shift(-(n - 1));\r\n    }\r\n    constexpr\
    \ std::vector<Value> eval(std::vector<Value> x) const {\r\n        if (this->size()\
    \ == 0) {\r\n            return std::vector<Value>(x.size(), 0);\r\n        }\r\
    \n        const int n = std::max(x.size(), this->size());\r\n        std::vector<Poly>\
    \ q(4 * n);\r\n        std::vector<Value> ans(x.size());\r\n        x.resize(n);\r\
    \n        std::function<void(int, int, int)> build = [&](int p, int l, int r)\
    \ {\r\n            if (r - l == 1) {\r\n                q[p] = Poly{1, -x[l]};\r\
    \n            } else {\r\n                int m = (l + r) / 2;\r\n           \
    \     build(2 * p, l, m);\r\n                build(2 * p + 1, m, r);\r\n     \
    \           q[p] = q[2 * p] * q[2 * p + 1];\r\n            }\r\n        };\r\n\
    \        build(1, 0, n);\r\n        std::function<void(int, int, int, const Poly\
    \ &)> work = [&](int p, int l, int r, const Poly &num) {\r\n            if (r\
    \ - l == 1) {\r\n                if (l < int(ans.size())) {\r\n              \
    \      ans[l] = num[0];\r\n                }\r\n            } else {\r\n     \
    \           int m = (l + r) / 2;\r\n                work(2 * p, l, m, num.mulT(q[2\
    \ * p + 1]).resize(m - l));\r\n                work(2 * p + 1, m, r, num.mulT(q[2\
    \ * p]).resize(r - m));\r\n            }\r\n        };\r\n        work(1, 0, n,\
    \ mulT(q[1].inv(n)));\r\n        return ans;\r\n    }\r\n};\r\n\r\ntemplate<int\
    \ P = 998244353>\r\nPoly<P> berlekampMassey(const Poly<P> &s) {\r\n    Poly<P>\
    \ c;\r\n    Poly<P> oldC;\r\n    int f = -1;\r\n    for (int i = 0; i < s.size();\
    \ i++) {\r\n        auto delta = s[i];\r\n        for (int j = 1; j <= c.size();\
    \ j++) {\r\n            delta -= c[j - 1] * s[i - j];\r\n        }\r\n       \
    \ if (delta == 0) {\r\n            continue;\r\n        }\r\n        if (f ==\
    \ -1) {\r\n            c.resize(i + 1);\r\n            f = i;\r\n        } else\
    \ {\r\n            auto d = oldC;\r\n            d *= -1;\r\n            d.insert(d.begin(),\
    \ 1);\r\n            MInt<P> df1 = 0;\r\n            for (int j = 1; j <= d.size();\
    \ j++) {\r\n                df1 += d[j - 1] * s[f + 1 - j];\r\n            }\r\
    \n            assert(df1 != 0);\r\n            auto coef = delta / df1;\r\n  \
    \          d *= coef;\r\n            Poly<P> zeros(i - f - 1);\r\n           \
    \ zeros.insert(zeros.end(), d.begin(), d.end());\r\n            d = zeros;\r\n\
    \            auto temp = c;\r\n            c += d;\r\n            if (i - temp.size()\
    \ > f - oldC.size()) {\r\n                oldC = temp;\r\n                f =\
    \ i;\r\n            }\r\n        }\r\n    }\r\n    c *= -1;\r\n    c.insert(c.begin(),\
    \ 1);\r\n    return c;\r\n}\r\n\r\n\r\ntemplate<int P = 998244353>\r\nMInt<P>\
    \ linearRecurrence(Poly<P> p, Poly<P> q, i64 n) {\r\n    int m = q.size() - 1;\r\
    \n    while (n > 0) {\r\n        auto newq = q;\r\n        for (int i = 1; i <=\
    \ m; i += 2) {\r\n            newq[i] *= -1;\r\n        }\r\n        auto newp\
    \ = p * newq;\r\n        newq = q * newq;\r\n        for (int i = 0; i < m; i++)\
    \ {\r\n            p[i] = newp[i * 2 + n % 2];\r\n        }\r\n        for (int\
    \ i = 0; i <= m; i++) {\r\n            q[i] = newq[i * 2];\r\n        }\r\n  \
    \      n /= 2;\r\n    }\r\n    return p[0] / q[0];\r\n}\r\n\r\nstruct Comb {\r\
    \n    int n;\r\n    std::vector<Z> _fac;\r\n    std::vector<Z> _invfac;\r\n  \
    \  std::vector<Z> _inv;\r\n    \r\n    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0}\
    \ {}\r\n    Comb(int n) : Comb() {\r\n        init(n);\r\n    }\r\n    \r\n  \
    \  void init(int m) {\r\n        m = std::min(m, Z::getMod() - 1);\r\n       \
    \ if (m <= n) return;\r\n        _fac.resize(m + 1);\r\n        _invfac.resize(m\
    \ + 1);\r\n        _inv.resize(m + 1);\r\n        \r\n        for (int i = n +\
    \ 1; i <= m; i++) {\r\n            _fac[i] = _fac[i - 1] * i;\r\n        }\r\n\
    \        _invfac[m] = _fac[m].inv();\r\n        for (int i = m; i > n; i--) {\r\
    \n            _invfac[i - 1] = _invfac[i] * i;\r\n            _inv[i] = _invfac[i]\
    \ * _fac[i - 1];\r\n        }\r\n        n = m;\r\n    }\r\n    \r\n    Z fac(int\
    \ m) {\r\n        if (m > n) init(2 * m);\r\n        return _fac[m];\r\n    }\r\
    \n    Z invfac(int m) {\r\n        if (m > n) init(2 * m);\r\n        return _invfac[m];\r\
    \n    }\r\n    Z inv(int m) {\r\n        if (m > n) init(2 * m);\r\n        return\
    \ _inv[m];\r\n    }\r\n    Z binom(int n, int m) {\r\n        if (n < m || m <\
    \ 0) return 0;\r\n        return fac(n) * invfac(m) * invfac(n - m);\r\n    }\r\
    \n} comb;\r\n\r\nPoly<P> get(int n, int m) {\r\n    if (m == 0) {\r\n        return\
    \ Poly(n + 1);\r\n    }\r\n    if (m % 2 == 1) {\r\n        auto f = get(n, m\
    \ - 1);\r\n        Z p = 1;\r\n        for (int i = 0; i <= n; i++) {\r\n    \
    \        f[n - i] += comb.binom(n, i) * p;\r\n            p *= m;\r\n        }\r\
    \n        return f;\r\n    }\r\n    auto f = get(n, m / 2);\r\n    auto fm = f;\r\
    \n    for (int i = 0; i <= n; i++) {\r\n        fm[i] *= comb.fac(i);\r\n    }\r\
    \n    Poly pw(n + 1);\r\n    pw[0] = 1;\r\n    for (int i = 1; i <= n; i++) {\r\
    \n        pw[i] = pw[i - 1] * (m / 2);\r\n    }\r\n    for (int i = 0; i <= n;\
    \ i++) {\r\n        pw[i] *= comb.invfac(i);\r\n    }\r\n    fm = fm.mulT(pw);\r\
    \n    for (int i = 0; i <= n; i++) {\r\n        fm[i] *= comb.invfac(i);\r\n \
    \   }\r\n    return f + fm;\r\n}\n"
  code: "/**   \u591A\u9879\u5F0F\u76F8\u5173\uFF08Poly, with. MInt & MLong\uFF09\r\
    \n *    2023-09-20: https://atcoder.jp/contests/arc163/submissions/45737810\r\n\
    **/\r\nstd::vector<int> rev;\r\ntemplate<int P>\r\nstd::vector<MInt<P>> roots{0,\
    \ 1};\r\n\r\ntemplate<int P>\r\nconstexpr MInt<P> findPrimitiveRoot() {\r\n  \
    \  MInt<P> i = 2;\r\n    int k = __builtin_ctz(P - 1);\r\n    while (true) {\r\
    \n        if (power(i, (P - 1) / 2) != 1) {\r\n            break;\r\n        }\r\
    \n        i += 1;\r\n    }\r\n    return power(i, (P - 1) >> k);\r\n}\r\n\r\n\
    template<int P>\r\nconstexpr MInt<P> primitiveRoot = findPrimitiveRoot<P>();\r\
    \n\r\ntemplate<>\r\nconstexpr MInt<998244353> primitiveRoot<998244353> {31};\r\
    \n\r\ntemplate<int P>\r\nconstexpr void dft(std::vector<MInt<P>> &a) {\r\n   \
    \ int n = a.size();\r\n    \r\n    if (int(rev.size()) != n) {\r\n        int\
    \ k = __builtin_ctz(n) - 1;\r\n        rev.resize(n);\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\r\n\
    \        }\r\n    }\r\n    \r\n    for (int i = 0; i < n; i++) {\r\n        if\
    \ (rev[i] < i) {\r\n            std::swap(a[i], a[rev[i]]);\r\n        }\r\n \
    \   }\r\n    if (roots<P>.size() < n) {\r\n        int k = __builtin_ctz(roots<P>.size());\r\
    \n        roots<P>.resize(n);\r\n        while ((1 << k) < n) {\r\n          \
    \  auto e = power(primitiveRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));\r\n\
    \            for (int i = 1 << (k - 1); i < (1 << k); i++) {\r\n             \
    \   roots<P>[2 * i] = roots<P>[i];\r\n                roots<P>[2 * i + 1] = roots<P>[i]\
    \ * e;\r\n            }\r\n            k++;\r\n        }\r\n    }\r\n    for (int\
    \ k = 1; k < n; k *= 2) {\r\n        for (int i = 0; i < n; i += 2 * k) {\r\n\
    \            for (int j = 0; j < k; j++) {\r\n                MInt<P> u = a[i\
    \ + j];\r\n                MInt<P> v = a[i + j + k] * roots<P>[k + j];\r\n   \
    \             a[i + j] = u + v;\r\n                a[i + j + k] = u - v;\r\n \
    \           }\r\n        }\r\n    }\r\n}\r\n\r\ntemplate<int P>\r\nconstexpr void\
    \ idft(std::vector<MInt<P>> &a) {\r\n    int n = a.size();\r\n    std::reverse(a.begin()\
    \ + 1, a.end());\r\n    dft(a);\r\n    MInt<P> inv = (1 - P) / n;\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        a[i] *= inv;\r\n    }\r\n}\r\n\r\ntemplate<int\
    \ P = 998244353>\r\nstruct Poly : public std::vector<MInt<P>> {\r\n    using Value\
    \ = MInt<P>;\r\n    \r\n    Poly() : std::vector<Value>() {}\r\n    explicit constexpr\
    \ Poly(int n) : std::vector<Value>(n) {}\r\n    \r\n    explicit constexpr Poly(const\
    \ std::vector<Value> &a) : std::vector<Value>(a) {}\r\n    constexpr Poly(const\
    \ std::initializer_list<Value> &a) : std::vector<Value>(a) {}\r\n    \r\n    template<class\
    \ InputIt, class = std::_RequireInputIter<InputIt>>\r\n    explicit constexpr\
    \ Poly(InputIt first, InputIt last) : std::vector<Value>(first, last) {}\r\n \
    \   \r\n    template<class F>\r\n    explicit constexpr Poly(int n, F f) : std::vector<Value>(n)\
    \ {\r\n        for (int i = 0; i < n; i++) {\r\n            (*this)[i] = f(i);\r\
    \n        }\r\n    }\r\n    \r\n    constexpr Poly shift(int k) const {\r\n  \
    \      if (k >= 0) {\r\n            auto b = *this;\r\n            b.insert(b.begin(),\
    \ k, 0);\r\n            return b;\r\n        } else if (this->size() <= -k) {\r\
    \n            return Poly();\r\n        } else {\r\n            return Poly(this->begin()\
    \ + (-k), this->end());\r\n        }\r\n    }\r\n    constexpr Poly trunc(int\
    \ k) const {\r\n        Poly f = *this;\r\n        f.resize(k);\r\n        return\
    \ f;\r\n    }\r\n    constexpr friend Poly operator+(const Poly &a, const Poly\
    \ &b) {\r\n        Poly res(std::max(a.size(), b.size()));\r\n        for (int\
    \ i = 0; i < a.size(); i++) {\r\n            res[i] += a[i];\r\n        }\r\n\
    \        for (int i = 0; i < b.size(); i++) {\r\n            res[i] += b[i];\r\
    \n        }\r\n        return res;\r\n    }\r\n    constexpr friend Poly operator-(const\
    \ Poly &a, const Poly &b) {\r\n        Poly res(std::max(a.size(), b.size()));\r\
    \n        for (int i = 0; i < a.size(); i++) {\r\n            res[i] += a[i];\r\
    \n        }\r\n        for (int i = 0; i < b.size(); i++) {\r\n            res[i]\
    \ -= b[i];\r\n        }\r\n        return res;\r\n    }\r\n    constexpr friend\
    \ Poly operator-(const Poly &a) {\r\n        std::vector<Value> res(a.size());\r\
    \n        for (int i = 0; i < int(res.size()); i++) {\r\n            res[i] =\
    \ -a[i];\r\n        }\r\n        return Poly(res);\r\n    }\r\n    constexpr friend\
    \ Poly operator*(Poly a, Poly b) {\r\n        if (a.size() == 0 || b.size() ==\
    \ 0) {\r\n            return Poly();\r\n        }\r\n        if (a.size() < b.size())\
    \ {\r\n            std::swap(a, b);\r\n        }\r\n        int n = 1, tot = a.size()\
    \ + b.size() - 1;\r\n        while (n < tot) {\r\n            n *= 2;\r\n    \
    \    }\r\n        if (((P - 1) & (n - 1)) != 0 || b.size() < 128) {\r\n      \
    \      Poly c(a.size() + b.size() - 1);\r\n            for (int i = 0; i < a.size();\
    \ i++) {\r\n                for (int j = 0; j < b.size(); j++) {\r\n         \
    \           c[i + j] += a[i] * b[j];\r\n                }\r\n            }\r\n\
    \            return c;\r\n        }\r\n        a.resize(n);\r\n        b.resize(n);\r\
    \n        dft(a);\r\n        dft(b);\r\n        for (int i = 0; i < n; ++i) {\r\
    \n            a[i] *= b[i];\r\n        }\r\n        idft(a);\r\n        a.resize(tot);\r\
    \n        return a;\r\n    }\r\n    constexpr friend Poly operator*(Value a, Poly\
    \ b) {\r\n        for (int i = 0; i < int(b.size()); i++) {\r\n            b[i]\
    \ *= a;\r\n        }\r\n        return b;\r\n    }\r\n    constexpr friend Poly\
    \ operator*(Poly a, Value b) {\r\n        for (int i = 0; i < int(a.size()); i++)\
    \ {\r\n            a[i] *= b;\r\n        }\r\n        return a;\r\n    }\r\n \
    \   constexpr friend Poly operator/(Poly a, Value b) {\r\n        for (int i =\
    \ 0; i < int(a.size()); i++) {\r\n            a[i] /= b;\r\n        }\r\n    \
    \    return a;\r\n    }\r\n    constexpr Poly &operator+=(Poly b) {\r\n      \
    \  return (*this) = (*this) + b;\r\n    }\r\n    constexpr Poly &operator-=(Poly\
    \ b) {\r\n        return (*this) = (*this) - b;\r\n    }\r\n    constexpr Poly\
    \ &operator*=(Poly b) {\r\n        return (*this) = (*this) * b;\r\n    }\r\n\
    \    constexpr Poly &operator*=(Value b) {\r\n        return (*this) = (*this)\
    \ * b;\r\n    }\r\n    constexpr Poly &operator/=(Value b) {\r\n        return\
    \ (*this) = (*this) / b;\r\n    }\r\n    constexpr Poly deriv() const {\r\n  \
    \      if (this->empty()) {\r\n            return Poly();\r\n        }\r\n   \
    \     Poly res(this->size() - 1);\r\n        for (int i = 0; i < this->size()\
    \ - 1; ++i) {\r\n            res[i] = (i + 1) * (*this)[i + 1];\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr Poly integr() const {\r\n    \
    \    Poly res(this->size() + 1);\r\n        for (int i = 0; i < this->size();\
    \ ++i) {\r\n            res[i + 1] = (*this)[i] / (i + 1);\r\n        }\r\n  \
    \      return res;\r\n    }\r\n    constexpr Poly inv(int m) const {\r\n     \
    \   Poly x{(*this)[0].inv()};\r\n        int k = 1;\r\n        while (k < m) {\r\
    \n            k *= 2;\r\n            x = (x * (Poly{2} - trunc(k) * x)).trunc(k);\r\
    \n        }\r\n        return x.trunc(m);\r\n    }\r\n    constexpr Poly log(int\
    \ m) const {\r\n        return (deriv() * inv(m)).integr().trunc(m);\r\n    }\r\
    \n    constexpr Poly exp(int m) const {\r\n        Poly x{1};\r\n        int k\
    \ = 1;\r\n        while (k < m) {\r\n            k *= 2;\r\n            x = (x\
    \ * (Poly{1} - x.log(k) + trunc(k))).trunc(k);\r\n        }\r\n        return\
    \ x.trunc(m);\r\n    }\r\n    constexpr Poly pow(int k, int m) const {\r\n   \
    \     int i = 0;\r\n        while (i < this->size() && (*this)[i] == 0) {\r\n\
    \            i++;\r\n        }\r\n        if (i == this->size() || 1LL * i * k\
    \ >= m) {\r\n            return Poly(m);\r\n        }\r\n        Value v = (*this)[i];\r\
    \n        auto f = shift(-i) * v.inv();\r\n        return (f.log(m - i * k) *\
    \ k).exp(m - i * k).shift(i * k) * power(v, k);\r\n    }\r\n    constexpr Poly\
    \ sqrt(int m) const {\r\n        Poly x{1};\r\n        int k = 1;\r\n        while\
    \ (k < m) {\r\n            k *= 2;\r\n            x = (x + (trunc(k) * x.inv(k)).trunc(k))\
    \ * CInv<2, P>;\r\n        }\r\n        return x.trunc(m);\r\n    }\r\n    constexpr\
    \ Poly mulT(Poly b) const {\r\n        if (b.size() == 0) {\r\n            return\
    \ Poly();\r\n        }\r\n        int n = b.size();\r\n        std::reverse(b.begin(),\
    \ b.end());\r\n        return ((*this) * b).shift(-(n - 1));\r\n    }\r\n    constexpr\
    \ std::vector<Value> eval(std::vector<Value> x) const {\r\n        if (this->size()\
    \ == 0) {\r\n            return std::vector<Value>(x.size(), 0);\r\n        }\r\
    \n        const int n = std::max(x.size(), this->size());\r\n        std::vector<Poly>\
    \ q(4 * n);\r\n        std::vector<Value> ans(x.size());\r\n        x.resize(n);\r\
    \n        std::function<void(int, int, int)> build = [&](int p, int l, int r)\
    \ {\r\n            if (r - l == 1) {\r\n                q[p] = Poly{1, -x[l]};\r\
    \n            } else {\r\n                int m = (l + r) / 2;\r\n           \
    \     build(2 * p, l, m);\r\n                build(2 * p + 1, m, r);\r\n     \
    \           q[p] = q[2 * p] * q[2 * p + 1];\r\n            }\r\n        };\r\n\
    \        build(1, 0, n);\r\n        std::function<void(int, int, int, const Poly\
    \ &)> work = [&](int p, int l, int r, const Poly &num) {\r\n            if (r\
    \ - l == 1) {\r\n                if (l < int(ans.size())) {\r\n              \
    \      ans[l] = num[0];\r\n                }\r\n            } else {\r\n     \
    \           int m = (l + r) / 2;\r\n                work(2 * p, l, m, num.mulT(q[2\
    \ * p + 1]).resize(m - l));\r\n                work(2 * p + 1, m, r, num.mulT(q[2\
    \ * p]).resize(r - m));\r\n            }\r\n        };\r\n        work(1, 0, n,\
    \ mulT(q[1].inv(n)));\r\n        return ans;\r\n    }\r\n};\r\n\r\ntemplate<int\
    \ P = 998244353>\r\nPoly<P> berlekampMassey(const Poly<P> &s) {\r\n    Poly<P>\
    \ c;\r\n    Poly<P> oldC;\r\n    int f = -1;\r\n    for (int i = 0; i < s.size();\
    \ i++) {\r\n        auto delta = s[i];\r\n        for (int j = 1; j <= c.size();\
    \ j++) {\r\n            delta -= c[j - 1] * s[i - j];\r\n        }\r\n       \
    \ if (delta == 0) {\r\n            continue;\r\n        }\r\n        if (f ==\
    \ -1) {\r\n            c.resize(i + 1);\r\n            f = i;\r\n        } else\
    \ {\r\n            auto d = oldC;\r\n            d *= -1;\r\n            d.insert(d.begin(),\
    \ 1);\r\n            MInt<P> df1 = 0;\r\n            for (int j = 1; j <= d.size();\
    \ j++) {\r\n                df1 += d[j - 1] * s[f + 1 - j];\r\n            }\r\
    \n            assert(df1 != 0);\r\n            auto coef = delta / df1;\r\n  \
    \          d *= coef;\r\n            Poly<P> zeros(i - f - 1);\r\n           \
    \ zeros.insert(zeros.end(), d.begin(), d.end());\r\n            d = zeros;\r\n\
    \            auto temp = c;\r\n            c += d;\r\n            if (i - temp.size()\
    \ > f - oldC.size()) {\r\n                oldC = temp;\r\n                f =\
    \ i;\r\n            }\r\n        }\r\n    }\r\n    c *= -1;\r\n    c.insert(c.begin(),\
    \ 1);\r\n    return c;\r\n}\r\n\r\n\r\ntemplate<int P = 998244353>\r\nMInt<P>\
    \ linearRecurrence(Poly<P> p, Poly<P> q, i64 n) {\r\n    int m = q.size() - 1;\r\
    \n    while (n > 0) {\r\n        auto newq = q;\r\n        for (int i = 1; i <=\
    \ m; i += 2) {\r\n            newq[i] *= -1;\r\n        }\r\n        auto newp\
    \ = p * newq;\r\n        newq = q * newq;\r\n        for (int i = 0; i < m; i++)\
    \ {\r\n            p[i] = newp[i * 2 + n % 2];\r\n        }\r\n        for (int\
    \ i = 0; i <= m; i++) {\r\n            q[i] = newq[i * 2];\r\n        }\r\n  \
    \      n /= 2;\r\n    }\r\n    return p[0] / q[0];\r\n}\r\n\r\nstruct Comb {\r\
    \n    int n;\r\n    std::vector<Z> _fac;\r\n    std::vector<Z> _invfac;\r\n  \
    \  std::vector<Z> _inv;\r\n    \r\n    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0}\
    \ {}\r\n    Comb(int n) : Comb() {\r\n        init(n);\r\n    }\r\n    \r\n  \
    \  void init(int m) {\r\n        m = std::min(m, Z::getMod() - 1);\r\n       \
    \ if (m <= n) return;\r\n        _fac.resize(m + 1);\r\n        _invfac.resize(m\
    \ + 1);\r\n        _inv.resize(m + 1);\r\n        \r\n        for (int i = n +\
    \ 1; i <= m; i++) {\r\n            _fac[i] = _fac[i - 1] * i;\r\n        }\r\n\
    \        _invfac[m] = _fac[m].inv();\r\n        for (int i = m; i > n; i--) {\r\
    \n            _invfac[i - 1] = _invfac[i] * i;\r\n            _inv[i] = _invfac[i]\
    \ * _fac[i - 1];\r\n        }\r\n        n = m;\r\n    }\r\n    \r\n    Z fac(int\
    \ m) {\r\n        if (m > n) init(2 * m);\r\n        return _fac[m];\r\n    }\r\
    \n    Z invfac(int m) {\r\n        if (m > n) init(2 * m);\r\n        return _invfac[m];\r\
    \n    }\r\n    Z inv(int m) {\r\n        if (m > n) init(2 * m);\r\n        return\
    \ _inv[m];\r\n    }\r\n    Z binom(int n, int m) {\r\n        if (n < m || m <\
    \ 0) return 0;\r\n        return fac(n) * invfac(m) * invfac(n - m);\r\n    }\r\
    \n} comb;\r\n\r\nPoly<P> get(int n, int m) {\r\n    if (m == 0) {\r\n        return\
    \ Poly(n + 1);\r\n    }\r\n    if (m % 2 == 1) {\r\n        auto f = get(n, m\
    \ - 1);\r\n        Z p = 1;\r\n        for (int i = 0; i <= n; i++) {\r\n    \
    \        f[n - i] += comb.binom(n, i) * p;\r\n            p *= m;\r\n        }\r\
    \n        return f;\r\n    }\r\n    auto f = get(n, m / 2);\r\n    auto fm = f;\r\
    \n    for (int i = 0; i <= n; i++) {\r\n        fm[i] *= comb.fac(i);\r\n    }\r\
    \n    Poly pw(n + 1);\r\n    pw[0] = 1;\r\n    for (int i = 1; i <= n; i++) {\r\
    \n        pw[i] = pw[i - 1] * (m / 2);\r\n    }\r\n    for (int i = 0; i <= n;\
    \ i++) {\r\n        pw[i] *= comb.invfac(i);\r\n    }\r\n    fm = fm.mulT(pw);\r\
    \n    for (int i = 0; i <= n; i++) {\r\n        fm[i] *= comb.invfac(i);\r\n \
    \   }\r\n    return f + fm;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/jiangly/math/12B-Poly.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/jiangly/math/12B-Poly.hpp
layout: document
redirect_from:
- /library/src/jiangly/math/12B-Poly.hpp
- /library/src/jiangly/math/12B-Poly.hpp.html
title: src/jiangly/math/12B-Poly.hpp
---
