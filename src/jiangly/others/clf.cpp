using i64 = long long;
using i128 = __int128;
inline i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    } else {
        return n / m;
    }
}
inline i64 floorDiv(i64 n, i64 m) {
    if (n >= 0) {
        return n / m;
    } else {
        return (n - m + 1) / m;
    }
}
template <class T>
inline void chmax(T &a, T b) {
    if (a < b) a = b;
}
template <class T>
inline void chmin(T &a, T b) {
    if (!(a < b)) a = b;
}
inline i128 gcd(i128 a, i128 b) {
    return b ? gcd(b, a % b) : a;
}
