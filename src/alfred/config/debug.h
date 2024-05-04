/**
 * @file        debug.h
 * @author      Dr.Alfred (abonlinejudge@163.com)
 * @brief       Local Debug Printer
 * @version     1.0
 * @date        2023-12-30
 *
 * @copyright   Copyright (c) 2019-now <Rhodes Island Inc.>
 *
 */

#include <bits/stdc++.h>

using std::cerr;
using std::pair;
using std::string;

const long long dbg_inf = 9e18 + 19260817;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) {
    if (x != dbg_inf) {
        cerr << x;
    } else {
        cerr << "inf";
    }
}
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(__int128_t x) {
    if (x < 0) cerr << '-', x = -x;
    if (x > 9) __print(x / 10);
    cerr << char((x % 10) ^ 48);
}
void dbgEndl(void) { cerr << '\n'; }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{', __print(x.first), cerr << ", ", __print(x.second), cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto i : x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef DEBUG
// To customize a struct/class to print, just define the __print function.

#ifndef NO_DBG_COLOR
#define dbg(x...)                                                             \
    cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    _print(x);                                                                \
    cerr << "\e[39m";

#define short_dbg(x...) \
    cerr << "\e[91m[["; \
    _print(x);          \
    cerr << "\e[39m";
#else
#define dbg(x...)                                                 \
    cerr << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
    _print(x);
#define short_dbg(x...) \
    cerr << "[";        \
    _print(x);
#endif // !NO_DBG_COLOR

#else
#define dbg(x...)
#endif
