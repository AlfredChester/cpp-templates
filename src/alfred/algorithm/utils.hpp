#ifndef AFALG_UTILS
#define AFALG_UTILS

#include <initializer_list>

template <class T>
inline void chkmax(T &x, T y) {
    if (x < y) x = y;
}

template <class T>
inline void chkmin(T &x, T y) {
    if (x > y) x = y;
}

template <class T>
inline void chkmax(T &x, std::initializer_list<T> Y) {
    for (auto &y : Y) chkmax(x, y);
}

template <class T>
inline void chkmin(T &x, std::initializer_list<T> Y) {
    for (auto &y : Y) chkmin(x, y);
}

#endif // AFALG_UTILS
