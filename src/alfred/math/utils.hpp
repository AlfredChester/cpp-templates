#ifndef AFMT_PRIME
#define AFMT_PRIME

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

#endif // AFMT_PRIME
