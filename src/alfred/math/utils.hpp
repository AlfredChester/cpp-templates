#ifndef AFMT_UTIL
#define AFMT_UTIL

#include <cmath>
#include <vector>

// O(sqrt(x)) to judge if x is a prime.
// It will be re-written in Miller-rabin sometime.
constexpr bool is_prime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

template <class T>
inline T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template <class T>
inline T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template <class T>
inline T isqrt(T x) {
    T res = std::sqrt(x);
    if (res * res > x) res--;
    return res;
}

// Given in integer n. Returns (primes, minp)
std::pair<std::vector<int>, std::vector<int>> euler_sieve(int n) {
    std::vector<int> primes, minp(n + 1);
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (i % p == 0) break;
        }
    }
    return std::make_pair(primes, minp);
}

#endif // AFMT_UTIL
