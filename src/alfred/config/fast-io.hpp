#include <iostream>

class FastIO {
private:
    int siz = 100000;
    char *buf, *p1, *p2;

public:
    inline char nc(void) {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, siz, stdin), p1 == p2) ? EOF : *p1++;
    }
    inline void pc(char c) { putchar(c); }
    FastIO(void) { buf = (char *)malloc(siz); }
    FastIO(int n) : siz(n) { buf = (char *)malloc(siz); } // n characters.
    ~FastIO(void) { free(buf); }
    inline void resize(int n) {
        siz = n;
        buf = (char *)realloc(buf, siz);
    }
} __buf;

inline void reset_size(int siz) {
    __buf.resize(siz);
}

template <class T>
inline void fast_read(T &x) {
    x = 0;
    static char c = __buf.nc();
    while (c < '0' || c > '9') c = __buf.nc();
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + (c ^ 48), c = __buf.nc();
    }
}
template <class T>
inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar((x % 10) ^ 48);
}
template <class T>
inline void writeln(T x) {
    write(x), puts("");
}
template <typename T, typename... V>
inline void writeln(T x, V... v) {
    write(x), putchar(' '), writeln(v...);
}
template <typename T, typename... V>
inline void fast_read(T &t, V &...v) {
    fast_read(t), fast_read(v...);
}
