#ifndef AFALG_UTILS
#define AFALG_UTILS

#include <initializer_list>
#include <iostream>
#include <random>
#include <vector>

template <class T>
inline bool chkmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template <class T>
inline bool chkmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
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
    std::vector<T> vec, bool in_line = false
) {
    std::cout << vec.size() << "\n "[in_line];
    for (T &x : vec) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template <class T>
std::vector<T> rand_seq(size_t n, size_t seed = 20090913) {
    std::vector<T> res(n);
    std::mt19937_64 rng(seed);
    for (size_t i = 0; i < n; i++) {
        res[i] = rng();
    }
    return res;
}

template <class T>
std::vector<std::vector<T>> range_traverse(size_t n, T l, T r) {
    std::vector<T> cur(n);
    std::vector<std::vector<T>> res;
    auto dfs = [&](auto &self, size_t depth) {
        if (depth == n) {
            res.push_back(cur);
            return;
        }
        for (T i = l; i <= r; i++) {
            cur[depth] = i;
            self(self, depth + 1);
        }
    };
    dfs(dfs, 0);
    return res;
}

template <class T>
inline std::string bin(T v) {
    std::string s;
    if (v == 0) return "0b0";
    while (v > 0) {
        s += v & 1 ? '1' : '0', v >>= 1;
    }
    s += "b0";
    std::reverse(s.begin(), s.end());
    return s;
}

template <class T>
inline std::string bin(T v, int dig) {
    std::string s = "0b";
    for (int i = dig - 1; i >= 0; i--) {
        s += (v >> i & 1) ? '1' : '0';
    }
    return s;
}

inline char hex(int v) {
    static const char tab[16]{
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };
    return tab[v];
}

template <class T>
inline std::string hex(T v) {
    std::string s;
    if (v == 0) return "0x0";
    while (v > 0) {
        s += hex(v & 15), v >>= 4;
    }
    s += "x0";
    std::reverse(s.begin(), s.end());
    return s;
}

template <class T>
inline std::string hex(T v, int dig) {
    std::string s = "0x";
    for (int i = dig - 1; i >= 0; i--) {
        s += hex(v >> (4 * i) & 15);
    }
    return s;
}

#endif // AFALG_UTILS
