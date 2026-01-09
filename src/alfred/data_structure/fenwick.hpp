#ifndef AFDS_FENWICK
#define AFDS_FENWICK

#include <vector>

template <class T>
struct Fenwick {
    int n;
    std::vector<T> c;
    Fenwick(void) = default;
    Fenwick(int len) : n(len + 2), c(len + 2) {}
    inline void init(int _n) { n = _n + 2, c.resize(n); }
    inline int lowbit(int x) { return x & -x; }
    inline void merge(T &x, T &y) { x = x + y; }
    inline T subtract(T x, T y) { return x - y; }
    inline void update(int pos, T x) {
        for (pos++; pos < n; pos += lowbit(pos)) merge(c[pos], x);
    }
    inline void clear(void) {
        for (auto &x : c) x = T();
    }
    inline T query(int pos) {
        T ans = T();
        for (pos++; pos; pos ^= lowbit(pos)) merge(ans, c[pos]);
        return ans;
    }
    inline T query(int l, int r) {
        return subtract(query(r), query(l - 1));
    }
    inline int kth(T k) {
        int ans = 0;
        for (int i = 1 << std::__lg(c.size() - 1); i; i >>= 1) {
            if (ans + i < (int)c.size() && c[ans + i] <= k) {
                k -= c[ans + i], ans += i;
            }
        }
        return ans;
    }
};

#endif // AFDS_FENWICK
