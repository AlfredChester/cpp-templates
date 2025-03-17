#ifndef AFDS_WEIGHTED_DSU
#define AFDS_WEIGHTED_DSU

#include <bits/stdc++.h>

template <class T>
struct WeightedDSU {
    std::vector<int> fa;
    std::vector<T> w;
    WeightedDSU(int n) : fa(n + 1), w(n + 1) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    inline int find(int x) {
        if (fa[x] == x) return x;
        int f = fa[x], f2 = find(f);
        return w[x] += w[f], fa[x] = f2;
    }
    inline bool same(int x, int y) {
        return find(x) == find(y);
    }
    // Given info: a[x] + v = a[y]
    // Returns true if this operation has no conflict, false otherwise.
    inline bool merge(int x, int y, T v) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return w[x] + v == w[y];
        }
        w[fy] = w[x] + v - w[y], fa[fy] = fx;
        return true;
    }
    inline T distance(int x, int y) {
        return find(x), find(y), w[y] - w[x];
    }
};

#endif // AFDS_WEIGHTED_DSU