#pragma once

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

#endif // AFMT_PRIME
