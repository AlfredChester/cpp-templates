#ifndef AFALG_UTILS
#define AFALG_UTILS

#include <initializer_list>
#include <iostream>
#include <vector>

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

template <class T>
inline void write_vec(
    std::vector<T> &vec, bool in_line = false
) {
    std::cout << vec.size() << "\n "[in_line];
    for (T &x : vec) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

#endif // AFALG_UTILS
