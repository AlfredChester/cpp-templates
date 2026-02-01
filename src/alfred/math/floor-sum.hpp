#ifndef AFMT_FLOOR_SUM
#define AFMT_FLOOR_SUM

// Calculate $\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$ in $O(\min\{a, m, n\})$
long long floor_sum(
    long long a, long long b, long long m, long long n
) {
    if (a == 0) return b / m * n;
    if (a >= m || b >= m) {
        return (a / m) * (n * (n - 1) / 2) + b / m * n +
               floor_sum(a % m, b % m, m, n);
    }
    long long mx = (a * (n - 1) + b) / m;
    return (n - 1) * mx - floor_sum(m, m - b - 1, a, mx);
}

#endif // !AFMT_FLOOR_SUM
