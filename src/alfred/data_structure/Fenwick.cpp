#include "fenwick.h"
#include <bits/stdc++.h>

template <class T>
struct Fenwick {
    std::vector<T> c;
    inline int lowbit(int x) { return x & -x; }
    inline void merge(T &x, T &y) { x = x + y; }
    inline T subtract(T x, T y) { return x - y; }
    inline void update(size_t pos, T x) {
        for (pos++; pos < c.size(); pos += lowbit(pos)) merge(c[pos], x);
    }
    inline void clear(void) {
        for (auto &x : c) x = T();
    }
    inline T query(size_t pos) {
        T ans = T();
        for (pos++; pos; pos ^= lowbit(pos)) merge(ans, c[pos]);
        return ans;
    }
    inline T query(size_t l, size_t r) {
        return l == 0 ? query(r) : subtract(query(r), query(l - 1));
    }
    inline int kth(const T k) {
        int ans = 0;
        for (int i = 1 << std::__lg(c.size() - 1); i; i >>= 1) {
            if (ans + i < (int)c.size() && c[ans + i] <= k) {
                k -= c[ans + i], ans += i;
            }
        }
        return ans;
    }
    Fenwick(size_t len) : c(len + 2) {}
};