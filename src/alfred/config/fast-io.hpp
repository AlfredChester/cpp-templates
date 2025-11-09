#ifndef ALFRED_IO
#define ALFRED_IO

#include "../math/mod-int.hpp"
#include <iostream>

class FastIO {
private:
    int chunk = 1 << 18;
    char *buf, *p1, *p2;
    char *obuf, *op;

    inline void flush_output() {
        size_t len = size_t(op - obuf);
        fwrite(obuf, 1, len, stdout), op = obuf;
    }

public:
    inline char nc(void) {
        if (p1 == p2) {
            p2 = (p1 = buf) + fread(buf, 1, chunk, stdin);
            if (p1 == p2) return EOF;
        }
        return *p1++;
    }
    inline void pc(char c) {
        if (op == obuf + chunk) flush_output();
        *op++ = c;
    }
    FastIO(void) : chunk(1 << 18) {
        p1 = p2 = buf = (char *)(malloc(chunk));
        op = obuf = (char *)(malloc(chunk));
    }
    FastIO(int _chunk) : chunk(_chunk) {
        p1 = p2 = buf = (char *)(malloc(chunk));
        op = obuf = (char *)(malloc(chunk));
    }
    ~FastIO(void) {
        flush_output();
        free(buf), free(obuf);
    }
    inline void flush(void) { flush_output(); }
} __buf;

inline void pc(char c) { __buf.pc(c); }

template <class T>
inline void fast_read(T &x) {
    x = 0;
    static bool neg = false;
    static char c = __buf.nc();
    while (c < '0' || c > '9') {
        neg = (c == '-'), c = __buf.nc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + (c ^ 48), c = __buf.nc();
    }
    if (neg) x = -x;
}
template <class T>
inline void write(T x) {
    if (x < 0) {
        __buf.pc('-'), x = -x;
    }
    if (x > 9) write(x / 10);
    __buf.pc((x % 10) ^ 48);
}
template <int mod>
inline void write(ModInt<mod> x) {
    write(x.x);
}
template <typename T, typename... V>
inline void write(T x, V... v) {
    write(x), __buf.pc(' '), write(v...);
}
template <class T>
inline void writeln(T x) {
    write(x), __buf.pc('\n');
}
template <typename T, typename... V>
inline void writeln(T x, V... v) {
    write(x), __buf.pc(' '), writeln(v...);
}
template <typename T, typename... V>
inline void fast_read(T &t, V &...v) {
    fast_read(t), fast_read(v...);
}

#endif // ALFRED_IO
