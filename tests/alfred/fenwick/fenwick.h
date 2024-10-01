#include <bits/stdc++.h>

#ifndef _FENWICK_H_
#define _FENWICK_H_

template <class T>
struct Fenwick {
    std::vector<T> c;
    inline int lowbit(int x);
    inline void merge(T &x, T &y);
    inline T subtract(T x, T y);
    inline void update(size_t pos, T x);
    inline void clear(void);
    inline T query(size_t pos);
    inline T query(size_t l, size_t r);
    inline int kth(const T k);
    Fenwick(size_t len);
};

#endif
